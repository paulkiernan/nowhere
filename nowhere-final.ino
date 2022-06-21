#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 300
#define MAX_BRIGHTNESS 50
#define STEP_BRIGHTNESS 128

#define LED_STRIP_N 2
#define LED_STRIP_O 14
#define LED_STRIP_W 7
#define LED_STRIP_H 8
#define LED_STRIP_E1 6
#define LED_STRIP_R 20
#define LED_STRIP_E2 21
#define LED_STRIP_AUX 5

#define LED_PIN 13
#define CHIPSET        WS2813
#define COLOR_ORDER    GRB

int period = 1000;

// Define the array of leds
CRGB led_strip_N[NUM_LEDS];
CRGB led_strip_O[NUM_LEDS];
CRGB led_strip_W[NUM_LEDS];
CRGB led_strip_H[NUM_LEDS];
CRGB led_strip_E1[NUM_LEDS];
CRGB led_strip_R[NUM_LEDS];
CRGB led_strip_E2[NUM_LEDS];
CRGB led_strip_AUX[NUM_LEDS];

int ledStripSize = 7;
CRGB* ledStrips[] = {
    led_strip_N,
    led_strip_O,
    led_strip_W,
    led_strip_H,
    led_strip_E1,
    led_strip_R,
    led_strip_E2
};

int colors[] = {
  CRGB::Amethyst,
  CRGB::Brown,
  CRGB::Chartreuse,
  CRGB::Coral,
  CRGB::Crimson,
  CRGB::DarkBlue,
  CRGB::DarkCyan,
  CRGB::DarkGoldenrod,
  CRGB::DarkGreen,
  CRGB::DarkMagenta,
  CRGB::DarkOrange,
  CRGB::DarkOrchid,
  CRGB::DarkRed,
  CRGB::DarkSlateBlue,
  CRGB::FireBrick,
  CRGB::FloralWhite,
  CRGB::Gold,
  CRGB::Goldenrod,
  CRGB::HotPink,
  CRGB::IndianRed,
  CRGB::Indigo,
  CRGB::Lavender,
  CRGB::LavenderBlush,
  CRGB::LightBlue,
  CRGB::LightCoral,
  CRGB::LightSalmon,
  CRGB::LightSeaGreen,
  CRGB::Maroon,
  CRGB::MediumOrchid,
  CRGB::MediumPurple,
  CRGB::MediumVioletRed,
  CRGB::MistyRose,
  CRGB::Olive,
  CRGB::Plum,
  CRGB::LightGoldenrodYellow
};
int colorArraySize = sizeof(colors) / sizeof(int);

void flicker(int start_index, int end_index, CRGB* leds)
{
    int original_colour_r = leds[start_index].r;
    int original_colour_g = leds[start_index].g;
    int original_colour_b = leds[start_index].b;
    
    int number_flickers = random(1, 5);

    for (int i=0; i < number_flickers; i++) {

        // Turn off
        for (int j=start_index; j < end_index; j++) {
            leds[j] = 0x000000;
        }
        FastLED.show();
        int delay_ms = random(50, 100);
        delay(delay_ms);

        // Turn back on
        for (int j=start_index; j < end_index; j++) {
            leds[j].setRGB(
                original_colour_r,
                original_colour_g,
                original_colour_b
            );
        }
        FastLED.show();
    }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_STRIP_N, OUTPUT);
  pinMode(LED_STRIP_O, OUTPUT);
  pinMode(LED_STRIP_W, OUTPUT);
  pinMode(LED_STRIP_H, OUTPUT);
  pinMode(LED_STRIP_E1, OUTPUT);
  pinMode(LED_STRIP_R, OUTPUT);
  pinMode(LED_STRIP_E2, OUTPUT);
  pinMode(LED_STRIP_AUX, OUTPUT);
  FastLED.addLeds<CHIPSET, LED_STRIP_N, COLOR_ORDER>(
          led_strip_N,
          NUM_LEDS
  ).setCorrection(TypicalSMD5050);
  FastLED.addLeds<CHIPSET, LED_STRIP_O, COLOR_ORDER>(
          led_strip_O,
          NUM_LEDS
  ).setCorrection(TypicalSMD5050);
  FastLED.addLeds<CHIPSET, LED_STRIP_W, COLOR_ORDER>(
          led_strip_W,
          NUM_LEDS
  ).setCorrection(TypicalSMD5050);
  FastLED.addLeds<CHIPSET, LED_STRIP_H, COLOR_ORDER>(
          led_strip_H,
          NUM_LEDS
  ).setCorrection(TypicalSMD5050);
  FastLED.addLeds<CHIPSET, LED_STRIP_E1, COLOR_ORDER>(
          led_strip_E1,
          NUM_LEDS
  ).setCorrection(TypicalSMD5050);
  FastLED.addLeds<CHIPSET, LED_STRIP_R, COLOR_ORDER>(
          led_strip_R,
          NUM_LEDS
  ).setCorrection(TypicalSMD5050);
  FastLED.addLeds<CHIPSET, LED_STRIP_E2, COLOR_ORDER>(
          led_strip_E2,
          NUM_LEDS
  ).setCorrection(TypicalSMD5050);
  FastLED.addLeds<CHIPSET, LED_STRIP_AUX, COLOR_ORDER>(
          led_strip_AUX,
          NUM_LEDS
  ).setCorrection(TypicalSMD5050);

  // Initialize with color
  int newColor = random (0, colorArraySize);
  for (int strip = 0; strip < ledStripSize; strip++){
      for(int dot = 0; dot < NUM_LEDS; dot++) { 
        led_strip_N[dot] = colors[newColor];
        led_strip_O[dot] = colors[newColor];
        led_strip_W[dot] = colors[newColor];
        led_strip_H[dot] = colors[newColor];
        led_strip_E1[dot] = colors[newColor];
        led_strip_R[dot] = colors[newColor];
        led_strip_E2[dot] = colors[newColor];
        // Strip lighting
        //led_strip_AUX[dot] = CRGB::DarkGoldenrod;
        led_strip_AUX[dot] = 0x777700;
      }
      FastLED.setBrightness(MAX_BRIGHTNESS);
  }
  FastLED.show();
}

void setNewColor()
{
  int newColor = random (0, colorArraySize);
  for(int dot = 0; dot < NUM_LEDS; dot++) { 
      led_strip_N[dot] = colors[newColor];
      led_strip_O[dot] = colors[newColor];
      led_strip_W[dot] = colors[newColor];
      led_strip_H[dot] = colors[newColor];
      led_strip_E1[dot] = colors[newColor];
      led_strip_R[dot] = colors[newColor];
      led_strip_E2[dot] = colors[newColor];
  }
  FastLED.show();
}

void loop() {
    digitalWrite(LED_PIN, HIGH);   // set the LED on
    delay(period);                  // wait for a second
    digitalWrite(LED_PIN, LOW);    // set the LED off
    long random_100 = random(100);
    if(random_100 <= 20){
        int random_led_strip = random(7);
        flicker(0, NUM_LEDS, ledStrips[random_led_strip]);
        long random_color_100 = random(100);
        if(random_color_100 <= 5){
          delay(1000);
          setNewColor();
        }
    } else if (random_100 > 20 && random_100 <= 30) {
        // Flicker W
        flicker(0, NUM_LEDS, led_strip_W);
    } else if (random_100 > 30 && random_100 <= 40) {
        // Flicker H
        flicker(0, NUM_LEDS, led_strip_H);
    }
    delay(period);
}
