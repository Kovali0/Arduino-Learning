#include <ISADefinitions.h>
#include <DueTimer.h>
volatile int first=0;

void pair_off(){
  digitalWrite(LEDS[first], LOW);
  digitalWrite(LEDS[7-first], LOW);
  if(first!=7){
    first+=1;
  }else{
    first=0;
  }
}

void pair_on(){
  digitalWrite(LEDS[first], HIGH);
  digitalWrite(LEDS[7-first], HIGH);
}

void setup(){
  for (int L = 0; L < 8; L++) {
    pinMode(LEDS[L], OUTPUT);
  }
  Timer4.attachInterrupt(pair_on);
  Timer4.start(25000);
  Timer5.attachInterrupt(pair_off);
  Timer5.start();
}
void loop(){}
