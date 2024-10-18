/**
 * 
 */

#include "LogicGatesFlipFlopJK.h"

/**
 * 
 */
LogicGatesFlipFlopJK::LogicGatesFlipFlopJK(
    uint8_t gpio_J,
    uint8_t gpio_K,
    uint8_t gpio_Q,
    uint8_t gpio_Qnot,
    uint8_t gpio_clk
)
{

    _gpio_J = gpio_J;
    _gpio_K = gpio_K;
    _gpio_Q = gpio_Q;
    _gpio_Qnot = gpio_Qnot;
    _gpio_clk = _gpio_clk;
    _last_clk_state = false;

    pinMode(_gpio_Q, OUTPUT);
    pinMode(_gpio_Qnot, OUTPUT);
    digitalWrite(_gpio_Q, LOW);
    digitalWrite(_gpio_Qnot, HIGH);

}

/**
 * 
 */
void LogicGatesFlipFlopJK::actualizar()
{

    if(!_last_clk_state && digitalRead(_gpio_clk))
    {

        bool j_state = digitalRead(_gpio_J);
        bool k_state = digitalRead(_gpio_K);

        if(j_state && k_state)
        {

            digitalWrite(_gpio_Q, !digitalRead(_gpio_Q));

        } else if(j_state && !k_state)
        {

            digitalWrite(_gpio_Q, HIGH);

        } else if(!j_state && k_state)
        {

            digitalWrite(_gpio_Q, LOW);

        }

    }

    _last_clk_state = digitalRead(_gpio_clk);

}

/**
 * 
 */
void LogicGatesFlipFlopJK::setear()
{

    digitalWrite(_gpio_Q, HIGH);
    digitalWrite(_gpio_Qnot, LOW);

}

/**
 * 
 */
void LogicGatesFlipFlopJK::resetear()
{

    digitalWrite(_gpio_Q, LOW);
    digitalWrite(_gpio_Qnot, HIGH);

}

/**
 * 
 */
uint8_t LogicGatesFlipFlopJK::obtenerQ()
{

    return digitalRead(_gpio_Q);

}

/**
 * 
 */
uint8_t LogicGatesFlipFlopJK::obtenerQnegada()
{

    return digitalRead(_gpio_Qnot);

}
