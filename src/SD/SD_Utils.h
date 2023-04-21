class SD_Utils {
    private:
        // static SPIClass sdSPI;
        static const uint8_t SDCARD_MISO = 2;
        static const uint8_t SDCARD_CS = 13;
        static const uint8_t SDCARD_SCLK = 14;
        static const uint8_t SDCARD_MOSI = 15;
    public:
        static void init();
        static bool fileExists(const char* path);
        // static String getFileContent(const char* path);
};
