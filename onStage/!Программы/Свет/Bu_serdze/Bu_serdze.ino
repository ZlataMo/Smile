#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 64

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 10
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];
int myTimer = millis();

void setup() {
  myTimer = millis();
  // Uncomment/edit one of the following lines for your leds arrangement.
  // ## Clockless types ##
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
  // FastLED.addLeds<SM16703, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1829, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1812, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS1904, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS2903, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  // FastLED.addLeds<WS2852, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  // FastLED.addLeds<GS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SK6812, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  // FastLED.addLeds<SK6822, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<APA106, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<PL9823, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SK6822, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2813, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2811_400, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<GE8822, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<LPD1886, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<LPD1886_8BIT, DATA_PIN, RGB>(leds, NUM_LEDS);
  // ## Clocked (SPI) types ##
  // FastLED.addLeds<LPD6803, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2803, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
  // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
  // FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
  // FastLED.addLeds<SK9822, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
}

void loop() {
  // Turn the LED on, then pause
  int i;
  FastLED.show();
  for ( int i = 0; i < 64; i = i + 1)
  {
    if ( (millis() - myTimer) % 2000 < 1000)
    {
      if ((i == 1 || i == 2 || i == 3 || i == 8 || i == 9 || i == 10 || i == 11 || i == 12 || i == 16 || i == 17 || i == 18 || i == 19 || i == 20 || i == 21 || i == 25 || i == 26 || i == 27 || i == 28 || i == 29 || i == 30 || i == 33 || i == 34 || i == 35 || i == 36 || i == 37 || i == 38 || i == 40 || i == 41 || i == 42 || i == 43 || i == 44 || i == 45 || i == 48 || i == 49 || i == 50 || i == 51 || i == 52 || i == 57 || i == 58 || i == 59) ) {
        leds[i] = 0x400000;
        
      }
      //myTimer = millis();
    }
    else {
      if ((i == 1 || i == 2 || i == 3 || i == 8 || i == 9 || i == 10 || i == 11 || i == 12 || i == 16 || i == 17 || i == 18 || i == 19 || i == 20 || i == 21 || i == 25 || i == 26 || i == 27 || i == 28 || i == 29 || i == 30 || i == 33 || i == 34 || i == 35 || i == 36 || i == 37 || i == 38 || i == 40 || i == 41 || i == 42 || i == 43 || i == 44 || i == 45 || i == 48 || i == 49 || i == 50 || i == 51 || i == 52 || i == 57 || i == 58 || i == 59) ) {
        leds[i] = 0x100000;
      }

    }
  }
}
