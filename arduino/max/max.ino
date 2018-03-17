//步進馬達需要的標頭檔
#include <Servo.h>

//宣告超音波腳位
#define TRIGGER 17
#define ECHO    16

//宣告LED腳位
#define LED_C_Red 13
#define LED_C_Green 12 
#define LED_C_Blue 11

#define LED_B_Red 10
#define LED_B_Green 9 
#define LED_B_Blue 8

#define LED_A_Red 7
#define LED_A_Green 6 
#define LED_A_Blue 5

//宣告小馬達腳位
#define M1_Left 18
#define M1_Right 19

//宣告步進馬達腳位
#define serA =14;
#define serB =15;

//宣告步進馬達
Servo myservoA;
Servo myservoB;

//int M1_Left = 18;
//int M1_Right = 19;

//int serA =14;
//int serB =15;

//Servo myservoA;
//Servo myservoB;




//小馬達轉動
void turn(int direction)
{

  // 宣告 pin 腳位電壓
  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;
  
  //轉動方向
  if(direction== 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }
  // 將狀態寫入腳位
  digitalWrite(M1_Left, inPin1);
  digitalWrite(M1_Right , inPin2);
}

//小馬達停止轉動
void stop(){
    digitalWrite(M1_Left, LOW);
    digitalWrite(M1_Right , LOW);
} 

//步進馬達
void servo(){
  
  
  int limit =180;
  int sped =5;

  int Redirection;
  for(int i = 0; i <= limit;i+=sped)
  {
    
    //計算反方向
    Redirection = limit - i;
    myservoA.write(i); 
    myservoB.write(Redirection);
    delay(20);
  }
  
  for(int i = 180; i >= 0; i-=sped){
    cut = limit -i;
    myservoA.write(i);
    myservoB.write(Redirection);
    delay(20);
  }
}



void setup()
{
    //初始化，將LED小馬達腳位註冊為輸出
    pinMode(M1_Left, OUTPUT);
    pinMode(M1_Right , OUTPUT);

    //初始化，將超音波 TRIGGER腳位註冊為輸出
    pinMode(TRIGGER, OUTPUT);
    //初始化，將超音波 ECHO腳位註冊為輸入
    pinMode(ECHO, INPUT);
    
    //修正脈衝寬度範圍
    myservoA.attach(serA, 500, 2400); 
    myservoB.attach(serB, 500, 2400); 
    
    //步進馬達角度 從0~180度 
    //使用write，讓步進A傳入角度為0。
    myservoA.write(0);
    //使用write，讓步進A傳入角度為180。
    myservoB.write(180);

    //初始化，將LED腳位註冊為輸出
    pinMode(LED_A_Red, OUTPUT);
    pinMode(LED_A_Green, OUTPUT);
    pinMode(LED_A_Blue, OUTPUT);

    pinMode(LED_B_Red, OUTPUT);
    pinMode(LED_B_Green, OUTPUT);
    pinMode(LED_B_Blue, OUTPUT);

    pinMode(LED_C_Red, OUTPUT);
    pinMode(LED_C_Green, OUTPUT);
    pinMode(LED_C_Blue, OUTPUT); 
    
    //設定序列 鮑率
    Serial.begin (9600);
     
     
    //將所有LED先關閉
    turnOff();
}

//超音波與小馬達
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



}

