#include <Arduino.h>

#define LoRa_CS    18
#define Select    LOW   //  Low CS means that SPI device Selected
#define DeSelect  HIGH  //  High CS means that SPI device Deselected

#define SDCARD_MISO 2
#define SDCARD_CS 13
#define SDCARD_SCK 14
#define SDCARD_MOSI 15

class SD_Utils {
    // private:
        // static SPIClass sdSPI;
    public:
        static void init();
        static bool fileExists(const char* path);
        static String getFileContent(const char* path);
};
