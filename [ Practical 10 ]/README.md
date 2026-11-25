# Practical 10: Automatic Plant Irrigation System using Arduino, Soil Moisture Sensor & Relay Module


**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  


---


## 1. Aim
To design, implement, debug, and evaluate the performance of an Automatic Plant Irrigation System using an Arduino Uno, a soil moisture sensor, and a 5V relay module to automate water pump control based on soil moisture levels.


---


## 2. Theory


### 2.1 Soil Moisture Sensor Principle
A resistive/capacitive **Soil Moisture Sensor** estimates volumetric water content in soil by measuring electrical conductivity (or dielectric permittivity) between its two probes:
**Dry Soil:** Air gaps between soil particles create high electrical resistance, resulting in a **high analog voltage** and **high 10-bit ADC reading** (typically 650 – 1023).
**Wet / Moist Soil:** Water conducts electricity easily between the probes, lowering resistance and producing a **low analog voltage** and **low ADC reading** (typically 200 – 450).
### 2.2 5V Electromechanical Relay Module (Load Isolation)
An Arduino digital pin can safely source only $\approx 20\,\text{mA}$ at $5\text{V}$—far too little to drive a DC water pump directly. A **5V Single-Channel Relay Module** acts as an electrically isolated electromechanical switch:
**Control Side:** The Arduino sends a low-current logic signal to the relay's IN pin to energize an internal electromagnetic coil.
**Load Side (COM, NO, NC):** The magnetic field mechanically closes the **Normally Open (NO)** and **Common (COM)** contacts, completing the external $5\text{V} - 12\text{V}$ power circuit for the DC water pump while isolating the microcontroller from inductive voltage spikes.
**Active-LOW Trigger Logic:** Most commercial 5V relay boards are **Active-LOW** (digitalWrite(relayPin, LOW) turns the pump **ON**, and digitalWrite(relayPin, HIGH) turns the pump **OFF**).
### 2.3 Hysteresis Control & Debugging
To prevent rapid relay "chattering" (rapidly clicking ON/OFF when moisture hovers right on a single threshold), a **dual-threshold hysteresis band** is used:
Turn pump **ON** when soil becomes dry (moistureADC > 650).
Keep pumping until soil is thoroughly watered (moistureADC < 450), then turn pump **OFF**.
---


## 3. Required Components
1. **Arduino Uno R3 Board** with USB Cable
2. **Soil Moisture Sensor Module** (with probe & comparator/amplifier board)
3. **5V Single-Channel Relay Module**
4. **Mini DC Water Pump** (or DC Motor + LED indicator in Tinkercad simulation)
5. **External Power Supply / Battery Pack** (for the water pump load circuit)
6. **Breadboard & Jumper Wires**


---


## 4. Circuit Connections


| Component | Pin / Terminal | Connected To | Purpose |
| :--- | :--- | :--- | :--- |
| **Soil Moisture Sensor** | VCC | Arduino 5V | Sensor power supply |
| **Soil Moisture Sensor** | GND | Arduino GND | Common ground reference |
| **Soil Moisture Sensor** | A0 (Analog Out) | Arduino Analog Pin A0 | Continuous soil moisture voltage signal |
| **5V Relay Module** | VCC / GND | Arduino 5V / GND | Relay coil power |
| **5V Relay Module** | IN | Arduino Digital Pin 7 | Control signal from microcontroller |
| **DC Water Pump** | Positive (+) | Battery + via Relay COM & NO | Switched high-current pump supply |
| **DC Water Pump** | Negative (-) | Battery - (Ground) | Pump return path |


---


## 5. Steps for Implementation
1. Wire the soil moisture sensor's VCC to Arduino 5V, GND to GND, and analog output A0 to Arduino Analog Pin A0.
2. Connect the 5V relay module's VCC and GND to Arduino 5V and GND, and connect its signal pin IN to Arduino Digital Pin 7.
3. Wire the DC water pump in series with the external battery supply through the relay's COM and NO (Normally Open) terminals.
4. Open the Arduino IDE (or Tinkercad Code Editor), upload the sketch below, and open the **Serial Monitor** at 9600 baud.
5. **Debugging & Performance Evaluation:** Test the probes in dry air/soil, damp soil, and water while monitoring Serial ADC readings, relay LED status, and pump response time.


---


## 6. Files in This Folder
[automatic_irrigation.ino](./automatic_irrigation.ino) — Arduino C++ sketch with hysteresis threshold control and serial telemetry.
[circuit_diagram.png](./circuit_diagram.png) — Tinkercad/hardware circuit wiring and simulation screenshot (upload your screenshot with this filename).
---


## 7. Source Code (automatic_irrigation.ino)


cpp
// Practical 10: Automatic Plant Irrigation System using Arduino, Soil Moisture Sensor & Relay


const int moisturePin = A0;     // Soil moisture sensor analog output on A0
const int relayPin = 7;         // 5V Relay IN pin connected to Digital Pin 7


// Calibrated hysteresis thresholds (0 = saturated wet, 1023 = completely dry)
const int dryThreshold = 650;   // Turn pump ON above this reading
const int wetThreshold = 450;   // Turn pump OFF below this reading


bool pumpState = false;


void setup() {
  pinMode(moisturePin, INPUT);
  pinMode(relayPin, OUTPUT);


  // Initialize Active-LOW relay to OFF state (HIGH = OFF)
  digitalWrite(relayPin, HIGH);


  Serial.begin(9600);
  Serial.println("Automatic Plant Irrigation System Initialized...");
}


void loop() {
  int moistureADC = analogRead(moisturePin);
  int moisturePercent = map(moistureADC, 1023, 0, 0, 100); // Convert to 0-100% scale


  // Hysteresis control logic to prevent relay chattering
  if (moistureADC > dryThreshold && !pumpState) {
    digitalWrite(relayPin, LOW);   // Energize Active-LOW relay -> Pump ON
    pumpState = true;
  } else if (moistureADC < wetThreshold && pumpState) {
    digitalWrite(relayPin, HIGH);  // De-energize relay -> Pump OFF
    pumpState = false;
  }


  // Serial Monitor Debugging & Telemetry Output
  Serial.print("ADC: ");
  Serial.print(moistureADC);
  Serial.print(" | Moisture: ");
  Serial.print(moisturePercent);
  Serial.print("% | Pump: ");
  Serial.println(pumpState ? "ON (Watering)" : "OFF (Standby)");


  delay(500);
}
