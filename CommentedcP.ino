#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 overcompete();
}
void overcompete(void){
 float brightness;
 //Brightness serves as a marker for how intensely the Neopixels will shine
 int lightval = CircuitPlayground.lightSensor();
 //Lightval ranges from 0 to 1023 and is a marker for how much light the sensor is picking up
  if (lightval <= 10){
    //This condition prevents the playground from going dark if not enough light is registered. It doesn't take absolute darkness to bring it down to 0.
  lightval = 10;
 }
 int soundval = CircuitPlayground.soundSensor();
 //soundval marks how much sound is being picked up and ranges from 0 to 800. It hovers at around 330. Because of this, the following if condition was made so that random variance will not have an effect and lights will only change when there truly is noise.
 if( (333 <soundval) and (soundval < 345)){
  brightness = (lightval/4);
  }
 else if ( (soundval <= 333) or (soundval >= 345)){
  //This if condition is the primary determiner of how bright the neopixels will be. Wether the soundval goes up or down with noise seemed random, so the absolute difference is used.
 brightness = (lightval/4) + (5 * abs((soundval - 340))); 
 }
 if (brightness >250){
  //To ensure the Neopixels aren't overloaded.
  brightness = 250;
 }
  float ratio = 1000/lightval;
  //Ratio is a dimensionless term for brightness
  float each = brightness / (ratio+5);
  //Each is a method of dividing the brightness between the two desirable colors. The 5 is present to make the color assigned the top value more likely to be seen,
  float blue = each * ratio;
  float yellow = each * 5;
  int bright = brightness;
  Serial.println("Blu");
  Serial.println(blue);
  Serial.println("Yellow");
  Serial.println(yellow);
  Serial.println(brightness);
 for (int i=2;i<NUMPIXELS;i++){

   pixels.setPixelColor(i, pixels.Color(yellow,yellow,blue)); 
    pixels.show(); // This sends the updated pixel color to the hardware.
  }

}

