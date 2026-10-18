
#define RED 11
#define GREEN 3
#define BLUE 9

// C++ code

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop()
{
  RGBColour(255, 0, 0);
  delay(1000);

  RGBColour(0, 255, 0);
  delay(1000);

  RGBColour(0, 0, 255);
  delay(1000);
}

void RGBColour(int redvalue, int greenvalue, int bluevalue)
{
  analogWrite(RED, redvalue);
  analogWrite(GREEN, greenvalue);
  analogWrite(BLUE, bluevalue);
}
