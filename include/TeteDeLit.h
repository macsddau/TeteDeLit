/**
 * @file TeteDeLit.h
 * Header file for TeteDeLit programm
 * @author d.macsddau
 * @copyright \@2024, d.macsddau
 * @version 0.01
*/
#ifndef TETEDELIT_H
#define TETEDELIT_H

#include <FastLED.h>

/**
 * @name Lights
 * @brief Definition for lights.
 * @{
*/

/**
 * NUM_LIGHTS
 * @brief The number of lights. One on each side of the bed.
*/
#define NUM_LIGHTS            2

/**
 * LIGHT_STATE_COUNT
 * @brief The number of light states.
*/
#define LIGHT_STATE_COUNT     3

/**
 * LIGHT_BRIGTHNESS
 * @brief Maximum light brighness.
*/
#define LIGHT_BRIGTHNESS      128

/**
 * lightSide
 * @brief Enumerator for light side.
*/
enum lightSide {
  LH,                                 //!<Light on left hand from the front of the bed,
  RH                                  //!<Light on right hand from the front of the beb.
};

/**
 * lightState
 * @brief Enumerator for light states.
*/
enum lightState {
  LIGHT_OFF,                          //!<The light is off.
  LIGHT_NIGHT,                        //!<A side off the bed is lighted is on in cool red using pattern for not disturbing bed neighbor.
  LIGHT_ON                            //!<The light in on. all the bed head side is lighted in white.
};

/** @} Lights */

/**
 * @name Leds
 * @brief Leds definitions.
 * @{
*/

/**
 * NUM_LEDS
 * @brief The number of led on a strip (a side of the bed have one strip).
*/
#define NUM_LEDS              120

/**
 * MAX_POWER_MA
 * @brief The maximum power of one strip in milliamps for 5V power supply.
*/
#define MAX_POWER_MA          800

/**
 * DATA_PIN_LH 
 * @brief The GPIO pin used for LH light.
*/
#define DATA_PIN_LH           0

/**
 * DATA_PIN_RH
 * @brief The GPIO pin used for RH light.
*/
#define DATA_PIN_RH           2

/**
 * whiteTemp
 * @brief Common commercial RGBW white led temperature.
*/
enum whiteTemp {
  WARM_WHITE                  = 2700, //!<Warm white.
  NATURAL_WHITE               = 4000, //!<Natural white.
  COLD_WHITE                  = 6000  //!<Cold white.
};

/**
 * rgbw
 * @brief The custom rgbw strcuture
*/
const Rgbw rgbw = Rgbw(
  NATURAL_WHITE,                      //!<The temperature of white LED chose for the strip.
  kRGBWBoostedWhite,                  //!<The methode of rendering white in RGBW leds.
  W3                                  //!<The white byte position.
);

/** @} Leds */

/**
 * @name Switch
 * @{
*/

/**
 * SWITCH_PIN_LH
 * @brief LH Switch pin.
*/
#define SWITCH_PIN_LH         4

/**
 * SWITCH_PIN_RH
 * @brief RH Switch pin.
*/
#define SWITCH_PIN_RH         15

/**
 * LONG_PULSE
 * @brief Long pulse duration in ms
*/
#define LONG_PULSE            1000

/**
 * switchPins
 * @brief Array with switches pins.
*/
const int switchPins[]        = {SWITCH_PIN_LH, SWITCH_PIN_RH};

/** @} Switches */

/**
 * @name Patterns
 * @brief Leds patterns
 * @{
*/

/**
 * nightPattern[]
 * @brief Night led pattern.
*/
const int nightPattern[] = { \
  0, 9, 17, 26, 34, 43, 51, 60, 68, 77, 85, 94, 102, 111, 119, 128, 136, 145, 153, 162, 170, 179, 187, 196, 204, 213, 221, 230, 238, 247, \
  0, 0, 0, 9, 17, 26, 34, 43, 51, 60, 68, 77, 85, 94, 102, 111, 119, 128, 136, 145, 153, 162, 170, 179, 187, 196, 204, 213, 221, 230, \
  0, 0, 0, 0, 0, 0, 9, 17, 26, 34, 43, 51, 60, 68, 77, 85, 94, 102, 111, 119, 128, 136, 145, 153, 162, 170, 179, 187, 196, 204, \
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 \
};

/** @} Patterns */

/**
 * @name Prototypes
 * @brief function defined in TeteDeLit.cpp
 * @{
*/

void setLightOff(struct CRGB * ledArray);

void setLightNight(struct CRGB * ledArray);

void setLightOn(struct CRGB * ledArray);

/** @} Protoptypes */

#endif  /** TETEDELIT_H */