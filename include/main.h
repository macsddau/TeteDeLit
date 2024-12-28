#ifndef _MAIN_H_
#define _MAIN_H_

#include <FastLED.h>

//Lights
#define NUM_LIGHTS            2
#define LIGHT_STATE_COUNT     3
#define LIGHT_BRIGTHNESS      128

enum lightSide {
  LH,
  RH
};

enum lightState {
  LIGHT_OFF,
  LIGHT_NIGHT,
  LIGHT_ON
};

lightState lightStates[]      = {LIGHT_OFF, LIGHT_OFF};

//Leds
#define NUM_LEDS              120
#define MAX_POWER_MA          800   //mA
#define DATA_PIN_LH           0
#define DATA_PIN_RH           2

enum whiteTemp {
  WARM_WHITE                  = 2700,
  NATURAL_WHITE               = 4000,
  COLD_WHITE                  = 6000
};

CRGB leds[NUM_LIGHTS][NUM_LEDS];

PROGMEM Rgbw rgbw = Rgbw(
  NATURAL_WHITE,
  kRGBWBoostedWhite,
  W3
);

// buttons
#define BUTTON_PIN_LH         4
#define BUTTON_PIN_RH         15
#define LONG_PULSE            1000  // = 1s

const int buttonPins[]        = {BUTTON_PIN_LH, BUTTON_PIN_RH};
int buttonStates[]            = {HIGH, HIGH};
unsigned long buttonTimes[]   = {0, 0};

// Effects
PROGMEM const int nightLeds[] = { \
  0, 9, 17, 26, 34, 43, 51, 60, 68, 77, 85, 94, 102, 111, 119, 128, 136, 145, 153, 162, 170, 179, 187, 196, 204, 213, 221, 230, 238, 247, \
  0, 0, 0, 9, 17, 26, 34, 43, 51, 60, 68, 77, 85, 94, 102, 111, 119, 128, 136, 145, 153, 162, 170, 179, 187, 196, 204, 213, 221, 230, \
  0, 0, 0, 0, 0, 0, 9, 17, 26, 34, 43, 51, 60, 68, 77, 85, 94, 102, 111, 119, 128, 136, 145, 153, 162, 170, 179, 187, 196, 204, \
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 \
};

// utilities definitions
static void setLightOff(int side);
static void setLightNight(int side);
static void setLightOn(int side);

#endif  // _MAIN_H_