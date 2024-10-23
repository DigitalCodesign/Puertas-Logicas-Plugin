/**
 * LogicGatesSignal.cpp - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Definición de la clase LogicGateSignal, referida a la gestión de Señales generadas.
 */

#include "LogicGatesSignal.h"

/**
 * Constructor de la clase LogicGatesSignal indicando como argumentos los parámetros para
 * la Señal que se desea generar.
 * 
 * @param:
 *  - uint8_t gpio_salida: Pin del microcontrolador donde generar la Señal creada.
 *  - uint16_t frecuencia: Frecuencia de oscilación de la Señal creada.
 */
LogicGatesSignal::LogicGatesSignal(uint8_t gpio_salida, uint16_t frecuencia)
{

    _enable = false;
    _gpio_out = gpio_salida;
    _frequency = (frecuencia > 0) ? frecuencia : 0;
    _period = 1000 / _frequency;

    pinMode(_gpio_out, OUTPUT);
    digitalWrite(_gpio_out, LOW);

}

/**
 * Método para habilitar la generación de la Señal creada.
 */
void LogicGatesSignal::iniciar()
{

    _enable = true;

}

/**
 * Método para deshabilitar la generación de la Señal creada.
 */
void LogicGatesSignal::detener()
{

    _enable = false;

}

/**
 * Método para modificar la frecuencia de oscilación de la Señal creada.
 * 
 * @param:
 *  - uint16_t frecuencia: Nueva frecuencia de oscilación deseada para la Señal.
 */
void LogicGatesSignal::editarFrecuencia(uint16_t frecuencia)
{

    _frequency = (frecuencia > 0) ? frecuencia : 0;
    _period = 1000 / _frequency;

}

/**
 * Método que debe llamarse constantemente para actualizar el estado de la señal
 * y realizar las oscilaciones correspondientes en los momentos adecuados.
 */
uint8_t LogicGatesSignal::actualizar()
{


    if(((millis() - _last_time) >= _period) && _enable)
    {

        digitalWrite(_gpio_out, !digitalRead(_gpio_out));
        _last_time = millis();

    }

}
