void voidwifihandlemenu(void * pvParameters) {
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

