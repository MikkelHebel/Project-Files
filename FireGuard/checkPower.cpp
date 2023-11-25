#include "checkPower.h"
int value = 0;
float voltage;
float percentage;

void setup(){
  Serial.begin(9600);
}

void loop(){
  value = analogRead(A0);
  voltage = value * 5.0/1023;
  percentage = map(voltage, 3.6, 4.2, 0, 100);
  Serial.print("Voltage= ");
  Serial.println(voltage);
  Serial.print("Battery level= ");
  Serial.print(percentage);
  Serial.println(" %");
  delay(500);
}
