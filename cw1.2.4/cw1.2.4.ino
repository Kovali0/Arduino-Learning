#include <ISADefinitions.h>
#include <DueTimer.h>
volatile unsigned char t = 0;

void clear_time(){
  for (int j = 0; j < 8; j++) {
    digitalWrite(LEDS[j], LOW);
  }
}

void time_now(){
  int bits[8];
  for (int i = 0; i < 8; i++) {
    bits[i] = (t >> i) & 1;
  }
  for (int j = 0; j < 8; j++) {
    if(bits[j]==1){
      digitalWrite(LEDS[j], HIGH);
    }
  }
  t++;
}

void setup(){
  for (int L = 0; L < 8; L++) {
    pinMode(LEDS[L], OUTPUT);
  }
  Timer4.attachInterrupt(clear_time);
  Timer4.start();
  Timer5.attachInterrupt(time_now);
  Timer5.start(1000000);
}
void loop(){}
