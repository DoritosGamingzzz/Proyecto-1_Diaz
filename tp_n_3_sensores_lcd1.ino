#include <LiquidCrystal.h>

#define AZUL A2
#define VERDE A3
#define ROJO A4 
#define TEMP A5
#define BUZZ A1

#define ECHO 6
#define TRIG 7
#define MOV 2
#define LUZ A0

LiquidCrystal LCD( 8 , 9 , 10 , 11 , 12 , 13 ); 

void setup()
{

  pinMode( AZUL , OUTPUT );
  pinMode( VERDE , OUTPUT );
  pinMode( ROJO , OUTPUT );
  pinMode( BUZZ , OUTPUT );
  pinMode( TRIG , OUTPUT );
  
  pinMode( TEMP , INPUT );
  pinMode( ECHO , INPUT );
  pinMode( MOV , INPUT );
  pinMode( LUZ , INPUT ); 
  
  LCD.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{

  float lecturaTemp = analogRead(TEMP);
  float voltaje = lecturaTemp * ( 5.0 / 1023.0 );
  float temperatura = ( voltaje - 0.5 ) * 100.0;
  
  bool mov = digitalRead(MOV);    
  
  int lecturaLuz = analogRead(LUZ);
  int porcentajeLuz = map( lecturaLuz , 0 , 1023 , 0 , 100 );
  bool esDeNoche = ( porcentajeLuz < 20 );
  
  digitalWrite( TRIG , LOW );
  delayMicroseconds(2);   
  digitalWrite( TRIG , HIGH );
  delayMicroseconds(10);
  digitalWrite( TRIG , LOW );
  
  float tiempo = pulseIn( ECHO , HIGH );
  float distCM = tiempo * 0.034 / 2.0;
  float distMetros = distCM / 100.0;

  LCD.setCursor(0, 0);
  LCD.print("T:"); LCD.print((int)temperatura); LCD.print("C ");
  if (esDeNoche) {
    LCD.print("NOCHE    ");
  } else {
    LCD.print("DIA      ");
  }
  
  LCD.setCursor(0, 1);
  LCD.print("D:"); LCD.print(distMetros, 1); LCD.print("m ");
  LCD.print("Mov:"); LCD.print(mov ? "SI " : "NO ");

  Serial.print("Temp: "); Serial.print(temperatura);
  Serial.print("C | Noche: "); Serial.print(esDeNoche);
  Serial.print(" | Mov: "); Serial.print(mov);
  Serial.print(" | Dist: "); Serial.print(distMetros);
  Serial.println("m");

  digitalWrite( ROJO , LOW );
  digitalWrite( VERDE , LOW );
  digitalWrite( AZUL , LOW );
  digitalWrite( BUZZ , LOW );

  if (esDeNoche) 
    {
   
    if  (temperatura > 39.0 ) {
      digitalWrite( ROJO , HIGH );
      digitalWrite( BUZZ , HIGH ); 
      delay(200);
      digitalWrite( BUZZ , LOW );
    }
    
    else if ( mov == HIGH ) {
      digitalWrite( ROJO , HIGH );
      digitalWrite( VERDE , HIGH );
      digitalWrite( BUZZ , HIGH ); 
      delay(100);
      digitalWrite( BUZZ , LOW );
    }
  } 
 
  else {
   
    if ( distMetros < 1.0 && distMetros > 0.05 ) {
      digitalWrite( ROJO , HIGH ); 
      
      digitalWrite( BUZZ , HIGH ); delay(150);
      digitalWrite( BUZZ , LOW );  delay(100);
      digitalWrite( BUZZ , HIGH ); delay(150);
      digitalWrite( BUZZ , LOW );
    }
  }
  
  delay(200); 
}