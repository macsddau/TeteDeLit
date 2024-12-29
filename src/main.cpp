/**
 * @file main.cpp
 * @author d.macsddau
 * @copyright (c)2024, d.macsddau
 * @version 0.01
*/
#include <TeteDeLit.h>
#include <Arduino.h>

/**
 * lightStates
 * @brief Array to store current lights states.
 * 
 * Initilal state with lights off.
*/
lightState lightStates[]      = {LIGHT_OFF, LIGHT_OFF};

/**
 * leds
 * @brief The array where is store the LEDs
*/
CRGB leds[NUM_LIGHTS][NUM_LEDS];

/**
 * switchStates
 * @brief Array with swiches states.
*/
int switchStates[] = {HIGH, HIGH};

/**
 * switchTimes
 * @brief Array with switches times.
*/
unsigned long switchTimes[]   = {0, 0};

/**
 * \fn void setup()
 * \brief starup function.
*/
void setup() {
  //! add leds arrays to led controller with our custom rgbw definition.
  FastLED.addLeds<SK6812, DATA_PIN_LH, RGB>(leds[LH], NUM_LEDS).setRgbw(rgbw);
  FastLED.addLeds<SK6812, DATA_PIN_RH, RGB>(leds[RH], NUM_LEDS).setRgbw(rgbw);

  //! setup input pins
  pinMode(switchPins[LH], INPUT_PULLUP);
  pinMode(switchPins[RH], INPUT_PULLUP);

  //! additional setups for leds rendering.
  FastLED.clear();
  FastLED.setBrightness(LIGHT_BRIGTHNESS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, MAX_POWER_MA);

  //! add some delays in case of setup failure.
  delay(2000);
}

/**
 * \fn void loop()
 * \brief Main loop.
*/
void loop() {
  //! temporary switch state.
  int state;

  //! loop for each ligth side.
  for (int l = LH; l <= RH; l++) {
    //! Read the light switch.
    state = digitalRead(switchPins[l]);

    //! Compare the current state with previous stored state.
    if (state != switchStates[l]) {
      //! Pullup ! Normaly open switch ! LOW when pressed !
      if (state == LOW) {
        //! momorize the time.
        switchTimes[l] = millis();
      } else {
        //! switch is released. Compare time value to know how long it was pressed. 
        if (millis() - switchTimes[l] < LONG_PULSE) {
          //! Short pulse
          switch(lightStates[l]) {
            case LIGHT_OFF: //!< Light off + short pluse => turn on for night mode
              setLightNight(leds[l]);
              lightStates[l] = LIGHT_NIGHT;
              break;
            default: //!< Light on (full or night) + short pulse => turn off the light
              setLightOff(leds[l]);
              lightStates[l] = LIGHT_OFF;
          }
        } else {
          //! Long pulse
          switch(lightStates[l]) {
            case LIGHT_ON: //!< Light on (full) + long pulse => switch to night mode
              setLightNight(leds[l]);
              lightStates[l] = LIGHT_NIGHT;
              break;
            default: //!< Ligth off or night + long pulse => turn on or switch to full mode
              setLightOn(leds[l]);
              lightStates[l] = LIGHT_ON;
          }
        }
      }

      //! save the switch state for next time
      switchStates[l] = state;
    }
  }

  //! render the light according to settings and user action.
  FastLED.show();
}