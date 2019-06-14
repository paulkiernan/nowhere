#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 300
#define MAX_BRIGHTNESS 255
#define TEENSY_LED_PIN 13
#define CHIPSET        WS2813
#define COLOR_ORDER    GRB

#define LED_STRIP0_PIN  2
#define LED_STRIP1_PIN  14
#define LED_STRIP2_PIN  7
#define LED_STRIP3_PIN  8
#define LED_STRIP4_PIN  6
#define LED_STRIP5_PIN  20
#define LED_STRIP6_PIN  21
#define LED_STRIP7_PIN  5

CRGB led_strip0[NUM_LEDS];
CRGB led_strip1[NUM_LEDS];
CRGB led_strip2[NUM_LEDS];
CRGB led_strip3[NUM_LEDS];
CRGB led_strip4[NUM_LEDS];
CRGB led_strip5[NUM_LEDS];
CRGB led_strip6[NUM_LEDS];
CRGB led_strip7[NUM_LEDS];

uint8_t ledBrightness = 255;
uint8_t direction = -1;
int period = 10;


void setup() {
    pinMode(TEENSY_LED_PIN, OUTPUT);

    // LED Output test
    FastLED.addLeds<CHIPSET, LED_STRIP0_PIN, COLOR_ORDER>(
        led_strip0,
        NUM_LEDS
    ).setCorrection(TypicalSMD5050);
    FastLED.addLeds<CHIPSET, LED_STRIP1_PIN, COLOR_ORDER>(
        led_strip1,
        NUM_LEDS
    ).setCorrection(TypicalSMD5050);
    FastLED.addLeds<CHIPSET, LED_STRIP2_PIN, COLOR_ORDER>(
        led_strip2,
        NUM_LEDS
    ).setCorrection(TypicalSMD5050);
    FastLED.addLeds<CHIPSET, LED_STRIP3_PIN, COLOR_ORDER>(
        led_strip3,
        NUM_LEDS
    ).setCorrection(TypicalSMD5050);
    FastLED.addLeds<CHIPSET, LED_STRIP4_PIN, COLOR_ORDER>(
        led_strip4,
        NUM_LEDS
    ).setCorrection(TypicalSMD5050);
    FastLED.addLeds<CHIPSET, LED_STRIP5_PIN, COLOR_ORDER>(
        led_strip5,
        NUM_LEDS
    ).setCorrection(TypicalSMD5050);
    FastLED.addLeds<CHIPSET, LED_STRIP6_PIN, COLOR_ORDER>(
        led_strip6,
        NUM_LEDS
    ).setCorrection(TypicalSMD5050);
    FastLED.addLeds<CHIPSET, LED_STRIP7_PIN, COLOR_ORDER>(
        led_strip7,
        NUM_LEDS
    ).setCorrection(TypicalSMD5050);

    for(int dot = 0; dot < NUM_LEDS; dot++) {
        led_strip0[dot] = 0xe6194B;
        led_strip1[dot] = 0xf58231;
        led_strip2[dot] = 0xffe119;
        led_strip3[dot] = 0xbfef45;
        led_strip4[dot] = 0x3cb44b;
        led_strip5[dot] = 0x42d4f4;
        led_strip6[dot] = 0x4363d8;
        led_strip7[dot] = 0x911eb4;
    }
    FastLED.setBrightness(MAX_BRIGHTNESS);
    FastLED.show();
}

void loop() {
    digitalWrite(TEENSY_LED_PIN, HIGH);   // set the LED on
    delay(period);                  // wait for a second
    digitalWrite(TEENSY_LED_PIN, LOW);    // set the LED off
    delay(period);                  // wait for a second
    ledBrightness += direction;
    if (ledBrightness == 0){
      direction = 1;
    } else if (ledBrightness == MAX_BRIGHTNESS){
      direction = -1;
    }
    for(int dot = 0; dot < NUM_LEDS; dot++) {
        FastLED.setBrightness(ledBrightness);
    }
    FastLED.show();
}
