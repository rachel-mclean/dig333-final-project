#include <Servo.h>
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

Servo myServo;

// Pin definitions

const int knockSensor = A0;         // Piezo sensor on pin 0.

 

// Tuning constants.  Could be made vars and hoooked to potentiometers for soft configuration, etc.

const int threshold = 50;           // Minimum signal from the piezo to register as a knock

const int rejectValue = 30;        // If an individual knock is off by this percentage of a knock we don't unlock..

const int averageRejectValue = 30; // If the average timing of the knocks is off by this percent we don't unlock.

const int knockFadeTime = 150;     // milliseconds we allow a knock to fade before we listen for another one. (Debounce timer.)

const int maximumKnocks = 20;       // Maximum number of knocks to listen for.

const int knockComplete = 1300;     // Longest time to wait for a knock before we assume that it's finished.

// Variables.

int secretCode[maximumKnocks] = {50, 25, 25, 50, 100, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // Initial setup: "Shave and a Hair Cut, two bits."

int knockReadings[maximumKnocks];   // When someone knocks this array fills with delays between knocks.

int knockSensorValue = 0;           // Last reading of the knock sensor.


void setup() {

  delay(1000);
  CircuitPlayground.begin();
  myServo.attach(A3);
  pinMode(13, OUTPUT);
  pinMode(knockSensor, OUTPUT);
  Serial.begin(9600);                           // Uncomment the Serial.bla lines for debugging.
  Serial.println("Program start.");              // but feel free to comment them out after it's working right.

 

  CircuitPlayground.setPixelColor(1, 0, 255, 0); // Green LED on, everything is go.
  delay(500);
  CircuitPlayground.clearPixels();

}

void loop() {

  // Listen for any knock at all.

  knockSensorValue = analogRead(knockSensor);
  // Serial.println(knockSensorValue, DEC);

 
  if (knockSensorValue >=threshold){

    listenToSecretKnock();

  }

}

// Records the timing of knocks.

void listenToSecretKnock(){

  Serial.println("knock starting");  

  int i = 0;

  // First let's reset the listening array.

  for (i=0;i<maximumKnocks;i++){

    knockReadings[i]=0;

  }

 

  int currentKnockNumber=0;                     // Incrementer for the array.

  int startTime=millis();                       // Reference for when this knock started.

  int now=millis();

 

  CircuitPlayground.setPixelColor(1, 0, 255, 0); // we blink the LED for a bit as a visual indicator of the knock.
  delay(500);
  CircuitPlayground.clearPixels();                  


  delay(knockFadeTime);                                   // wait for this peak to fade before we listen to the next one.

  CircuitPlayground.setPixelColor(1, 0, 255, 0); 


  do {

    //listen for the next knock or wait for it to timeout.

    knockSensorValue = analogRead(knockSensor);

    if (knockSensorValue >=threshold){                   //got another knock...

      //record the delay time.

      Serial.println("knock.");

      now=millis();

      knockReadings[currentKnockNumber] = now-startTime;

      currentKnockNumber ++;                             //increment the counter

      startTime=now;         

      // and reset our timer for the next knock

      CircuitPlayground.clearPixels();  


      delay(knockFadeTime);                              // again, a little delay to let the knock decay.

      CircuitPlayground.setPixelColor(1, 0, 255, 0);

    }

    now=millis();

   

    //did we timeout or run out of knocks?

  } while ((now-startTime < knockComplete) && (currentKnockNumber < maximumKnocks));

 

  // we've got our knock recorded, lets see if it's valid


   if (validateKnock() == true){

     triggerDoorUnlock();
     Serial.println("Secret knock achieved!!!!");

   } else {

     Serial.println("Secret knock failed.");

     CircuitPlayground.clearPixels();           // We didn't unlock, so blink the red LED as visual feedback.

     CircuitPlayground.redLED(HIGH);
     delay(700);
     CircuitPlayground.redLED(LOW);

     CircuitPlayground.setPixelColor(1, 0, 255, 0);

   }

}
//
//// Runs the motor (or whatever) to unlock the door.
//
void triggerDoorUnlock(){

  CircuitPlayground.setPixelColor(1, 0, 255, 0);

  Serial.println("Door unlocked!");

  int i=0;

 

  // turn the motor on for a bit.

  for(int i = 75; i >= 0; i--) {
    myServo.write(i);
    delay(15);
  }

  delay(650);
  
  for(int i = 0; i <= 75; i++) {
   myServo.write(i);
   
   if(i == 0) {
     delay(15000);
   }

   else{
     delay(15);
   }

  }

  delay(650);
 

  // Blink the green LED a few times for more visual feedback.

  CircuitPlayground.setPixelColor(1, 0, 255, 0);
  delay(500);
  CircuitPlayground.clearPixels();

  }

//// Sees if our knock matches the secret.
//
//// returns true if it's a good knock, false if it's not.
//
//// todo: break it into smaller functions for readability.
//
boolean validateKnock(){

  int i=0;

 

  // simplest check first: Did we get the right number of knocks?

  int currentKnockCount = 0;

  int secretKnockCount = 0;

  int maxKnockInterval = 0;                      // We use this later to normalize the times.

 

  for (i=0;i<maximumKnocks;i++){

    if (knockReadings[i] > 0){

      currentKnockCount++;

    }

    if (secretCode[i] > 0){                      //todo: precalculate this.

      secretKnockCount++;

    }

   

    if (knockReadings[i] > maxKnockInterval){     // collect normalization data while we're looping.

      maxKnockInterval = knockReadings[i];

    }

  }

  if (currentKnockCount != secretKnockCount){

    return false;

  }

 
  /*  Now we compare the relative intervals of our knocks, not the absolute time between them.

      (ie: if you do the same pattern slow or fast it should still open the door.)

      This makes it less picky, which while making it less secure can also make it

      less of a pain to use if you're tempo is a little slow or fast.

  */

  int totaltimeDifferences=0;

  int timeDiff=0;

  for (i=0;i<maximumKnocks;i++){ // Normalize the times

    knockReadings[i]= map(knockReadings[i],0, maxKnockInterval, 0, 100);     

    timeDiff = abs(knockReadings[i]-secretCode[i]);

    if (timeDiff > rejectValue){ // Individual value too far out of whack

      return false;

    }

    totaltimeDifferences += timeDiff;

  }

  // It can also fail if the whole thing is too inaccurate.

  if (totaltimeDifferences/secretKnockCount>averageRejectValue){

    return false;

  }

 

  return true;

 }
