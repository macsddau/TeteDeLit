/**
 * @file TeteDeLit.cpp
 * @author d.macsddau
 * @copyright (c)2024, d.macsddau
 * @version 0.01
*/
#include <TeteDeLit.h>

/**
 * void setLightOff(truct CRGB * ledArray)
 * \brief Turn off the light
*/
void setLightOff(struct CRGB * ledArray) {
  	/** Fil the leds array with black.   */
  	fill_solid(ledArray, NUM_LEDS, CRGB::Black);
}

/**
 * void setLightNight(truct CRGB * ledArray)
 * \brief Turn on the light in night mode
*/
void setLightNight(struct CRGB * ledArray) {
    /** Fil the leds array with red. */
    fill_solid(ledArray, NUM_LEDS, CRGB::Red);

    /** Apply the night pattern to the leds array. */
    for (int l = 0; l < NUM_LEDS; l++) {
        ledArray[l].nscale8(nightPattern[l]);
    }
}

/**
 * void setLightOn(truct CRGB * ledArray)
 * \brief Turn on the light
*/
void setLightOn(struct CRGB * ledArray) {
    /** Fil the leds array with white. */
    fill_solid(ledArray, NUM_LEDS, CRGB::White);
}
