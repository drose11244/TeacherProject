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
#define serA 14
#define serB 15

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
    Redirection = limit -i;
    myservoA.write(i);
    myservoB.write(Redirection);
    delay(20);
  }
}

//關閉所有的LED
void turnOff(){
   turnOff_LED_A();
   turnOff_LED_B();
   turnOff_LED_C();

}

//只關閉腳位LED_A
void turnOff_LED_A(){
  //腳為寫入
  //LED_A_Red 為腳位 7
  //255 為關閉
  digitalWrite(LED_A_Red, 255);
  digitalWrite(LED_A_Green, 255);
  digitalWrite(LED_A_Blue, 255);

}

//只關閉腳位LED_B
void turnOff_LED_B()
{
  digitalWrite(LED_B_Red, 255);
  digitalWrite(LED_B_Green, 255);
  digitalWrite(LED_B_Blue, 255);

}

//只關閉腳位LED_C
void turnOff_LED_C()
{
  digitalWrite(LED_C_Red, 255);
  digitalWrite(LED_C_Green, 255);
  digitalWrite(LED_C_Blue, 255);
}

//只有打開腳位LED_A
//可以輸入的顏色： red (紅色)  blue（藍色） green（綠色）
//example: 
//turnOn_A("red"); //打開腳位LED_A，  紅色
void turnOn_A(String color){

    //初始化腳位，就是將腳LED_A先關閉
    turnOff_LED_A();

    if(color == "red"){
     //顯示在序列阜
     Serial.println("red");
     //腳為寫入
     //LED_A_Red 為腳位 7
     //0 為打開
     digitalWrite(LED_A_Red, 0);
    }else if(color == "blue"){
     Serial.println("blue");
     digitalWrite(LED_A_Blue, 0);
    }else if(color == "green"){
     Serial.println("green");
     digitalWrite(LED_A_Green,0);
    }else{
     Serial.println("Error_LED_A");
     turnOff();
    }
}


//只有打開腳位LED_B
//可以輸入的顏色： red (紅色)  blue（藍色） green（綠色）
//example: 
//turnOn_B("red"); //打開腳位LED_B，  紅色

void turnOn_B(String color){
    //Serial.print(color);
    turnOff_LED_B();

    if(color == "red"){
     Serial.println("red");
     digitalWrite(LED_B_Red, 0);
    }else if(color == "blue"){
     Serial.println("blue");
     digitalWrite(LED_B_Blue, 0);
    }else if(color == "green"){
     Serial.println("green");
     digitalWrite(LED_B_Green,0);
    }else{
     Serial.println("Error_LED_B");
     turnOff();
    }
}

//只有打開腳位LED_C
//可以輸入的顏色： red (紅色)  blue（藍色） green（綠色）
//example: 
//turnOn_C("red"); //打開腳位LED_C，  紅色


void turnOn_C(String color){
    //Serial.print(color);
    turnOff_LED_C();

    if(color == "red"){
     Serial.println("red");
     digitalWrite(LED_C_Red, 0);
    }else if(color == "blue"){
     Serial.println("blue");
     digitalWrite(LED_C_Blue, 0);
    }else if(color == "green"){
     Serial.println("green");
     digitalWrite(LED_C_Green,0);
    }else{
     Serial.println("Error_LED_C");
     turnOff();
    }
}

//可以打開任何一個LED與顏色
//可以輸入的顏色： red (紅色)  blue（藍色） green（綠色）
//example: 
//turnLED("A","blue"); //打開腳位LED_A，  藍色

void turnLED(String pos,String color){
    Serial.println(pos);
    Serial.println(color);
    turnOff();
    if( pos == "A"){
      Serial.println("A");
      turnOn_A(color);
    }else if( pos == "B"){
      Serial.println("B");
      turnOn_B(color);
    }else if( pos == "C"){
      Serial.println("C");
      turnOn_C(color);
    }else {
      Serial.println("Error_LED");
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
    
    stop();
    long duration, distance;
     
    //觸發TRIGGER腳位
    digitalWrite(TRIGGER, LOW);
   
    //延誤2微秒（10的6次方）
    delayMicroseconds(2);
  
    //TRIGGER腳位將會發送信號
    digitalWrite(TRIGGER, HIGH);
    //延誤10微秒
    delayMicroseconds(10); 
    
    
    //TRIGGER關閉
    digitalWrite(TRIGGER, LOW);

    // 計算高電位的持續時間
    duration = pulseIn(ECHO, HIGH);
    
    //距離 = (時間 / 2(來回)) / 29.1 m/s 轉換cm/us 
    distance = (duration/2) / 29.1;
    
    //如果距離小於20
    if( distance < 20 ){
      Serial.print("small");
      Serial.print(distance);
      //轉動馬達
      turn (1);
      delay(1000);
      stop();
    }
    
    stop();
    Serial.print(distance);
    Serial.println("Centimeter:");
    delay(1000);
  }

void loop(){

    

    servo();
    ul_motoer();
    //打開LED A 藍色
    turnLED("A","blue");
    //停一秒
    delay(1000);
    //打開LED A 綠色
    turnLED("A","green");
    //停一秒
    delay(1000);
    //打開LED A 紅色
    turnLED("A","red");
    //停一秒
    delay(1000);
   
    //打開LED B 藍色
    turnLED("B","blue");
    //停一秒
    delay(1000);
    //打開LED B 綠色
    turnLED("B","green");
    //停一秒
    delay(1000);
    //打開LED B 紅色
    turnLED("B","red");
    //停一秒
    delay(1000);

    //打開LED C 藍色
    turnLED("C","blue");
    //停一秒
    delay(1000);
    //打開LED C 綠色
    turnLED("C","green");
    //停一秒
    delay(1000);
    //打開LED C 紅色
    turnLED("C","red");
    //停一秒
    delay(1000);

}

