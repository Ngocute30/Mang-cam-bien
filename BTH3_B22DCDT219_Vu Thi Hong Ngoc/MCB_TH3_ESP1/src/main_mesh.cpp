/*#include "painlessMesh.h"

#define MESH_PREFIX "ESP_MESH"
#define MESH_PASSWORD "12345678"
#define MESH_PORT 5555

painlessMesh mesh;

// hàm gửi dữ liệu
void sendMessage()
{
  String msg = "Hello from node ";
  msg += mesh.getNodeId();

  mesh.sendBroadcast(msg);

  Serial.println("Send: " + msg);
}

// callback nhận
void receivedCallback(uint32_t from, String &msg)
{
  Serial.printf("Received from %u: %s\n", from, msg.c_str());
}

void setup()
{
  Serial.begin(115200);

  mesh.setDebugMsgTypes(ERROR | STARTUP);
  mesh.init(MESH_PREFIX, MESH_PASSWORD, MESH_PORT);

  mesh.onReceive(&receivedCallback);

  mesh.addTask(2000, TASK_FOREVER, []()
               { sendMessage(); });

  Serial.println("MESH STARTED");
}

void loop()
{
  mesh.update();
}

*/