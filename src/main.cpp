#include <Arduino.h>

// #include <SPI.h>

// https://randomnerdtutorials.com/esp32-web-server-microsd-card/
//Libraries for OLED Display
#include <Wire.h>						// This library allows you to communicate with I2C / TWI devices.
#include <Adafruit_I2CDevice.h>
#include <Adafruit_SSD1306.h>
#include <Wifi_Utils.h>
#include <SD/SD_Utils.h>
// #include "HTTPClient.h"
// #include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"

#define OLED_RST -1
#define I2C_ADDRESS 0x3c // Address 0x3C for 128x32
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

AsyncWebServer server(80);
SD_Utils sdUtils;


/**
 * Initialize OLED
 * @brief 
 */
void initScreen() {
	Wire.begin(OLED_SDA, OLED_SCL);
	if(!display.begin(SSD1306_SWITCHCAPVCC, I2C_ADDRESS, false, false)) { 
		Serial.println(F("SSD1306 allocation failed"));
		for(;;); // Don't proceed, loop forever
	}

	display.clearDisplay();
	display.setRotation(2);

	display.setTextColor(WHITE);
	display.setTextSize(1);
	display.setCursor(0,0);
}



void setup() {
	Serial.begin(9600);
	initScreen();
	display.print("LORA RECEIVER 10");
	display.display();

	Serial.println("LoRa Receiver Test");
  	
	// Setup pins
	pinMode(LED_BUILTIN, OUTPUT);

	Wifi_Utils::connect("MikroTik-441D07", "11111111");
	sdUtils.init();

	// Handle requests to the root URL ("/")


	server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
		// request->send(200, "text/plain", "Hello, world!");
		// File file = SD.open("/index.html");


		String file = sdUtils.getFileContent("/index.html");

		if (!file) {
			request->send(404, "text/plain", "File not found");
		}
		else {
			request->send(200, "text/html", file);
		}
	});

	// Handle requests to other URLs
	server.on("/example", HTTP_GET, [](AsyncWebServerRequest *request) {
		request->send(200, "text/plain", "This is an example page");
	});




	// Start the server
	server.begin();
}

void loop() {
//   digitalWrite(LED_BUILTIN, HIGH);
//   delay(500);
//   digitalWrite(LED_BUILTIN, LOW);
	// Serial.print("\nHello");
  	// delay(2000);
}
