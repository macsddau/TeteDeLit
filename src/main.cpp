#include <main.h>
#include <Arduino.h>

void setup() {
  delay(1000);
  // put your setup code here, to run once:
	Serial.begin(115200);

  FastLED.addLeds(&rgbEmuLH, leds[LH], NUM_LEDS);
  FastLED.addLeds(&rgbEmuRH, leds[RH], NUM_LEDS);

  pinMode(buttonPins[LH], INPUT_PULLUP);
  pinMode(buttonPins[RH], INPUT_PULLUP);

  FastLED.clear();
  FastLED.setBrightness(LIGHT_BRIGTHNESS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, MAX_POWER_MA);
}

void loop() {
  // put your main code here, to run repeatedly:
  int state;

  for (int l = LH; l <= RH; l++) { 
    state = digitalRead(buttonPins[l]);

    if (state != buttonStates[l]) {
      if (state == LOW) {
        buttonTimes[l] = millis();
      } else {
        if (millis() - buttonTimes[l] < LONG_PULSE) {
          //short pulse
          switch(lightStates[l]) {
            case LIGHT_OFF:
              setLightNight(l);
              lightStates[l] = LIGHT_NIGHT;
              break;
            default:
              setLightOff(l);
              lightStates[l] = LIGHT_OFF;
            }
        } else {
          //long pulse
          switch(lightStates[l]) {
            case LIGHT_ON:
              setLightNight(l);
              lightStates[l] = LIGHT_NIGHT;
              break;
            default:
              setLightOn(l);
              lightStates[l] = LIGHT_ON;
          }
        }
      }

      buttonStates[l] = state;
    }
  }

//  FastLED.show();

}

// utilities
static void setLightOff(int side) {
  fill_solid(leds[side], NUM_LEDS, CRGB::Black);
}

static void setLightNight(int side) {
  fill_solid(leds[side], NUM_LEDS, CRGB::Red);
  for (int l = 0; l < NUM_LEDS; l++) {
    leds[side][l].nscale8(nightLeds[l]);
  }
}

static void setLightOn(int side) {
  fill_solid(leds[side], NUM_LEDS, CRGB::White);
}