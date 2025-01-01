/**
 * @file main.cpp
 * @author d.macsddau
 * @copyright (c)2024, d.macsddau
 * @version 0.01
*/
#include <TeteDeLit.h>
#include <Arduino.h>

/**
 * @name Lights
 * @brief Definition for lights.
 * @{
*/

//! The number of light states.
#define LIGHT_STATE_COUNT		3

//! Enumerator for light states.
enum lightState {
	LIGHT_OFF,                          //!<The light is off.
	LIGHT_NIGHT,                        //!<A side off the bed is lighted is on in cool red using pattern for not disturbing bed neighbor.
	LIGHT_ON                            //!<The light in on. all the bed head side is lighted in white.
};

//! Initilal state with lights off.
lightState lightStates[] = {
	LIGHT_OFF,
	LIGHT_OFF,
	LIGHT_OFF,
	LIGHT_OFF
};

//! Maximum light brighness.
#define LIGHT_BRIGTHNESS		128

/** @} Lights */

/**
 * @name Leds strips
 * @{
 */

//! Number of leds strips (max 20)
#define NUM_STRIPS 7

//! Number of led on a strip.
#define NUM_LEDS_1              30
#define NUM_LEDS_2				30
#define NUM_LEDS_3				30
#define NUM_LEDS_4				30
#define NUM_LEDS_5				10
#define NUM_LEDS_6				10
#define NUM_LEDS_7				10
#define NUM_LEDS_8				0
#define NUM_LEDS_9				0
#define NUM_LEDS_10				0
#define NUM_LEDS_11				0
#define NUM_LEDS_12				0
#define NUM_LEDS_13				0
#define NUM_LEDS_14				0
#define NUM_LEDS_15				0
#define NUM_LEDS_16				0
#define NUM_LEDS_17				0
#define NUM_LEDS_18				0
#define NUM_LEDS_19				0
#define NUM_LEDS_20				0

//! array of number of leds.
const int numLeds[] = {
	NUM_LEDS_1,
	NUM_LEDS_2,
	NUM_LEDS_3,
	NUM_LEDS_4,
	NUM_LEDS_5,
	NUM_LEDS_6,
	NUM_LEDS_7,
	NUM_LEDS_8,
	NUM_LEDS_9,
	NUM_LEDS_10,
	NUM_LEDS_11,
	NUM_LEDS_12,
	NUM_LEDS_13,
	NUM_LEDS_14,
	NUM_LEDS_15,
	NUM_LEDS_16,
	NUM_LEDS_17,
	NUM_LEDS_18,
	NUM_LEDS_19,
	NUM_LEDS_20,
};

//! Leds strips.
CRGB leds_1[NUM_LEDS_1];
CRGB leds_2[NUM_LEDS_2];
CRGB leds_3[NUM_LEDS_3];
CRGB leds_4[NUM_LEDS_4];
CRGB leds_5[NUM_LEDS_5];
CRGB leds_6[NUM_LEDS_6];
CRGB leds_7[NUM_LEDS_7];
CRGB leds_8[NUM_LEDS_8];
CRGB leds_9[NUM_LEDS_9];
CRGB leds_10[NUM_LEDS_10];
CRGB leds_11[NUM_LEDS_11];
CRGB leds_12[NUM_LEDS_12];
CRGB leds_13[NUM_LEDS_13];
CRGB leds_14[NUM_LEDS_14];
CRGB leds_15[NUM_LEDS_15];
CRGB leds_16[NUM_LEDS_16];
CRGB leds_17[NUM_LEDS_17];
CRGB leds_18[NUM_LEDS_18];
CRGB leds_19[NUM_LEDS_19];
CRGB leds_20[NUM_LEDS_20];

//! Array of leds strips.
CRGB * leds[] = {
	leds_1,
	leds_2,
	leds_3,
	leds_4,
	leds_5,
	leds_6,
	leds_7,
	leds_8,
	leds_9,
	leds_10,
	leds_11,
	leds_12,
	leds_13,
	leds_14,
	leds_15,
	leds_16,
	leds_17,
	leds_18,
	leds_19,
	leds_20
};

//! The maximum power of one strip in milliamps for 5V power supply.
#define MAX_POWER_MA			57000 //! 95% of 300W @ 5V = 57A

//! Common commercial RGBW white led temperature.
enum whiteTemp {
	WARM_WHITE                  = 2700, //!<Warm white.
	NATURAL_WHITE               = 4000, //!<Natural white.
	COLD_WHITE                  = 6000  //!<Cold white.
};

