int M1_Left = 0; //Direccion
int M1_Right = 2; //Direccion

void setup()
{
  pinMode(M1_Left, OUTPUT);
  pinMode(M1_Right , OUTPUT);
}

void loop(){
  turn (1);
  delay(1000); //1 sg
 
  stop();
  delay(250); //250ms

  turn(2);
  delay(1000); //1 sg
 
  stop();
  delay(250); //250ms
}


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
