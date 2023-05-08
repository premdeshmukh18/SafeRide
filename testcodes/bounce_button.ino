const int BUTTON_PIN = 2;
const int DEBOUNCE_DELAY_MS = 50;

bool buttonState = false;
bool lastButtonState = false;
unsigned long lastDebounceTime = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  // Read the button state
  bool reading = digitalRead(BUTTON_PIN);

  // Check if the button state has changed since last time
  if (reading != lastButtonState) {
    // Reset the debounce timer
    lastDebounceTime = millis();
  }

  // Check if the debounce delay has elapsed
  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY_MS) {
    // Update the button state if it has stabilized
    if (reading != buttonState) {
      buttonState = reading;

      // Print the new button state
      Serial.print("Button state: ");
      Serial.println(buttonState);
    }
  }

  // Save the current button state for the next loop iteration
  lastButtonState = reading;
}
