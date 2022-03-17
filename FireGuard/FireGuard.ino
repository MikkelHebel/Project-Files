// FireGuard
// Version: 1.0
#include "Arduino.h"
char debug = true;

void setup() {
  Serial.begin(115200);
  Serial.println("[SETUP] Beginning setup!");
  Serial.print("[DEBUG] debug mode: ");
  Serial.println(debug);
  Serial.println("[SETUP] Setup completed!");
}

void loop() {
  if (debug == true) {
    Serial.println("[DEBUG] Running loop!");
  }
}
