// MotorController
// Version: 2.0
#include "Arduino.h"
char debug = true;

// Motor A
int ENA = 36;
int IN1 = 15;
int IN2 = 2;

// Motor B
int ENB = 39;
int IN3 = 0;
int IN4 = 4;

// Sensor A
int TRIG_PIN = 35;
int ECHO_PIN = 34;

void setup () {
  Serial.begin(115200);
  Serial.println("[SETUP] Beginning setup!");
  Serial.print("[DEBUG] debug mode: ");
  Serial.println(debug);
  // Motor A pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // Motor B pins
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  // Sensor A pins
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  // LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("[SETUP] Setup completed!");
}

void loop () {
  if (debug == true) {
    Serial.println("[DEBUG] Running loop!");
  }
  delay(10000);
  digitalWrite(LED_BUILTIN, LOW);
  // Move the DC motor forward at maximum speed
  Serial.println("[INFO] Moving Forward");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(3000);
  Serial.println("[INFO] Object detected in front of the vehicle!");
  // Full stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(300);
  // Move DC motor backwards at maximum speed
  Serial.println("[INFO] Moving Backwards");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000);
  // Full stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(300);
  // Take a turn
  Serial.println("[INFO] Turning");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(300);
  // Full stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(300);
  // Move the DC motor forward at maximum speed
  Serial.println("[INFO] Moving Forward");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(10000);
}
