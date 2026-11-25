# Value-Added Experiment 04: Smart Street Light System using Arduino and LDR (Sensor Calibration & Troubleshooting)

**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  

---

## 1. Aim
To design and implement an automatic Smart Street Light controller using an Arduino Uno and a Light Dependent Resistor (LDR) that switches LEDs ON/OFF based on ambient light intensity, while systematically calibrating ADC thresholds and troubleshooting sensor calibration issues.

---

## 2. Theory

### 2.1 Ambient Light Sensing & Voltage Divider Response
An **LDR (Photoresistor)** exhibits a non-linear inverse relationship between incident illuminance (measured in lux) and electrical resistance:
- **Bright Ambient Light:** $R_{\text{LDR}}$ drops to a few hundred ohms, raising the voltage at the voltage divider junction (`A0`).
- **Low Ambient Light / Darkness:** $R_{\text{LDR}}$ rises above $100\,\text{k}\Omega$, pulling the junction voltage toward `GND` via the $10\,\text{k}\Omega$ series pull-down resistor:
  $$V_{\text{A0}} = 5\text{V} \times \frac{R_{\text{fixed}}}{R_{\text{LDR}} + R_{\text{fixed}}}$$

### 2.2 Sensor Calibration & Hysteresis Thresholding
Unlike a basic fixed-cutoff circuit, real-world ambient lighting fluctuates due to cloud cover, indoor shadows, or passing headlights. **Sensor calibration** addresses two key challenges:
1. **Series Resistor Matching:** Selecting a $10\,\text{k}\Omega$ pull-down resistor maximizes voltage swing across the twilight transition zone (`300 – 500` on the 10-bit ADC scale).
2. **Hysteresis Deadband (`300` vs. `500`):** Using separate turn-ON (`ADC < 300`, dark) and turn-OFF (`ADC > 500`, daylight) thresholds prevents rapid LED flickering ("chattering") during dusk or dawn transitions, while `300 <= ADC <= 500` maintains a stable twilight hold state.

### 2.3 Common LDR Calibration Issues & Troubleshooting
- **Inverted Switching Logic:** Swapping the LDR and $10\,\text{k}\Omega$ resistor positions reverses the voltage divider polarity (high ADC in dark, low ADC in light).
- **Ambient Interference / Self-Illumination:** Light from the street light LED reflecting back onto the LDR causes continuous oscillation; resolved via physical shielding and hysteresis margins.
- **Analog Noise / Jitter:** Averaging multiple consecutive `analogRead(A0)` samples smooths transient sensor spikes.

---

## 3. Required Components
1. **Arduino Uno R3 Board** with USB Cable
2. **LDR (Photoresistor)**
3. **Street Light LED(s)** (5mm Red/White)
4. **$10\,\text{k}\Omega$ Resistor** (calibrated voltage divider pull-down)
5. **$330\,\Omega$ Resistor** (LED current limiter)
6. **Breadboard & Jumper Wires**

---

## 4. Circuit Connections

| Component | Terminal / Pin | Connected To | Purpose |
| :--- | :--- | :--- | :--- |
| **LDR** | Terminal 1 | Arduino `5V` | Supply rail for light-dependent divider |
| **LDR** | Terminal 2 | `Analog Pin A0` (Divider Junction) | Analog light intensity signal |
| **$10\,\text{k}\Omega$ Resistor** | End 1 / End 2 | `Analog Pin A0` / `GND` | Calibrated pull-down reference resistor |
| **Street Light LED** | Anode (`+`) | `Digital Pin 10` (via $330\,\Omega$ resistor) | Automated street light output control |
| **Street Light LED** | Cathode (`-`) | `GND` | Common ground return path |

---

## 5. Steps for Implementation
1. Assemble the LDR and $10\,\text{k}\Omega$ resistor as a voltage divider between **5V** and **GND**, connecting their junction to **Analog Pin A0**.
2. Connect the street light LED anode to **Digital Pin 10** through a $330\,\Omega$ resistor and connect its cathode to **GND**.
3. Upload the calibration sketch below, which averages 10 ADC samples per cycle and logs raw ADC values, calibrated lighting states (`DAYLIGHT`, `TWILIGHT_HOLD`, `NIGHT_DARK`), and LED status to the **Serial Monitor** (`9600 baud`).
4. Sweep the ambient light intensity from full brightness to complete darkness while recording ADC readings at each transition point.
5. **Troubleshoot & Validate Calibration:** Verify that intermediate twilight readings (`300 – 500`) do not cause LED flickering and confirm clean switching across full day/night cycles.

---

## 6. Files in This Folder
- [`ldr_calibrated_streetlight.ino`](./ldr_calibrated_streetlight.ino) — Arduino C++ sketch with multi-sample smoothing, hysteresis calibration, and serial diagnostics.
- [`schematic.pdf`](./schematic.pdf) — Tinkercad schematic export *(upload if exported)*.
- [`circuit_diagram.png`](./circuit_diagram.png) — Tinkercad breadboard wiring and calibration simulation screenshot *(upload your screenshot with this filename)*.

---

## 7. Source Code (`ldr_calibrated_streetlight.ino`)

```cpp
