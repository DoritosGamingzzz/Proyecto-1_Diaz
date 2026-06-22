#include <LiquidCrystal.h>

#define MSG_LUZ "El nivel de luz actual es: "
#define MSG_TEMP " y la temperatura actual: "
#define SIMBOLO_C "ºc"

const int PIN_LUZ = A0;   
const int PIN_TEMP = A5; 

const int LED_ROJO = A4;
const int LED_VERDE = A3;
const int LED_AZUL = A2;

void setup() {
  
  pinMode( LED_ROJO , OUTPUT );
  pinMode( LED_VERDE , OUTPUT );
  pinMode( LED_AZUL , OUTPUT );

  pinMode( PIN_LUZ , INPUT );
  pinMode( PIN_TEMP , INPUT );

  Serial.begin(9600);
}

void loop() {
  
  int lecturaTemp = analogRead(PIN_TEMP);
  float voltaje = lecturaTemp * ( 5.0 / 1023.0 );
  float temperatura = ( voltaje - 0.5 ) * 100.0;

  int lecturaLuz = analogRead(PIN_LUZ);
  int porcentajeLuz = map( lecturaLuz , 0 , 1023 , 100 , 0 );

  Serial.print(MSG_LUZ);
  Serial.print(porcentajeLuz);
  Serial.print(MSG_TEMP);
  Serial.print(temperatura);
  Serial.println(SIMBOLO_C);
 
  digitalWrite( LED_ROJO , LOW );
  digitalWrite( LED_VERDE , LOW );
  digitalWrite( LED_AZUL , LOW );

  if ( porcentajeLuz >= 30 && porcentajeLuz <= 70 ){
    if ( temperatura > 90.0 ) {
      digitalWrite( LED_ROJO , HIGH );  
    } 
    else if ( temperatura < 18.0 ) {
      digitalWrite( LED_AZUL , HIGH );
    } 
    else if ( temperatura >= 18.0 && temperatura <= 90.0 ) {
      digitalWrite( LED_VERDE , HIGH ); 
    }

  }

  delay(500); 
}