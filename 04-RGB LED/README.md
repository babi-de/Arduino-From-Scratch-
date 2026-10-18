# RGB LED Project 

## Description
This project uses an RGB LED with an Arduino Uno to display different colors. A custom C++ function, `RGBColour()`, controls the intensity of the red, green, and blue components.

## Components
- Arduino Uno
- RGB LED
- Breadboard
- Jumper wires
- 3 resistors
- Tinkercad Circuits

## Concepts Learned
- `pinMode()` to configure output pins.
- `analogWrite()` to control color intensity using PWM.
- Custom functions in C++.
- `delay()` to control the timing between color changes.

## How It Works
The `RGBColour()` function takes three parameters:
- `redvalue`: red intensity
- `greenvalue`: green intensity
- `bluevalue`: blue intensity

Each value ranges from 0 to 255. Combining these values produces different colors.

## Pins Used
- Red: Pin 11
- Green: Pin 10
- Blue: Pin 9

## Simulation
Created and tested using Tinkercad Circuits.

---

*Part of my Arduino From Scratch learning journey.*