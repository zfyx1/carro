#ifndef _API_
#define _API_
#include <ESPAsyncWebServer.h>

void getAll(AsyncWebServerRequest *request);
void getFiltered(AsyncWebServerRequest *request);
void getById(AsyncWebServerRequest *request);
void getRequest(AsyncWebServerRequest *request);
void apiSetVelocidad(AsyncWebServerRequest *request);

#endif