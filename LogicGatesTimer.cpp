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

}

/**
 * 
 */
void LogicGatesTimer::crearTemporizador(unsigned long tiempo, uint8_t unidad)
{

    _objetive_time = tiempo;
    _use_milliseconds = (unidad == LogicGates::MILISEGUNDOS);

}

/**
 * 
 */
void LogicGatesTimer::iniciarTemporizador()
{

    _use_milliseconds ? _start_time = millis() : _start_time = micros();

}

/**
 * 
 */
bool LogicGatesTimer::comprobarTemporizador()
{

    if(((_use_milliseconds ? millis() : micros()) - _start_time) > _objetive_time)
        return true;

    return false;

}
