#include <Arduino.h>
#define SDCARD_MISO 2
#define SDCARD_CS 13
#define SDCARD_SCLK 14
#define SDCARD_MOSI 15

class SD_Utils {
    // private:
        // static SPIClass sdSPI;
    public:
        static void init();
        static bool fileExists(const char* path);
        static String getFileContent(const char* path);
};
