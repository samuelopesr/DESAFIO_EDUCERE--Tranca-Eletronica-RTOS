#include<Stepper.h>
unsigned const int VALUE;
Stepper pin(VALUE,8,9,10,11);

void setup() {
  pin.setSpeed(300);
  
}

void loop() {
  pin.step(-VALUE);//sentido horario;;
}
