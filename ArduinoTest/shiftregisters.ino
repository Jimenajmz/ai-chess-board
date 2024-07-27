#include <FastLED.h>
#include <ShiftIn.h>

#define LED_PIN 7
#define NUM_LEDS 4
CRGB leds[NUM_LEDS];

// Init ShiftIn instance with one chip.
ShiftIn<1> shift;

void setup() {
  Serial.begin(9600);
  // declare pins: pLoadPin, clockEnablePin, dataPin, clockPin
  shift.begin(8, 9, 11, 12);
  FastLED.addLeds<WS2812,LED_PIN,GRB>(leds, NUM_LEDS);
}

uint8_t* displayValues() {
  static uint8_t values[NUM_LEDS];
  for(int i = 0; i < NUM_LEDS; i++) {
    values[i] = shift.state(i); // get state of button i
    Serial.print(values[i]);
  }
  Serial.println();
  return values;
}

void visualizeValues(uint8_t* values) {
  for(int i = 0; i < NUM_LEDS; i++) {
    if (values[i] == 1) {
      leds[i] = CRGB::Green; // LED on
    } else {
      leds[i] = CRGB::Black; // LED off
    }
  }
  FastLED.show();
}

void loop() {
  if(shift.update()) { // read in all values. returns true if any button has changed
    uint8_t* values = displayValues();
    visualizeValues(values);
  }
  delay(1);
}
