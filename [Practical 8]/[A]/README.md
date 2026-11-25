# Practical 08 [A]: Temperature Sensor (TMP36) Interfacing

**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  

---

## 1. Aim
To interface an analog **TMP36 temperature sensor** with the Arduino Uno R3 and convert its analog output voltage into temperature readings in degrees Celsius and Fahrenheit.

---

## 2. Theory
The **TMP36** is a low-voltage, precision centigrade temperature sensor that outputs an analog voltage linearly proportional to the ambient temperature:
- **Scale Factor:** $10\,\text{mV}/^\circ\text{C}$
- **Offset Voltage:** $500\,\text{mV}$ ($0.5\,\text{V}$) at $0^\circ\text{C}$.
- **ADC-to-Temperature Conversion (10-bit ADC at $5\,\text{V}$ reference):**
  $$V_{\text{out}} = \text{analogRead}(A0) \times \frac{5.0}{1023.0}$$
  $$T(^\circ\text{C}) = (V_{\text{out}} - 0.5) \times 100.0$$
  $$T(^\circ\text{F}) = \left(T(^\circ\text{C}) \times \frac{9.0}{5.0}\right) + 32.0$$

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
![Temperature Sensor Circuit](./%5BA%5D.png)

### Schematic Diagram
![Temperature Sensor Schematic](./Temperature%20Sensor%20%5BA%5D.jpg)

---

## 5. Arduino Code
```cpp
// Define the analog pin connected to the TMP36 sensor
const int sensorPin = A0;

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

void loop() {
  // Read the raw analog value from the sensor (0 to 1023)
  int rawValue = analogRead(sensorPin);

  // Convert the raw reading to voltage (0V - 5V)
  float voltage = rawValue * (5.0 / 1023.0);

  // Convert voltage to temperature in Celsius
  // TMP36 has a 500 mV offset and a 10 mV per degree C scale.
  float temperatureC = (voltage - 0.5) * 100.0;

  // Convert Celsius to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  // Print the results to the Serial Monitor
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print("V | Temp: ");
  Serial.print(temperatureC);
  Serial.print(" °C | ");
  Serial.print(temperatureF);
  Serial.println(" °F");

  // Wait 1 second before the next reading
  delay(1000);
}
```

---

## 6. Files in This Folder
- [`code.cpp`](./code.cpp) — Arduino C++ sketch for TMP36 temperature measurement in °C and °F.
- [`[A].png`](./%5BA%5D.png) — Tinkercad wiring diagram.
- [`Temperature Sensor [A].jpg`](./Temperature%20Sensor%20%5BA%5D.jpg) — Tinkercad schematic diagram.
- [`Temperature Sensor [A].pdf`](./Temperature%20Sensor%20%5BA%5D.pdf) — Tinkercad schematic PDF.
