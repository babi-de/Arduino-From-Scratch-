
# HC-SR04 Distance Detector — Register-Level Programming

## 1. Project Overview

This project consists of an ultrasonic distance detection system built using an Arduino Uno, an HC-SR04 sensor, three LEDs, and a buzzer.

The objective is to detect obstacles and indicate their proximity through visual and sound alerts.

**Main Learning Focus:** Controlling microcontroller pins directly through hardware registers instead of relying on Arduino functions such as `pinMode()` and `digitalWrite()`.

---

## 2. Components Used

| Component | Quantity |
|---|---:|
| Arduino Uno (ATmega328P) | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Green LED | 1 |
| Yellow LED | 1 |
| Red LED | 1 |
| Piezo Buzzer | 1 |
| 220 Ω Resistors | 3 |
| Breadboard | 1 |
| Jumper Wires | As needed |

---

## 3. How the System Works

The HC-SR04 measures the distance between the sensor and an obstacle.

1. Arduino sends a 10-microsecond pulse through the TRIG pin.
2. The sensor emits an ultrasonic wave.
3. The wave hits an obstacle and returns to the sensor.
4. The ECHO pin produces a pulse whose duration represents the round-trip travel time.
5. Arduino measures this duration and calculates the distance.

### Distance Calculation

```cpp
Distance (cm) = Duration × 0.0343 / 2
```

The division by 2 is necessary because the ultrasonic wave travels to the obstacle and back.

---

## 4. System Behavior

The system reacts according to the detected distance:

| Detected Distance | Green LED | Yellow LED | Red LED | Buzzer |
|---|---|---|---|---|
| Above 30 cm | ON | OFF | OFF | OFF |
| Between 15 and 30 cm | OFF | ON | OFF | OFF |
| 15 cm or less | OFF | OFF | ON | ON |
| No echo detected | OFF | OFF | ON | ON |

---

## 5. Understanding Microcontroller Registers

Instead of using Arduino's high-level digital I/O functions, this project uses the ATmega328P hardware registers.

### 5.1 DDRD — Data Direction Register

DDRD configures the direction of each pin.

- `1` = OUTPUT
- `0` = INPUT

**Configuration used:**

```cpp
DDRD |= 0b01111100;
```

This configures PD2 to PD6 as outputs.

```cpp
DDRD &= ~(1 << PD7);
```

This configures PD7 as an input.

### 5.2 PORTD — Data Register

PORTD controls output states.

**Set PD2 to HIGH:**

```cpp
PORTD |= (1 << PD2);
```

Sets PD2 to HIGH (green LED ON).

**Set PD2 to LOW:**

```cpp
PORTD &= ~(1 << PD2);
```

Sets PD2 to LOW (green LED OFF).

### 5.3 PIND — Input Pins Register

PIND reads the actual logical state of the physical pins.

```cpp
PIND & (1 << PD7);
```

Checks whether PD7 (ECHO) is HIGH.

---

## 6. Pin Mapping

The following table shows the connection between Arduino pins, ATmega328P pins, and their functions.

| Component | Arduino Pin | ATmega328P Pin | Function |
|---|---|---|---|
| Green LED | D2 | PD2 | Distance indicator |
| Yellow LED | D3 | PD3 | Distance indicator |
| Red LED | D4 | PD4 | Warning indicator |
| Buzzer | D5 | PD5 | Sound alert |
| HC-SR04 TRIG | D6 | PD6 | Trigger signal |
| HC-SR04 ECHO | D7 | PD7 | Echo signal |

---

## 7. Bitwise Operations Learned

This project helped me understand how to manipulate individual bits without affecting other bits.

| Operator | Meaning | Purpose |
|---|---|---|
| `\|=` | Bitwise OR assignment | Set a specific bit to 1 |
| `&= ~` | Bitwise AND with NOT | Clear a specific bit to 0 |
| `<<` | Left shift | Move a bit to a specific position |
| `&` | Bitwise AND | Mask and test a specific bit |

---

## 8. What I Learned

Through this project, I practiced:

- Understanding the ATmega328P and its AVR architecture.
- Configuring input and output pins using DDRD.
- Controlling LEDs and TRIG using PORTD.
- Reading the ECHO signal using PIND.
- Working with binary values and bitwise operations.
- Measuring pulse duration using `micros()`.
- Calculating distance from ultrasonic travel time.
- Implementing conditional logic for real-time obstacle detection.
- Generating sound alerts using `tone()` and `noTone()`.

---

## 9. Development Environment

| Tool | Purpose |
|---|---|
| Arduino Uno | Microcontroller board |
| Tinkercad Circuits | Circuit simulation |
| Arduino C++ | Programming language |
| Visual Studio Code | Code editing and documentation |

---

## 10. Main Learning Outcome

This project helped me move from using Arduino's simplified functions to understanding how microcontroller pins are controlled at register level.

It was an introduction to low-level embedded programming and the relationship between software instructions and hardware behavior.
