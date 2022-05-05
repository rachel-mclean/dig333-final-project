# dig333-final-project
Secret knock detecting computer lock

#### Milestones: [1](#Milestone-1) [2-3](#Milestone-2-and-Milestone-3) [4](#Milestone-4)

## Final Project Milestones

### Milestone 1: 
Decide how the motor and lock are rigged, gather materials, and construct the physical device.

* I decided on a Piezo buzzer for the sensor and a 5V DC motor for my motor and sensor. I wanted to use an actuator motor, but concluded that a mini actuator motor of the right voltage would not have enough range of movement to open the lock. 
* The DC motor will lay on its side at one end of the rectangular opening. A curved wire, attached to the end of the motor, will sit inside the hook keep the case closed. When the correct knock is performed, the motor will turn and the curved wire will slightly rotate so that the hook is released, opening the case.
*  I scavenged some hinges from an old wooden box to use on my computer case. I also scavenged an old raspberry pi case from the Maker Space to use as casing for some of my electric components.
* <img src = "https://user-images.githubusercontent.com/59896196/163921633-78396d70-bbad-4ded-8e51-142cc3f6a320.jpg" width="250" height = "400">
* Using Tinkercad, I created an updated design iteration of my project (updated Tinkercad design [here](https://www.tinkercad.com/things/37gWwb9qrOn-exquisite-blorr/edit))
* <img src="https://user-images.githubusercontent.com/59896196/163921910-44a6b30e-a00f-4fbd-83e2-be316050d9f9.png" width="400" height="300" >
* In the Makerspace, I created files for the different components of the computer case on Adobe. Then, I used the laser cutter  to cut out the different parts of my case. I used sandpaper to sand down the edges. Luca, an employee in the Maker Space, guided me on how to use Adobe and the laser cutter.
* Luca and I also used the laser cutter to engrave a door-knock shape onto the 4 sides of the case. I thought this was a fun touch to subtly suggest the purpose of the case.
* <img src = "https://user-images.githubusercontent.com/59896196/163922642-3ec52590-d94d-4e3e-be53-4816910500f9.jpg" width="500" height="400">
* I glued two of the sides using wood glue before realizing that I should attach the hinged part of the case first. I first began to attach the hinge on the outside using a drill, before realizing that the screws ruined the door-knock design on my wooden piece. I then attached the hinge on the inside of the wooden pieces, before realizing that this prevented the hinged side from opening. Finally, I re-attached the hinge to the outside of the case. Unfortunately, this interrupted the engraved design, but worked.
* My last step was to attach the "hook" on the inside of the hinged piece. I realized the hook I created was far too small, so that it didn't match the opening in the top of the case when glued to the side piece. I remedied this by drilling the hook to a wooden block, so that the hook reaches the opening of the case.
* I then glued all pieces together and waited for them to dry.
* <img src = "https://user-images.githubusercontent.com/59896196/163923232-c8b87a3b-2df0-4f1d-860d-4c9e71e94ca5.jpg" width = "500" height = "400">



### Milestone 2 and Milestone 3:
Milestone 2 - Write the necessary Python Code: 1) for the sensor to recognize a knock and 2) for the motor to turn when the sensor correctly recognizes a knock.

Milestone 3 - Test all components with the Arduino on a breadboard to test functionality of the code.

