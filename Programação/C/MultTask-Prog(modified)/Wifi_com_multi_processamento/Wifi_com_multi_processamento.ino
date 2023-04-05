TaskHandle_t Wifi;
TaskHandle_t Motor;
TaskHandle_t LogicaMotor;
TaskHandle_t VarWifiWebServer;
TaskHandle_t VoidWifi;
TaskHandle_t VoidWifi_HandleMenu;
TaskHandle_t VoidWifi_HandleHome; 



void setup() {
  
  xTaskCreatePinnedToCore(
                    wifi,   /* função de tarefa. */
                    "tarefa1",     /* nome da tarefa. */
                    10000,       /* Tamanho da pilha da tarefa */
                    NULL,        /* parâmetro da tarefa */
                    1,           /* prioridade da tarefa */
                    &Wifi,      /* Alça de tarefa para acompanhar a tarefa criada */
                    0);          /* fixar tarefa no núcleo 1 */
                      
  xTaskCreatePinnedToCore(
                    motor,   
                    "tarefa2",     
                    10000,    
                    NULL,       
                    1,          
                    &Motor,      
                    1);          

 xTaskCreatePinnedToCore(
                    logicamotor,
                    "tarefa3",
                    10000,
                    NULL,
                    1,
                    &LogicaMotor,
                    0)
}
 xTaskCreatePinnedToCore(
                    varwifiwebserver,
                    "tarefa4",
                    10000,
                    NULL,
                    &VarWifiWebServer,
                    1)

                    
 xTaskCreatePinnedToCore(
                    voidwifi,
                    "tarefa5",  
                    10000,
                    NULL,
                    &VoidWifi,
                    0)

xTaskCreatePinnedToCore(
                    voidwifihandlemenu,
                    "tarefa6",
                    10000,
                    &VoidWifiHandleMenu,
                    1)   

                                    
xTaskCreatePinnedToCore(
                    voidwifihandlehome,
                    "tarefa7",
                    10000,
                    &VoidWifi_HandleHome,
                    0)                                   
void loop() {
  // put your main code here, to run repeatedly:

}
