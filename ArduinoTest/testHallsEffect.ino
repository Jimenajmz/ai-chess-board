//Sets pin 13 to the same value as pin 7, declared as an input.
#include <FastLED.h>

#define LED_PIN 8
#define NUM_LEDS 4

#define ROWONE_NUM 4

CRGB leds[NUM_LEDS];



int ledPin = 13;  // LED connected to digital pin 13
int index0 = 2;
int index1 = 3;
int index2 = 4;
int index3 = 5;
int val = 0;      // variable to store the read value
int rowone[ROWONE_NUM];

void setup() {
  pinMode(ledPin, OUTPUT);  // sets the digital pin 13 as output
  pinMode(index0, INPUT);    // sets the digital pin 7 as input
  pinMode(index1, INPUT);    // sets the digital pin 7 as input
  pinMode(index2, INPUT);    // sets the digital pin 7 as input
  pinMode(index3, INPUT);    // sets the digital pin 7 as input
  
  Serial.begin(9600);   // initialize serial interface
  FastLED.addLeds<WS2812,LED_PIN,GRB>(leds, NUM_LEDS);
  
}

void loop() {
  rowone[0] = digitalRead(index0);   // read the input pin
  rowone[1] = digitalRead(index1);
  rowone[2] = digitalRead(index2);
  rowone[3] = digitalRead(index3);
  
  for (byte i = 0; i <= 3; i = i + 1) {
  Serial.print(rowone[i]);
  }
  
  Serial.println();

 for(int i = 0; i <= 3; i++) {
  if(rowone[i] == 0) {
    leds[i] = CRGB(0,0,255);
    FastLED.show();
  } else if(rowone[i] == 1) {
    leds[i] = CRGB(255,0,0);
    FastLED.show();
  }
 }
//
// for(int i = 0; i <= 6; i++) {
//  leds[i] = CRGB(255,0,0);
//  FastLED.show();
//  delay(40);
// }
 
}
