/**
 * 
 */

#include "LogicGatesTimer.h"

/**
 * 
 */
LogicGatesTimer::LogicGatesTimer(unsigned long tiempo, uint8_t unidad)
{

    _start_time = 0;
    _objetive_time = tiempo;
    _use_milliseconds = (unidad == LogicGates::MILISEGUNDOS);

}

/**
 * 
 */
void LogicGatesTimer::iniciar()
{

    _use_milliseconds ? _start_time = millis() : _start_time = micros();

}

/**
 * 
 */
bool LogicGatesTimer::comprobar()
{

    if(((_use_milliseconds ? millis() : micros()) - _start_time) > _objetive_time)
        return true;

    return false;

}
