#include <OctoWS2811.h>
#include "logging.h"

#define RED    0xFF0000
#define GREEN  0x00FF00
#define BLUE   0x0000FF
#define YELLOW 0xFFFF00
#define PINK   0xFF1088
#define ORANGE 0xE05800
#define WHITE  0xFFFFFF

const int ledsPerStrip = 300;
int drawingMemory[ledsPerStrip*6];
DMAMEM int displayMemory[ledsPerStrip*6];
OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, WS2811_GRB | WS2811_800kHz);


void flicker(int start_index, int end_index)
{
    int original_colour = leds.getPixel(start_index);
    int number_flickers = random(1, 5);

    for (int i=0; i < number_flickers; i++) {

        // Turn off
        for (int j=start_index; j < end_index; j++) {
            leds.setPixel(j, 0x000000);
        }
        leds.show();
        int delay_ms = random(50, 100);
        delay(delay_ms);

        // Turn back on
        for (int j=start_index; j < end_index; j++) {
            leds.setPixel(j, original_colour);
        }
        leds.show();
    }
}


void setup()
{

    delay(1000);
    Logging::Init();

    leds.begin();

    for (int i=0; i < 150; i++) {
        leds.setPixel(i, RED);
    }

    for (int i=150; i < 300; i++) {
        leds.setPixel(i, GREEN);
    }

    leds.show();

    randomSeed(analogRead(0));
}

void loop()
{
    Logging::log("meow");
    long random_100 = random(100);
    if(random_100 <= 20){
        long red_or_green = random(0, 2);
        if(red_or_green == 0){
            flicker(0, 150);
        } else {
            flicker(150, 300);
        }
    }
    delay(1000);
}
