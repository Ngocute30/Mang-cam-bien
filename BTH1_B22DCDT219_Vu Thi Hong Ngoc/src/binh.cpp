/////////////
/*
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define LDR_PIN 34
#define LED_PIN 25
#define LED1_PIN 26
#define LED2_PIN 27

#define DHT_PIN 4
#define DHTTYPE DHT22

DHT dht(DHT_PIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

int light_value = 0;

void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);

    dht.begin();

    lcd.init();
    lcd.backlight();
}

void loop()
{
    float nhiet_do = dht.readTemperature();
    float do_am = dht.readHumidity();

    light_value = analogRead(LDR_PIN);

    Serial.print("Light: ");
    Serial.println(light_value);

    lcd.clear();

    // dong 1 hthi nhiet do do am
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(nhiet_do);
    lcd.print("C ");

    lcd.print("H:");
    lcd.print(do_am);
    lcd.print("%");

    // dong 2 hien thi sang/toi
    lcd.setCursor(0, 1);

    if (light_value < 2000)
    {
        digitalWrite(LED_PIN, LOW);
        lcd.print("Troi: SANG");
    }
    else
    {
        digitalWrite(LED_PIN, HIGH);
        lcd.print("Troi: TOI");
    }

    // led nhap nhay chuki 1s
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    delay(500);

    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    delay(500);
}
*/
//////////////

/*
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define LDR_PIN 34
#define LED_PIN 25
#define DHT_PIN 4
#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

int light_value = 0;

void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);

    dht.begin();

    lcd.init();
    lcd.backlight();
}

void loop()
{
    float nhiet_do = dht.readTemperature();
    float do_am = dht.readHumidity();

    light_value = analogRead(LDR_PIN);

    Serial.print("Light: ");
    Serial.println(light_value);

    lcd.clear();

    // dòng 1 hiển thị nhiệt độ và độ ẩm
    lcd.setCursor(0,0);
    lcd.print("T:");
    lcd.print(nhiet_do);
    lcd.print("C ");

    lcd.print("H:");
    lcd.print(do_am);
    lcd.print("%");

    // dòng 2 hiển thị sáng/tối
    lcd.setCursor(0,1);

    if(light_value < 2000)
    {
        digitalWrite(LED_PIN, LOW);
        lcd.print("Troi: SANG");
    }
    else
    {
        digitalWrite(LED_PIN, HIGH);
        lcd.print("Troi: TOI");
    }

    delay(2000);
}


*/

/*#include <Arduino.h>
#define LDR_PIN 34 // doc analog cb asang
#define LED_PIN 25 // chan dk led

int light_value = 0;

void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
}

void loop()
{

    light_value = analogRead(LDR_PIN); // doc as tu (0-4095)

    Serial.print("Light value: ");
    Serial.println(light_value);

    if (light_value < 2000)
    {
        digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
    }

    delay(500);
}

*/