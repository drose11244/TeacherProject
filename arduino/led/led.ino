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

void setup(){
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
    Serial.begin(115200);

    //將所有LED先關閉
    turnOff();
}

void loop(){
    //打開LED A 藍色
    turnLED("A","blue");
    //停一秒
    delay(1000);
    //打開LED B 綠色
    turnLED("B","green");
    //停一秒
    delay(1000);
    //打開LED C 紅色
    turnLED("C","red");
    //停一秒
    delay(1000);
}
