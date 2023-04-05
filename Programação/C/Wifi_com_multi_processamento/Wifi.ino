#include <WiFi.h>
#include <WebServer.h>


//Servidor configuração
WebServer Servidor(80);

//ssid de rede e senha
const char* ssid = "";
const char* senha = "";

//pinos de conexao
#define conexao_0 27
//#define conexao_1 26

//bool trás frente
bool BValor;

//string HTML
String html;

void wifi(void* pvParameters) 
{

   //set modo pinos para conexao de dados
   /*    pinos que não pode
         23 22 21 19 12 14
   */
   pinMode(conexao_0, OUTPUT);  
   //pinMode(conexao_1, OUTPUT);  


  //clock RX TX
  Serial.begin(115200);

  //configuração Wifi
  WiFi.begin(ssid, senha);

  //set ip fixo
  IPAddress local_IP(192, 168, 0, 184);
  IPAddress gateway(192, 168, 0, 1);
  IPAddress subnet(255, 255, 25, 0);
  IPAddress primaryDNS(192, 168, 0, 1);
  IPAddress secondaryDNS(0, 0, 0, 0);



  //check ip fixo
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) 
  {
    Serial.println("STA FALHOU");
  }

  //check conexao
  while (WiFi.status() != WL_CONNECTED) 
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

  while (1) 
  {
    Servidor.handleClient();
    if (!BValor) 
    {
      digitalWrite(conexao_0,1);
    } 
    else if (BValor) 
    {
      digitalWrite(conexao_0,0);
    }
  }
}

void handlemenu() {
  if (Servidor.hasArg("button")) 
  {
    BValor = !BValor;
  }


  html = "<html><head><title>ESP32 Online!!</title></head>";
  if (!BValor) 
  {
    html += "<style>*{margin: 0px; padding: 0px; box-sizing: border-box;  font-family: Arial, Helvetica, sans-serif;}";
    html += "body, html{background: linear-gradient(45deg, rgb(4, 23, 39), rgb(37, 51, 112)); height: 100vh; width: 100vw;}";
    html += "h1{color: white; position: absolute; width: 270px; margin-top: 45%; margin-left: 22%;}";
    html += "form > button{font-size: 1.9em; background-color: rgb(154, 191, 212); position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%); height: 300px; width: 300px; border-radius: 50%; border: none;}</style>";
    html += "<body><center><h1>Controle do Motor</h1>";
    html += "<form method='GET'>";
    html += "<button name='button' value='1'>Ligar Motor</button>";
    html += "</form></center></body></html>";
  } 
  else if (BValor) 
  {
    html += "<style>*{margin: 0px; padding: 0px; box-sizing: border-box;  font-family: Arial, Helvetica, sans-serif;}";
    html += "body, html {background: linear-gradient(45deg, rgb(4, 23, 39), rgb(37, 51, 112)); height: 100vh; width: 100vw;}";
    html += "h1{color: white; position: absolute; width: 270px; margin-top: 45%; margin-left: 22%;}";
    html += "form > button{font-size: 1.9em; background-color: rgb(154, 191, 212); position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%); height: 300px; width: 300px; border-radius: 50%; border: none;}</style>";
    html += "<body><center><h1>Controle do Motor</h1>";
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