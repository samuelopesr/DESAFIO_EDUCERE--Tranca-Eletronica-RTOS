void logicamotor (void * pvParameters)
{
  MOTOR.setSpeed(10);

   //set modo pinos para conexao de dados
   /*    pinos que não pode
         23 22 21 19 12 14
   */
   pinMode(conexao_0, INPUT);  
   //pinMode(conexao_1, OUTPUT);  

  while(1)
  {
    if(digitalRead(conexao_0))
    {
      MOTOR.step(-Pos);
    }
    else if(!digitalRead(conexao_0))
    {
      MOTOR.step(-Pos);
    }
      
  }
}
