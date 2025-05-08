#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// Code for helping change actual Dabble libraries to work on current ESP32 core
// #if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(5, 1, 1)
//   ledcAttach(LED_BUILTIN, 5000, 8);
// #else
//   ledcSetup(0, 5000, 8);
//   ledcAttachPin(LED_BUILTIN, 0);
// #endif


// INITIALIZING VARIABLES
// ESP32-S3 Version (Fried)
// int EN1 = 37;     // MOTOR 1 CONNECTIONS 
// int EN2 = 38;     // MOTOR 2 CONNECTIONS
// int EN3 = 36;     // MOTOR 3 CONNECTIONS
// int EN4 = 39;     // MOTOR 4 CONNECTIONS
// int PNE = 40;     // PNEUMATICS

// ESP32
// int EN1 = 4; // HBridge A1
// int EN2 = 16; // HBridge A2
// int EN3 = 17; // HBridge B1
// int EN4 = 5; // HBridge B2
// int PNE = 18; // Pneumatic
// int BLE = 19; // Bluetooth LED

// ESP32 Bare Chip
int EN1 = 13; // HBridge A1
int EN2 = 14; // HBridge A2
// int EN3 = 18; // HBridge B1
int EN3 = 32; // HBridge B1
int EN4 = 19; // HBridge B2
int PNE = 17; // Pneumatic
int BLE = 16; // Bluetooth LED




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("Scooper");       //set bluetooth name of your device

  Serial.println("ROBOT CAR..\n\n");
  pinMode(EN1, OUTPUT);  // MOTOR 1 AS OUTPUT
  pinMode(EN2, OUTPUT);  // MOTOR 2 AS OUTPUT
  pinMode(EN3, OUTPUT);  // MOTOR 3 AS OUTPUT
  pinMode(EN4, OUTPUT);  // MOTOR 4 AS OUTPUT
  pinMode(PNE, OUTPUT);  // Pneumatic AS OUTPUT
  pinMode(BLE, OUTPUT);  // Bluetooth
  digitalWrite(BLE, HIGH);
  

}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");

  // Move up
  if (GamePad.isUpPressed())
  {
    Serial.print("Up");
    Serial.println(" ROBOT CAR MOVING FORWARD...");
    // digitalWrite(EN1, HIGH);
    // delay(200);
    // digitalWrite(EN1, LOW);
    digitalWrite(EN1, HIGH); // AIN1 = 1
    digitalWrite(EN3, HIGH); // BIN1 = 1
    digitalWrite(EN2, LOW); // AIN2 = 0
    digitalWrite(EN4, LOW); // BIN2 = 0
    delay(200);
    digitalWrite(EN1, LOW);
    digitalWrite(EN3, LOW);

  }

  if (GamePad.isDownPressed())
  {
    Serial.print("Down");
    Serial.println(" ROBOT CAR MOVING BACKWARD...");
    // digitalWrite(EN2, HIGH);
    // delay(200);
    // digitalWrite(EN2, LOW);
    digitalWrite(EN1, LOW); // AIN1 = 0
    digitalWrite(EN3, LOW); // BIN1 = 0
    digitalWrite(EN2, HIGH); // AIN2 = 1
    digitalWrite(EN4, HIGH); // BIN2 = 1
    delay(200);
    digitalWrite(EN2, LOW);
    digitalWrite(EN4, LOW);

  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    Serial.println(" ROBOT CAR MOVING LEFT...");
    // digitalWrite(EN3, HIGH);
    // delay(200);
    // digitalWrite(EN3, LOW);

    // Turn on only right motor
    digitalWrite(EN1, LOW); // AIN1 = 0
    digitalWrite(EN2, LOW); // AIN2 = 0
    digitalWrite(EN3, HIGH); // BIN1 = 1
    digitalWrite(EN4, LOW); // BIN2 = 0
    delay(200);
    digitalWrite(EN3, LOW);

  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    Serial.println(" ROBOT CAR MOVING RIGHT...");
    // digitalWrite(EN4, HIGH);
    // delay(200);
    // digitalWrite(EN4, LOW);
    digitalWrite(EN1, HIGH); // AIN1 = 1
    digitalWrite(EN2, LOW); // AIN2 = 0
    digitalWrite(EN3, LOW); // BIN1 = 0
    digitalWrite(EN4, LOW); // BIN2 = 0
    delay(200);
    digitalWrite(EN1, LOW);

  }

  if (GamePad.isTrianglePressed() || GamePad.isSquarePressed() || GamePad.isCirclePressed() || GamePad.isCrossPressed())
  {
    Serial.print("Four Button");
    Serial.println(" PNEUMATICS... ");
    digitalWrite(PNE, HIGH);
    delay(400);
    digitalWrite(PNE, LOW);
  }

}
