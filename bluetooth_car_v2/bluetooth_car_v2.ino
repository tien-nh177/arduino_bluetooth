#include <AFMotor.h>
byte blue = 0;              //Biến nhận dữ liệu qua bluetooth
AF_DCMotor motor1(1); //Khai báo động cơ 1
AF_DCMotor motor2(2); //Khai báo động cơ 2
AF_DCMotor motor3(3); //Khai báo động cơ 3
AF_DCMotor motor4(4); //Khai báo động cơ 4
void setup() {
    Serial.begin(9600);     //Mở cổng Serial
    motor1.setSpeed(255);   
    motor2.setSpeed(255);
    motor3.setSpeed(255);   
    motor4.setSpeed(255);
}
void loop() 
{

if(Serial.available() > 0){
    blue = Serial.read();   // Đọc giá trị nhận được từ bluetooth
 } else
      blue = 0;
 
    Serial.println(blue);
switch (blue) {
  case '1':
    //motor1.run(FORWARD);
    //motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    break;
  case '2':
    //motor1.run(BACKWARD);
    //motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    break;
  case '3':
    //motor1.run(BACKWARD);
    //motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(FORWARD);
    break;
  case '4':
    //motor1.run(FORWARD);
    //motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(BACKWARD);
    break;
  case '6':
    //motor1.run(RELEASE);
    //motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    break;
  
  default:
   break;
}
} 
