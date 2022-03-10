//const int buzzerPin = 11;
const int flamePin = 32;
int Flame = HIGH;

void setup() {
  Serial.begin(115200);
  Serial.println("[SETUP] Beginning setup!");
  //pinMode(buzzerPin, OUTPUT);
  pinMode(flamePin, INPUT);
  Serial.println("[SETUP] Setup completed!");
}

void loop() {
  Flame = digitalRead(flamePin);
  if (Flame == LOW) {
    Serial.println("[INFO] Fire is Detected");
    //digitalWrite(buzzerPin, HIGH);
  } else {
  Serial.println("[INFO] No Fire is Detected");
  //digitalWrite(buzzerPin, LOW);
 }
}
