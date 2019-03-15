#include <ISADefinitions.h>
#include <DueTimer.h>

void led_off(){
  digitalWrite(LED8, LOW);
}

void led_on(){
  digitalWrite(LED8, HIGH);
}

void setup(){
  pinMode(LED8, OUTPUT);
  Timer4.attachInterrupt(led_on);
  Timer4.start(1000000);
  Timer5.attachInterrupt(led_off);
  Timer5.start(2000000);
}
void loop(){}
