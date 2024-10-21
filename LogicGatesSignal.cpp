/**
 * 
 */

#include "LogicGatesSignal.h"

/**
 * 
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
 * 
 */
void LogicGatesSignal::iniciar()
{

    _enable = true;

}

/**
 * 
 */
void LogicGatesSignal::detener()
{

    _enable = false;

}

/**
 * 
 */
void LogicGatesSignal::editarFrecuencia(uint16_t frecuencia)
{

    _frequency = (frecuencia > 0) ? frecuencia : 0;
    _period = 1000 / _frequency;

}

/**
 * 
 */
uint8_t LogicGatesSignal::actualizar()
{


    if(((millis() - _last_time) >= _period) && _enable)
    {

        digitalWrite(_gpio_out, !digitalRead(_gpio_out));
        _last_time = millis();

    }

}