/**
 * 
 */

#include "LogicGatesEdges.h"

LogicGatesEdges::LogicGatesEdges(uint8_t gpio_entrada)
{

    _gpio_in = gpio_entrada;
    _last_state = digitalRead(gpio_entrada);

}

bool LogicGatesEdges::comprobarFlancoSubida()
{

    uint8_t actual_state = digitalRead(_gpio_in);
    uint8_t edge = (_last_state != actual_state) & actual_state;
    _last_state = actual_state;

    return edge ? true : false;

}

bool LogicGatesEdges::comprobarFlancoBajada()
{

    uint8_t actual_state = digitalRead(_gpio_in);
    uint8_t edge = (_last_state != actual_state) & !actual_state;
    _last_state = actual_state;

    return edge ? true : false;

}
