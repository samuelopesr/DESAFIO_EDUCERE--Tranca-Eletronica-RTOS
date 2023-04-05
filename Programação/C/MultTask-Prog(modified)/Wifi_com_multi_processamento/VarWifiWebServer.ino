void varwifiwebserver (void * pvParameters)
{
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
}
