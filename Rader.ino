#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

//Antager 20 grader celcius rumtemperatur
const int TRIG_PIN = 35;
const int ECHO_PIN = 39;

void setup() {
 // initialiser serial kommunikation:
 Serial.begin(9600);
 pinMode(TRIG_PIN,OUTPUT);
 pinMode(ECHO_PIN,INPUT);
 // initialize LCD
 lcd.init();
 // turn on LCD backlight                      
 lcd.backlight();
}

void loop() {
 long duration, distanceCm;
 // Laver en kort lav puls først, for derefter at lave en ren høj 10ms puls:
 digitalWrite(TRIG_PIN, LOW); //Sætter den lav
 delayMicroseconds(2); //Vent 2ms
 digitalWrite(TRIG_PIN, HIGH); //Sætter den høj
 delayMicroseconds(10); //Venter => 10ms lang puls
 digitalWrite(TRIG_PIN, LOW); //Sætter den lav
 duration = pulseIn(ECHO_PIN,HIGH);//Venter på, og læser puls-længde på echo-pin.
// konverterer tid til distance
 distanceCm = duration / 29.1 / 2 ; //Beregner distancen.
//Burde være: duration / 34 / 2;
//Men 29.1 var en bedre kalibrering med min sensor.
 lcd.clear();
 // set cursor to first column, first row
 lcd.setCursor(0, 0);
 // print message
 lcd.print("Distance:");
if (distanceCm <= 0 || distanceCm>2400){
 Serial.println("Out of range");
 lcd.setCursor(0,1);
 lcd.print("Out of range!");
 }
 else {
 Serial.print(distanceCm);
 Serial.print("cm");
 Serial.println();
 // set cursor to first column, second row
 lcd.setCursor(0,1);
 lcd.print(distanceCm);
 lcd.print(" cm");
 delay(1000);
 }
 delay(1000);
}
