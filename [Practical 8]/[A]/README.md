# Practical 08 [A]: Temperature Sensor (TMP36) Interfacing

**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  

---

## 1. Aim
To interface an analog **TMP36 temperature sensor** with the Arduino Uno R3 and convert its analog output voltage into temperature readings in degrees Celsius.

---

## 2. Theory
The **TMP36** is a low-voltage, precision centigrade temperature sensor that outputs an analog voltage linearly proportional to the ambient temperature:
- **Scale Factor:** $10\,\text{mV}/^\circ\text{C}$
- **Offset Voltage:** $500\,\text{mV}$ ($0.5\,\text{V}$) at $0^\circ\text{C}$.
- **ADC-to-Temperature Conversion (10-bit ADC at $5\,\text{V}$ reference):**
  $$V_{\text{out}} = \frac{\text{analogRead}(A0) \times 5.0}{1024}$$
  $$T(^\circ\text{C}) = (V_{\text{out}} - 0.5) \times 100$$

---

## 3. Required Components
1. **Arduino Uno R3** with USB cable
2. **TMP36 Temperature Sensor**
3. **Jumper Wires**

---

## 4. Circuit Connections

| TMP36 Pin | Arduino Uno Pin | Purpose |
| :--- | :--- | :--- |
| **+VS (Power)** | `5V` | Supply voltage |
| **VOUT (Signal)** | `A0` | Analog temperature voltage input |
| **GND** | `GND` | Ground reference |

### Circuit Diagram
![Temperature Sensor Circuit](./Temperature%20Sensor%20%5BA%5D%20Circuit.png)

---

## 5. Reference Arduino Code
```cpp
const int tempPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int rawValue = analogRead(tempPin);
  float voltage = rawValue * (5.0 / 1024.0);
  float tempC = (voltage - 0.5) * 100.0;

  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");
  delay(1000);
}
```

---

## 6. Files in This Folder
- [`Temperature Sensor [A] Circuit.png`](./Temperature%20Sensor%20%5BA%5D%20Circuit.png) — Tinkercad wiring diagram.
- [`Temperature Sensor [A] Code.png`](./Temperature%20Sensor%20%5BA%5D%20Code.png) — Tinkercad code editor screenshot.
- [`Temperature Sensor [A].jpg`](./Temperature%20Sensor%20%5BA%5D.jpg) — Tinkercad schematic image.
- [`Temperature Sensor [A].pdf`](./Temperature%20Sensor%20%5BA%5D.pdf) — Tinkercad schematic PDF.
