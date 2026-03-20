// #include <Arduino.h>
// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// #include <SPI.h>
// #include <MFRC522.h>
// #include "DHT.h"

// //
// #define LCD_ADDR 0x27
// #define LCD_COLS 16
// #define LCD_ROWS 2

// LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

// // RFID MFRC522 
// #define SS_PIN   5
// #define RST_PIN  27

// MFRC522 rfid(SS_PIN, RST_PIN);

// //dht11
// #define DHT_PIN 4
// #define DHT_TYPE DHT11

// DHT dht(DHT_PIN, DHT_TYPE);

// void setup()
// {
//     /* ---------- Serial ---------- */
//     Serial.begin(9600);
//     Serial.println("System start...");

//     /* ---------- LCD I2C ---------- */
//     Wire.begin(21, 22);      // SDA = GPIO21, SCL = GPIO22
//     lcd.init();              // Khởi tạo LCD
//     lcd.backlight();         // Bật đèn nền

//     lcd.setCursor(0, 0);
//     lcd.print("RFID + DHT11");
//     lcd.setCursor(0, 1);
//     lcd.print("System Ready");

//     //dht11
//     dht.begin();             // Khởi tạo cảm biến DHT11

//     //spi 
//     // SPI pins:
//     // SCK  = GPIO18
//     // MISO = GPIO19
//     // MOSI = GPIO23
//     // SS   = GPIO5
//     SPI.begin(18, 19, 23, 5);
//     rfid.PCD_Init();         // Khởi tạo module RFID

//     delay(1500);
// }

// void loop()
// {
//     //Đọc nhiệt độ & độ ẩm 
//     float temperature = dht.readTemperature(); // °C
//     float humidity    = dht.readHumidity();    // %

//     // In ra Serial 
//     if (isnan(temperature) || isnan(humidity))
//     {
//         Serial.println("DHT11 Error");
//     }
//     else
//     {
//         Serial.print("Temp: ");
//         Serial.print(temperature);
//         Serial.print(" C | Hum: ");
//         Serial.print(humidity);
//         Serial.println(" %");
//     }

//     /* ---------- Hiển thị lên LCD (dòng 1) ---------- */
//     lcd.setCursor(0, 0);
//     if (isnan(temperature) || isnan(humidity))
//     {
//         lcd.print("DHT11 Error   ");
//     }
//     else
//     {
//         lcd.print("T:");
//         lcd.print(temperature);
//         lcd.print("C H:");
//         lcd.print(humidity);
//         lcd.print("% ");
//     }

//     /* ---------- Kiểm tra RFID ---------- */
//     if (!rfid.PICC_IsNewCardPresent())
//     {
//         delay(1000);
//         return;
//     }

//     if (!rfid.PICC_ReadCardSerial())
//     {
//         delay(1000);
//         return;
//     }

//     /* ---------- In UID ra Serial ---------- */
//     Serial.print("UID: ");
//     for (byte i = 0; i < rfid.uid.size; i++)
//     {
//         Serial.print(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
//         Serial.print(rfid.uid.uidByte[i], HEX);
//         Serial.print(" ");
//     }
//     Serial.println();

//     /* ---------- Hiển thị UID lên LCD (dòng 2) ---------- */
//     lcd.setCursor(0, 1);
//     lcd.print("UID: ");

//     for (byte i = 0; i < rfid.uid.size; i++)
//     {
//         if (rfid.uid.uidByte[i] < 0x10)
//             lcd.print("0");
//         lcd.print(rfid.uid.uidByte[i], HEX);
//         lcd.print(" ");
//     }

//     /* ---------- Kết thúc giao tiếp RFID ---------- */
//     rfid.PICC_HaltA();
//     rfid.PCD_StopCrypto1();

//     delay(2000);   // Tránh đọc lặp
// }


// /*typedef struct {
//     byte size;          // Số byte UID (4 / 7 / 10)
//     byte uidByte[10];   // Mảng chứa UID
//     byte sak;           // Select Acknowledge
// } Uid;
// size = 4
// uidByte = {0xA3, 0x9F, 0x4C, 0x1B}
// sak = 0x08

// DHT11	Đo vật lý	5 byte → float
// RFID	Nhận dạng	struct + byte array
// LCD I2C	Hiển thị	ASCII byte

// */