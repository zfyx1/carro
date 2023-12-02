#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <ArduinoJson.h>

#include "Server.h"

void controlTask(void *params)
{
      InitServer();
      while (true)
      {
            vTaskDelay(1000 / portTICK_PERIOD_MS);
      }
}
