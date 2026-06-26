#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUM_LEDS 12
#define POT_PIN A0
#define BTN_PIN 2

Adafruit_NeoPixel strip(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int efecto = 3; 
bool ultimoBtn = 1;
int indexLed = 0; 
bool direccionIda = true; 

void setup() {
  strip.begin();
  strip.show();
  pinMode( BTN_PIN , INPUT_PULLUP );
  randomSeed(analogRead(A1));
}

void loop() {
  bool estado = digitalRead(BTN_PIN);
  if (estado == 0 && ultimoBtn == 1) {
    if (efecto == 3) {
      efecto = 0; 
    } else {
      efecto = efecto + 1;
    }
    
    if (efecto > 2) {
      efecto = 0;
    }
    indexLed = 0;
    direccionIda = true;
    strip.clear();
    strip.show();
    delay(200); 
  }
  ultimoBtn = estado;

  int velocidad = map( analogRead(POT_PIN), 0 , 1023 , 100 , 700 );

  if (efecto == 3) {
    strip.clear();
    strip.show();
  }

  else if (efecto == 0) {
    strip.clear();
    
    int r = 0; int g = 0; int b = 0;

    if ( indexLed == 0 || indexLed == 6) { r = 255; g = 0;   b = 0;   } // rojo
    else if ( indexLed == 1 || indexLed == 7) { r = 0;   g = 255; b = 0;   } // verde
    else if ( indexLed == 2 || indexLed == 8) { r = 0;   g = 0;   b = 255; } // azul
    else if ( indexLed == 3 || indexLed == 9) { r = 255; g = 255; b = 0;   } // amarillo
    else if ( indexLed == 4 || indexLed == 10){ r = 0;   g = 255; b = 255; } // cian
    else if ( indexLed == 5 || indexLed == 11){ r = 255; g = 0;   b = 255; } // magenta

    strip.setPixelColor( indexLed, strip.Color(r , g , b) );
    strip.show();
    delay(velocidad);

    indexLed = indexLed + 1; 
    
    if (indexLed >= 12) {
      indexLed = 0;
      delay(1000); 
    }
  }

  else if (efecto == 1) {
    strip.clear();

    int r = 0; int g = 0; int b = 0;

    if ( direccionIda == true ) {
      if ( indexLed == 0 )      { r = 255; g = 0;   b = 0;   }
      else if ( indexLed == 1 ) { r = 255; g = 128; b = 0;   }
      else if ( indexLed == 2 ) { r = 255; g = 255; b = 0;   }
      else if ( indexLed == 3 ) { r = 0;   g = 255; b = 0;   }
      else if ( indexLed == 4 ) { r = 0;   g = 255; b = 255; }
      else if ( indexLed == 5 ) { r = 0;   g = 0;   b = 255; }
      else if ( indexLed == 6 ) { r = 128; g = 0;   b = 255; }
      else if ( indexLed == 7 ) { r = 255; g = 0;   b = 255; }
      else if ( indexLed == 8 ) { r = 255; g = 0;   b = 128; }
      else if ( indexLed == 9 ) { r = 128; g = 255; b = 0;   }
      else if ( indexLed == 10 ){ r = 0;   g = 128; b = 255; }
      else if ( indexLed == 11 ){ r = 255; g = 255; b = 255; }
    }
  
    else {
      if ( indexLed == 11 )     { r = 255; g = 0;   b = 0;   }
      else if ( indexLed == 10 ){ r = 0;   g = 255; b = 0;   }
      else if ( indexLed == 9 ) { r = 0;   g = 0;   b = 255; }
      else if ( indexLed == 8 ) { r = 255; g = 255; b = 0;   }
      else if ( indexLed == 7 ) { r = 0;   g = 255; b = 255; }
      else if ( indexLed == 6 ) { r = 255; g = 0;   b = 255; }
      else if ( indexLed == 5 ) { r = 255; g = 128; b = 0;   }
      else if ( indexLed == 4 ) { r = 128; g = 0;   b = 255; }
      else if ( indexLed == 3 ) { r = 0;   g = 128; b = 255; }
      else if ( indexLed == 2 ) { r = 128; g = 255; b = 0;   }
      else if ( indexLed == 1 ) { r = 255; g = 0;   b = 128; }
      else if ( indexLed == 0 ) { r = 255; g = 255; b = 255; }
    }

    strip.setPixelColor( indexLed , strip.Color(r , g , b) );
    strip.show();
    delay(velocidad);

    if ( direccionIda == true ) {
      indexLed = indexLed + 1;
      if ( indexLed >= 12 ) {
        indexLed = 11;      
        direccionIda = false;
      }
    } 
    else {
      indexLed = indexLed - 1;
      if ( indexLed < 0 ) {
        indexLed = 0;        
        direccionIda = true;  
        delay(1000);         
      }
    }
  }

  else if (efecto == 2) {

    uint32_t colorPares = strip.Color(random(0 , 256), random(0 , 256), random(0 , 256));
    uint32_t colorImpares = strip.Color(random(0 , 256), random(0 , 256), random(0 , 256));

    strip.clear();
    strip.setPixelColor( 0 , colorPares );  strip.setPixelColor( 2 , colorPares );
    strip.setPixelColor( 4 , colorPares );  strip.setPixelColor( 6 , colorPares );
    strip.setPixelColor( 8 , colorPares );  strip.setPixelColor( 10 , colorPares );
    strip.show();
    delay(velocidad);

    strip.clear();
    strip.show();
    delay(velocidad);

    strip.setPixelColor( 1 , colorImpares ); strip.setPixelColor( 3 , colorImpares );
    strip.setPixelColor( 5 , colorImpares ); strip.setPixelColor( 7 , colorImpares );
    strip.setPixelColor( 9 , colorImpares ); strip.setPixelColor( 11 , colorImpares );
    strip.show();
    delay(velocidad);

    strip.clear();
    strip.show();
    delay(velocidad);

    delay(1000); 
  }
}