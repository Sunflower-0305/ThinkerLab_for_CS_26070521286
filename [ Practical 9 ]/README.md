# Practical 09: Smart Street Light System using Arduino and LDR


**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  


---


## 1. Aim
To design and implement a Smart Street Light System using an Arduino Uno and a Light Dependent Resistor (LDR) sensor, including circuit testing and troubleshooting for automated day/night switching[span_0](start_span)[span_0](end_span).


---


## 2. Theory


### 2.1 Light Dependent Resistor (LDR)
An **LDR (Photoresistor)** is a passive semiconductor sensor whose electrical resistance varies inversely with incident light intensity:
- **High Light Intensity (Daylight):** Photons excite charge carriers, causing resistance to drop sharply (typically a few hundred ohms to a few kilo-ohms).
- **Low Light Intensity (Darkness / Night):** Fewer free carriers exist, causing resistance to rise significantly (up to mega-ohms).


### 2.2 Voltage Divider & 10-Bit ADC Conversion
Because the Arduino Uno measures voltage rather than resistance directly, the LDR is paired in series with a fixed $10\,\text{k}\Omega$ pull-down resistor (`R3`) to form a **voltage divider** between $5\text{V}$ and `GND`[span_1](start_span)[span_1](end_span)[span_2](start_span)[span_2](end_span):
$$V_{\text{out}} = V_{\text{CC}} \times \frac{R_{\text{fixed}}}{R_{\text{LDR}} + R_{\text{fixed}}}$$
- The midpoint junction connects to Analog Pin `A0`[span_3](start_span)[span_3](end_span)[span_4](start_span)[span_4](end_span).
- The Arduino's internal **10-bit Analog-to-Digital Converter (ADC)** converts the $0\text{V} - 5\text{V}$ analog voltage into a discrete integer (`0` to `1023`) via `analogRead(A0)`.
- Based on a calibrated light threshold, the microcontroller toggles Digital Pin `10` (`HIGH` or `LOW`) to control the street light LED automatically[span_5](start_span)[span_5](end_span)[span_6](start_span)[span_6](end_span).


### 2.3 Testing & Troubleshooting Methodology
- **Serial Telemetry Verification:** Printing live `analogRead(A0)` readings to the Serial Monitor (`9600 baud`) isolates hardware wiring faults (such as floating analog pins or swapped resistors) from software threshold errors[span_7](start_span)[span_7](end_span).
- **Current Limiting:** A $330\,\Omega$ resistor (`R2`) in series with the LED (`D1`) limits forward current to safe levels ($\approx 10\text{ mA}$)[span_8](start_span)[span_8](end_span)[span_9](start_span)[span_9](end_span).


---


## 3. Required Components
1. **Arduino Uno R3 Board** with USB Cable
2. **LDR (Photoresistor)**
3. **LED (Red/White)** acting as the street light
4. **$10\,\text{k}\Omega$ Resistor** (voltage divider pull-down)
5. **$330\,\Omega$ Resistor** (LED current limiter)
6. **Breadboard & Jumper Wires**[span_10](start_span)[span_10](end_span)[span_11](start_span)[span_11](end_span)


---


## 4. Circuit Connections


| Component | Terminal / Pin | Connected To | Purpose |
| :--- | :--- | :--- | :--- |
| **LDR** | Terminal 1 | `5V` | Supply voltage for light sensing |
| **LDR** | Terminal 2 | `Analog Pin A0` (Divider Junction) | Outputs light-dependent voltage |
| **$10\,\text{k}\Omega$ Resistor (`R3`)** | End 1 / End 2 | `Analog Pin A0` / `GND` | Completes voltage divider to ground |
| **LED (`D1`)** | Anode (`+`) | `Digital Pin 10` (via $330\,\Omega$ resistor `R2`) | Automated street light switching |
| **LED (`D1`)** | Cathode (`-`) | `GND` | Ground return path[span_12](start_span)[span_12](end_span)[span_13](start_span)[span_13](end_span) |


---


## 5. Steps for Implementation
1. Place the LDR and $10\,\text{k}\Omega$ resistor in series on the breadboard; connect the free end of the LDR to **5V**, the free end of the $10\,\text{k}\Omega$ resistor to **GND**, and their middle junction to **Analog Pin A0**[span_14](start_span)[span_14](end_span)[span_15](start_span)[span_15](end_span).
2. Connect the LED anode to **Digital Pin 10** via a $330\,\Omega$ current-limiting resistor and connect the LED cathode to **GND**[span_16](start_span)[span_16](end_span)[span_17](start_span)[span_17](end_span).
3. Open the Arduino IDE (or Tinkercad Code Editor), write the sketch to read `A0` and control Pin `10`, and initialize `Serial.begin(9600)` for debugging[span_18](start_span)[span_18](end_span).
4. Run the simulation/circuit and open the **Serial Monitor** to record raw ADC values under bright light and low-light/darkness conditions.
5. **Troubleshoot & Verify:** Confirm that covering the LDR drops the ADC reading below the darkness threshold and switches the LED `ON`, while exposing it to bright light switches the LED `OFF`.


---


## 6. Files in This Folder
- [`smart_street_light.ino`](./smart_street_light.ino) — Arduino C++ sketch for automated LDR street light control.
- [`schematic.pdf`](./schematic.pdf) — Tinkercad schematic export (`Practical 9 Smart street light.pdf`).
- [`circuit_diagram.png`](./circuit_diagram.png) — Tinkercad breadboard wiring and simulation screenshot.
