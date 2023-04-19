#include <Stepper.h>

//define de pinos do motor
#define motor_pin_1  13
#define motor_pin_2  26
#define motor_pin_3  14
#define motor_pin_4  25

//passos por revolução
long int Pos = 2048;

#define conexao_0 27
//#define conexao_1 26

//configuração motor
Stepper MOTOR(Pos,motor_pin_1,motor_pin_2,motor_pin_3,motor_pin_4);

void motor(void * pvParameters)
{
  MOTOR.setSpeed(10);

   //set modo pinos para conexao de dados
   /*    
         pinos que não pode
         23 22 21 19 12 14
   */  
   pinMode(conexao_0, OUTPUT); 
   //pinMode(conexao_1, OUTPUT);  

  while(1)
  {
    if(digitalRead(conexao_0))
    {
      MOTOR.step(-Pos);
      delay(1);
    }
    else if(!digitalRead(conexao_0))
    {
      MOTOR.step(Pos);
    }
  }
}
