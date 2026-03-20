/*#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

DHT Dht11(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Ký tự độ C custom
byte doC[8] = {
    0b00110,
    0b01001,
    0b01001,
    0b00110,
    0b00000,
    0b00000,
    0b00000,
    0b00000};

void setup()
{
    Serial.begin(9600);
    Dht11.begin();

    lcd.init();
    lcd.backlight();
    lcd.createChar(0, doC);

    lcd.setCursor(0, 0);
    lcd.print("DHT11 Ready");
    delay(2000);
    lcd.clear();
}

void loop()
{
    float do_am = Dht11.readHumidity();
    float nhiet_do = Dht11.readTemperature();

    if (isnan(do_am) || isnan(nhiet_do))
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Sensor Error");
        delay(2000);
        return;
    }

    // Dòng 1: Nhiệt độ
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(nhiet_do, 1);
    lcd.write(byte(0)); // ký tự độ C
    lcd.print("C");

    // Dòng 2: Độ ẩm
    lcd.setCursor(0, 1);
    lcd.print("Hum : ");
    lcd.print(do_am, 1);
    lcd.print(" %");

    delay(2000);
}

*/
// #include <Arduino.h>
// #include "DHT.h"

// DHT Dht11(4, DHT11);

// void setup()
// {
//   Serial.begin(9600);
//   Dht11.begin();
// }

// void loop()
// {
//   float do_am = Dht11.readHumidity();
//   float nhiet_do = Dht11.readTemperature();
//   if (isnan(do_am) || isnan(nhiet_do))
//   {
//     Serial.println("Error");
//     delay(2000);
//     return;
//   }
//   Serial.print(nhiet_do);
//   Serial.print(" °C | Do am: ");
//   Serial.print(do_am);
//   Serial.println(" %");
//   delay(2000);
// }

// lcd.print("Temp: ");
// lcd.print(nhiet_do, 1);
// lcd.print((char)223);
// lcd.print("C");