/*
// Arduino MKRZero board
  Board : Arduino MKRZero board
  App.  : 4DIGIT 7-SEGMENT MODULE
//출처: https://juahnpop.tistory.com/111 [Blacklog]

*/
//#include <Adafruit_ZeroFFT.h>
/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
G |   | B
  | F |
   ---
E |   | C
  |   |
   ---  .
    D   DP
  This example code is in the public domain.
 */
 
// 핀 번호 선언

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
#define TRUE 1

int pos_pins[] = {digit1,digit2,digit3,digit4}; // 몇번째 세그먼트
int num_of_pos = 4;
int pins[] = {segA, segB, segC, segD, segE, segF, segG, segDP}; // 세그먼트 a, b, c, d, e, f, g, dp
int num_of_pins = 8;
int delaytime = 5;

// 세그먼트에 표시 할 숫자
bool segment[10][8] = {
  { FALSE,  FALSE,  FALSE,  FALSE,  FALSE,  TRUE,  FALSE,   TRUE }, // 0
  { TRUE,   FALSE,  FALSE,  TRUE,   TRUE,   TRUE,   TRUE,   TRUE }, // 1
  { FALSE,  FALSE,  TRUE,   FALSE,  FALSE,  FALSE,   TRUE,  TRUE }, // 2
  { FALSE,  FALSE,  FALSE,  FALSE,  TRUE,   FALSE,   TRUE,  TRUE }, // 3
  { TRUE,   FALSE,  FALSE,  TRUE,   TRUE,   FALSE,  FALSE,  TRUE }, // 4
  { FALSE,  TRUE,   FALSE,  FALSE,  TRUE,   FALSE,  FALSE,  TRUE }, // 5
  { FALSE,  TRUE,   FALSE,  FALSE,  FALSE,  FALSE,  FALSE,  TRUE }, // 6
  { FALSE,  FALSE,  FALSE,  TRUE,   TRUE,   TRUE,  TRUE,   TRUE }, // 7
  { FALSE,  FALSE,  FALSE,  FALSE,  FALSE,  FALSE,  FALSE,  TRUE }, // 8
  { FALSE,  FALSE,  FALSE,  FALSE,  TRUE,   FALSE,  FALSE,  TRUE }, // 9
};
bool segment_dot[10][8] = {
  { FALSE,  FALSE,  FALSE,  FALSE,  FALSE,  TRUE,  FALSE,   FALSE }, // 0.
  { TRUE,   FALSE,  FALSE,  TRUE,   TRUE,   TRUE,   TRUE,   FALSE }, // 1.
  { FALSE,  FALSE,  TRUE,   FALSE,  FALSE,  FALSE,   TRUE,  FALSE }, // 2.
  { FALSE,  FALSE,  FALSE,  FALSE,  TRUE,   FALSE,   TRUE,  FALSE }, // 3.
  { TRUE,   FALSE,  FALSE,  TRUE,   TRUE,   FALSE,  FALSE,  FALSE }, // 4.
  { FALSE,  TRUE,   FALSE,  FALSE,  TRUE,   FALSE,  FALSE,  FALSE }, // 5.
  { FALSE,  TRUE,   FALSE,  FALSE,  FALSE,  FALSE,  FALSE,  FALSE }, // 6.
  { FALSE,  FALSE,  FALSE,  TRUE,   TRUE,   TRUE,  TRUE,   FALSE }, // 7.
  { FALSE,  FALSE,  FALSE,  FALSE,  FALSE,  FALSE,  FALSE,  FALSE }, // 8.
  { FALSE,  FALSE,  FALSE,  FALSE,  TRUE,   FALSE,  FALSE,  FALSE }, // 9.
};

bool segment_blank[1][8] = {
  { TRUE,  TRUE,  TRUE,  TRUE,  TRUE,  TRUE,  TRUE,   TRUE }, // 0.
};


void setup() {
  for(int i=0; i<num_of_pos; i++) {
     pinMode(pos_pins[i], OUTPUT);
  }
  for(int i=0; i<num_of_pins; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  //int num[] = {9, 8, 7, 6};
  //int num[] = {5, 4, 3, 2};
  int num[] = {3, 2, 1, 0};
  digits_4_seven_segment(num);
}

// 원하는 위치에 표시되도록 set
void set_position(int pos){
  for(int i = 0; i < 4; i++) {
    if(i == pos){
      digitalWrite(pos_pins[i], LOW);
    } else {
      digitalWrite(pos_pins[i], HIGH);
    }
  }
}

// 원하는 숫자 표시
void set_number(int number){
  for(int i=0;i<num_of_pins;++i){ 
    segment[number][i] ? digitalWrite(pins[i], HIGH) : digitalWrite(pins[i], LOW); 
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
    delay(delaytime);
  }
}
