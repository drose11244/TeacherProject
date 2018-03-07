#include <Servo.h>

Servo myservoA;
Servo myservoB;

int limit =180;
int sped =5;

void setup()
{
  myservoA.attach(15, 500, 2400); // 修正脈衝寬度範圍
  myservoB.attach(13, 500, 2400); // 修正脈衝寬度範圍
  myservoA.write(0);
  myservoB.write(180);
  delay(3000);
  Serial.begin(9600);
}


void loop()
{   
  int cut;
  for(int i = 0; i <= limit;i+=sped)
  {
    cut = limit - i;
//    Serial.println("0-180");
//    Serial.println(cut);
//    Serial.println("---");
//    Serial.println(i);
    myservoA.write(i); 
    myservoB.write(cut);
    delay(20);
  }
  
  for(int i = 180; i >= 0; i-=sped){
    cut = limit -i;
//    Serial.println("180-0");
//    Serial.println(cut);
//    Serial.println("---");
//    Serial.println(i);
    myservoA.write(i);// 使用write，傳入角度，從180度轉到0度
    myservoB.write(cut);
    delay(20);
  }
}
