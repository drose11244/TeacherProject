#define TRIGGER 5
#define ECHO    4

int M1_Left = 0; //Direccion
int M1_Right = 2; //Direccion

void turn(int direction)
{
  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction== 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }
    digitalWrite(M1_Left, inPin1);
    digitalWrite(M1_Right , inPin2);
}

void stop(){
    digitalWrite(M1_Left, LOW);
    digitalWrite(M1_Right , LOW);
} 


void setup()
{
  pinMode(M1_Left, OUTPUT);
  pinMode(M1_Right , OUTPUT);
  Serial.begin (9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
}

void loop(){
//  turn (1);
//  delay(1000); //1 sg
// 
//  stop();
//  delay(250); //250ms
//
//  turn(2);
//  delay(1000); //1 sg
// 
//  stop();
//  delay(250); //250ms
  long duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  stop();
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1;
  
  if( distance < 20 ){
    Serial.print("small");
    Serial.print(distance);
    turn (1);
    }
  Serial.print(distance);
  Serial.println("Centimeter:");
  delay(1000);





}

