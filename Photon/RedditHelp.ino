#include <FastLED.h>

/*  How many times per second should we update the
 *  colour of the LED?
 */
const int frameRate = 30;

/*  We use 5 known colours which are each expanded to
 *  16 colours in the palette. Palettes have a maximum
 *  of 256 colours but we calculate the size of our
 *  smaller palette.
 */
const int paletteSize = 5 * 16;

/*  We fill the palette with our 5 aurora colours. The
 *  sixth colour is a copy of the first which allows
 *  for smooth cyclic transitions.
 *  The remainder of the palette is zero-padded.
 */
const CRGBPalette16 auroraPalette(
  CRGB(20,232,30),
  CRGB(0,234,141),
  CRGB(1,126,213),
  CRGB(181,61,255),
  
  CRGB(141,0,196),
  CRGB(20,232,30),
  0,
  0,

  0,
  0,
  0,
  0,

  0,
  0,
  0,
  0
);

CRGB led;

void setup() {
  // attach our one NeoPixel LED to pin 9
  FastLED.addLeds<NEOPIXEL, 9>(&led, 1);

  // so we don't blind ourselves
  FastLED.setBrightness(63);
}


void loop() {
  static int index = 0;
  if (++index >= paletteSize) index = 0;
  
  led = ColorFromPalette(auroraPalette, index, 255, LINEARBLEND);
  
  FastLED.show();
  FastLED.delay(1000 / frameRate);
}
