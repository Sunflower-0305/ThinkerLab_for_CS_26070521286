# Practical 08 [B]: Potentiometer Interfacing with LED

**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  

---

## 1. Aim
To interface a **potentiometer** with the Arduino Uno R3 analog input (`A0`) and dynamically vary the blink rate of an external LED connected to digital pin `13`.

---

## 2. Theory
A **potentiometer** is a three-terminal variable resistor wired as a voltage divider between `5V` and `GND`. Rotating the knob changes the wiper voltage continuously from $0\,\text{V}$ to $5\,\text{V}$, which the Arduino Uno's 10-bit ADC converts to an integer `sensorValue` from `0` to `1023`. Using `sensorValue` directly in `delay(sensorValue)` varies the LED ON/OFF interval between $0\,\text{ms}$ and $1023\,\text{ms}$.

---

## 3. Required Components
1. **Arduino Uno R3** with USB cable
2. **Breadboard & Jumper Wires**
3. **Potentiometer (`RPOT1`)**
4. **Red LED (`D1`)**
5. **$1\,\text{k}\Omega$ Current-Limiting Resistor (`R1`)**

---

## 4. Circuit Connections

| Component | Terminal / Pin | Connected To | Purpose |
| :--- | :--- | :--- | :--- |
| **Potentiometer** | Terminal 1 | `5V` (Breadboard `+` rail) | Upper reference voltage |
| **Potentiometer** | Wiper (Middle) | `A0` | Variable analog voltage input |
| **Potentiometer** | Terminal 2 | `GND` (Breadboard `-` rail) | Ground reference |
| **Red LED** | Anode (`+`) | `Digital Pin 13` | Digital output drive |
| **Red LED** | Cathode (`-`) | `GND` (via $1\,\text{k}\Omega$ resistor) | Current-limited ground return |

### Circuit Diagram
![Potentiometer Circuit](./Potentiometer%20%5BB%5D%20Circuit.png)

---

## 5. Arduino Code
```cpp
int sensorPin = A0;
int ledPin = 13;
int sensorValue;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);

  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
}
```

---

## 6. Files in This Folder
- [`Potentiometer [B] Circuit.png`](./Potentiometer%20%5BB%5D%20Circuit.png) — Tinkercad breadboard circuit diagram.
- [`Potentiometer [B] Code.png`](./Potentiometer%20%5BB%5D%20Code.png) — Arduino sketch screenshot.
- [`Potentiometer [B].jpg`](./Potentiometer%20%5BB%5D.jpg) — Tinkercad schematic image.
- [`Potentiometer [B].pdf`](./Potentiometer%20%5BB%5D.pdf) — Tinkercad schematic PDF.
