/*
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
Programmer: Dillon Girvin
Project Name: ShootingMechanism
Version: 1.0.3
Project Description:
This project is intended to be used in order to rotate the stepper motor conencted to the shooting
mechanism. It does this by going one step at a time at a predefined RPM until one full revolution
has occured. This should pull back the spring loaded mechanism on the gun, then release it shooting
the ball that is loaded inside.
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
*/

// Libraries
#include <Arduino.h>
#include <Stepper.h>

// #defines
#define DIRECTION_TOGGLE -1 // Change to -1 to switch direction
#define STEPS 200
#define RPM_SPEED 300

#define DIR_PIN 2
#define STEP_PIN 9

// Local instance variables
Stepper stepperMotor = Stepper(STEPS, DIR_PIN, STEP_PIN);

int amountOfStepsTaken = 0;

/*
setup()
Purpose:
--The setup method runs once when the program is started.
Parameters:
--None
Return Variables:
--None
*/
void setup()
{
  // Set the desired speed of the motor in RPMs
  stepperMotor.setSpeed(RPM_SPEED);


  // Turn on LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

/*
loop()
Purpose:
--The loop() method runs repeatedly until the program is terminated.
Parameters:
--None
Return Variables:
--None
*/
void loop()
{
  // Move the stepper one step in the desired direction.
  stepperMotor.step(DIRECTION_TOGGLE * 1);

  // Increase or reset the amount of steps taken.
  if (amountOfStepsTaken < 200)
  {
    amountOfStepsTaken++;
  }
  else
  {
    amountOfStepsTaken = 0;
  }
}

/*
Version Notes:
1.0:
+Added Stepper class
+Created #defines in order to be able to easily change parameters later.
+Made the stepper motor move one step at a time until one revolution has taken place
(once one revolution has taken place, the program waits then starts to rotate again.)

1.0.1:
+Changed pins for DIR and STEP to 2 and 9
-Removed delay call

1.0.2:
+Added LED light on while program is on

1.0.3:
+Changed direction
+Changed RPM
*/