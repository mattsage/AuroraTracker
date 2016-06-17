/*
Reddit Post: https://www.reddit.com/r/arduino/comments/4bmjc9/aurora_effect_neopixel_help/
Photon Help: https://community.particle.io/t/help-error-when-compiling-code-works-with-arduino-ide-and-codebender/22030/3
*/

#include "FastLED/FastLED.h"

/*#include <FastLED.h>
^^Above is for Arduino/Codebender^^ */

/*  How many times per second should we update the
 *  colour of the LED? http://pastebin.com/1wLEJyB9
 */
int pinled = D7; 

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
using namespace NSFastLED; //Added for Particle Photon build due to FastLED in the community libraries includes a C++ namespace
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
  FastLED.addLeds<NEOPIXEL, 6>(&led, 1); // attach our one NeoPixel LED to pin 6
  Spark.function("tweet", twittermessage);
  //particle.function("tweet", twittermessage);
  pinMode(pinled, OUTPUT); // Set up onboard LED as a "pre" notification
  //FastLED.setBrightness(63); // so we don't blind ourselves


}



//Standard Loop turn CRGB LED off (Black)
void loop() {
        led = CRGB::Black; 
        FastLED.show(); 
        delay(30); 
} 



 
// this function automagically gets called upon a tweet mention
int twittermessage(String ignore)
{
    digitalWrite(pinled, HIGH); // Turn on On-board LED as "pre-notification"
    delay(1800000); //Wait 30 mins (1800000 Milliseconds) as @auroraalerts predicts ~50 mins before events )
    digitalWrite(pinled, LOW); // Turn off On-board LED
    //Turn on Neopixel
    while(1){
    static int index = 0;
    if (++index >= paletteSize) index = 0;
  
    led = ColorFromPalette(auroraPalette, index, 255, LINEARBLEND); //Changed BLEND to LINEARBLEND
  
    FastLED.show();
    FastLED.delay(1000 / frameRate);
    }
}