//! The custom rgbw strcuture
const Rgbw rgbw = Rgbw(
	NATURAL_WHITE,				//!<The temperature of white LED chose for the strip.
	kRGBWBoostedWhite,			//!<The methode of rendering white in RGBW leds.
	W3							//!<The white byte position.
);

/** @} Leds strips */

/**
 * @name Patterns
 * @{
*/

//! Night led pattern.
const uint8_t nightPattern_1[] = { \
	0, 9, 17, 26, 34, 43, 51, 60, 68, 77, 85, 94, 102, 111, 119, 128, 136, 145, 153, 162, 170, 179, 187, 196, 204, 213, 221, 230, 238, 247 \
};
const uint8_t nightPattern_2[] = { \
	0, 0, 0, 9, 17, 26, 34, 43, 51, 60, 68, 77, 85, 94, 102, 111, 119, 128, 136, 145, 153, 162, 170, 179, 187, 196, 204, 213, 221, 230 \
};
const uint8_t nightPattern_3[] = { \
	0, 0, 0, 0, 0, 0, 9, 17, 26, 34, 43, 51, 60, 68, 77, 85, 94, 102, 111, 119, 128, 136, 145, 153, 162, 170, 179, 187, 196, 204 \
};
const uint8_t nightPattern_4[] = { \
	0, 0, 0, 0, 0, 0, 9, 17, 26, 34, 43, 51, 60, 68, 77, 85, 94, 102, 111, 119, 128, 136, 145, 153, 162, 170, 179, 187, 196, 204 \
};
const uint8_t nightPattern_5[] = { \
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0 \
};
const uint8_t nightPattern_6[] = { \
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0 \
};
const uint8_t nightPattern_7[] = { \
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0 \
};
const uint8_t nightPattern_8[] = {};
const uint8_t nightPattern_9[] = {};
const uint8_t nightPattern_10[] = {};
const uint8_t nightPattern_11[] = {};
const uint8_t nightPattern_12[] = {};
const uint8_t nightPattern_13[] = {};
const uint8_t nightPattern_14[] = {};
const uint8_t nightPattern_15[] = {};
const uint8_t nightPattern_16[] = {};
const uint8_t nightPattern_17[] = {};
const uint8_t nightPattern_18[] = {};
const uint8_t nightPattern_19[] = {};
const uint8_t nightPattern_20[] = {};

const uint8_t * nightPatterns[] = {
	nightPattern_1,
	nightPattern_2,
	nightPattern_3,
	nightPattern_4,
	nightPattern_5,
	nightPattern_6,
	nightPattern_7,
	nightPattern_8,
	nightPattern_9,
	nightPattern_10,
	nightPattern_11,
	nightPattern_12,
	nightPattern_13,
	nightPattern_14,
	nightPattern_15,
	nightPattern_16,
	nightPattern_17,
	nightPattern_18,
	nightPattern_19,
	nightPattern_20
};

/** @} Patterns */

/**
 * @name Switches
 * @{
 */

//! Number of switches (max 4).
#define NUM_SWITCHES 1

//! Array with swiches states.
int switchStates[] = {
	HIGH,
	HIGH,
	HIGH,
	HIGH
};

//! Array with switches times.
unsigned long switchTimes[]   = {
	0,
	0,
	0,
	0
};

//! Long pulse duration in ms
#define LONG_PULSE				1000

/** @} Switches */

