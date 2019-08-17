#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 300
#define MAX_BRIGHTNESS 80

#define DATA_PIN 2
#define LED_PIN 13
#define CHIPSET        WS2813
#define COLOR_ORDER    GRB

// Define the array of leds
CRGB leds[NUM_LEDS];
uint8_t ledBrightness = 128;
uint8_t direction = -1;
int period = 800;

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
  CRGB::DarkRed
};
int colorArraySize = sizeof(colors) / sizeof(int);

void flicker(int start_index, int end_index)
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
    FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(
        leds,
        NUM_LEDS
    ).setCorrection(TypicalSMD5050);
    for(int dot = 0; dot < NUM_LEDS; dot++) {
        leds[dot] = colors[0];
    }
    FastLED.setBrightness(MAX_BRIGHTNESS);
    FastLED.show();
}

void setNewColor()
{
  int newColor = random (0, colorArraySize);
  for(int dot = 0; dot < NUM_LEDS; dot++) {
      leds[dot] = colors[newColor];
  }
  FastLED.show();
}

void loop() {
    digitalWrite(LED_PIN, HIGH);   // set the LED on
    delay(period);                  // wait for a second
    digitalWrite(LED_PIN, LOW);    // set the LED off
    long random_100 = random(100);
    if(random_100 <= 20){
        flicker(0, 100);
        long color_random_100 = random(100);
        if(random_100 <= 10){
          setNewColor();
        }
    }
    delay(period);                  // wait for a second

}
