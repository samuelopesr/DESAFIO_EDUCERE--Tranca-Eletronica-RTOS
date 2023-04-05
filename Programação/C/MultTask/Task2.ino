
void Task2code( void * pvParameters ){
 
  while(1){
    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led2, LOW);
    delay(500);
  }
}
