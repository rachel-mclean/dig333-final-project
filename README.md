# dig333-final-project
Secret knock detecting computer lock

#### Milestones: [1](#Milestone-1) [2](#Milestone-2) [3](#Milestone-3) [4](#Milestone-4)

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


### Milestone 2: 
Write the necessary Python Code: 1) for the sensor to recognize a knock and 2) for the motor to turn when the sensor correctly recognizes a knock.

* Initially, I looked at two options: 
  * Adapting [this](https://www.instructables.com/Secret-Knock-Detecting-Door-Lock/) code, written for Arduino in C+. This required use of a capacitator for the RaspberryPi.
  * Adapting [this](https://github.com/iver56/clap-detection/blob/master/clap.py) code, written in Python for RaspberryPi. This code does not mention any pin connections so I had trouble figuring out what sensor was used and how/if it is attached to the pi.
  * I borrowed a Piezo vibration sensor from Dr. Mundy (datasheet [here](http://cdn.sparkfun.com/datasheets/Sensors/ForceFlex/LDT_Series.pdf))
  * <img src = "https://user-images.githubusercontent.com/59896196/165547117-4c534c73-d768-407a-918f-26bdeef968af.jpg" width="250" height = "500"


### Milestone 3:
Test all components with the RaspberryPi on a breadboard to test functionality of the code.

### Milestone 4:
Finalize casing for the sensor, motor, and raspberry pi on the physical device. If time permits, attach a BlueTooth module that sends an alert when the wrong knock is performed.


