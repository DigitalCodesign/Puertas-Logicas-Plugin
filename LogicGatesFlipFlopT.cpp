/**
 * 
 */

#include "LogicGatesFlipFlopT.h"

/**
 * 
 */

LogicGatesFlipFlopT::LogicGatesFlipFlopT(
    uint8_t gpio_T,
    uint8_t gpio_Q,
    uint8_t gpio_Qnot,
    uint8_t gpio_clk
)
{

    _gpio_T = gpio_T;
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
void LogicGatesFlipFlopT::actualizar()
{

    if(!_last_clk_state && digitalRead(_gpio_clk))
    {
        if(digitalRead(_gpio_T))
        {

            digitalWrite(_gpio_Q, !digitalRead(_gpio_Q));
            digitalWrite(_gpio_Qnot, !digitalRead(_gpio_Qnot));

        }
    }

    _last_clk_state = digitalRead(_gpio_clk);

}

/**
 * 
 */
void LogicGatesFlipFlopT::setear()
{

    digitalWrite(_gpio_Q, HIGH);
    digitalWrite(_gpio_Qnot, LOW);

}

/**
 * 
 */
void LogicGatesFlipFlopT::resetear()
{

    digitalWrite(_gpio_Q, LOW);
    digitalWrite(_gpio_Qnot, HIGH);

}

/**
 * 
 */
uint8_t LogicGatesFlipFlopT::obtenerQ()
{

    return digitalRead(_gpio_Q);

}

/**
 * 
 */
uint8_t LogicGatesFlipFlopT::obtenerQnegada()
{

    return digitalRead(_gpio_Qnot);

}
