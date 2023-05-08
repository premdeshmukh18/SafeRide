#include <ESP8266WiFi.h>
#include <espnow.h>
#include <LiquidCrystal_I2C.h>

int lcdColumns = 16;
int lcdRows = 2;
int motor = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
  int a;
  int b;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.println("mq3_value: ");
  Serial.println(myData.a);

  Serial.println("helmet_wear:");
  Serial.println(myData.b);
  
  // set cursor to first column, first row
  lcd.setCursor(0, 0);

  if (myData.a == 1 && myData.b == 0) {
    Serial.println("SAFE TO RIDE");
    lcd.print("SAFE TO RIDE");
    //delay(1000);
    //lcd.clear();
    digitalWrite(motor, HIGH);
  }
  else {
    if (myData.a == 0 && myData.b == 0) {
      Serial.println("ALCOHOL DETECTED");
      lcd.print("ALCOHOL DETECTED");
      //delay(1000);
      //lcd.clear();
      digitalWrite(motor, LOW);
    }
    else {
      Serial.println("WEAR HELMET     ");
      lcd.print("WEAR HELMET     ");
      //lcd.clear();
      digitalWrite(motor, LOW);
    }
    Serial.println("NOT SAFE TO RIDE");
  }
}

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();

  pinMode(motor, OUTPUT);
  Serial.begin(115200);
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    lcd.print("ESP NC");
    digitalWrite(motor,LOW);
    return;
  }

  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {

}
