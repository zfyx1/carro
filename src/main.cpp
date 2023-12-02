#include <Arduino.h>

#include <motores.h>
#include <control.h>
#include <luces.h>
#include <OTA.h>

void setup()
{
  Serial.begin(115200);
  Serial.println("Booting");

  xTaskCreatePinnedToCore(motoresTask, "motoresTask", 4096, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(controlTask, "controlTask", 4096, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(OTATask, "OTATask", 4096, NULL, 1, NULL, 1);
  xTaskCreate(taskLuces, "taskLuces", 4096, NULL, 1, NULL);

}

void loop()
{
}