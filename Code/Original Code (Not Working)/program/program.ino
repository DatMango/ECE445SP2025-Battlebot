// #include "link.h"

#include "config.h"
#include "my_wifi.h"
#include "wifi_communicator.h"


// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(115200);

//   WiFi.begin(ssid,password);


//   Serial.print("Connecting WIFI");
//   while (WiFi.status()!= WL_CONNECTED)
//   {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("Connected");
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.localIP());
  

//   // WiFi Connect Pin, turn LED on
//   pinMode(WIFI_PIN, OUTPUT);
//   digitalWrite(WIFI_PIN, HIGH);

  
//   // Enable all GPIO
//   pinMode(AIN1_PIN, OUTPUT);
//   pinMode(AIN2_PIN, OUTPUT);
//   pinMode(BIN1_PIN, OUTPUT);
//   pinMode(BIN2_PIN, OUTPUT);
//   pinMode(ATTACK_PIN, OUTPUT);


//   // Test Code
//   // pinMode(TEST_PIN, OUTPUT); // set the pin as output
  
// }


// void loop() {
//   // put your main code here, to run repeatedly:
  
  




//   // Test Code
//   // digitalWrite(TEST_PIN, HIGH);
//   // delay(500);
//   // digitalWrite(TEST_PIN, LOW);
//   // delay(500);

// }




#include <MyButton.h>

#define ENABLE_DEBUG /* <-- Commenting this line will remove any trace of debug printing */
#include <MacroDebugger.h>

#define NUM_LEDS 5
const int LED_PINS[NUM_LEDS] = { AIN1_PIN, AIN2_PIN, BIN1_PIN, BIN2_PIN, PNEUMATIC_PIN };


// Button object to simulate input events
MyButton my_btn(BTN_PIN, NORMAL_DOWN, 50);

// Communication messages
char incoming_msg[MAX_BUFFER_LEN] = {0};
char response[MAX_BUFFER_LEN] = {0};

/* A collection of random responses to send when the button is clicked */
#define NUM_RANDOM_RESPONSES    10
char *responses[NUM_RANDOM_RESPONSES] = {
  "hola!",
  "hiii",
  "potato",
  "arduino",
  "esp32",
  "okay so we get it it's a random message!",
  "so what?",
  "running out of messages here",
  "okay two more to go",
  "finally ..."
};

void setup(){
  DEBUG_BEGIN();
  
  setup_wifi();
  
  setup_wifi_communicator();
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);


  pinMode(AIN1_PIN, OUTPUT);
  pinMode(AIN2_PIN, OUTPUT);
  pinMode(BIN1_PIN, OUTPUT);
  pinMode(BIN2_PIN, OUTPUT);
  pinMode(PNEUMATIC_PIN, OUTPUT);

  DEBUG_I("Done setting up!");
}

void loop(){

  // if we lost connection, we attempt to reconnect (blocking)
  if(!is_client_connected()){
    digitalWrite(LED_PIN, LOW);
    connect_client(); 
    digitalWrite(LED_PIN, HIGH);
  }
  
  bool received = get_message(incoming_msg);

  if(received){
    DEBUG_I("Received: %s", incoming_msg);
    uint8_t start = 0;

    // if(incoming_msg[0] == 'A'){
    //   sprintf(response, "%s", ACK);
    //   start++;
    // }

    // //switch the number and do the appropriate action
    // switch(incoming_msg[start]){
    //   case 'n':
    //     digitalWrite(AIN1_PIN, HIGH);
    //     break;

    //   default:
    //   case 'f':
    //     digitalWrite(AIN1_PIN, LOW);
    //     break;
    // }

    int btn_index = incoming_msg[0] - '0';  // Convert ASCII to integer
    char state = incoming_msg[1];  // Get 'n' or 'f' state

    // Validate button index
    if (btn_index >= 0 && btn_index < NUM_LEDS) {
      if (state == 'n') {
        digitalWrite(LED_PINS[btn_index], HIGH);
      } else if (state == 'f') {
        digitalWrite(LED_PINS[btn_index], LOW);
      }
    }


    // If start is bigger than 0, then we have to acknowledge the reception
    if(start > 0){
      send_message(response);
      // Clear the response buffer
      memset(response, 0, MAX_BUFFER_LEN);
    }
  }

  if(my_btn.readRisingClick()){
    // Choose a random response to send back
    uint8_t idx = random(NUM_RANDOM_RESPONSES);
    strncpy(response, responses[idx], MAX_BUFFER_LEN);
    send_message(response);
    memset(response, 0, MAX_BUFFER_LEN);
    DEBUG_I("Sent: %s", responses[idx]);
  }
}


