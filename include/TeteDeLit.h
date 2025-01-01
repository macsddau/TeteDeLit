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
 * LIGHT_STATE_COUNT
 * @brief The number of light states.
*/
#define LIGHT_STATE_COUNT		3

/**
 * LIGHT_BRIGTHNESS
 * @brief Maximum light brighness.
*/
#define LIGHT_BRIGTHNESS		128

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

//! The GPIO pin used for leds strips
#define DATA_PIN_1				15
#define DATA_PIN_2				13
#define DATA_PIN_3				2
#define DATA_PIN_4            	0
#define DATA_PIN_5				12
#define DATA_PIN_6				4
#define DATA_PIN_7				14
#define DATA_PIN_8				16
#define DATA_PIN_9				27
#define DATA_PIN_10				17
#define DATA_PIN_11				26
#define DATA_PIN_12				5
#define DATA_PIN_13				25
#define DATA_PIN_14				18
#define DATA_PIN_15				33
#define DATA_PIN_16				19
#define DATA_PIN_17				32
#define DATA_PIN_18				21
#define DATA_PIN_19				22
#define DATA_PIN_20				23

/**
 * MAX_POWER_MA
 * @brief The maximum power of one strip in milliamps for 5V power supply.
*/
#define MAX_POWER_MA			57000 //! 95% of 300W @ 5V = 57A

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

//! Switch pins.
#define SWITCH_PIN_1			35
#define SWITCH_PIN_2			34
#define SWITCH_PIN_3			39
#define SWITCH_PIN_4			36

//! Array with switches pins.
const int switchPins[] = {
	SWITCH_PIN_1,
	SWITCH_PIN_2,
	SWITCH_PIN_3,
	SWITCH_PIN_4
};

//! Long pulse duration in ms
#define LONG_PULSE				1000

/** @} Switches */

/**
 * @name Prototypes
 * @brief function defined in TeteDeLit.cpp
 * @{
*/

void setLightOff(CRGB * pleds, const int * numLeds, uint8_t numStrips);

void setLightNight(CRGB * pleds, const int * numLeds, uint8_t numStrips, const uint8_t * pattern);

void setLightOn(CRGB * pleds, const int * numLeds, uint8_t numStrips);

/** @} Protoptypes */

#endif  /** TETEDELIT_H */