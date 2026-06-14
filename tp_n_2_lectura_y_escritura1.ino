#define R 9

#define B 10

#define G 11



#define BUZZER 3

#define BOTON 2



#define POT_TIEMPO A0

#define POT_R A1

#define POT_G A2

#define POT_B A3



bool funcionando = true;

bool estadoAnterior = HIGH;



void setup()

{

  pinMode( R , OUTPUT );

  pinMode( G , OUTPUT );

  pinMode( B , OUTPUT );



  pinMode( BUZZER , OUTPUT );

  pinMode( BOTON , INPUT );



  Serial.begin(9600);

}



void loop()

{

  bool estadoActual = digitalRead(BOTON);



  if (estadoAnterior == LOW && estadoActual == HIGH)

  {

    funcionando = funcionando == 0;

    delay(200);

  }



  estadoAnterior = estadoActual;



  int tiempo = analogRead(POT_TIEMPO) * 3000L / 1023;



  int rojo = analogRead(POT_R) * 255L / 1023;

  int verde = analogRead(POT_G) * 255L / 1023;

  int azul = analogRead(POT_B) * 255L / 1023;



  Serial.print("Tiempo: ");

  Serial.println(tiempo / 1000.0);



  Serial.print("R: ");

  Serial.println(rojo);



  Serial.print("G: ");

  Serial.println(verde);



  Serial.print("B: ");

  Serial.println(azul);



  Serial.println();



  if (funcionando == 0)

  {

    analogWrite( R , 0 );

    analogWrite( G , 0 );

    analogWrite( B , 0 );

    return;

  }



  analogWrite( R , rojo );

  analogWrite( G , verde );

  analogWrite( B , azul );



  delay(tiempo);



  tone( BUZZER , 1000 );



  for (int i = 0; i < 3; i++)

  {

    analogWrite( R , 0 );

    analogWrite( G , 0 );

    analogWrite( B , 0 );



    delay(100);



    analogWrite( R , rojo );

    analogWrite( G , verde );

    analogWrite( B , azul );



    delay(100);

  }



  noTone(BUZZER);

}