#include <AFMotor.h>
AF_DCMotor motor1(1, MOTOR12_64KHZ); // tạo động cơ #1, 64KHz pwm   
AF_DCMotor motor2(2, MOTOR12_64KHZ); // tạo động cơ #2, 64KHz pwm   
AF_DCMotor motor3(3, MOTOR12_64KHZ); // tạo động cơ #3, 64KHz pwm   
AF_DCMotor motor4(4, MOTOR12_64KHZ); // tạo động cơ #4, 64KHz pwm  

const int GND1 = 22;     // 
const int GND2 = 23;     // 
/*const int nhanSauT = 26;     // 
const int nhanTruocT = 27;     // 
const int nhanSauP = 28;     // 
const int nhanTruocP = 29;     // 
const int denpha = 53;     // */
const int echo = 24;     // 
const int trig = 25;     // 

char state;

void setup() {                

// Ngat 0
   pinMode(2, INPUT_PULLUP); // sử dụng điện trở kéo lên cho chân số 2, ngắt 0
   attachInterrupt(0, lui, LOW); // gọi hàm quayphai liên tục khi còn nhấn nút
   
// Ngat 1
   pinMode(3, INPUT_PULLUP); // sử dụng điện trở kéo lên cho chân số 3, ngắt 1
   attachInterrupt(1, lui, LOW); // gọi hàm quayphai liên tục khi còn nhấn nút
   
    motor1.setSpeed(255);     // chọn tốc độ 
    motor2.setSpeed(255);     // chọn tốc độ 
    motor3.setSpeed(255);     // chọn tốc độ 
    motor4.setSpeed(255);     // chọn tốc độ 
 Serial.begin(9600); // Kết nối bluetooth module ở tốc độ 9600
pinMode(GND1,OUTPUT);
pinMode(GND2,OUTPUT);  
/*pinMode(nhanSauT,OUTPUT);   
pinMode(nhanTruocT,OUTPUT);  
pinMode(nhanSauP,OUTPUT);  
pinMode(nhanTruocP,OUTPUT);  
pinMode(denpha,OUTPUT);  */
pinMode(trig,OUTPUT);  
pinMode(echo,INPUT);  
}  
 
void lui()
{
    motor1.run(BACKWARD);     // động cơ 1 lùi  
    motor3.run(BACKWARD);      // động cơ 3 lùi 
    //digitalWrite(nhanSauP, HIGH);
   // digitalWrite(nhanSauT, HIGH);    // Bật 2 led Sau
}


void loop() {  
digitalWrite(GND1,LOW); 
digitalWrite(GND2,LOW);   //Cai dat chan 22, 23 la GND

 if(Serial.available() > 0)
 {
   // Đọc giá trị nhận được từ bluetooth
   state = Serial.read();
 } else 
   state = 0;
 
 Serial.println(state);


switch (state) {
  case '6':
//Dung
    motor1.run(RELEASE);      //   dừng động cơ
    motor2.run(RELEASE);      //   dừng động cơ
    motor3.run(RELEASE);      //   dừng động cơ
    motor4.run(RELEASE);      //   dừng động cơ  
    /*digitalWrite(nhanTruocT, LOW);
    digitalWrite(nhanTruocP, LOW);
    digitalWrite(nhanSauT, LOW);
    digitalWrite(nhanSauP, LOW);*/
    break;
    
  case '1':
//xe Tien    
    motor1.run(FORWARD);      // động cơ 1 tiến 
    motor3.run(FORWARD);      // động cơ 3 tiến  
    /*digitalWrite(nhanTruocT, HIGH);
    digitalWrite(nhanTruocP, HIGH);   // Bật 2 led trước*/
    break;
    
  case '4':
//xe Re trai   
    motor3.run(BACKWARD);     // động cơ 3 lùi  
    motor1.run(FORWARD);      // động cơ 1 tiến 
    /*digitalWrite(nhanSauP, HIGH);
    digitalWrite(nhanTruocP, HIGH);   // Bật 2 led Phải*/
    break;
    
  case '3':
//xe Re phai   
    motor1.run(BACKWARD);     // động cơ 1 lùi  
    motor3.run(FORWARD);      // động cơ 3 tiến 
    /*digitalWrite(nhanTruocT, HIGH);
    digitalWrite(nhanSauT, HIGH);   // Bật 2 led trái*/
    break;
    
  case '2':
//xe Lui
    motor1.run(BACKWARD);     // động cơ 1 lùi  
    motor3.run(BACKWARD);      // động cơ 3 lùi 
    /*digitalWrite(nhanSauP, HIGH);
    digitalWrite(nhanSauT, HIGH);   // Bật 2 led Sau*/
    break;
    
 /* case '6':
//den len    
    motor4.run(FORWARD);      // động cơ 4 tiến 
    break;
    
  case '8':
//den xuong   
    motor4.run(BACKWARD);     // động cơ 4 lùi  
    break;
    
  case '7':
//den quay trai   
    motor2.run(BACKWARD);      // động cơ 2 tiến  
    break;
    
  case '9':
//den quay phai   
    motor2.run(FORWARD);      // động cơ 2 tiến  
    break;
    */
 /* case '5':
//Bật đèn pha
  digitalWrite(denpha, HIGH);
    break;
    
  case 'A':
//Tắt đèn pha
  digitalWrite(denpha, LOW);
    break;
    
  case 'B':
//Bật đèn led
    digitalWrite(nhanTruocT, HIGH);
    digitalWrite(nhanTruocP, HIGH);
    digitalWrite(nhanSauT, HIGH);
    digitalWrite(nhanSauP, HIGH);
    break;
    
  case 'C':
//Tăt đèn led
    digitalWrite(nhanTruocT, LOW);
    digitalWrite(nhanTruocP, LOW);
    digitalWrite(nhanSauT, LOW);
    digitalWrite(nhanSauP, LOW);
    break; */
}

}
