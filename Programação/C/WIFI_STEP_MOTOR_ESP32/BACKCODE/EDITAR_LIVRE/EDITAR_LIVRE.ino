
//libs
#include <WiFi.h>
#include <WebServer.h>
#include <Stepper.h>

//define de pinos

#define motor_pin_1  23
#define motor_pin_2  22
#define motor_pin_3  21
#define motor_pin_4  19

//passos por revolução
long int Pos = 200;

//Servidor configuração
WebServer Servidor(80);

//string HTML
String html;

//configuração motor
Stepper MOTOR(Pos,motor_pin_1,motor_pin_2,motor_pin_3,motor_pin_4);

//ssid de rede e senha
const char* ssid="P&D_EDUCERE";
const char* senha="FUNDACAO2991";

                      

//bool trás frente
bool BValor;

void setup()
{
  //clock RX TX
  Serial.begin(115200);

  //speed motor de passo
  MOTOR.setSpeed(75);

  //configuração Wifi
  WiFi.begin(ssid, senha);

  
  //set ip fixo
  IPAddress local_IP(192, 168, 0, 184);
  IPAddress gateway(192,168,0,1);
  IPAddress subnet(255,255,25,0);
  IPAddress primaryDNS(192,168,0,1);
  IPAddress secondaryDNS(0,0,0,0);

  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA FALHOU");
  }

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
  Serial.println("Seu SubMask:");
  Serial.println(WiFi.subnetMask());
  Serial.println("Seu GateWay:");
  Serial.println(WiFi.gatewayIP());
  Serial.println("Seu DNS primario");
  Serial.println(WiFi.dnsIP(0));
  Serial.println("Seu DNS secundario:");
  Serial.println(WiFi.dnsIP(1));


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
    
    Serial.print(BValor);
    Serial.print(" + ");
    Serial.println(Pos);
  }
  else if(BValor)
  {
    MOTOR.step(-Pos);

    Serial.print(BValor);
    Serial.print(" - ");
    Serial.println(-Pos);
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
<<<<<<< HEAD
    html += "<style>*{margin: 0px; padding: 0px; box-sizing: border-box; font-family: Helvetica, sans-serif, Arial;}";
    html += "body, html{background: rgba(22, 44, 68, 0.555); background-position: center center; background-repeat: no-repeat; background-size: cover; height: 100vh; width: 100vw;}";
    html += "h1{font-size: 1.4em; text-align: center; display: flex; flex-direction: row; }";
    html += "button{display: flex; flex-direction: row; justify-content: center; align-items: center; height: 80vh; width: 80vw; border: none; border-radius: 50%; background-color: rgb(40, 128, 251); font-size: 1.1em; text-align: center;}</style>";
    html += "<body><h1>Controle do Motor</h1>";
=======
    html += "<style>*{margin: 0px; padding: 0px; box-sizing: border-box;  font-family: Arial, Helvetica, sans-serif;}";
    html += "body, html{background: linear-gradient(45deg, rgb(4, 23, 39), rgb(37, 51, 112)); height: 100vh; width: 100vw;}";
    html += "h1{color: white; position: absolute; width: 270px; margin-top: 45%; margin-left: 22%;}";
    html += "form > button{font-size: 1.9em; background-color: rgb(154, 191, 212); position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%); height: 300px; width: 300px; border-radius: 50%; border: none;}</style>";
    html += "<body><center><h1>Controle do Motor</h1>";
>>>>>>> 6fa76eef83207c3c7208fbed9de926b78ef8c5af
    html += "<form method='GET'>";
    html += "<button name='button' value='1'>Ligar Motor</button>";
    html += "</form></center></body></html>";
  }
  else if(BValor)
  {
<<<<<<< HEAD
    html += "<style>*{margin: 0px; padding: 0px; box-sizing: border-box; font-family: Helvetica, sans-serif, Arial;}";
    html += "body, html{background: rgba(22, 44, 68, 0.555); background-position: center center; background-repeat: no-repeat; background-size: cover; height: 100vh; width: 100vw;}";
    html += "h1{font-size: 1.4em; text-align: center; display: flex; flex-direction: row; }";
    html += "button{display: flex; flex-direction: row; justify-content: center; align-items: center; height: 80vh; width: 80vw; border: none; border-radius: 50%; background-color: rgb(40, 128, 251); font-size: 1.1em; text-align: center;}</style>";
    html += "<body><h1>Controle do Motor</h1>";
=======
    html += "<style>*{margin: 0px; padding: 0px; box-sizing: border-box;  font-family: Arial, Helvetica, sans-serif;}";
    html += "body, html {background: linear-gradient(45deg, rgb(4, 23, 39), rgb(37, 51, 112)); height: 100vh; width: 100vw;}";
    html += "h1{color: white; position: absolute; width: 270px; margin-top: 45%; margin-left: 22%;}";
    html += "form > button{font-size: 1.9em; background-color: rgb(154, 191, 212); position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%); height: 300px; width: 300px; border-radius: 50%; border: none;}</style>";
    html += "<body><center><h1>Controle do Motor</h1>";
>>>>>>> 6fa76eef83207c3c7208fbed9de926b78ef8c5af
    html += "<form method='GET'>";
    html += "<button name='button' value='0'>Desligar Motor</button>";
    html += "</form></center></body></html>";
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
