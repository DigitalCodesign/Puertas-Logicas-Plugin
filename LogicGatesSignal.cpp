/**
 * 
 */

#include "LogicGatesSignal.h"

/**
 * 
 */
LogicGatesSignal::LogicGatesSignal(uint8_t gpio_salida, unsigned long periodo, double frecuencia)
{

    _gpio_out = gpio_salida;
    _frequency = frecuencia;
    _period = periodo;

}

/**
 * 
 */
LogicGatesSignal::actualizarGenerador()
{



}
