#include <Servo.h>

#define LEDR 14
#define LEDG 12
#define LEDB 13


Servo myservo;


void turnOff(){
  digitalWrite(LEDR, 255);
  digitalWrite(LEDG, 255);
  digitalWrite(LEDB, 255);

}
void servo(){
  for(int i = 0; i <= 180; i+=1){
    myservo.write(i); // 使用write，傳入角度，從0度轉到180度
    delay(20);
  }
  for(int i = 180; i >= 0; i-=1){
    myservo.write(i);// 使用write，傳入角度，從180度轉到0度
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

void setup() {
  myservo.attach(15, 500, 2400); // 修正脈衝寬度範圍
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  Serial.begin(115200);
  turnOff();
}

void loop() {
  led();
  servo();  
}
