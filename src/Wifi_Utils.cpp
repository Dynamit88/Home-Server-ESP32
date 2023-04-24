#include <WiFi.h>
#include "Wifi_Utils.h"


// Local IP: 192.168.88.239
// Subnet Mask: 255.255.255.0
// Gateway IP: 192.168.88.1
// DNS 1: 192.168.88.1
// DNS 2: 91.222.112.46

IPAddress staticIP(192, 168, 88, 239);
IPAddress subnet(255, 255, 255, 0);
IPAddress gateway(192, 168, 88, 1);
IPAddress dns(192, 168, 88, 1);

void Wifi_Utils::connect(char* ssid, char* password) {
    Serial.print("\nConnecting to WiFi");

    if (WiFi.config(staticIP, gateway, subnet, dns, dns) == false) {
        Serial.println("Couldn't use pre-defined WI-FI configuration.");
    }

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

        
        // Serial.print("Subnet Mask: ");
        // Serial.println(WiFi.subnetMask());
        // Serial.print("Gateway IP: ");
        // Serial.println(WiFi.gatewayIP());
        // Serial.print("DNS 1: ");
        // Serial.println(WiFi.dnsIP(0));
        // Serial.print("DNS 2: ");
        // Serial.println(WiFi.dnsIP(1));
    }
}

IPAddress Wifi_Utils::getLocalIP() {
    return WiFi.localIP();
}

IPAddress Wifi_Utils::getSubnetMask() {
    return WiFi.subnetMask();
}

IPAddress Wifi_Utils::getGatewayIP() {
    return WiFi.gatewayIP();
}

IPAddress Wifi_Utils::getDNS0() {
    return WiFi.dnsIP(0);
}

IPAddress Wifi_Utils::getDNS1() {
    return WiFi.dnsIP(1);
}
