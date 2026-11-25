# Practical 08 [D]: DC Motor Interfacing with L293D Motor Driver

**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  

---

## 1. Aim
To interface a **DC motor** with the Arduino Uno R3 using an **L293D Dual H-Bridge Motor Driver IC** to safely supply motor current and control rotation direction.

---

## 2. Theory
Arduino Uno digital I/O pins can only source a small current (recommended max $20\,\text{mA}$ per pin), which is insufficient to drive an inductive DC motor directly and risks back-EMF damage. The **L293D** is a quadruple half-H driver IC that isolates the microcontroller logic from the motor load and allows bidirectional control:
- `1A = HIGH`, `2A = LOW` → Motor rotates **clockwise (forward)**
- `1A = LOW`, `2A = HIGH` → Motor rotates **counter-clockwise (reverse)**
- `1A = LOW`, `2A = LOW` (or both `HIGH`) → Motor **stops**

---

## 3. Required Components
1. **Arduino Uno R3** with USB cable
2. **L293D Motor Driver IC**
3. **DC Motor (`M1`)**
4. **Breadboard & Jumper Wires**

---

## 4. Circuit Connections

| L293D Pin | Connected To | Purpose |
| :--- | :--- | :--- |
| **1-2EN (Pin 1)** | `5V` | Enables Channel 1–2 output driver |
| **1A (Pin 2)** | `Digital Pin 3` | Direction / PWM control input 1 |
| **1Y (Pin 3)** | DC Motor Terminal 1 | Motor output 1 |
| **GND1 / GND2 (Pins 4, 5)** | `GND` | Common ground |
| **2Y (Pin 6)** | DC Motor Terminal 2 | Motor output 2 |
| **2A (Pin 7)** | `Digital Pin 4` | Direction control input 2 |
| **VCC2 (Pin 8) & VCC1 (Pin 16)** | `5V` | Motor & IC logic power supply |

### Circuit Diagram
![DC Motor Circuit](./DC%20Motor%20%5BD%5D%20Circuit.png)

---

## 5. Reference Arduino Code
```cpp
const int in1 = 3;
const int in2 = 4;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  // Rotate forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(2000);

  // Stop
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);

  // Rotate reverse
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(2000);

  // Stop
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);
}
```

---

## 6. Files in This Folder
- [`DC Motor [D] Circuit.png`](./DC%20Motor%20%5BD%5D%20Circuit.png) — Tinkercad breadboard wiring diagram.
- [`DC Motor [D] Code.png`](./DC%20Motor%20%5BD%5D%20Code.png) — Tinkercad code editor screenshot.
- [`DC Motor [D].jpg`](./DC%20Motor%20%5BD%5D.jpg) — Tinkercad schematic image.
- [`DC Motor [D].pdf`](./DC%20Motor%20%5BD%5D.pdf) — Tinkercad schematic PDF.
