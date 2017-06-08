#include <Adafruit_NeoPixel.h>
//This first line includes Adafruit neopixel libraries that allows us to command the neopixels
#ifdef __AVR__
  #include <avr/power.h>
#endif
//The following are variables neccesary for the Bobble
#define PIN 11
#define NUMPIXELS 7
int ring_seq[6] = {0,1,2,6,5,4};
int middle_led = 3;
int delayval = 100;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//This takes the information we have put into variables and initializes them as neopixel objects we can command
void setup() {
  
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  test2();
  //Here lies the code that runs.
}
void test2(void)
{

  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    
    // pixels.setPixelColor(i, pixels.Color(red_,green_,blue_)); 
    pixels.setPixelColor(i, pixels.Color(40,0,40)); 
    
    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
  delay(200);
  erase_all();
}
void erase_all(void)
{
  
  for(int i=0;i<NUMPIXELS;i++)
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // zero color (off)

    pixels.show(); // This sends the updated pixel color to the hardware.
}

