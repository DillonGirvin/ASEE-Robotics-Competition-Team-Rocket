/*
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
Programmer: Dillon Girvin
Project Name: TeensyTest1
Version: 1.0.2

Project Description:
TeensyTest1 is a project that I created in order to test if ProjectIO would correctly 
upload programs to the Teensy 4.1 Board. To test this, I used code that I found on
the internet which would flash the built in LED on the Teensy board. The site used is:

https://forum.pjrc.com/threads/63712-Blink-sketch-does-nothing-on-Teensy-4-1

The code itself simply creates an integer to store the value of the LED, and then alternates
the LED between HIGH and LOW mode. Between each of these, there is a call to the delay()
function in order to keep the LED on or off for the specified amount of time in ms.

To ensure that the code worked, I uploaded a blank program to the teensy and observed that
it did not flash the LED. I then uploaded this program to the teensy and noted that the 
built in LED started to flash once the program was uploaded. Through this I have determined
that the ProjectIO exention is successfully detecting the board, and uploading files to it.

----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------





*/

// Libraries
#include <Arduino.h>

// Class variable to store LED address(?)
int led = 13;

/*
setup()

Purpose:
--The setup method runs once when the program is started. It changes the pin mode on the LED pin (13)
--to output mode.

Parameters:
--None

Return Variables:
--None
*/
void setup() {
  // Sets the pin for the LED to be used as output
  pinMode(led, OUTPUT);
}


/*
loop()

Purpose:
--The loop() method runs repeatedly until the program is terminated. It changes the
--pin for the LED between HIGH and LOW states, each for 1000 ms each.

Parameters:
--None

Return Variables:
--None
*/
void loop() {

  // Turn on LED
  digitalWrite(led, HIGH);
  delay(1000);

  // Turn off LED
  digitalWrite(led, LOW);
  delay(1000);
}




/*
Version Notes:

1.0: 
+Copied code from website listed in project description
+Added comments for documentation purposes.

1.0.1:
+Changed amount of time in the delay() function to 200ms
(This was done in order to ensure that the program uploaded was the 
program being run, rather than a pre-loaded program.)

1.0.2:
-Reverted amount of time in the delay() function to 1000ms
(this code is identical to the code in 1.0)
*/