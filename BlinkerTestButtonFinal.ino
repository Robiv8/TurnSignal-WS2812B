#define FASTLED_INTERNAL // Suppress the annoying error info
#include <FastLED.h>
#include <EEPROM.h>

#define NUM_LEDS 72 
#define blinkcount 3

CRGB leds[NUM_LEDS];
// PIN // ARDUINO :: WemosD1mini
//  2  //   D2    ::     D4
//  3  //   D3    ::     D2
//  4  //   D4    ::     D1

#define PIN 2
#define BUTTONLEFT  3
#define BUTTONRIGHT 4

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
  LEDS.setBrightness(200); // If powered with external power supply then 200-255,
                           // For tests with the 5V from the Arduino max. 100-150 recommended
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
      
      for(int i=36; i<72; i++) {      // starts at LED no. 36 building up to 72
        if(buttonStateLeft == HIGH) {
          leds[i].setRGB(255,130,0);
        } else {
          leds[72-i].setRGB(255,130,0); // starts at LED no. 72 to i (i = 36)
        }

        FastLED.show();
        delay(5.5); // Build speed from pixel to pixel
      }
      
      delay(200); // Duration of the full light
      
      setAll(0,0,0); // Instant black after swipe
      delay(300); // Duration until it starts again.
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