* Initially, I looked at two options: 
  * Adapting [this](https://www.instructables.com/Secret-Knock-Detecting-Door-Lock/) code, written for Arduino in C+. This required use of a capacitator for the RaspberryPi.
  * Adapting [this](https://github.com/iver56/clap-detection/blob/master/clap.py) code, written in Python for RaspberryPi. This code does not mention any pin connections so I had trouble figuring out what sensor was used and how/if it is attached to the pi.
 * I borrowed a Piezo vibration sensor from Dr. Mundy (datasheet [here](http://cdn.sparkfun.com/datasheets/Sensors/ForceFlex/LDT_Series.pdf))
 * <img src = "https://user-images.githubusercontent.com/59896196/165547117-4c534c73-d768-407a-918f-26bdeef968af.jpg" width="300" height = "500">
 * To make sure it worked, I connected the sensor to the RaspberryPi. I also used a 1M resistor. “The Piezo is grounded on one end, and a generated voltage is routed to the 3.3v pin. Reading the voltage at that pin should give us an idea of how much the piezo is moving.”
 * <img src="https://user-images.githubusercontent.com/59896196/165549001-18351730-207b-45dd-81f7-7ac144fe22cb.png" width = "400" height = "250">
 * <img src = "https://user-images.githubusercontent.com/59896196/165548139-5756cb01-71dd-40da-9183-11fe42d087d8.jpg" width = "300" height = "500">
 * The multimeter correctly read 3.3v. However, knocking created no change in this value.
 * Reading the datasheet informed me that the changes were in mV. I changed the pin to the 5v, and knocks correctly registered small changes in voltage.
 * <img src = "https://user-images.githubusercontent.com/59896196/165549275-7070b5e6-1482-4c55-a3da-b1ee2c132f51.jpg" width = "300" height = "500">
 * At this point, I decided to switch from the RaspberryPi to the Arduino Uno. This decision was based on the fact that most reference code was written for the Arduino.
 * <img src = "https://user-images.githubusercontent.com/59896196/165549666-4d63bb30-61b6-4343-9e87-f1dbbc5ffd34.jpg" width = "300" height = "500">
 * Unfortunately, this switch was not simple. Running the "Blink" sketch revealed an error. Despite installing some new drivers and spending a lot of time debugging, we were not able to remediate the error.
 * <img src="https://user-images.githubusercontent.com/59896196/165550266-87db00ea-f0e3-4ae9-afc2-181c3f7d64b5.png" width = "300" height = "500">
 * I switched to the Adafruit Circuit Playground Express, and was able to run a basic sketch. I successfully connected my circuit using the AO and GND pins.
 * <img src = "https://user-images.githubusercontent.com/59896196/165551042-1eb92fb1-3194-4d7b-aead-aa1f6efa289a.jpg" width = "300" height = "500">
 * I verified my sensor was connected by printing values to the serial monitor.
 * <img width="379" alt="Show timestamp" src="https://user-images.githubusercontent.com/59896196/165551266-30c5d70d-c391-4f9d-9251-7255bce4fb0f.png">
 * Hooking up the servo motor, using A3, GND, and VOUT
 * <img src="https://user-images.githubusercontent.com/59896196/165603889-6f4c4af1-1763-4823-b384-dd6da6e5bc2a.png" width="400" height = "200">
 * <img src = "https://user-images.githubusercontent.com/59896196/165610020-f86bd2e6-6096-4a9c-9021-f3c55de43d57.jpg" width = "300" height = "500">
 * I realized the Piezo vibration sensor was not consistently reading knock values as expected, and had too much "fuzz." I switched to a Piezo knock sensor and was able to use the same circuit setup, and the readings on the serial monitor were much better. The higher values at the bottom of the image below are knocks.
 * <img src="https://user-images.githubusercontent.com/59896196/166840781-7bd66b02-aac7-4a7c-8ff2-25e1b603d842.png" width="500" height="200">
 * <img src = "https://user-images.githubusercontent.com/59896196/166705320-82a842e0-c1a5-475a-994b-9145ad9e4bf9.jpg" width = "300" height = "500">
 * Modifying [this](https://electronics.divinechildhighschool.org/electronics-class/logs-for-fall-2009/secret-knock-final) code to work for the Adafruit Circuit Playground, and referencing [this](https://codepen.io/owenmundy/pen/abErxLv?editors=0011) CodePen project by Dr. Mundy, I was able to recognize a secret knock! I used print statements in the serial monitor to ensure the secret knock had been performed. The knock used below is "Shave and a haircut, two bits."
 * <img src="https://user-images.githubusercontent.com/59896196/166722781-d177bc75-ee42-49a0-9c48-6ae18f97fd6f.png" width="700" height = "300">
 * I also ensured that it correctly recognized when a knock failed.
 * <img src="https://user-images.githubusercontent.com/59896196/166723639-61edeab2-e995-4138-b468-523fe9f9edd6.png" width="700" height = "300">
 * I finished the code for the motor. The most difficult part was figuring out at which angle I needed the Servo to turn, in relation to the position the Servo would be on the case. I initially determined that the Servo needs to start at 90 degree, move to 0 degrees, stay there for ~10 seconds so that you have time to remove your computer from the case, before moving back to 90 degrees to relock. After some trial and error, I realized that my Servo appears to be calibrated slightly off center, so I start at 75 degrees instead of 90.
 * [Video of motor here](https://user-images.githubusercontent.com/59896196/166842343-28a13e42-31e1-400a-b8df-9f518afb9f1b.mp4)

### Milestone 4:
Finalize casing for the sensor, motor, and raspberry pi on the physical device. If time permits, attach a BlueTooth module that sends an alert when the wrong knock is performed.

* Upon Dr. Mundy's recommendation, I added a structure on top of the Piezo sensor, consisting of an eraser and a square of cardboard. This allowed the knocking platform to essentially become extended, making it easier to knock.
* <img src = "https://user-images.githubusercontent.com/59896196/166813794-7b3f1776-6bbd-43f2-a6c9-ef36d7c014b2.jpg" width="350" height="500">
* I re-tested all components together, [Video Here.](https://drive.google.com/file/d/1woGJzguI93DCRYlKL7eZGD9Rzqljm2yh/view?usp=sharing) 
* I realized that I can run the program with my computer closed. This is good, because it means I can actually lock my computer using my project. Otherwise it would be completely useless!
* I rigged the lock using a sewing needle and a wire. The inside mechanics consisted of a yellow wire with protective plastic coating, in the shape of a loop. When locked, the sewing needle sits inside the loop and prevents the hinged door from opening. When the lock is unlocked, the Servo turns about 90 degrees and the needle slides out of the loop, allowing the door to open and your computer to be removed.
* <img src = "https://user-images.githubusercontent.com/59896196/166852966-e2647870-12a0-403d-bbae-aa355c347371.jpg" width="350" height="500">
* <img src = "https://user-images.githubusercontent.com/59896196/166853238-099957fc-6bec-4fb2-8602-33abe42901cb.jpg" width="400" height="550">
* Next, I tested a secret knock with the lock to make sure it worked. [Video of the secret knock with the lock here.](https://drive.google.com/file/d/1JxasYOTA9yxNGOqvPCbQ6JIbaI-sD3M1/view?usp=sharing)
* I put all wiring into a box with a hole in the top, so that the Arduino, motor, and sensor can remain hooked to the outside of the case. I secured the sensor and eraser to the top of the components box.
* <img src = "https://user-images.githubusercontent.com/59896196/166854188-cd25eca2-c184-4cf2-addb-d8e1d225ea17.jpg" width="350" height="500">
* One benefit of the hole in the top of the box is that the box fills with green or red light, when a knock is correctly or incorrectly performed. When the Arduino was outside of the box, the blinking of the LEDs was not as noticeable.
* I ensured that I could lock my computer in the case as expected, and safely remove it without damage.
* <img src="https://user-images.githubusercontent.com/59896196/166857625-7d142d5a-8acd-4ed2-8419-afeb71f2e192.png" width="350" height="500">

* Below is a video of the lock in action. My computer is locked inside the case, before the correct secret knock is performed and I am able to remove it.





