#include <WiFi.h>

//Entrar com os valores de conexao da rede Wifi
const char* ssid     = "Redmi";
const char* password = "felipehg";

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
  // Configurar as saidas
  pinMode(output26, OUTPUT);
  digitalWrite(output26, LOW);

  // Conectar no wifi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Printar o IP quando conectar
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
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
            } else {
              String teste ="\n"
                  "<div class=\"container-fluid\">\n"
                  "  <br>\n"
                  "\t<div class=\"row\">\n"
                  "    <div class=\"row\">\n"
                  "      <div class=\"col-lg-3 col-md-4 col-sm-4 col-xs-6\">\n"
                  "        <div class=\"speedo-heading\">Ethics and Professional Responsibility</div>\n"
                  "        <div class=\"checkmark text-center animate\">\n"
                  "          <div class=\"icon\">\n"
                  "            <span>&#10004;</span>\n"
                  "          </div>\n"
                  "        </div>\t\t\t\t        \n"
                  "        <div class=\"speedo\">\n"
                  "          <div class=\"face face-success\">\n"
                  "            <div class=\"needle\"></div>\t\t\t\t\n"
                  "          </div>\n"
                  "        </div>\n"
                  "        <div class=\"text-center\" style=\"line-height: 1.1em\">\n"
                  "          &nbsp;\n"
                  "        </div>\n"
                  "\n"
                  "      </div>\n"
                  "      <div class=\"col-lg-3 col-md-4 col-sm-4 col-xs-6\">\n"
                  "        <div class=\"speedo-heading\">\n"
                  "          Practice Management and Business Skills\n"
                  "        </div>\n"
                  "        <div class=\"speedo\">\n"
                  "          <div class=\"face face-danger\">\n"
                  "            <div class=\"needle\"></div>\n"
                  "          </div>\n"
                  "        </div>\n"
                  "        <div class=\"text-center\" style=\"line-height: 1.1em\">\n"
                  "          1 point needed\n"
                  "        </div>\n"
                  "      </div>\n"
                  "      <div class=\"col-lg-3 col-md-4 col-sm-4 col-xs-6\">\n"
                  "        <div class=\"speedo-heading\">\n"
                  "          Professional Skills\n"
                  "        </div>\n"
                  "        <div class=\"speedo\">\n"
                  "          <div class=\"face face-danger\">\n"
                  "            <div class=\"needle\"></div>\n"
                  "          </div>\n"
                  "        </div>\n"
                  "        <div class=\"text-center\" style=\"line-height: 1.1em\">\n"
                  "          1 point neeeded\n"
                  "        </div>        \n"
                  "      </div>\n"
                  "      <div class=\"col-lg-3 col-md-4 col-sm-4 col-xs-6\">\n"
                  "        <div class=\"speedo-heading\">\n"
                  "          Total Points\n"
                  "        </div>\n"
                  "        <div class=\"speedo\">\n"
                  "          <div class=\"face face-danger\">\n"
                  "            <div class=\"needle\"></div>\n"
                  "          </div>\n"
                  "        </div>\n"
                  "        <div class=\"text-center\" style=\"line-height: 1.1em\">\n"
                  "          8 points needed\n"
                  "        </div>        \n"
                  "      </div>\n"
                  "    </div>\t\t\n"
                  "\n"
                  "  </div>\n"
                  "</div>";



              String CSS = ".speedo-heading {\n"
                            "\tmargin-top: 3em;\n"
                            "\ttext-align:center;\n"
                            "\tfont-weight: bold;\n"
                            "\twhite-space: nowrap;\n"
                            "\toverflow: hidden;\n"
                            "\ttext-overflow: ellipsis;\n"
                            "}\n"
                            "\n"
                            ".speedo {\n"
                            "\twidth: 200px;\n"
                            "\theight: 90px;\n"
                            "\tmargin: 10px auto 10px auto;\n"
                            "\toverflow: hidden;\n"
                            "\t\n"
                            "\t.face {\n"
                            "\t\tbox-shadow: 1px 1px 2px rgba(0, 0, 0, 0.3) inset;\n"
                            "\t\twidth: 200px;\n"
                            "\t\theight: 200px;\n"
                            "\t\tborder: solid 30px;\n"
                            "\t\tborder-radius: 50%;\n"
                            "\t\tposition: relative;\n"
                            "\n"
                            "\t\t&.face-danger {\n"
                            "\t\t\tbox-shadow: 0px 2px 2px rgba(212, 73, 63, 1) inset;\n"
                            "\t\t\tborder-color: #fc6767;\n"
                            "\t\t}\n"
                            "\t\t&.face-success {\n"
                            "\t\t\tbox-shadow: 0px 2px 2px rgba(76, 175, 80, 0.7) inset;\n"
                            "\t\t\tborder-color: #a3e0ae;\n"
                            "\t\t}\n"
                            "\n"
                            "\t\t.needle {\n"
                            "\t\t\twidth: 5px;\n"
                            "\t\t\theight: 80px;\n"
                            "\t\t\tbackground: #333;\n"
                            "\t\t\tborder-bottom-left-radius: 5px;\n"
                            "\t\t\tborder-bottom-right-radius: 5px;\n"
                            "\t\t\tborder-top-left-radius: 100%;\n"
                            "\t\t\tborder-top-right-radius: 100%;\n"
                            "\t\t\tdisplay: inline-block;\n"
                            "\t\t\tleft: 65px;\n"
                            "\t\t\tposition: absolute;\n"
                            "\t\t\ttop: -23px;\n"
                            "\t\t\ttransform-origin: bottom;\n"
                            "\t\t}\t\t\n"
                            "\t}\n"
                            "}\n"
                            "\n"
                            ".checkmark {\n"
                            "\tz-index: 1;\n"
                            "\tposition: absolute;\n"
                            "\tleft: 0;\n"
                            "\tright: 0;\n"
                            "\t&.animate .icon {\n"
                            "\t\tanimation: fall-in 3s forwards;\n"
                            "\t}\n"
                            "\t.icon {\n"
                            "\t\txtext-shadow: 0px 1px 11px #fff;\n"
                            "\t\ttext-shadow: 0px 1px 11px rgba(0,0,0,0.3);\n"
                            "\t\tfont-family: \"Helvetica Neue\",Helvetica,Arial,sans-serif;\n"
                            "\t\tspan {\t\t\t\n"
                            "\t\t\tfont-size: 8em;\n"
                            "\t\t\tcolor: #4caf50;\n"
                            "\t\t}\n"
                            "\t}\n"
                            "}\n"
                            "\n"
                            "\n"
                            ".percent-0 {\n"
                            "\t-webkit-animation: keyframes-0 2s;\n"
                            "\ttransform: rotate(-90deg);\n"
                            "}\n"
                            "\n"
                            ".percent-10 {\n"
                            "\t-webkit-animation: keyframes-10 2s;\n"
                            "\ttransform: rotate(-68deg);\n"
                            "}\n"
                            "\n"
                            ".percent-20 {\n"
                            "\t-webkit-animation: keyframes-20 2s;\n"
                            "\ttransform: rotate(-36deg);\n"
                            "}\n"
                            "\n"
                            ".percent-50 {\n"
                            "\t-webkit-animation: keyframes-50 2s;\n"
                            "\ttransform: rotate(0deg);\n"
                            "}\n"
                            "\n"
                            ".percent-100 {\n"
                            "\t-webkit-animation: keyframes-100 2s;\n"
                            "\ttransform: rotate(90deg);\n"
                            "\topacity: 0;\n"
                            "}\n"
                            "\n"
                            "@keyframes keyframes-0 {\n"
                            "\t0% {\n"
                            "\t\ttransform: rotate(-90deg);\n"
                            "\t}\n"
                            "\t50% {\n"
                            "\t\ttransform: rotate(90deg);\n"
                            "\t}\n"
                            "\t100% {\n"
                            "\t\ttransform: rotate(-90deg);\n"
                            "\t}\n"
                            "}\n"
                            "\n"
                            "@keyframes keyframes-10 {\n"
                            "\t0% {\n"
                            "\t\ttransform: rotate(-90deg);\n"
                            "\t}\n"
                            "\t50% {\n"
                            "\t\ttransform: rotate(90deg);\n"
                            "\t}\n"
                            "\t100% {\n"
                            "\t\ttransform: rotate(-68deg);\n"
                            "\t}\n"
                            "}\n"
                            "\n"
                            "@keyframes keyframes-20 {\n"
                            "\t0% {\n"
                            "\t\ttransform: rotate(-90deg);\n"
                            "\t}\n"
                            "\t50% {\n"
                            "\t\ttransform: rotate(90deg);\n"
                            "\t}\n"
                            "\t100% {\n"
                            "\t\ttransform: rotate(-36deg);\n"
                            "\t}\n"
                            "}\n"
                            "\n"
                            "@keyframes keyframes-50 {\n"
                            "\t0% {\n"
                            "\t\ttransform: rotate(-90deg);\n"
                            "\t}\n"
                            "\t50% {\n"
                            "\t\ttransform: rotate(90deg);\n"
                            "\t}\n"
                            "\t100% {\n"
                            "\t\ttransform: rotate(0deg);\n"
                            "\t}\n"
                            "}\n"
                            "\n"
                            "@keyframes keyframes-50 {\n"
                            "\t0% {\n"
                            "\t\ttransform: rotate(-90deg);\n"
                            "\t}\n"
                            "\t50% {\n"
                            "\t\ttransform: rotate(90deg);\n"
                            "\t}\n"
                            "\t100% {\n"
                            "\t\ttransform: rotate(0deg);\n"
                            "\t}\n"
                            "}\n"
                            "\n"
                            "@keyframes keyframes-100 {\n"
                            "\t0% {\n"
                            "\t\ttransform: rotate(-90deg);\n"
                            "\t\topacity:1;\n"
                            " \t}\n"
                            "\t50% {\n"
                            "\t\ttransform: rotate(90deg);\n"
                            "\t\topacity:1;\n"
                            "\t}\n"
                            "\t100% {\n"
                            "\t\topacity:0;\n"
                            "\t}\n"
                            "}\n"
                            "\n"
                            "@keyframes fall-in {\n"
                            "\t0% {\n"
                            "\t\topacity:0;\n"
                            "\t}\n"
                            "\t60% {\n"
                            "    transform: scale(3, 3);\n"
                            "    opacity: 0;\n"
                            "  }\n"
                            "\n"
                            "  80% {\n"
                            "    transform: scale(1, 1);\n"
                            "    opacity: 1;\n"
                            "  }\n"
                            "\n"
                            "  90% {\n"
                            "    transform: scale(1.1, 1.1);\n"
                            "  }\n"
                            "\n"
                            "  100% {\n"
                            "    transform: scale(1, 1);\n"
                            "  }\n"
                            "}\n"
                            "\n"
                            ".odometer {\n"
                            "    font-size: 50px;\n"
                            "}\n"
                            ".odometer-digit {\n"
                            "  margin-top: -6px;\n"
                            "}\n"
                            "\n"
                            ".odometer-block {\n"
                            "  line-height: 1;\n"
                            "  background-image: -webkit-linear-gradient(top, #111111 0%, #111111 35%, #333333 55%, #111111 55%, #111111 100%);\n"
                            "  display: inline-block;\n"
                            "  min-width: 117px;\n"
                            "  text-align: right;\n"
                            "  border-radius: 3px;\n"
                            "  margin-right: 15px;\n"
                            "}\n"
                            ".odometer-label {\n"
                            "  margin-top: .25em;\n"
                            "  font-size: 1.1em;\n"
                            "}\n"
                            "\n"
                            ".progress-bar {\n"
                            "\tbackground-color: #a3e0ae;\n"
                            "\twidth: 0;\n"
                            "\tanimation: progress 1.5s ease-in-out forwards;\n"
                            "\n"
                            "  .title {\n"
                            "    opacity: 0;\n"
                            "    animation: progress-title 0.35s forwards ease-in-out 0.5s;\n"
                            "  }\n"
                            "} \n"
                            "\n"
                            "@keyframes progress {\n"
                            "  from {\n"
                            "    width: 0;\n"
                            "  }\n"
                            "  to {\n"
                            "    width: 100%;\n"
                            "  }\n"
                            "} \n"
                            "@keyframes progress-title  {\n"
                            "  from {\n"
                            "    opacity: 0;\n"
                            "  }\n"
                            "  to {\n"
                            "    opacity: 1;\n"
                            "  }\n"
                            "}";

              String Java = "$(\".needle:nth(0)\").addClass(\"percent-100\");\n"
                            "$(\".needle:nth(1)\").addClass(\"percent-0\");\n"
                            "$(\".needle:nth(2)\").addClass(\"percent-0\");\n"
                            "$(\".needle:nth(3)\").addClass(\"percent-20\");\n"
                            "\n"
                            "var el = document.querySelector('.odometer');\n"
                            "\n"
                            "od = new Odometer({\n"
                            "  el: el,\n"
                            "  duration: 750,\n"
                            "  value: 999,\n"
                            "  theme: 'train-station',\n"
                            "});\n"
                            "od.update(241)\n"
                            "";
              client.println(teste);
              client.println(CSS);
              client.println(Java);

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
            } else {
              client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
            
            // The HTTP response ends with another blank line
            client.println();
            client.println("Quantidades de cliks");
            client.println(contador);
            contador++;

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
