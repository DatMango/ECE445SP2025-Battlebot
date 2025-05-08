#include <WiFi.h>


// Using Hotspot as WiFi -- Credentials
const char * ssid ="Yuxuan S24";
const char * password ="qwertyui";


// GPIO setup
#define AIN1_PIN      14
#define AIN2_PIN      26
#define BIN1_PIN      27
#define BIN2_PIN      32
#define ATTACK_PIN    33    // Pneumatic
#define WIFI_PIN      27    // Original was Bluetooth
// #define TEST_PIN      38



bool get_message(char *msg){
    return xQueueReceive(_recv_q, (void*)msg, 5) == pdTRUE;
  }