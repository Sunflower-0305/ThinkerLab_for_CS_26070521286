// Value-Added Experiment 04: Smart Street Light System with LDR Calibration & Hysteresis

const int ldrPin = A0;            // LDR voltage divider junction on Analog Pin A0
const int ledPin = 10;            // Street light LED on Digital Pin 10

// Calibrated Hysteresis Thresholds (0 - 1023 10-bit ADC scale)
const int nightOnThreshold = 300; // Switch LED ON when ADC drops below 300 (Dark)
const int dayOffThreshold  = 500; // Switch LED OFF when ADC rises above 500 (Bright)

bool streetLightOn = false;

// Function to read and average 10 ADC samples to filter analog noise
int readCalibratedLDR() {
  long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(ldrPin);
    delay(5);
  }
  return sum / 10;
}

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.begin(9600);
  Serial.println("=== Smart Street Light LDR Calibration Diagnostics ===");
}

void loop() {
  int avgADC = readCalibratedLDR();
  String ambientState;

  // Hysteresis Calibration Control Logic
  if (avgADC < nightOnThreshold) {
    streetLightOn = true;
    ambientState = "NIGHT / DARK";
  } else if (avgADC > dayOffThreshold) {
    streetLightOn = false;
    ambientState = "DAYLIGHT / BRIGHT";
  } else {
    ambientState = "TWILIGHT (HYSTERESIS HOLD)";
  }

  digitalWrite(ledPin, streetLightOn ? HIGH : LOW);

  // Serial Calibration Telemetry
  Serial.print("Avg ADC: ");
  Serial.print(avgADC);
  Serial.print(" | State: ");
  Serial.print(ambientState);
  Serial.print(" | Street Light: ");
  Serial.println(streetLightOn ? "ON" : "OFF");

  delay(250);
}
