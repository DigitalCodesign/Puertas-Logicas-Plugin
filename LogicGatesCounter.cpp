/**
 * 
 */

#include "LogicGatesCounter.h"

/**
 * 
 */
LogicGatesCounter::LogicGatesCounter(uint8_t gpio_entrada)
{

    _count = 0;
    _gpio_in = gpio_entrada;

}

/**
 * 
 */
uint16_t LogicGatesCounter::comprobar()
{

    return digitalRead(_gpio_in) ? ++_count : _count;

}

/**
 * 
 */
void LogicGatesCounter::reiniciar()
{

    _count = 0;

}
