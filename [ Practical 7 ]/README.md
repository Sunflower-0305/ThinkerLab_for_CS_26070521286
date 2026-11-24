# Practical 07: Arduino Uno Architecture, IDE, Digital/Analog I/O & LED/Push-Button Interfacing

**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  

---

## 1. Aim
To study the hardware architecture of the Arduino Uno microcontroller board, understand the Arduino IDE workflow, examine digital and analog I/O pins, and analyze the behavior of basic electronic components through LED and push-button interfacing.

---

## 2. Theory

### 2.1 Arduino Uno Architecture (ATmega328P)
The **Arduino Uno R3** is an open-source microcontroller development board built around the **Microchip ATmega328P** 8-bit AVR microcontroller operating at $16\,\text{MHz}$ and $5\,\text{V}$ logic:
- **Memory Architecture:**
  - **Flash Memory ($32\,\text{KB}$):** Non-volatile program storage ($0.5\,\text{KB}$ reserved for the bootloader).
  - **SRAM ($2\,\text{KB}$):** Volatile runtime memory for variables and stack operations.
  - **EEPROM ($1\,\text{KB}$):** Non-volatile storage for persistent configuration values.
- **Power & Communication Subsystems:**
  - Accepts $7\text{V} - 12\text{V}$ DC via the barrel jack / `VIN` pin (regulated to $5\text{V}$ and $3.3\text{V}$ onboard) or $5\text{V}$ directly over USB.
  - An onboard **ATmega16U2** USB-to-Serial converter enables sketch uploading and serial debugging via UART (`TX` Pin 1 / `RX` Pin 0).

### 2.2 Digital vs. Analog I/O Pins
- **Digital I/O Pins (`D0` – `D13`):** Operate at discrete binary logic levels—`LOW` ($0\,\text{V}$) or `HIGH` ($5\,\text{V}$)—configured via `pinMode(pin, INPUT | OUTPUT | INPUT_PULLUP)`. Six pins (`D3, D5, D6, D9, D10, D11`, marked with `~`) support **PWM (Pulse Width Modulation)** via `analogWrite(pin, 0–255)` to simulate variable output power.
- **Analog Input Pins (`A0` – `A5`):** Connected to an internal **10-bit Analog-to-Digital Converter (ADC)** that maps continuous input voltages from $0\,\text{V}$ to $5\,\text{V}$ into integer values between $0$ and $1023$ via `analogRead(pin)`.

### 2.3 Arduino IDE & Program Structure
Every Arduino C/C++ sketch relies on two mandatory functions:
- `void setup()`: Executes **once** on power-up or reset to initialize pin modes and serial communication (`Serial.begin(9600)`).
- `void loop()`: Executes **repeatedly** in an infinite cycle to read inputs, evaluate control logic, and update outputs.

### 2.4 LED & Push-Button Interfacing Principles
- **LED (Light Emitting Diode):** A polarized semiconductor diode (longer leg = Anode `+`, shorter leg = Cathode `-`). A series current-limiting resistor ($220\,\Omega$ to $330\,\Omega$) prevents excessive current from damaging the LED or microcontroller pin ($I = \frac{5\text{V} - 2\text{V}}{220\,\Omega} \approx 13.6\,\text{mA}$).
- **Push-Button & Pull-Down Resistor:** A tactile switch bridges two terminals when pressed. Connecting a $10\,\text{k}\Omega$ **pull-down resistor** between the input pin and `GND` prevents a "floating" input state (random noise) when the button is unpressed, ensuring a clean `LOW` ($0\,\text{V}$) until pressed (`HIGH`, $5\,\text{V}$).

---

## 3. Required Components
1. **Arduino Uno R3 Board** with USB Cable
2. **Breadboard & Jumper Wires**
3. **5mm LED** (Red/Green)
4. **Tactile Push-Button Switch**
5. **$220\,\Omega$ Resistor** (LED current limiter) & **$10\,\text{k}\Omega$ Resistor** (Pull-down resistor for push-button)

---

## 4. Circuit Connections

| Component | Terminal / Pin | Connected To | Purpose |
| :--- | :--- | :--- | :--- |
| **LED** | Anode (`+`, long leg) | `Digital Pin 13` (via $220\,\Omega$ resistor) | Digital output drive signal |
| **LED** | Cathode (`-`, short leg) | `GND` | Ground return path |
| **Push-Button** | Terminal 1 | `5V` | Logic `HIGH` supply when pressed |
| **Push-Button** | Terminal 2 | `Digital Pin 2` & $10\,\text{k}\Omega$ resistor to `GND` | Digital input signal with pull-down reference |

---

## 5. Steps for Implementation
1. Open **Tinkercad Circuits** (or set up a physical breadboard) and place the **Arduino Uno**, **LED**, **push-button**, **$220\,\Omega$ resistor**, and **$10\,\text{k}\Omega$ resistor**.
2. Connect the LED anode to **Digital Pin 13** through the $220\,\Omega$ resistor and connect the cathode to **GND**.
3. Wire one side of the push-button to **5V**, and wire the opposite side to **Digital Pin 2** while connecting the $10\,\text{k}\Omega$ pull-down resistor from **Digital Pin 2** to **GND**.
4. Open the **Arduino IDE** (or Tinkercad Code Editor), enter the sketch below, verify compilation, and upload/start the simulation.
5. Press and release the push-button while observing the LED state and the **Serial Monitor** (`9600 baud`).

---

## 6. Files in This Folder
- [`led_pushbutton.ino`](./led_pushbutton.ino) — Arduino C++ sketch for push-button controlled LED switching.
- [`circuit_diagram.png`](./circuit_diagram.png) — Tinkercad wiring and simulation screenshot *(upload your screenshot with this filename)*.

--
