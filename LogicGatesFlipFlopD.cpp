/**
 * 
 */

#include "LogicGatesFlipFlopD.h"

/**
 * 
 */
LogicGatesFlipFlopD::LogicGatesFlipFlopD(
    uint8_t gpio_D,
    uint8_t gpio_Q,
    uint8_t gpio_Qnot,
    uint8_t gpio_clk
)
{

    _gpio_D = gpio_D;
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
void LogicGatesFlipFlopD::actualizar()
{

    bool actual_clk_state = digitalRead(_gpio_clk);

    if(!_last_clk_state && actual_clk_state)
    {

        digitalWrite(_gpio_Q, digitalRead(_gpio_D));
        digitalWrite(_gpio_Qnot, !digitalRead(_gpio_Q));

    }

    _last_clk_state = actual_clk_state;

}

/**
 * 
 */
void LogicGatesFlipFlopD::setear()
{

    digitalWrite(_gpio_Q, HIGH);
    digitalWrite(_gpio_Qnot, LOW);

}

/**
 * 
 */
void LogicGatesFlipFlopD::resetear()
{

    digitalWrite(_gpio_Q, LOW);
    digitalWrite(_gpio_Qnot, HIGH);

}

/**
 * 
 */
uint8_t LogicGatesFlipFlopD::obtenerQ()
{

    return digitalRead(_gpio_Q);

}

/**
 * 
 */
uint8_t LogicGatesFlipFlopD::obtenerQnegada()
{

    return digitalRead(_gpio_Qnot);

}
