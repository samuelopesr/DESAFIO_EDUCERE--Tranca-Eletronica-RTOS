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



void handlehome() 
{
  String html = "<html><head><title>ESP32 Online!!</title></head><body><a href='./Chave'>MENU</a></body></html>";

  //manda informação para o servidor web
  Servidor.send(200, "text/html", html);
}
