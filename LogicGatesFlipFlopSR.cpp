/**
 * 
 */

#include "LogicGatesFlipFlopSR.h"

/**
 * 
 */
LogicGatesFlipFlopSR::LogicGatesFlipFlopSR(
    uint8_t gpio_S,
    uint8_t gpio_R,
    uint8_t gpio_Q,
    uint8_t gpio_Qnot,
    uint8_t gpio_clk
)
{

    _gpio_S = gpio_S;
    _gpio_R = gpio_R;
    _gpio_Q = gpio_Q;
    _gpio_Qnot = gpio_Qnot;
    _gpio_clk = gpio_clk;
    _last_clk_state = false;

    pinMode(_gpio_Q, OUTPUT);
    pinMode(_gpio_Qnot, OUTPUT);
    digitalWrite(_gpio_Q, LOW);
    digitalWrite(_gpio_Qnot, HIGH);

}

/**
 * 
 */
void LogicGatesFlipFlopSR::actualizar()
{

    if(!_last_clk_state && digitalRead(_gpio_clk))
    {

        bool s_state = digitalRead(_gpio_S);
        bool r_state = digitalRead(_gpio_R);

        if( s_state != r_state)
        {

            if(s_state) digitalWrite(_gpio_Q, HIGH);
            else if(r_state) digitalWrite(_gpio_Q, LOW);

            digitalWrite(_gpio_Qnot, !digitalRead(_gpio_Q));

        }
    }

    _last_clk_state = digitalRead(_gpio_clk);

}

/**
 * 
 */
void LogicGatesFlipFlopSR::setear()
{

    digitalWrite(_gpio_Q, HIGH);
    digitalWrite(_gpio_Qnot, LOW);

}

/**
 * 
 */
void LogicGatesFlipFlopSR::resetear()
{

    digitalWrite(_gpio_Q, LOW);
    digitalWrite(_gpio_Qnot, HIGH);

}

/**
 * 
 */
uint8_t LogicGatesFlipFlopSR::obtenerQ()
{

    return digitalRead(_gpio_Q);

}

/**
 * 
 */
uint8_t LogicGatesFlipFlopSR::obtenerQnegada()
{

    return digitalRead(_gpio_Qnot);

}
