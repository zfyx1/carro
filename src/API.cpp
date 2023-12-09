#include <Arduino.h>
#include "Utils_APIREST.h"
#include <motores.h>

const char *PARAM_FILTER = "filter";

void getAll(AsyncWebServerRequest *request)
{
  String message = "Get All";
  Serial.println(message);
  request->send(200, "text/plain", message);
}

void getFiltered(AsyncWebServerRequest *request)
{
  String message = "Get filtered by " + request->getParam(PARAM_FILTER)->value();
  Serial.println(message);
  request->send(200, "text/plain", message);
}

void getById(AsyncWebServerRequest *request)
{
  int id = GetIdFromURL(request, "/item/");

  String message = String("Get by Id ") + id;
  if (id == 1)
  {
    setVelocidad(45);
    setDireccion(1);
  }
  if (id == -1)
  {
    setVelocidad(45);
    setDireccion(-1);
  }
  if (id == 0)
  {
    setDireccion(0);
  }

  Serial.println(message);
  request->send(200, "text/plain", message);
}

void apiSetVelocidad(AsyncWebServerRequest *request)
{
  int id = GetIdFromURL(request, "/velocidad/");

  String message = String("Set Velocidad ") + id;
  if (id > 0)
  {
    setDireccion(1);
    setVelocidad(id);
  }
  else if (id < 0)
  {
    setDireccion(-1);
    setVelocidad(id * -1);
  }
  else
  {
    setDireccion(0);
    setVelocidad(0);
  }

  Serial.println(message);
  request->send(200, "text/plain", message);
}

void apiSetRotacion(AsyncWebServerRequest *request)
{
  int id = GetIdFromURL(request, "/rotacion/");

  String message = String("Set Rotacion ") + id;
  if (id > 0)
  {
    setRotacion(1);
    setVelocidadRotacion(id);
  }
  else if (id < 0)
  {
    setRotacion(-1);
    setVelocidadRotacion(id * -1);
  }
  else
  {
    setRotacion(0);
    setVelocidadRotacion(0);
  }

  Serial.println(message);
  request->send(200, "text/plain", message);
}
void getRequest(AsyncWebServerRequest *request)
{

  if (request->hasParam(PARAM_FILTER))
  {
    getFiltered(request);
  }
  else if (request->url().indexOf("/item/") != -1)
  {
    getById(request);
  }
  else
  {
    getAll(request);
  }
}
