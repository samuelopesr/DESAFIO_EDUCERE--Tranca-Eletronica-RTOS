TaskHandle_t Wifi;
TaskHandle_t Motor;



void setup() {
  
  xTaskCreatePinnedToCore(
                    wifi,   /* função de tarefa. */
                    "tarefa1",     /* nome da tarefa. */
                    10000,       /* Tamanho da pilha da tarefa */
                    NULL,        /* parâmetro da tarefa */
                    1,           /* prioridade da tarefa */
                    &Wifi,      /* Alça de tarefa para acompanhar a tarefa criada */
                    1);          /* fixar tarefa no núcleo 1 */
                      
  xTaskCreatePinnedToCore(
                    motor,   /* função de tarefa. */
                    "tarefa2",     /* nome da tarefa. */
                    10000,       /* Tamanho da pilha da tarefa */
                    NULL,        /* parâmetro da tarefa */
                    1,           /* prioridade da tarefa */
                    &Motor,      /* Alça de tarefa para acompanhar a tarefa criada */
                    0);          /* fixar tarefa no núcleo 1 */           
}

void loop() {
  // put your main code here, to run repeatedly:
  disableCore0WDT();
}
