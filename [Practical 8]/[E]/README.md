# Practical 08 [E]: Servo Motor Interfacing

**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  

---

## 1. Aim
To interface a **micro servo motor** with the Arduino Uno R3 and control its shaft position smoothly from $0^\circ$ to $180^\circ$ and back using the built-in `Servo` library.

---

## 2. Theory
A **servo motor** is a closed-loop rotary actuator consisting of a DC motor, gear train, position-sensing potentiometer, and internal control circuit. It interprets a $50\,\text{Hz}$ ($20\,\text{ms}$ period) **PWM control signal** where pulse widths typically between $1\,\text{ms}$ and $2\,\text{ms}$ map to angular positions from $0^\circ$ to $180^\circ$. The Arduino `Servo.h` library abstracts this timing via `attach(pin)` and `write(angle)`.

---

## 3. Required Components
1. **Arduino Uno R3** with USB cable
2. **Micro Servo Motor (`SERVO1`)**
3. **Jumper Wires**

---

## 4. Circuit Connections

| Servo Motor Pin | Arduino Uno Pin | Purpose |
| :--- | :--- | :--- |
| **PWR (Power)** | `5V` | Power supply |
| **GND (Ground)** | `GND` | Ground reference |
| **SIG (Signal)** | `Digital Pin 9 (~PWM)` | PWM angle control signal |

### Circuit Diagram
![Servo Motor Circuit](./Servo%20Motor%20%5BE%5D%20Circuit.png)

---

## 5. Arduino Code
```cpp
#include <Servo.h>

Servo myServo;
int pos = 0;

void setup() {
  myServo.attach(9); // Connect servo signal to digital pin 9
}

void loop() {
  // Move from 0 to 180 degrees
  for (pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);
    delay(15);
  }

  // Move back from 180 to 0 degrees
  for (pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos);
    delay(15);
  }
}
```

---

## 6. Files in This Folder
- [`Servo Motor [E] Circuit.png`](./Servo%20Motor%20%5BE%5D%20Circuit.png) — Tinkercad wiring diagram.
- [`Servo Motor [E] Code.png`](./Servo%20Motor%20%5BE%5D%20Code.png) — Arduino sketch screenshot.
- [`Servo Motor [E].jpg`](./Servo%20Motor%20%5BE%5D.jpg) — Tinkercad schematic image.
- [`Servo Motor [E].pdf`](./Servo%20Motor%20%5BE%5D.pdf) — Tinkercad schematic PDF.
