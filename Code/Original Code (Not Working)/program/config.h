#ifndef __CONFG_H___
#define __CONFG_H___

/* Pins definitions */

#define AIN1_PIN                    37
#define AIN2_PIN                    36
#define BIN1_PIN                    35
#define BIN2_PIN                    45
#define PNEUMATIC_PIN               9
#define LED_PIN                     38
#define BTN_PIN                     25 // Useless

// // GPIO setup
// #define AIN1_PIN      14
// #define AIN2_PIN      26
// #define BIN1_PIN      27
// #define BIN2_PIN      32
// #define ATTACK_PIN    33    // Pneumatic
// #define WIFI_PIN      27    // Original was Bluetooth


/* Communication params */
#define ACK                         "A" // acknowledgment packet
#define QUEUE_LEN                   5
#define MAX_BUFFER_LEN              128

/* WiFi params */
#define WIFI_SSID                   "Yuxuan S24"
#define WIFI_PASSWORD               "qwertyui"

/* Socket */
#define SERVER_ADDRESS              "192.168.107.188" //"PYTHON.IP.GOES.HERE"
#define SERVER_PORT                 11111

#endif // __CONFG_H___