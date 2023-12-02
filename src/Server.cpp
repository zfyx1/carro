#include <ESPAsyncWebServer.h>
#include <API.h>
#include <Utils_APIREST.h>
#include <OTA.h>

AsyncWebServer server(80);

void homeRequest(AsyncWebServerRequest *request)
{
    Serial.println("Llamo al home");
    request->send(200, "text/plain", "Hello, world, aqui carrito");
}

void notFound(AsyncWebServerRequest *request)
{
    request->send(404, "text/plain", "Not found");
}

void InitServer()
{
    while (!isConnected())
    {
        Serial.println("Esperando conexion a la wifi");
        delay(5000);
    }
    Serial.println("Escuchando comandos");
    server.on("/", HTTP_GET, homeRequest);
    server.on("/velocidad", HTTP_GET, apiSetVelocidad);

    server.on("/item", HTTP_GET, getRequest);
    server.on(
        "/item", HTTP_POST, [](AsyncWebServerRequest *request) {}, NULL, postRequest);
    server.on(
        "/item", HTTP_PUT, [](AsyncWebServerRequest *request) {}, NULL, putRequest);
    server.on(
        "/item", HTTP_PATCH, [](AsyncWebServerRequest *request) {}, NULL, patchRequest);
    server.on("/item", HTTP_DELETE, deleteRequest);

    server.onNotFound(notFound);

    server.begin();
    Serial.println("HTTP server started");
}