//! setup.
void setup() {
	//! add some delays in case of setup failure.
	delay(2000);

	//! add leds arrays to led controller with our custom rgbw definition.
	FastLED.addLeds<SK6812, DATA_PIN_1, RGB>(leds[0], numLeds[0]).setRgbw(rgbw);
	FastLED.addLeds<SK6812, DATA_PIN_2, RGB>(leds[1], numLeds[1]).setRgbw(rgbw);
	FastLED.addLeds<SK6812, DATA_PIN_3, RGB>(leds[2], numLeds[2]).setRgbw(rgbw);
	FastLED.addLeds<SK6812, DATA_PIN_4, RGB>(leds[3], numLeds[3]).setRgbw(rgbw);
	FastLED.addLeds<SK6812, DATA_PIN_5, RGB>(leds[4], numLeds[4]).setRgbw(rgbw);
	FastLED.addLeds<SK6812, DATA_PIN_6, RGB>(leds[5], numLeds[5]).setRgbw(rgbw);
	FastLED.addLeds<SK6812, DATA_PIN_7, RGB>(leds[6], numLeds[6]).setRgbw(rgbw);
	// FastLED.addLeds<SK6812, DATA_PIN_8, RGB>(leds[7], numLeds[7]).setRgbw(rgbw);
	// FastLED.addLeds<SK6812, DATA_PIN_9, RGB>(leds[8], numLeds[8]).setRgbw(rgbw);
	// FastLED.addLeds<SK6812, DATA_PIN_10, RGB>(leds[9], numLeds[9]).setRgbw(rgbw);
	// FastLED.addLeds<SK6812, DATA_PIN_11, RGB>(leds[10], numLeds[10]).setRgbw(rgbw);
	// FastLED.addLeds<SK6812, DATA_PIN_12, RGB>(leds[11], numLeds[11]).setRgbw(rgbw);
	// FastLED.addLeds<SK6812, DATA_PIN_13, RGB>(leds[12], numLeds[12]).setRgbw(rgbw);
	// FastLED.addLeds<SK6812, DATA_PIN_14, RGB>(leds[13], numLeds[13]).setRgbw(rgbw);
	// FastLED.addLeds<SK6812, DATA_PIN_15, RGB>(leds[14], numLeds[14]).setRgbw(rgbw);
	// FastLED.addLeds<SK6812, DATA_PIN_16, RGB>(leds[15], numLeds[15]).setRgbw(rgbw);
	// FastLED.addLeds<SK6812, DATA_PIN_17, RGB>(leds[16], numLeds[16]).setRgbw(rgbw);
	// FastLED.addLeds<SK6812, DATA_PIN_18, RGB>(leds[17], numLeds[17]).setRgbw(rgbw);
	// FastLED.addLeds<SK6812, DATA_PIN_19, RGB>(leds[18], numLeds[18]).setRgbw(rgbw);
	// FastLED.addLeds<SK6812, DATA_PIN_20, RGB>(leds[19], numLeds[19]).setRgbw(rgbw);

	//! setup input pins
	pinMode(switchPins[0], INPUT_PULLUP);
	// pinMode(switchPins[1], INPUT_PULLUP);
	// pinMode(switchPins[2], INPUT_PULLUP);
	// pinMode(switchPins[3], INPUT_PULLUP);

	//! additional setups for leds rendering.
	FastLED.clear();
	FastLED.setBrightness(LIGHT_BRIGTHNESS);
	FastLED.setMaxPowerInVoltsAndMilliamps(5, MAX_POWER_MA);
}

//! loop.
void loop() {
	//! temporary switch state.
	int state;

	//! loop for each ligth side.
	for (int sw = 0; sw < NUM_SWITCHES; sw++) {
		//! Read the light switch.
		state = digitalRead(switchPins[sw]);

		//! Compare the current state with previous stored state.
		if (state != switchStates[sw]) {
			//! Pullup ! Normaly open switch ! LOW when pressed !
			if (state == LOW) {
				//! momorize the time.
				switchTimes[sw] = millis();
			} else {
				//! switch is released. Compare time value to know how long it was pressed.
				if (millis() - switchTimes[sw] < LONG_PULSE) {
					//! Short pulse
					switch(lightStates[sw]) {
						case LIGHT_OFF: //!< Light off + short pluse => turn on for night mode
							setLightNight(*leds, numLeds, NUM_STRIPS, *nightPatterns);
							lightStates[sw] = LIGHT_NIGHT;
							break;
						default: //!< Light on (full or night) + short pulse => turn off the light
							setLightOff(*leds, numLeds, NUM_STRIPS);
							lightStates[sw] = LIGHT_OFF;
					}
				} else {
					//! Long pulse
					switch(lightStates[sw]) {
						case LIGHT_ON: //!< Light on (full) + long pulse => switch to night mode
							setLightNight(*leds, numLeds, NUM_STRIPS, *nightPatterns);
							lightStates[sw] = LIGHT_NIGHT;
							break;
						default: //!< Ligth off or night + long pulse => turn on or switch to full mode
							setLightOn(*leds, numLeds, NUM_STRIPS);
							lightStates[sw] = LIGHT_ON;
					}
				}
			}

			//! save the switch state for next time
			switchStates[sw] = state;
		}
	}

	//! render the light according to settings and user action.
	FastLED.show();
}