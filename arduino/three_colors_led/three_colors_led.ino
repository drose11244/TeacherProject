#define LEDR 13 //D0=16=Red
#define LEDG 12 //D1=5=Green
#define LEDB 11 //D2=4=Blue


void turnOff(){
  digitalWrite(LEDR, 255);
  digitalWrite(LEDG, 255);
  digitalWrite(LEDB, 255);

}

void setup() {
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  Serial.begin(115200);
  turnOff();
}

void loop() {
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
