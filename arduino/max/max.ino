#include <Servo.h>

#define TRIGGER 5
#define ECHO    4

#define LEDR 14
#define LEDG 12
#define LEDB 13

int M1_Left = 0; //Direccion
int M1_Right = 2; //Direccion

Servo myservoA;
Servo myservoB;
int limit =180;
int sped =5;

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
void turnOff(){
  digitalWrite(LEDR, 255);
  digitalWrite(LEDG, 255);
  digitalWrite(LEDB, 255);

}
void servo(){
  int cut;
  for(int i = 0; i <= limit;i+=sped)
  {
    cut = limit - i;
    myservoA.write(i); 
    myservoB.write(cut);
    delay(20);
  }
  
  for(int i = 180; i >= 0; i-=sped){
    cut = limit -i;
    myservoA.write(i);// 使用write，傳入角度，從180度轉到0度
    myservoB.write(cut);
    delay(20);
  }
}
void led(){
    digitalWrite(LEDR, 0);
    delay(1000);
    turnOff();
    delay(1000);
    digitalWrite(LEDG, 0);
    delay(1000);
    turnOff();
    delay(1000);
    digitalWrite(LEDB, 0);
    delay(1000);
    turnOff();
    delay(1000);
}

void setup()
{
  pinMode(M1_Left, OUTPUT);
  pinMode(M1_Right , OUTPUT);
  
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);

  myservoA.attach(9, 500, 2400); // 修正脈衝寬度範圍
  myservoB.attach(10, 500, 2400); // 修正脈衝寬度範圍
  myservoA.write(0);
  myservoB.write(180);

  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  turnOff();
  Serial.begin (9600);
  delay(3000);
}

void ul_motoer(){
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
    delay(1000);
    stop();
    }
  Serial.print(distance);
  Serial.println("Centimeter:");
  delay(1000);
  }

void loop(){

  servo();
  delay(1000);
  led();
  delay(1000);
  ul_motoer();
  delay(1000);
}

