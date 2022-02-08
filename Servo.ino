/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
  Written by BARRAGAN and modified by Scott Fitzgerald
*********/


//#include <ESP32Servo.h>
//#include <analogWrite.h>
//#include <tone.h>
//#include <ESP32Tone.h>
//#include <ESP32PWM.h>
#include <Servo.h>


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(13);  // attaches the servo on pin 13 to the servo object
  Serial.println("[SETUP] Ran setup!");
}

void loop() {
  Serial.println("[INFO] Ran loop!");
  for (pos = 55; pos <= 145; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 145; pos >= 55; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
