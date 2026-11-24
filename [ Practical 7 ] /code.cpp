## 7. Source Code (`led_pushbutton.ino`)

```cpp
// Practical 07: Digital I/O Control using Push-Button and LED

const int buttonPin = 2;   // Push-button connected to Digital Pin 2
const int ledPin = 13;     // LED connected to Digital Pin 13
int buttonState = 0;       // Variable to store push-button logic state

void setup() {
  pinMode(ledPin, OUTPUT);      // Configure Pin 13 as digital output
  pinMode(buttonPin, INPUT);    // Configure Pin 2 as digital input
  Serial.begin(9600);           // Initialize Serial Monitor at 9600 baud
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read HIGH (1) or LOW (0)

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);         // Turn LED ON
    Serial.println("Button Pressed -> LED ON");
  } else {
    digitalWrite(ledPin, LOW);          // Turn LED OFF
    Serial.println("Button Released -> LED OFF");
  }

  delay(100); // Short delay for serial readability
}
