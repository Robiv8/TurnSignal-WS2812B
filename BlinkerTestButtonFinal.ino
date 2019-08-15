#define FASTLED_INTERNAL
#include <FastLED.h>
#include <EEPROM.h>

#define NUM_LEDS 72 
#define blinkcount 3

CRGB leds[NUM_LEDS];

#define PIN 2 
#define BUTTONLEFT  4
#define BUTTONRIGHT 5

byte selectedEffect   = 0;
int  buttonStateLeft  = 0;
int  buttonStateRight = 0;
bool AButtonPressed   = false;
bool DirectionCorrection = false;

void setup()
{
  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  pinMode(BUTTONLEFT,  INPUT);
  pinMode(BUTTONRIGHT, INPUT);
  LEDS.setBrightness(100);
}

void loop() { 
  buttonStateLeft  = digitalRead(BUTTONLEFT);
  buttonStateRight = digitalRead(BUTTONRIGHT);
  AButtonPressed = (buttonStateLeft == HIGH) || (buttonStateRight == HIGH);
  
  if (AButtonPressed) {
    if(buttonStateLeft == HIGH) {
      DirectionCorrection = 0;
    }
    else {
      DirectionCorrection = NUM_LEDS;
    }
    for(int blink=0; blink<blinkcount; blink++) {
      
      for(int i=36; i<72; i++) {      //beginnt bei LED Nr. 36 aufbauend bis 72
        if(buttonStateLeft == HIGH) {
          leds[i].setRGB(255,130,0);
        } else {
          leds[72-i].setRGB(255,130,0); // beginnt bei LED Nr. 72 bis i (i=36)
        }
/*      for(int i=0; i<NUM_LEDS; i++) {
        if(buttonStateLeft == HIGH) {
          leds[i].setRGB(255,130,0);
        } else {
          leds[NUM_LEDS-i].setRGB(255,130,0);
        }
        */
        FastLED.show();
        delay(5.5); // Aufbau geschwindigkeit von Pixel zu Pixel
      }
      
      delay(200); //Standdauer des Vollen Lichts
      
      // Instant black after swipe
      setAll(0,0,0);
      //for(int i=0; i<NUM_LEDS; i++) {
      //  if(buttonStateLeft == HIGH) {
      //    leds[i].setRGB(0,0,0);
      //  } else {
      //    leds[NUM_LEDS-i].setRGB(0,0,0);
      //  }
      //  FastLED.show();
      //  delay(10);
      
      //}
      delay(300); //Dauer bis erneut beginnt.
    }
    setAll(0,0,0);
  }
  else {
    setAll(0,0,0);
  }
}
// Set all LEDs to a given color and apply it (visible)
void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    leds[i].setRGB(red, green, blue); 
  }
  FastLED.show();
}
