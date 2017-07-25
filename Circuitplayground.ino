void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 overcompete();
}
void overcompete(void){
 float brightness;
 int lightval = CircuitPlayground.lightSensor();
  if (lightval <= 10){
  lightval = 10;
 }
 int soundval = CircuitPlayground.soundSensor();
 if( (333 <soundval) and (soundval < 345)){
  brightness = (lightval/4);
  }
 else if ( (soundval <= 333) or (soundval >= 345)){
 brightness = (lightval/4) + (5 * abs((soundval - 340))); 
 }
 if (brightness >250){
  brightness = 250;
 }
  float rat = 1000/lightval;
  float each = brightness / (rat+5);
  
  float blue = each * rat;
  float yellow = each * 5;
  int bright = brightness;
  Serial.println("Blu");
  Serial.println(blue);
  Serial.println("Yellow");
  Serial.println(yellow);
  Serial.println(brightness);
 for (int i=0;i<NUMPIXELS;i++){

   pixels.setPixelColor(i, pixels.Color(yellow,yellow,blue)); 
    pixels.show(); // This sends the updated pixel color to the hardware.
  }

}

