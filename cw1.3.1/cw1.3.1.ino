#include <ISADefinitions.h>
#include <ISAButtons.h>
ISAButtons btn;

void setup() {
  btn.init();
  for (int L = 0; L < 8; L++) {
    pinMode(LEDS[L], OUTPUT);
  }
  int iter=7;
  digitalWrite(LED8,HIGH)
}

void loop() {
  if (btn.buttonPressed(11){ //11 przycisk minus
    digitalWrite(LEDS[iter],LOW)
    iter-=1;
    digitalWrite(LEDS[iter],HIGH)
  }else{
    if (btn.buttonPressed(12){ //12 przycisk plus
      digitalWrite(LEDS[iter],LOW)
      iter+=1;
      digitalWrite(LEDS[iter],HIGH)
    }
  }
}
