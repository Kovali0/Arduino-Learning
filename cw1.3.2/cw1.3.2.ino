#include <ISADefinitions.h>
#include <ISAButtons.h>
ISAButtons btn;

void setup() {
  btn.init();
  for (int L = 0; L < 8; L++) {
    pinMode(LEDS[L], OUTPUT);
  }
  int iter=0;
  digitalWrite(LED8,HIGH);
  bool goright=true;
}

void loop() {
  if (goright==true){
    digitalWrite(LEDS[iter-1],LOW);
    digitalWrite(LEDS[iter],HIGH);
    if (btn.buttonPressed(0){
      goright=false;
      iter-=1;
    }else{
      if (btn.buttonPressed(1){
        iter+=1;
      }
    }
  }else{
    digitalWrite(LEDS[iter+1],LOW);
    digitalWrite(LEDS[iter],HIGH);
    if (btn.buttonPressed(0){
      iter-=1;
    }else{
      if (btn.buttonPressed(1){
        goright=true;
        iter+=1;
      }
    }
  }
}
