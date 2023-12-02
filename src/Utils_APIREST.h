#ifndef _Utils_APIREST_
#define _Utils_APIREST_
#include <ESPAsyncWebServer.h>

void postRequest(AsyncWebServerRequest * request, uint8_t *data, size_t len, size_t index, size_t total);
void patchRequest(AsyncWebServerRequest * request, uint8_t *data, size_t len, size_t index, size_t total);
void putRequest(AsyncWebServerRequest * request, uint8_t *data, size_t len, size_t index, size_t total);
void deleteRequest(AsyncWebServerRequest *request);
String GetBodyContent(uint8_t *data, size_t len);
int GetIdFromURL(AsyncWebServerRequest *request, String root);



#endif