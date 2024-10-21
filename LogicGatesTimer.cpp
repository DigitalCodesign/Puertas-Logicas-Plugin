/**
 * 
 */

#include "LogicGatesTimer.h"

/**
 * 
 */
LogicGatesTimer::LogicGatesTimer()
{

    _start_time = 0;
    _objetive_time = -1;
    _use_milliseconds = true;
    _enable = false;

}

/**
 * 
 */
LogicGatesTimer::LogicGatesTimer(unsigned long tiempo, uint8_t unidad)
{

    _start_time = 0;
    _objetive_time = tiempo;
    _use_milliseconds = (unidad == LogicGates::MILISEGUNDOS);
    _enable = false;

}

/**
 * 
 */
void LogicGatesTimer::iniciar()
{

    _start_time = millis();
    _enable = true;

}

/**
 * 
 */
void LogicGatesTimer::establecer(unsigned long tiempo, uint8_t unidad)
{

    _start_time = 0;
    _objetive_time = tiempo;
    _use_milliseconds = (unidad == LogicGates::MILISEGUNDOS);

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
