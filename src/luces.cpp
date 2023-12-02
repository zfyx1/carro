#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 23      // Pin donde está conectada la tira de LEDs
#define NUM_LEDS 22 // Número de LEDs en la tira

Adafruit_NeoPixel strip(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// Función para encender los LEDs en color rojo
void redLEDs()
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        strip.setPixelColor(i, strip.Color(90, 0, 0)); // Rojo
        strip.show();
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

// Función para encender los LEDs en color verde
void greenLEDs()
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        strip.setPixelColor(i, strip.Color(0, 90, 0)); // Verde
        strip.show();
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void taskLuces(void *params)
{
    strip.begin();
    strip.show(); // Apagar todos los LEDs al inicio
    // No se utiliza en este caso
    while (true)
    {
        redLEDs();
        greenLEDs();
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
