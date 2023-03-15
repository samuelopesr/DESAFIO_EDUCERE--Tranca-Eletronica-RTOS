#include <Stepper.h>

int   in1 = 8;   
int   in2 =  9;    
int   in3 = 10;    
int   in4 = 11;  
int   Bin0 = 13;
bool T= 0x00;


unsigned const int stepsPerRevolution = 100;

Stepper myStepper(stepsPerRevolution, in1, in3, in2, in4);

void setup()
{
  // set the speed at 60 rpm:
  myStepper.setSpeed(325);
  Serial.begin(9600);
  pinMode(Bin0, INPUT);
}

void loop()
{
  
  bool check=digitalRead(Bin0);
  if(T)
  {
      if(!check)
      {
        myStepper.step(stepsPerRevolution);
      }
      else
      {
        myStepper.step(0);
      }
  }
  else if(!T)
  {
      if(check)
      {
        myStepper.step(-stepsPerRevolution);
      }
      else
      {
        myStepper.step(0);
      }
  }

  

}
















