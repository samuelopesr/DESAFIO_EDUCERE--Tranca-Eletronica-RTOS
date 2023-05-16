#include <Stepper.h>

//define de pinos do motor
#define motor_pin_1  23
#define motor_pin_2  21
#define motor_pin_3  22
#define motor_pin_4  19

//passos por revolução
long int Pos = 100;

#define conexao_0 27
#define conexao_r0 14
#define conexao_r1 12

//configuração motor
Stepper MOTOR(Pos,motor_pin_1,motor_pin_2,motor_pin_3,motor_pin_4);

void motor(void * pvParameters)
{
  MOTOR.setSpeed(300);

   //set modo pinos para conexao de dados
   /*    
         pinos que não pode
         23 22 21 19 12 14
   */  
   pinMode(conexao_0, OUTPUT);
   pinMode(conexao_r0, INPUT); 
   pinMode(conexao_r1, INPUT); 
   //pinMode(conexao_1, OUTPUT);  

  while(1)
  {
    if(digitalRead(conexao_0))
    {
      if(!digitalRead(conexao_r0))
      {
        MOTOR.step(-Pos);
        delay(1);
      }
    }
    else if(!digitalRead(conexao_0))
    {
      if(!digitalRead(conexao_r1))
      {
        MOTOR.step(Pos);
        delay(1);
      }
    }
  }
}
