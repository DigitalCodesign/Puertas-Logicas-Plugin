/**
 * 
*/

#include "LogicGatesBCD.h"

/**
 * 
*/
LogicGatesBCD::LogicGatesBCD(uint8_t bit_0, uint8_t bit_1, uint8_t bit_2, uint8_t bit_3)
{

    _gpio_bit_0 = bit_0;
    _gpio_bit_1 = bit_1;
    _gpio_bit_2 = bit_2;
    _gpio_bit_3 = bit_3;

}

/**
 * 
*/
uint8_t LogicGatesBCD::leerEntradas()
{

    uint8_t bcd_inputs = 0;

    bcd_inputs |= digitalRead(_gpio_bit_0) << 0;
    bcd_inputs |= digitalRead(_gpio_bit_1) << 1;
    bcd_inputs |= digitalRead(_gpio_bit_2) << 2;
    bcd_inputs |= digitalRead(_gpio_bit_3) << 3;

    return (bcd_inputs > 0b1001) ? 0b1001 : bcd_inputs;

}

/**
 * 
*/


