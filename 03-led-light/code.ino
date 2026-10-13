int LED_ROUGE = 12;
int LED_JAUNE = 4;
int LED_VERTE = 2;

void setup() {
  pinMode(LED_ROUGE, OUTPUT);
  pinMode(LED_JAUNE, OUTPUT);
  pinMode(LED_VERTE, OUTPUT);
}

void loop() {
  // R
  digitalWrite(LED_ROUGE, HIGH);
  digitalWrite(LED_JAUNE, LOW);
  digitalWrite(LED_VERTE, LOW);
  delay(5000);

  // v
  digitalWrite(LED_ROUGE, LOW);
  digitalWrite(LED_JAUNE, LOW);
  digitalWrite(LED_VERTE, HIGH);
  delay(5000);

  // y
  digitalWrite(LED_VERTE, LOW);
  digitalWrite(LED_JAUNE, HIGH);
  delay(2000);

  
  digitalWrite(LED_JAUNE, LOW);
}