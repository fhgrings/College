# Wireless connection with ESP-32
## Wifi.h POC


**Software and materials**

- ESP-32
- Cabo micro-USB
- Arduino IDE
- Google Chrome

**Bibliotecas utilizadas**

- Wifi.h


## Function explanation

Wifi.h biblio abstract a a lot of wifi conection between module and Wifi network, where we just need to configure Network name and password.
The server up in ESP-32 run constantly verifying if a new client exists, if not, finish the loop and starts again. If a new client appaers, ESP reccieve a request
with URI and header configs connection, with that we have all necessary to configura each screen the user will receive and what the server needs to do.
ESP process, configure and send a HTML/CSS page with new datas to client browser. After that ESP close client connection and start again looking for a new connection


## To run

In Arduino IDE go to File -> Preferences
URLs 
Add JSON link
https://dl.espressif.com/dl/package_esp32_index.json

--------------------

Tools->Board-> Board Manager

Search esp32 -> install

------------------

Tool -> Board -> ESP32 Dev Module


Run! :)

