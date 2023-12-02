#include <Arduino.h>
#include <Servo.h>
#define SERVO_DERECHO_DELANTE 33
#define SERVO_DERECHO_ATRAS 27
#define SERVO_IZQUIERDO_DELANTE 32
#define SERVO_IZQUIERDO_ATRAS 26

Servo myservo = Servo();
int velocidad = 0, direccion = 0, rotacion = 0, velocidadRotacion = 0;
void setVelocidad(int v)
{
  velocidad = v;
}
void setDireccion(int d)
{
  direccion = d;
}

void motoresTask(void *params)
{
  while (true)
  {
    // myservo.write(33, map((velocidad*direccion)+(velocidadRotacion*rotacion), -100, 100, 180, 0));  // izquierda

    myservo.write(SERVO_DERECHO_DELANTE, map(velocidad * direccion - velocidadRotacion * rotacion, -100, 100, 0, 180));   // derecha delante
    myservo.write(SERVO_IZQUIERDO_DELANTE, map(velocidad * direccion + velocidadRotacion * rotacion, -100, 100, 180, 0)); // izquierda delante
    myservo.write(SERVO_IZQUIERDO_ATRAS, map(velocidad * direccion + velocidadRotacion * rotacion, -100, 100, 180, 0));   // izquierda trasera
    myservo.write(SERVO_DERECHO_ATRAS, map(velocidad * direccion - velocidadRotacion * rotacion, -100, 100, 0, 180));     // derecha trasera
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}