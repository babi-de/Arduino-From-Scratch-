# Potentiometer – Analog Input

## Project Description
This project demonstrates how to read an analog signal using a potentiometer connected to an Arduino Uno.

By rotating the potentiometer, the output voltage changes. Arduino reads this voltage through its analog input pin (A0) and converts it into a digital value.

## Components
- Arduino Uno
- Potentiometer (10kΩ)
- Breadboard
- Jumper wires
- Voltmeter

## Circuit Connections

| Potentiometer       | Arduino 
----------------------------------------
| Terminal 1          | GND 
| Terminal 2 (middle) | A0 
| Terminal 3          | 5V 

The voltmeter is connected in parallel to measure the voltage between A0 and GND.

## Code Explanation

- `analogRead(A0)`: Reads the analog voltage.
- `Serial.begin(9600)`: Initializes serial communication.
- `Serial.println(value)`: Displays the converted value in the Serial Monitor.
- `delay(1000)`: Waits one second between readings.

## Expected Results

The Arduino Uno ADC converts the input voltage (0–5V) into a digital value between 0 and 1023.

| Input Voltage | Analog Value 
--------------------------------
| 0V            | 0 
| 2.5V          | Approximately 512 
| 5V            | 1023 

## What I Learned
- Understanding analog signals.
- Reading analog inputs using Arduino.
- Understanding Analog-to-Digital Conversion (ADC).
- Using the Serial Monitor to display sensor readings.

## Tools
- Arduino IDE / Tinkercad Circuits
- Arduino Uno
