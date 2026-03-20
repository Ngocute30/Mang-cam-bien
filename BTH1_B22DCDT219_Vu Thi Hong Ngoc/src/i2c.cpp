// #include <Arduino.h>
// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// #define LCD_ADDR 0x27 
// #define LCD_COLS 16
// #define LCD_ROWS 2

// LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

// void setup()
// {
//     Wire.begin(21, 22);

//     lcd.init();      // khởi tạo LCD
//     lcd.backlight(); // bật đèn nền

//     lcd.setCursor(0, 0);
//     lcd.print("MCB Hong Ngoc");

//     lcd.setCursor(0, 1);
//     lcd.print("ESP32 I2C LCD");
// }

// void loop()
// {
//     // không cần làm gì thêm
// }

// // #include <Arduino.h>
// // #include <Wire.h>
// // #include <BH1750.h>

// // BH1750 lightMeter(0x23);

// // void setup() {
// //   Serial.begin(9600);
// //   delay(1000);

// //   Wire.begin(21, 22);
// //   Wire.setClock(100000);   // I2C standard mode

// //   Serial.println("Init BH1750...");

// //   if (!lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
// //     Serial.println("BH1750 NOT FOUND");
// //     while (1) {
// //       delay(1000);
// //     }
// //   }

// //   Serial.println("BH1750 OK");
// // }

// // void loop() {
// //   float lux = lightMeter.readLightLevel();

// //   if (lux < 0) {
// //     Serial.println("Read error");
// //   } else {
// //     Serial.print("Cuong do anh sang: ");
// //     Serial.print(lux);
// //     Serial.println(" lux");
// //   }

// //   delay(1000);
// // }
