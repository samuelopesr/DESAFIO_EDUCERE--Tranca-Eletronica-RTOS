#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "SALA DE TREINAMENTO";
const char* password = "treinamento@123";

WebServer server(80);

int ledPin = 20;
int buttonState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin   , LOW);

  Serial.begin(115200);

 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); 
  
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();

 
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(7000);
    digitalWrite(ledPin, LOW);
    delay(7000);
  }
}

void handleRoot() {
 
  if (server.hasArg("button")) {
    buttonState = !buttonState;
  }

 
  String html = "<html><body><h1>ESP32 LED Control</h1>";
  html += "<form method='GET'>";
  html += "<button name='button' value='1'>Toggle LED</button>";
  html += "</form></body></html>";
  server.send(200, "text/html", html);
}
