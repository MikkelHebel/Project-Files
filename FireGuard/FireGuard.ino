// FireGuard
// Version: 1.0
#include "Arduino.h"
#include "Drive.h"
#include "FireDetection.h"
char debug = false;

void setup() {
  Serial.begin(115200);
  Serial.println("[SETUP] Beginning setup!");
  Serial.print("[DEBUG] debug mode: ");
  Serial.println(debug);
  Serial.println(result);
  Serial.println("[SETUP] Setup completed!");
}

void loop() {
  if (debug == true) {
    Serial.println("[DEBUG] Running loop!");
  }
  drive();
}
