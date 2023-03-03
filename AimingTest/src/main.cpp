/*
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
Programmer: Dillon Girvin
Project Name: AimingTest
Version: 1.0.2
Project Description:
This project uses the ShootingMechanism project, with a minor alteration to delay once one full
rotation takes place. This is done to ensure that the stepper motor can be programmed to go specific
angles.

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
  if (amountOfStepsTaken < 800)
  {
    amountOfStepsTaken++;
  }
  else
  {
    amountOfStepsTaken = 0;
    delay(1000);
  }
}

/*
Version Notes:
1.0:
+Copied ShootingMechanism Project
+Added delay before program start
+Added delay after 1 full revolution

1.0.1:
+Changed delay to 1 second

1.0.2:
+Changed amount of steps to 800 because 800 steps is one full rotation

*/