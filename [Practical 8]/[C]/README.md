# Practical 08 [C]: 16×2 I2C LCD Display Interfacing

**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  

---

## 1. Aim
To interface a **16×2 LCD display** with the Arduino Uno R3 over the **I2C protocol** and display student name and roll number across both rows.

---

## 2. Theory
An **I2C (Inter-Integrated Circuit)** adapter backpack reduces the number of Arduino pins required to drive a 16×2 character LCD from 6+ parallel pins down to just **two communication lines** (`SDA` for serial data and `SCL` for serial clock), plus `VCC` and `GND`. Using the `LiquidCrystal_I2C` library at I2C address `32` (`0x20`), the Arduino initializes the display, enables the backlight, positions the cursor via `setCursor(col, row)`, and prints text.

---

## 3. Required Components
1. **Arduino Uno R3** with USB cable
2. **16×2 LCD Display (I2C Module)**
3. **Jumper Wires**

---

## 4. Circuit Connections

| LCD I2C Pin | Arduino Uno Pin | Purpose |
| :--- | :--- | :--- |
| **GND** | `GND` | Ground reference |
| **VCC** | `5V` | Power supply |
| **SDA** | `A4` | I2C Serial Data line |
| **SCL** | `A5` | I2C Serial Clock line |

### Circuit Diagram
![LCD Circuit](./LCD%20%5BC%5D%20Circuit.png)

---

## 5. Arduino Code
```cpp
#include <LiquidCrystal_I2C.h>

// Initialize the LCD display with I2C address 32 (0x20), 16 columns, and 2 rows
LiquidCrystal_I2C lcd_1(32, 16, 2);

void setup() {
  lcd_1.init();          // Turn on the LCD
  lcd_1.setCursor(0, 0); // Move cursor to top-left corner
  lcd_1.backlight();     // Turn on the background light
  lcd_1.display();       // Enable the screen display
}

void loop() {
  lcd_1.setCursor(0, 0);
  lcd_1.print("Manthan Dhale");
  delay(2000); // Wait for 2 seconds
  lcd_1.setCursor(0, 1);
  lcd_1.print("26070521286");
  delay(2000); // Wait for 2 seconds
  lcd_1.clear();
}
```

---

## 6. Files in This Folder
- [`LCD [C] Circuit.png`](./LCD%20%5BC%5D%20Circuit.png) — Tinkercad wiring diagram.
- [`LCD [C] Code.png`](./LCD%20%5BC%5D%20Code.png) — Arduino sketch screenshot.
- [`LCD [C].jpg`](./LCD%20%5BC%5D.jpg) — Tinkercad schematic image.
- [`LCD [C].pdf`](./LCD%20%5BC%5D.pdf) — Tinkercad schematic PDF.
