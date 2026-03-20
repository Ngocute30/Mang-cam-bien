#include <esp_now.h>
#include <WiFi.h>

// MAC ESP2
uint8_t peerMAC[] = {0x5C, 0x01, 0x3B, 0x73, 0xD7, 0xBC};

typedef struct
{
  char message[100]; // chứa chuỗi
} Data;

Data data;

void onReceive(const uint8_t *mac, const uint8_t *incomingData, int len)
{
  Data receivedData;
  memcpy(&receivedData, incomingData, sizeof(receivedData));

  Serial.print("ESP1 Received: ");
  Serial.println(receivedData.message);
}

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  esp_now_init();
  esp_now_register_recv_cb(onReceive);

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, peerMAC, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  peerInfo.ifidx = WIFI_IF_STA;

  esp_now_add_peer(&peerInfo);

  Serial.println("ESP1 READY - Nhap tin nhan:");
}

void loop()
{
  if (Serial.available())
  {
    String input = Serial.readStringUntil('\n');

    input.trim(); // bỏ xuống dòng

    input.toCharArray(data.message, sizeof(data.message));

    esp_err_t result = esp_now_send(peerMAC, (uint8_t *)&data, sizeof(data));

    if (result == ESP_OK)
    {
      Serial.print("ESP1 Sent: ");
      Serial.println(data.message);
    }
    else
    {
      Serial.println("Send FAIL");
    }
  }
}

// //NOI CHUYEN VOI NHAU BANG ESPNOW

// #include <esp_now.h>
// #include <WiFi.h>

// // MAC ESP2
// uint8_t peerMAC[] = {0x5C,0x01,0x3B,0x73,0xD7,0xBC};

// typedef struct {
//   int value;
// } Data;

// Data data;

// void onReceive(const uint8_t * mac, const uint8_t *incomingData, int len) {
//   Data receivedData;
//   memcpy(&receivedData, incomingData, sizeof(receivedData));

//   Serial.print("ESP1 Received: ");
//   Serial.println(receivedData.value);
// }

// void setup() {
//   Serial.begin(115200);
//   WiFi.mode(WIFI_STA);

//   if (esp_now_init() != ESP_OK) {
//     Serial.println("ESP-NOW ERROR");
//     return;
//   }

//   esp_now_register_recv_cb(onReceive);

//   esp_now_peer_info_t peerInfo = {};
//   memcpy(peerInfo.peer_addr, peerMAC, 6);
//   peerInfo.channel = 0;
//   peerInfo.encrypt = false;
//   peerInfo.ifidx = WIFI_IF_STA;

//   if (esp_now_add_peer(&peerInfo) != ESP_OK) {
//     Serial.println("ADD PEER FAIL");
//     return;
//   }

//   Serial.println("ESP1 READY");
// }

// void loop() {
//   data.value = random(0,100);

//   esp_err_t result = esp_now_send(peerMAC, (uint8_t *)&data, sizeof(data));

//   if (result == ESP_OK) {
//     Serial.print("ESP1 Send: ");
//     Serial.println(data.value);
//   } else {
//     Serial.println("ESP1 Send FAIL");
//   }

//   delay(2000);
// }
