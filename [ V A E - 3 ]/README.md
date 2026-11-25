# Value-Added Experiment 03: Smart Temperature Monitoring and Alert System

**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  

---

## 1. Aim
To design and implement a Smart Temperature Monitoring and Alert System using an Arduino Uno, an analog temperature sensor (TMP36 / LM35), a 16×2 LCD display, and a piezo buzzer that continuously displays ambient temperature and triggers visual and audible alerts when the temperature exceeds a predefined safety threshold.

---

## 2. Theory

### 2.1 Analog Temperature Sensing (TMP36 / LM35)
Analog temperature sensors convert thermal energy into a linearly proportional DC output voltage:
- **TMP36 Sensor:** Outputs $750\,\text{mV}$ at $25^\circ\text{C}$ with a scale factor of $10\,\text{mV}/^\circ\text{C}$ and a $500\,\text{mV}$ offset (allowing sub-zero readings without a negative supply).
- **ADC-to-Temperature Conversion:** The Arduino Uno's 10-bit ADC converts the $0\text{V} - 5\text{V}$ signal on Analog Pin `A0` into an integer (`0` to `1023`):
  $$V_{\text{out}} = \text{ADC} \times \frac{5.0}{1024.0}$$
  $$\text{Temperature } (^\circ\text{C}) = (V_{\text{out}} - 0.5) \times 100$$
  *(Note: For an LM35 sensor without offset, $\text{Temperature } (^\circ\text{C}) = V_{\text{out}} \times 100$.)*

### 2.2 16×2 Character LCD Interfacing (`LiquidCrystal`)
A **16×2 LCD** displays 2 rows of 16 ASCII characters each. Operated in **4-bit parallel mode** using Arduino's `LiquidCrystal` library (`D4`–`D7`, `RS`, and `EN`), it reduces pin usage while providing real-time local telemetry (live temperature in $^\circ\text{C}$ and system status) without requiring a connected computer. A $10\,\text{k}\Omega$ potentiometer connected to `V0` adjusts display contrast.

### 2.3 Threshold-Based Audible & Visual Alerting
- **Piezo Buzzer (`tone()`):** Driven by a PWM/digital pin, generating an audible acoustic warning frequency (e.g., $1000\,\text{Hz}$) whenever $\text{Temperature} > T_{\text{threshold}}$ (set to $35^\circ\text{C}$).
- **Status LEDs:** A green LED indicates normal operating temperature, while a red LED illuminates alongside the buzzer during an over-temperature condition.

---

## 3. Required Components
1. **Arduino Uno R3 Board** with USB Cable
2. **TMP36 Analog Temperature Sensor** (or LM35)
3. **16×2 Alphanumeric LCD Display**
4. **$10\,\text{k}\Omega$ Potentiometer** (LCD contrast control) & **$220\,\Omega$ Resistors** (LCD backlight & LED current limiters)
5. **Piezo Buzzer**
6. **Red & Green 5mm LEDs** (visual status indicators)
7. **Breadboard & Jumper Wires**

---

## 4. Circuit Connections

| Component | Pin / Terminal | Connected To | Purpose |
| :--- | :--- | :--- | :--- |
| **TMP36 Sensor** | `VCC` (Pin 1) / `GND` (Pin 3) | Arduino `5V` / `GND` | Sensor power supply |
| **TMP36 Sensor** | `VOUT` (Pin 2) | Arduino `Analog Pin A0` | Analog temperature voltage output |
| **16×2 LCD** | `VSS`, `RW`, `K` | `GND` | Ground, write mode, & backlight cathode |
| **16×2 LCD** | `VDD`, `A` (via $220\,\Omega$) | `5V` | LCD logic power & backlight anode |
| **16×2 LCD** | `V0` | $10\,\text{k}\Omega$ Potentiometer Wiper | Display contrast adjustment |
| **16×2 LCD** | `RS`, `EN` | `Digital Pin 12`, `Digital Pin 11` | Register select & enable control |
| **16×2 LCD** | `D4`, `D5`, `D6`, `D7` | `Pins 5, 4, 3, 2` | 4-bit parallel data bus |
| **Piezo Buzzer** | Positive (`+`) / Negative (`-`) | `Digital Pin 8` / `GND` | Audible over-temperature alarm |
| **Green / Red LEDs** | Anode (`+`) via $220\,\Omega$ / Cathode (`-`) | `Pin 6` (Green), `Pin 7` (Red) / `GND` | Normal vs. Alert visual indicators |

---

## 5. Steps for Implementation
1. Place the 16×2 LCD, TMP36 temperature sensor, piezo buzzer, potentiometer, and LEDs onto the breadboard in **Tinkercad Circuits** (or on hardware).
2. Wire the LCD power rails, $10\,\text{k}\Omega$ contrast potentiometer, and 4-bit data/control lines (`Pins 12, 11, 5, 4, 3, 2`) to the Arduino Uno.
3. Connect the TMP36 output pin (`VOUT`) to **Analog Pin A0**, the piezo buzzer to **Digital Pin 8**, the green status LED to **Pin 6**, and the red alert LED to **Pin 7**.
4. Open the Arduino IDE (or Tinkercad Code Editor), enter the sketch below, verify compilation, and start the simulation.
5. Vary the temperature slider on the TMP36 sensor across room temperature ($20^\circ\text{C} - 30^\circ\text{C}$) and high-temperature zones ($> 35^\circ\text{C}$) while observing the LCD readout, Serial Monitor, LEDs, and buzzer.

---

## 6. Files in This Folder
- [`temp_monitoring_alert.ino`](./temp_monitoring_alert.ino) — Arduino C++ sketch for TMP36 temperature calculation, 16×2 LCD output, and buzzer alert logic.
- [`schematic.pdf`](./schematic.pdf) — Tinkercad schematic export *(upload if exported)*.
- [`circuit_diagram.png`](./circuit_diagram.png) — Tinkercad breadboard wiring and simulation screenshot *(upload your screenshot with this filename)*.

---

## 7. Source Code (`temp_monitoring_alert.ino`)

```cpp
