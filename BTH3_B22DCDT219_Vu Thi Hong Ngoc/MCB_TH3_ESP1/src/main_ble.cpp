// client
/*
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

bool connected = false;

void setup()
{
    Serial.begin(115200);

    Serial.println("Connecting...");

    SerialBT.begin("ESP32_CLIENT", true); // master

    delay(2000);

    if (SerialBT.connect("ESP32_SERVER"))
    {
        Serial.println("Connected to server");
        connected = true;
    }
    else
    {
        Serial.println("Failed to connect");
    }
}

void loop()
{
    if (connected)
    {

        // 🔥 gửi
        SerialBT.println("Hello from ESP1");

        // 🔥 nhận
        if (SerialBT.available())
        {
            String msg = SerialBT.readStringUntil('\n');
            Serial.print("ESP1 Received: ");
            Serial.println(msg);
        }
    }

    delay(2000);
}

*/