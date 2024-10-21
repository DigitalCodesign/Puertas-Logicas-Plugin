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
    _last_state = false;

}

/**
 * 
 */
uint16_t LogicGatesCounter::comprobar()
{

    bool current_state = digitalRead(_gpio_in);
    if(current_state && !_last_state) ++_count;
    _last_state = current_state;

    return _count;

}

/**
 * 
 */
void LogicGatesCounter::reiniciar()
{

    _count = 0;

}
