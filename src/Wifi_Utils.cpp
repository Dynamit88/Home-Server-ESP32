#include <WiFi.h>
#include "Wifi_Utils.h"
// #include <WebServer.h>

// WiFiServer server(80);

void Wifi_Utils::connect(char* ssid, char* password) {
    Serial.print("\nConnecting to WiFi");
    WiFi.mode(WIFI_MODE_STA);
    WiFi.begin(ssid, password);

    unsigned long startAttemptTime = millis();

    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT) {
        Serial.print(".");
        delay(200);
    }

    Serial.print("\n");

    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("Connection failed! Status: " + WiFi.status());
    }
    else {
        Serial.println("Connected with IP address: " + WiFi.localIP().toString());
    }
}



// void Server_Utils::startServer() {
//     server.begin();
// }