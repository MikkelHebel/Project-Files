// MotorController
// Version: 0.3
#include "Arduino.h"
char debug = true;

// Motor A
int IN1 = 15;
int IN2 = 2;

// Motor B
int IN3 = 0;
int IN4 = 4;

void setup () {
  Serial.begin(115200);
  Serial.println("[SETUP] Beginning setup!");
  Serial.print("[DEBUG] debug mode: ");
  Serial.println(debug);
  // Alle ben er udgange
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  Serial.println("[SETUP] Setup completed!");
}

void loop () {
  if (debug == true) {
    Serial.println("[DEBUG] Running loop!");
  }

  // Move the DC motor forward at maximum speed
  Serial.println("[INFO] Moving Forward");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(5000);

  // Move DC motor backwards at maximum speed
  Serial.println("[INFO] Moving Backwards");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(5000);

  // Stop the DC motor
  Serial.println("[INFO] Motor stopped");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(5000);
}
