#include <ESP8266WiFi.h>
#include <espnow.h>

// REPLACE WITH RECEIVER MAC Address
uint8_t broadcastAddress[] = {0xBC,0xDD,0xC2,0x17,0xAD,0x2B};

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
   int a;
   int b;
} struct_message;

  int sensorval;
  int data_button;


// Create a struct_message called myData
struct_message myData;

unsigned long lastTime = 0;  
unsigned long timerDelay = 10;  // send readings timer

// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0){
    Serial.println("Delivery success");
//    Serial.print("MQ3:");
//    Serial.println(sensorval);
//    Serial.print(" Push_BUtton");
//    Serial.println(data_button);
  }
  else{
    Serial.println("Delivery fail");
  }
}
 
void setup() {
  // Init Serial Monitor
  Serial.begin(115200);
  pinMode(A0,INPUT);
  pinMode(13,INPUT);
  digitalWrite(
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}
 
void loop() {
     sensorval = analogRead(A0);
     data_button=digitalRead(12);
  if ((millis() - lastTime) > timerDelay) {
    // Set values to send
    
    myData.a = sensorval;
    myData.b = data_button;
    // Send message via ESP-NOW
    esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
    
   lastTime = millis();
    Serial.print("MQ3:");
    Serial.println(sensorval);
    Serial.print(" Push_BUtton");
    Serial.println(data_button);
  }
}
