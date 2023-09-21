#include <FastLED.h>

#define NUM_LEDS 64
#define DATA_PIN 8

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
  FastLED.clear();
  FastLED.show();
  delay(1000);
  for (int i = 0; i < 64; i++) {
    leds[i] = 0x019772;
  }
  FastLED.show();
}

void loop()
{
}
