int analogin = A0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int value = analogRead(analogin);

    Serial.println(value);

    delay(1000);
}