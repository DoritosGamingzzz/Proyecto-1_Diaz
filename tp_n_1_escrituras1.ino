#define R1 5
#define G1 7
#define B1 6

#define R2 4
#define G2 2
#define B2 3

#define R3 9
#define G3 11
#define B3 10

#define Buzz 12


void setup()
{
  pinMode( R1 , OUTPUT );
  pinMode( G1 , OUTPUT );
  pinMode( B1 , OUTPUT );
  
  pinMode( R2 , OUTPUT );
  pinMode( G2 , OUTPUT );
  pinMode( B2 , OUTPUT );
  
  pinMode( R3 , OUTPUT );
  pinMode( G3 , OUTPUT );
  pinMode( B3 , OUTPUT );
  
  pinMode( Buzz , OUTPUT );
}

void loop()
{
  sonarBuzzer();
  
  analogWrite( G3 , 0 );
  analogWrite( B3 , 0 );
  
  analogWrite( R1 , 255 );
  delay( 1000 );
  
  sonarBuzzer();
  
  analogWrite( R1 , 0 );
  
  digitalWrite( R2 , HIGH );
  digitalWrite( B2 , HIGH );
  delay( 1000 );
  
  sonarBuzzer();
  
  digitalWrite( R2 , LOW );
  digitalWrite( B2 , LOW );
  
  analogWrite( G3 , 60 );
  analogWrite( B3 , 60 );
  delay( 1000 );
}

void sonarBuzzer() 
{
  analogWrite( Buzz , 128 ); 
  delay( 90 );               
  analogWrite( Buzz , 0 );   
}