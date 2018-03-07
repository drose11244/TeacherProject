#include <Servo.h>

Servo myservo;

void setup()
{
  myservo.attach(15, 500, 2400); // 修正脈衝寬度範圍
//  myservo.write(90); // 一開始先置中90度
  delay(3000);
}


void loop()
{
    for(int i = 0; i <= 180; i+=1){
    myservo.write(i); // 使用write，傳入角度，從0度轉到180度
    delay(20);
  }
  for(int i = 180; i >= 0; i-=1){
    myservo.write(i);// 使用write，傳入角度，從180度轉到0度
    delay(20);
  }
}
