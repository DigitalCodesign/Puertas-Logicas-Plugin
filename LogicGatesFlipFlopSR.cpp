/**
 * LogicGatesFlipFlopSR.cpp - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Definición de la clase LogicGatesFlipFlopSR, referida a la gestión de Flip Flops de tipo SR.
 */

#include "LogicGatesFlipFlopSR.h"

/**
 * Constructor de la clase LogicGatesFlipFlopSR indicando como argumentos los pines del
 * conexionado del Flip Flop tipo SR.
 * 
 * @param:
 *  - uint8_t gpio_S: Pin de conexión de la entrada S del Flip Flop.
 *  - uint8_t gpio_R: Pin de conexión de la entrada R del Flip Flop.
 *  - uint8_t gpio_Q: Pin de conexión de la salida Q del Flip Flop.
 *  - uint8_t gpio_Qnot: Pin de conexión de la salida Q negada del Flip Flop.
 *  - uint8_t gpio_clk: Pin de conexión de la entrada de reloj clk del Flip Flop.
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
 * Método que debe invocarse constantemente para actualizar el estado de las salidas
 * del Flip Flop tipo SR tras comprobar las entradas del mismo.
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
 * Método para establecer un Set en las salidas en el Flip Flop tipo SR.
 */
void LogicGatesFlipFlopSR::setear()
{

    digitalWrite(_gpio_Q, HIGH);
    digitalWrite(_gpio_Qnot, LOW);

}

/**
 * Método para establecer un Reset en las salidas en el Flip Flop tipo SR.
 */
void LogicGatesFlipFlopSR::resetear()
{

    digitalWrite(_gpio_Q, LOW);
    digitalWrite(_gpio_Qnot, HIGH);

}

/**
 * Método que devuelve el estado de la salida Q del Flip Flop tipo SR.
 */
uint8_t LogicGatesFlipFlopSR::obtenerQ()
{

    return digitalRead(_gpio_Q);

}

/**
 * Método que devuelve el estado de la salida Q negada del Flip Flop tipo SR.
 */
uint8_t LogicGatesFlipFlopSR::obtenerQnegada()
{

    return digitalRead(_gpio_Qnot);

}
