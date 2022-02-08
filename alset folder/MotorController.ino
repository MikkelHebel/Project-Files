// MotorController
// Version: 0.2

#include "Arduino.h"
char debug = false;

// Motor A
int ENA = 25;
int IN1 = 13;
int IN2 = 12;

// Motor B
int ENB = 26;
int IN3 = 14;
int IN4 = 27;

void setup () {
  Serial.begin(115200);
  Serial.println("[SETUP] Beginning setup!");
  // Alle ben er udgange
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  Serial.println("[SETUP] Setup completed!");
}

void loop () {
  while (debug == true) {
    Serial.println("[DEBUG] Running loop!");
  }

  //Retning motor A
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);

  //Hastighed motor A
  digitalWrite(ENA, 0);

  //Retning motor B
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);

  //Hastighed motor B
  //ledcWrite(ENB, 75);
}
