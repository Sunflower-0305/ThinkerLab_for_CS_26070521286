// Value-Added Experiment 03: Smart Temperature Monitoring and Alert System

#include <LiquidCrystal.h>

// Initialize 16x2 LCD in 4-bit mode: LiquidCrystal(RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempPin = A0;          // TMP36 analog output connected to A0
const int buzzerPin = 8;         // Piezo buzzer connected to Digital Pin 8
const int greenLedPin = 6;       // Normal status LED
const int redLedPin = 7;         // Over-temperature alert LED

const float tempThreshold = 35.0; // Predefined alert threshold in °C

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  lcd.begin(16, 2);              // Initialize 16 columns x 2 rows LCD
  lcd.print("Temp Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(1500);
  lcd.clear();

  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(tempPin);
  float voltage = adcValue * (5.0 / 1024.0);
  float temperatureC = (voltage - 0.5) * 100.0; // TMP36 formula (°C)

  // Display live temperature on Row 0 of LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC, 1);
  lcd.print((char)223); // Degree symbol (°)
  lcd.print("C    ");

  // Check against predefined threshold
  lcd.setCursor(0, 1);
  if (temperatureC > tempThreshold) {
    lcd.print("ALERT: HIGH TEMP");
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    tone(buzzerPin, 1000);       // Activate 1 kHz audible alarm
  } else {
    lcd.print("Status: NORMAL  ");
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    noTone(buzzerPin);           // Silence buzzer
  }

  // Serial telemetry output
  Serial.print("ADC: ");
  Serial.print(adcValue);
  Serial.print(" | Temp: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  delay(500);
}
