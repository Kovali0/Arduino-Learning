#include <ISADefinitions.h>
int f = (1+rand()%10) * 1000;

void setup(){
  for (int L = 0; L < 8; L++) {
    pinMode(LEDS[L], OUTPUT);
  }
}

void loop(){
  for(int i=0; i<4; i++){
    pair_on(i,7-i);
    delay(f);
    pair_off(i,7-i);
  }
}

void pair_off(int first, int second){
  digitalWrite(LEDS[first], LOW);
  digitalWrite(LEDS[second], LOW);
}

void pair_on(int first, int second){
  digitalWrite(LEDS[first], HIGH);
  digitalWrite(LEDS[second], HIGH);
}
