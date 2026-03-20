// //server


// #include "BluetoothSerial.h"

// BluetoothSerial SerialBT;

// void setup() {
//   Serial.begin(115200);
//   SerialBT.begin("ESP32_SERVER");

//   Serial.println("Bluetooth Server Ready");
// }

// void loop() {
//   // 🔥 nhận dữ liệu
//   if (SerialBT.available()) {
//     String msg = SerialBT.readStringUntil('\n');
//     Serial.print("ESP2 Received: ");
//     Serial.println(msg);
//   }

//   // 🔥 gửi chủ động
//   SerialBT.println("Hello from ESP2");

//   delay(2000);
// }


// // #include "BluetoothSerial.h"

// // BluetoothSerial SerialBT;

// // void setup() {
// //   Serial.begin(115200);
// //   SerialBT.begin("ESP32_SERVER");  // tên Bluetooth

// //   Serial.println("Bluetooth Server Ready");
// // }

// // void loop() {
// //   // nhận dữ liệu
// //   if (SerialBT.available()) {
// //     String msg = SerialBT.readString();
// //     Serial.print("Received: ");
// //     Serial.println(msg);

// //     // gửi lại
// //     SerialBT.println("Reply: " + msg);
// //   }
// // }