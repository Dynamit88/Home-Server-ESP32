#include "SD_Utils.h"
#include <SD.h>
#include <SPI.h>


// SCK, MISO, MOSI,SS

void SD_Utils::init() {
    SPIClass sdSPI(VSPI);
    sdSPI.begin(SDCARD_SCLK, SDCARD_MISO, SDCARD_MOSI, SDCARD_CS);

    if (!SD.begin(SDCARD_CS, sdSPI)) {
        Serial.println("Card Mount Failed");
    }
    else {
        Serial.println("Card Mount OK");

        uint8_t cardType = SD.cardType();

        if(cardType == CARD_NONE){
            Serial.println("No SD card attached");
            return;
        }

        Serial.print("SD Card Type: ");
        if (cardType == CARD_MMC) {
            Serial.println("MMC");
        }
        else if(cardType == CARD_SD){
            Serial.println("SDSC");
        }
        else if(cardType == CARD_SDHC){
            Serial.println("SDHC");
        }
        else {
            Serial.println("UNKNOWN");
        }

        uint64_t cardSize = SD.cardSize() / (1024 * 1024);
        Serial.printf("SD Card Size: %lluMB\n", cardSize);
    }
}

bool SD_Utils::fileExists(const char* path) {
  return SD.exists(path);
}


String SD_Utils::getFileContent(const char * path) {
  File file = SD.open(path);
  if (!file) {
    Serial.println("Failed to open file for reading");
    return "";
  }

  String content = "";
  while (file.available()) {
    content += (char)file.read();
  }
  file.close();

  return content;
}