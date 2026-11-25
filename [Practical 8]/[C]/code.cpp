#include <LiquidCrystal_I2C.h>

// Initialize the LCD display with I2C address 32 (0x20), 16 columns, and 2 rows
LiquidCrystal_I2C lcd_1(32, 16, 2);

void setup()
{
  lcd_1.init();          // Turn on the LCD
  lcd_1.setCursor(0, 0); // Move cursor to top-left corner
  lcd_1.backlight();     // Turn on the background light
  lcd_1.display();       // Enable the screen display
}

void loop()
{
  lcd_1.setCursor(0, 0);
  lcd_1.print("Manthan Dhale");
  delay(2000); // Wait for 2 seconds
  lcd_1.setCursor(0, 1);
  lcd_1.print("26070521286");
  delay(2000); // Wait for 2 seconds
  lcd_1.clear();
}
