#include <WiFi.h>
#include <AccelStepper.h>

#define motor_pin_1  8 
#define motor_pin_2  9
#define motor_pin_3  10
#define motor_pin_4  11

AccelStepper stepper(AccelStepper::FULL4WIRE, motor_pin_1, motor_pin_2, motor_pin_3, motor_pin_4);

const char* ssid = "NomeDaRedeWiFi";
const char* password = "SenhaDaRedeWiFi";

WiFiServer server(80);

bool motor_ligado = false;
int motor_velocidade = 1000;
int motor_direcao = 1;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando à rede WiFi...");
  }

  server.begin();
  Serial.println("Servidor iniciado!");

  stepper.setMaxSpeed(motor_velocidade);
  stepper.setAcceleration(1000);
  stepper.moveTo(0);
  stepper.runToPosition();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Nova requisição!");
    
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    if (request.indexOf("/ligar") != -1) {
      motor_ligado = true;
      motor_direcao = 1;
      stepper.move(90 * motor_direcao);
      stepper.runToPosition();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println();
      client.println("<html><body><h1>Motor ligado!</h1></body></html>");
    }
    else if (request.indexOf("/desligar") != -1) {
      motor_ligado = false;
      motor_direcao = -1;
      stepper.move(90 * motor_direcao);
      stepper.runToPosition();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println();
      client.println("<html><body><h1>Motor desligado!</h1></body></html>");
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<html><body>");
    client.println("<h1>Controle do motor de passo</h1>");
    if (motor_ligado) {
      client.println("<p>Motor ligado!</p>");
    }
    else {
      client.println("<p>Motor desligado!</p>");
    }
    client.println("<p><a href=\"/ligar\">Ligar</a> | <a href=\"/desligar\">Desligar</a></p>");
    client.println("</body></html>");
    client.stop();
    Serial.println("Requisição concluída!");
  }

  if (motor_ligado) {
    stepper.runSpeed();
  }
  else {
    stepper.stop();
    stepper.runToPosition();
  }
}
