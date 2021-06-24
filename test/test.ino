/*
// Arduino MKRZero board
  Board : Arduino MKRZero board
  App.  : 4DIGIT 7-SEGMENT MODULE
//출처: https://juahnpop.tistory.com/111 [Blacklog]

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
//int DP = 1;
//int pinA = 2;
//int pinB = 3;
//int pinC = 4;
//int pinD = 5;
//int pinE = 6;
//int pinF = 7;
//int pinG = 8;
//int D1 = 9;
//int D2 = 10;
//int D3 = 11;
//int D4 = 12;

#define segA 2  // 'a' 세그먼트 연결 핀 번호
#define segB 3  // 'b' 세그먼트 연결 핀 번호
#define segC 4  // 'c' 세그먼트 연결 핀 번호
#define segD 5  // 'd' 세그먼트 연결 핀 번호
#define segE 6  // 'e' 세그먼트 연결 핀 번호
#define segF 7  // 'f' 세그먼트 연결 핀 번호
#define segG 8  // 'g' 세그먼트 연결 핀 번호
#define segDP 9 // 'dp' 세그먼트 연결 핀 번호
 
#define digit1 13 // 1st digit 연결 핀번호
#define digit2 12 // 2nd digit 연결 핀번호
#define digit3 11 // 3rd digit 연결 핀번호
#define digit4 10 // 4th digit 연결 핀번호

#define FALSE 0
#define TRUE  1

// main 함수에서 처리 편하게 하기 위해 핀번호 배열을 생성
int num_of_pins = 8;
int fndPort[] = {segA, segB, segC, segD, segE, segF, segG, segDP};
// index 0-9 -> 숫자 1~9
// index 10 -> Blank
int segment[11][8] = {
  { 0, 0, 0, 0, 0, 0, 1, 1 }, // 0
  { 1, 0, 0, 1, 1, 1, 1, 1 }, // 1
  { 0, 0, 1, 0, 0, 1, 0, 1 }, // 2
  { 0, 0, 0, 0, 1, 1, 0, 1 }, // 3
  { 1, 0, 0, 1, 1, 0, 0, 1 }, // 4
  { 0, 1, 0, 0, 1, 0, 0, 1 }, // 5
  { 0, 1, 0, 0, 0, 0, 0, 1 }, // 6
  { 0, 0, 0, 1, 1, 0, 1, 1 }, // 7
  { 0, 0, 0, 0, 0, 0, 0, 1 }, // 8
  { 0, 0, 0, 0, 1, 0, 0, 1 }, // 9
  { 1, 1, 1, 1, 1, 1, 1, 1 }, // 10 - blank
};   

int num_of_pos = 4;
int pos_pins[] = {digit1, digit2, digit3, digit4}; // 몇번째 세그먼트

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
    // SEGMENT 핀 출력모드로 설정
    for(int i = 0 ; i < 8 ; i++){
      pinMode(fndPort[i],OUTPUT);
    }
    // 공통 Digit 핀 출력 모드로 설정
    for(int i = 0 ; i < num_of_pos ; i++){
      pinMode(pos_pins[i], OUTPUT);
    }


    // FND 모두 끄기 - 공통-애노드 타입으로 LOW 출력시 OFF
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
    // 첫째 자리 FND 숫자 1출력
    for(int j = 0 ; j < 8 ; j++){
        digitalWrite(fndPort[j], segment[1][j]); 
    }
    digitalWrite(digit1, HIGH);
    delay(1000);
 
    fndOff(); //fnd 모두 끄기
 
    // 둘째 자리 FND 숫자 2출력
    for(int j = 0 ; j < 8 ; j++){
        digitalWrite(fndPort[j], segment[2][j]); 
    }
    digitalWrite(digit2, HIGH);
    delay(1000);
 
    fndOff(); //fnd 모두 끄기
 
    // 셋째 자리 FND 숫자 3출력
    for(int j = 0 ; j < 8 ; j++){
        digitalWrite(fndPort[j], segment[3][j]); 
    }
    digitalWrite(digit3, HIGH);
    delay(1000);
 
    fndOff(); //fnd 모두 끄기
 
    // 넷째 자리 FND 숫자 4출력
    for(int j = 0 ; j < 8 ; j++){
        digitalWrite(fndPort[j], segment[4][j]); 
    }
    digitalWrite(digit4, HIGH);
    delay(1000);
 
    fndOff(); //fnd 모두 끄기
}
 
void fndOff(){ // FND 모두 끄기
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, LOW);
}
