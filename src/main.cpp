/**
 * @file main.cpp
 * @author d.macsddau
 * @copyright (c)2024, d.macsddau
 * @version 0.01
*/
#include <TeteDeLit.h>
#include <Arduino.h>

#define NUM_SWITCHES 1

#define NUM_STRIPS 7

/**
 * lightStates
 * @brief Array to store current lights states.
 *
 * Initilal state with lights off.
*/
lightState lightStates[] = {
	LIGHT_OFF,
	LIGHT_OFF,
	LIGHT_OFF,
	LIGHT_OFF
};

/**
 * switchStates
 * @brief Array with swiches states.
*/
int switchStates[] = {
	HIGH,
	HIGH,
	HIGH,
	HIGH
};

/**
 * switchTimes
 * @brief Array with switches times.
*/
unsigned long switchTimes[]   = {
	0,
	0,
	0,
	0
};


//! The number of led on a strip.
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

//! The array where is store the LEDs
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

/**
 * @name Patterns
 * @brief Leds patterns
 * @{
*/

/**
 * nightPattern[]
 * @brief Night led pattern.
*/
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
 * \fn void setup()
 * \brief starup function.
*/
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

	//! setup input pins
	pinMode(switchPins[0], INPUT_PULLUP);

	//! additional setups for leds rendering.
	FastLED.clear();
	FastLED.setBrightness(LIGHT_BRIGTHNESS);
	FastLED.setMaxPowerInVoltsAndMilliamps(5, MAX_POWER_MA);
}

/**
 * \fn void loop()
 * \brief Main loop.
*/
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