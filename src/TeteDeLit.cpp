/**
 * @file TeteDeLit.cpp
 * @author d.macsddau
 * @copyright (c)2024, d.macsddau
 * @version 0.01
*/
#include <TeteDeLit.h>

///! Turn off the light
void setLightOff(   CRGB * pleds,
                    const int * numLeds,
                    uint8_t numStrips) {
  	/** Fil the leds array with black.   */
    for (uint8_t strip = 0; strip < numStrips; strip++)
  	    fill_solid(&pleds[strip], numLeds[strip], CRGB::Black);
}

//! Turn on the light in night mode
void setLightNight( CRGB * pleds,
                    const int * numLeds,
                    uint8_t numStrips,
                    const uint8_t * pattern) {
    /** Fil the leds array with red. */
    for (uint8_t strip = 0; strip < numStrips; strip++)
  	    fill_solid(&pleds[strip], numLeds[strip], CRGB::Red);

    /** Apply the night pattern to the leds array. */
    for (uint8_t strip = 0; strip < numStrips; strip++)
        for (int led = 0; led < numLeds[strip]; led++)
            (&pleds[strip])[led].nscale8((&pattern[strip])[led]);
}

//! Turn on the light
void setLightOn(    CRGB * pleds,
                    const int * numLeds,
                    uint8_t numStrips) {
    /** Fil the leds array with white. */
    for (uint8_t strip = 0; strip < numStrips; strip++)
  	    fill_solid(&pleds[strip], numLeds[strip], CRGB::White);
}
