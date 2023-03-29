//libs
#include <WiFi.h>
#include <WebServer.h>
#include <Stepper.h>

//define de pinos

#define motor_pin_1  13
#define motor_pin_2  12
#define motor_pin_3  14
#define motor_pin_4  27

//passos por revolução
const int Pos = 100;

//Servidor configuração
WebServer Servidor(80);

//string HTML
String html;

//configuração motor
Stepper MOTOR(Pos,motor_pin_1,motor_pin_2,motor_pin_3,motor_pin_4);

//ssid de rede e senha
const char* ssid="GOC";
const char* senha="terezinha";

//bool trás frente
bool BValor=0x00;

void setup()
{
  //clock RX TX
  Serial.begin(9600);

  //speed motor de passo
  MOTOR.setSpeed(200);

  //configuração Wifi
  WiFi.begin(ssid, senha);

  //check conexao
  while(WiFi.status() != WL_CONNECTED)
  {
      Serial.println("Conectando..");
      delay(500);
  }

  //informações
  Serial.println("Conectado com sucesso");
  Serial.println("Seu IP:");
  Serial.println(WiFi.localIP());


  Servidor.on("/", handlehome);
  Servidor.on("/Chave", handlemenu);
  Servidor.begin();
}
void loop()
{
  Servidor.handleClient();
  if(!BValor)
  {
    MOTOR.step(Pos);
  }
  else if(BValor)
  {
    MOTOR.step(-Pos);
  }
}

void handlemenu()
{
    if (Servidor.hasArg("button")) 
  {
    BValor = !BValor;
  }
  
  
  html = "<html><head><title>ESP32 Online!!</title></head>";
  if(!BValor)
  {
    html += "<body><h1>Controle do Motor</h1>";
    html += "<form method='GET'>";
    html += "<button name='button' value='1'>Liga LED</button>";
    html += "</form></body></html>";
    Serial.println(BValor);
  }
  else if(BValor)
  {
    html += "<body><h1>Controle do Motor</h1>";
    html += "<form method='GET'>";
    html += "<button name='button' value='0'>Desliga LED</button>";
    html += "</form></body></html>";
    Serial.println(BValor);
  }

  //manda informação para o servidor web
  Servidor.send(200, "text/html", html);
}

void handlehome()
{
  String html = "<html><head><title>ESP32 Online!!</title></head><body><a href='./Chave'>MENU</a></body></html>";

  //manda informação para o servidor web
  Servidor.send(200, "text/html", html);
}
