void motor(void * pvParameters)
{
#include <Stepper.h>

//define de pinos do motor
#define motor_pin_1  23
#define motor_pin_2  22
#define motor_pin_3  21
#define motor_pin_4  19

//passos por revolução
long int Pos = 2048;

#define conexao_0 27
//#define conexao_1 26

//configuração motor
Stepper MOTOR(Pos,motor_pin_1,motor_pin_2,motor_pin_3,motor_pin_4);
}
