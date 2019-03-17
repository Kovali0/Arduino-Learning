#include <ISADefinitions.h>
#include <ISAButtons.h>
#include <stdio.h>
#include <string.h>
ISAButtons btn;
using namespace std;

void setup() {
  btn.init();
  for(int l=0; l<8 ;l++){
    pinMode(LEDS[l],OUTPUT);
  }
  int number=0;
  //char input[]; 
  //string input="";
}

void loop() {
  if(btn.buttonPressed(15)){
    number=0;
  }
  if(btn.buttonPressed(14)){
    number+=0;
  }
  if(btn.buttonPressed(8)){
    number+=1;
  }
  if(btn.buttonPressed(9)){
    number+=2;
  }
  if(btn.buttonPressed(10)){
    number=0;
  }
  if(btn.buttonPressed(7)){
    number=0;
  }
  if(btn.buttonPressed(6)){
    number=0;
  }
  if(btn.buttonPressed(5)){
    number=0;
  }
  clearLEDS();
  show(number);
}

void clearLEDS(){
  for{int l=0; l<8; l++){
    digitalWrite(LEDS[l],LOW);
  }
}

void show(int number){
  int bits[8];
  for (int i = 0; i < 8; i++) {
    bits[i] = (number >> i) & 1;
  }
  for (int j = 0; j < 8; j++) {
    if(bits[j]==1){
      digitalWrite(LEDS[j], HIGH);
    }
  }
}
