#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>

#define PIN 6
#define NUM_LEDS 12
#define FLEX A0
#define BTN_PIN 2

Adafruit_NeoPixel strip(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

LiquidCrystal LCD( 8 , 9 , 10 , 11 , 12 , 13 ); 

bool funcionando = true;
bool estadoAnterior = HIGH;
int indexLed = 0; 

void setup()
{
  
  pinMode( FLEX , INPUT );
  pinMode( BTN_PIN , INPUT_PULLUP );
  strip.begin();
  strip.show();
  
  LCD.begin(16, 2);
  Serial.begin(9600);

}

void loop()
{
  int lecturaFlex = analogRead(FLEX);
  
  int porcentajeFlex = map( lecturaFlex , 0 , 1023 , 0 , 100 );
  
  LCD.setCursor(0, 0);
  LCD.print("Flexion:"); LCD.print((int)lecturaFlex); LCD.print("°");

  
  int r = 0; int g = 0; int b = 0;
  
  if ( lecturaFlex > 183 )
  {
    if ( indexLed == 0 ) { r = 0;   g = 255; b = 0; delay(300);  } 
    else if ( indexLed == 1 ) { r = 0;   g = 255; b = 0;   } 
  
    strip.setPixelColor( indexLed, strip.Color(r , g , b) );
    strip.show();
    delay(300); 
  }
  
  if ( lecturaFlex > 128; lecturaFlex < 183 )
  {
  if ( indexLed == 2 ) { r = 255;   g = 255; b = 0; delay(300);  } 
  else if ( indexLed == 3 ) { r = 255;   g = 255; b = 0;   } 
  
  strip.setPixelColor( indexLed, strip.Color(r , g , b) );
  strip.show();
  delay(300);
  } 
  
  if ( lecturaFlex >= 59; lecturaFlex < 128 )
  {
  if ( indexLed == 4 ) { r = 255;   g = 0; b = 0; delay(300);  } 
  else if ( indexLed == 5 ) { r = 255;   g = 0; b = 0;   } 

  strip.setPixelColor( indexLed, strip.Color(r , g , b) );
  strip.show();
  delay(300);
  }
  
  indexLed = indexLed + 1;
  
}