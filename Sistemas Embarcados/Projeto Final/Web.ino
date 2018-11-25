#include <WiFi.h>
#include "DHT.h"


//Pinos de leitura dos sensores
#define DHTPIN 18     // what digital pin we're connected to
#define DHTPIN2 19 



//Modelo do sensor
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)



//Instancia dos dois sensores
DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);

#define STORAGE_SIZE 10
#define TOLERANCE 10

int TemperatureSensor1[STORAGE_SIZE];
int TemperatureSensor2[STORAGE_SIZE];


//===========================================
// COnfigurar conexao WIfi
//Entrar com os valores de conexao da rede Wifi
const char* ssid     = "GVT-DE94";
const char* password = "0011710928";



//Setar porta
WiFiServer server(80);

//Variavel para ler a head
String header;

String output26State = "off";
String output27State = "off";



// Setar as portas com as saidas
const int output26 = 2;
int contador = 0;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output26, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output26, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){

  delay(1000);
  // Wait a few seconds between measurements.

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float h2 = dht2.readHumidity()+30;
  
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  addToVector1(h);
    

  float t2 = dht2.readTemperature()+20;
  addInVector2(h2);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }



  
  



  //======================================================================
  
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("GPIO 26 on");
              output26State = "on";
              digitalWrite(output26, HIGH);
            } else if (header.indexOf("GET /26/off") >= 0) {
              Serial.println("GPIO 26 off");
              output26State = "off";
              digitalWrite(output26, LOW);
            } else if (header.indexOf("GET /26/historico") >= 0) {
              Serial.println("GPIO 26 off");
              output26State = "historico";
            } else {
              client.println("ERROR: 404");
              break;
            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1><h2>Teoria de Redes - Projeto GB</h2>");
            
            // Display current state, and ON/OFF buttons for GPIO 26  
            client.println("<p>GPIO 26 - State " + output26State + "</p>");
            // If the output26State is off, it displays the ON button       
            if (output26State=="off") {
              client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
            } else if( output26State = "historico") {
              for(int i =0;i<8;i++){
                client.println( TemperatureSensor1[i]);
              }
            }
            else {
              client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
            
            client.println("<p><a href=\"/historico\"><button class=\"button buttonstory\">Historico</button></a></p>");

            // The HTTP response ends with another blank line

            if(!isEqual(t,t2) || isSensorProblem(TemperatureSensor2) || isSensorProblem(TemperatureSensor1) )
              client.println("Problema no sensor 1");

            client.println("<p>Temperatura: ");
            client.println(t);
            client.println("Umidade: ");
            client.println(h);
            client.println("</p>");

            
            client.println("<p>Temperatura: ");
            client.println(t2);
            client.println("Umidade: ");
            client.println(h2);
            client.println("</p>");
            

            

            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}




bool isEqual(int value1, int value2) {
  value2 += TOLERANCE / 2;
  for (int i = 0; i < TOLERANCE; i++) {
    if (value1 == (value2 - i))
      return true;
  }
  return false;
}



void addToVector1(int value) {
  int store;
  for (int i = STORAGE_SIZE-1; i > 0; i--) {

    store = TemperatureSensor1[i-1];
    TemperatureSensor1[i] = store;
  }
  
  TemperatureSensor1[0] = value;
}

void addInVector2(int value) {
  int store;
  for (int i = STORAGE_SIZE-1; i > 0; i--) {

    store = TemperatureSensor2[i-1];
    TemperatureSensor2[i] = store;
  }
  TemperatureSensor2[0] = value;

}

bool isSensorProblem(int vector[]){
  for(int i=1;i<STORAGE_SIZE;i++){
    if(isEqual(vector[0],vector[1]))
      return false;
  }
  return true;
}
