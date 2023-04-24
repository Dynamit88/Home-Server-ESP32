/* 
Function declaration (except statics)
Variable declaration (typically global)
User defined type declaration (read struct, union etc.)
Macro definition 
*/

// The #define declaration is known at compile time and cannot be changed. 

#ifndef WIFI_UTILS_H
#define WIFI_UTILS_H

#define WIFI_TIMEOUT 20000

class Wifi_Utils {
    public:
        static void connect(char* network, char* password);
        static IPAddress getLocalIP();
        static IPAddress getSubnetMask();
        static IPAddress getGatewayIP();
        static IPAddress getDNS0();
        static IPAddress getDNS1();
};

#endif /* WIFI_UTILS_H */