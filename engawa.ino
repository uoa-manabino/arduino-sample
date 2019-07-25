#include <Servo.h>

#define echoPin_in 2 // Echo Pin sensor_in
#define trigPin_in 3 // Trigger Pin sensor_in
#define echoPin_out 2 // Echo Pin sensor_out
#define trigPin_out 3 // Trigger Pin sensor_out
#define brightPin A2
#define AKARUSA 50
#define SHIKIITI 100
int member = 0,corrent = 0,flg;
double bright;

void setup() {
  // put your setup code here, to run once:
Serial.begin( 9600 );
pinMode( echoPin_in, INPUT );
pinMode( trigPin_in, OUTPUT );
pinMode( echoPin_out, INPUT );
pinMode( trigPin_out, OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  member = ultrasonic();
  bright = getBrightness();
  if(member > 0 && bright > AKARUSA){
    flg = 1;
    switching();
  }
  if(member == 0){
    flg = 0;
    switching();
  }
}

double getDistance(int pin){    // pin = 1 ... sensor_in, pin = 2 ... sensor_out
  double Duration = 0; //受信した間隔
  double Distance = 0; //距離
  if(pin == 1){ // sensor_in
    digitalWrite(trigPin_in, LOW); 
    delayMicroseconds(2); 
    digitalWrite( trigPin_in, HIGH ); //超音波を出力
    delayMicroseconds( 10 ); //
    digitalWrite( trigPin_in, LOW );
    Duration = pulseIn( echoPin_in, HIGH ); //センサからの入力
  }else{ // getDistance(2)
    digitalWrite(trigPin_out, LOW); 
    delayMicroseconds(2); 
    digitalWrite( trigPin_out, HIGH ); //超音波を出力
    delayMicroseconds( 10 ); //
    digitalWrite( trigPin_out, LOW );
    Duration = pulseIn( echoPin_out, HIGH ); //センサからの入力
  }
  if (Duration > 0) {
    Duration = Duration/2; //往復距離を半分にする
    Distance = Duration*340*100/1000000; // 音速を340m/sに設定
    Serial.print("Distance:");
    Serial.print(Distance);
  }
  return Distance;
}

int ultrassonic(){
  //超音波センサーを使用して人の出入りを検出する
  if(getDistance(1) > SHIKIITI){
    while(1){
      if(getDistance(1) < SHIKIITI)break;
      if(getDistance(2) > SHIKIITI){
        while(1){
          if(senfor_in < SHIKIITI){
            menber--:
            return memher; 
          }else if(getDistance(2) < SHIKIITI) return member;
        }
      }
    }
  }else if(getDistance(2) > SHIKIITI){
     while(1){
      if(getDistance(2) < SHIKIITI)break;
      if(getDistance(1) > SHIKIITI){
        while(1){
          if(senfor_out < SHIKIITI){
            menber++:
            return memher; 
          }else if(getDistance(1) < SHIKIITI) return member;
        }
      }
    }
}

double getBrightness(){
  // 明るさセンサーを使用して外の明るさを検知する
  bright = analogRead(brightPin);
  return bright;
}

int switching(){
  if(flg == 1 && corrent == 0){
    if(bright < AKARUSA){
      servo.switchOn();
      corrent = 1;
    }
  }
  if(flg == 0 && corrent == 1){
    servo.switchOff();
    corrent = 0:
  }
  return current;
}


static Servo servo;
static int pinNum = 0;
static int currentState = 0;
void switchInit(const int pin, const int state) {
  currentState = state;
  pinNum = pin;

  servo.attach(pinNum);
  (currentState == 0) ? switchOn(0) : switchOff(0);
}


void switchOn(const int offset) {
  servo.write((75 + offset)); 
}

void switchOff(const int offset) {
  servo.write((105 + offset)); 
}
