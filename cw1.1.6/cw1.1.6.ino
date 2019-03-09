#include <ISADefinitions.h>
void setup(){
  pinMode(LED1, OUTPUT);
}
void loop(){
  delay(500);
  digitalWrite(LED1, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);
}
