/*
// Arduino MKRZero board
  Board : Arduino MKRZero board
  App.  : 4DIGIT 7-SEGMENT MODULE
//출처: https://popcorn16.tistory.com/164

*/
#include <Adafruit_ZeroFFT.h>
/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---  .
    D   DP
  This example code is in the public domain.
 */
// Pin 1-8 is connected to the 7 segments of the display.
#define segA 2  // 'a' 세그먼트 연결 핀 번호
#define segB 3  // 'b' 세그먼트 연결 핀 번호
#define segC 4  // 'c' 세그먼트 연결 핀 번호
#define segD 5  // 'd' 세그먼트 연결 핀 번호
#define segE 6  // 'e' 세그먼트 연결 핀 번호
#define segF 7  // 'f' 세그먼트 연결 핀 번호
#define segG 8  // 'g' 세그먼트 연결 핀 번호
#define segDP 9 // 'dp' 세그먼트 연결 핀 번호
 
#define digit1 10 // 1st digit 연결 핀번호
#define digit2 11 // 2nd digit 연결 핀번호
#define digit3 12 // 3rd digit 연결 핀번호
#define digit4 13 // 4th digit 연결 핀번호

#define FALSE 0
#define TRUE  1

// main 함수에서 처리 편하게 하기 위해 핀번호 배열을 생성
int FindNumPins[8] = {segA, segB, segC, segD, segE, segF, segG, segDP};
int num_of_pins = 8;
// index 0-9 -> 숫자 1~9
// index 10 -> Blank
int FindSegmentData[11][8] = {
  { 0, 0, 0, 0, 0, 1, 0, 1 }, // 0
  { 1, 0, 0, 1, 1, 1, 1, 1 }, // 1
  { 0, 0, 1, 0, 0, 0, 1, 1 }, // 2
  { 0, 0, 0, 0, 1, 0, 1, 1 }, // 3
  { 1, 0, 0, 1, 1, 0, 0, 1 }, // 4
  { 0, 1, 0, 0, 1, 0, 0, 1 }, // 5
  { 0, 1, 0, 0, 0, 0, 0, 1 }, // 6
  { 0, 0, 0, 1, 1, 1, 0, 1 }, // 7
  { 0, 0, 0, 0, 0, 0, 0, 1 }, // 8
  { 0, 0, 0, 1, 1, 0, 0, 1 }, // 9
  { 1, 1, 1, 1, 1, 1, 1, 1 }, // 10 - blank
};   

int fndDigit[4] = {digit1, digit2, digit3, digit4};
int num_of_pos = 4;

int delayTime = 500;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
    // SEGMENT 핀 출력모드로 설정
    for(int i = 0 ; i < 8 ; i++)
    {
        pinMode(FindNumPins[i],OUTPUT);
    }
    // Digit 핀 출력 모드로 설정
    for(int i = 0 ; i < 4 ; i++)
    {
        pinMode(fndDigit[i],OUTPUT);
        digitalWrite(fndDigit[i],LOW);
//        digitalWrite(fndDigit[i],HIGH);
    }
    Serial.begin(9600);
}

// the loop routine runs over and over again forever:
//void loop() {
//  for(int i = 0 ; i < 11 ; i++){
//    for(int j = 0 ; j < 8 ; j++){
//      digitalWrite(FindNumPins[j], FindSegmentData[i][j]);
////      Serial.print("i ::");
////      Serial.print(i);
////      Serial.print(", j ::");
////      Serial.println(j); 
//  }
//  
//  //        digitalWrite(fndDigit[i], LOW);
//  fndOn(i);
//  Serial.println("fndOn");
//  delay(delayTime);
//  fndOff();
//  Serial.println("fndOff");
//  //        delay(delayTime);
//  //        
//    }
////    if(delayTime > 1)
////        delayTime = delayTime * 0.9;
////    else
////        delayTime = 1;
//
//}

void loop() {
  int num[] = {9, 8, 7, 6};
  digits_4_seven_segment(num);
}

  

void fndOn(int i){ // FND 모두 끄기
    if (i == 0){
      digitalWrite(digit1, LOW);
//      for(int j = 0 ; j < 8 ; j++){
//        digitalWrite(FindNumPins[j], FindSegmentData[10][j]);
//        }
      digitalWrite(digit2, HIGH);
      digitalWrite(digit3, HIGH);
      digitalWrite(digit4, HIGH);
    }else if (i == 1){
      digitalWrite(digit2, LOW);
//      for(int j = 0 ; j < 8 ; j++){
//        digitalWrite(FindNumPins[j], FindSegmentData[10][j]);
//        }
      digitalWrite(digit1, HIGH);
      digitalWrite(digit3, HIGH);
      digitalWrite(digit4, HIGH);
    }else if (i == 2){
      digitalWrite(digit3, LOW);
//      for(int j = 0 ; j < 8 ; j++){
//        digitalWrite(FindNumPins[j], FindSegmentData[10][j]);
//        }
      digitalWrite(digit1, HIGH);
      digitalWrite(digit2, HIGH);      
      digitalWrite(digit4, HIGH);
    }else if (i == 3){
      digitalWrite(digit4, LOW);
//      for(int j = 0 ; j < 8 ; j++){
//        digitalWrite(FindNumPins[j], FindSegmentData[10][j]);
//        }
      digitalWrite(digit1, HIGH);
      digitalWrite(digit2, HIGH);
      digitalWrite(digit3, HIGH);      
    }
}

void fndOff(){ // FND 모두 끄기
    digitalWrite(digit1, HIGH);
    digitalWrite(digit2, HIGH);
    digitalWrite(digit3, HIGH);
    digitalWrite(digit4, HIGH);
}

// 원하는 위치에 표시되도록 set
void set_position(int pos){
  for(int i = 0; i < 4; i++) {
    if(i == pos){
      digitalWrite(fndDigit[i], LOW);
    } else {
      digitalWrite(fndDigit[i], HIGH);
    }
  }
}

// 원하는 숫자 표시
void set_number(int number){
  for(int i=0;i<num_of_pins;++i){ 
    FindSegmentData[number][i] ? digitalWrite(FindNumPins[i], HIGH) : digitalWrite(FindNumPins[i], LOW); 
  }
}

// 원하는 위치, 원하는 숫자를 표시
void set_seven_segment(int pos, int number){
  set_position(pos);
  set_number(number);
}

// 입력된 4자리 숫자를 세그먼트에 표시
void digits_4_seven_segment(int num[]){
  for(int i=0;i<num_of_pos;++i){
    set_seven_segment(i,num[i]);
    delay(delayTime);
  }
}
