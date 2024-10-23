/**
 * LogicGatesFlipFlopJK.cpp - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Definición de la clase LogicGatesFlipFlopJK, referida a la gestión de Flip Flops de tipo JK.
 */

#include "LogicGatesFlipFlopJK.h"

/**
 * Constructor de la clase LogicGatesFlipFlopJK indicando como argumentos los pines del
 * conexionado del Flip Flop tipo JK.
 * 
 * @param:
 *  - uint8_t gpio_J: Pin de conexión de la entrada J del Flip Flop.
 *  - uint8_t gpio_K: Pin de conexión de la entrada K del Flip Flop.
 *  - uint8_t gpio_Q: Pin de conexión de la salida Q del Flip Flop.
 *  - uint8_t gpio_Qnot: Pin de conexión de la salida Q negada del Flip Flop.
 *  - uint8_t gpio_clk: Pin de conexión de la entrada de reloj clk del Flip Flop.
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
    _gpio_clk = gpio_clk;
    _last_clk_state = false;

    pinMode(_gpio_Q, OUTPUT);
    pinMode(_gpio_Qnot, OUTPUT);
    digitalWrite(_gpio_Q, LOW);
    digitalWrite(_gpio_Qnot, HIGH);

}

/**
 * Método que debe invocarse constantemente para actualizar el estado de las salidas
 * del Flip Flop tipo JK tras comprobar las entradas del mismo.
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

        digitalWrite(_gpio_Qnot, !digitalRead(_gpio_Q));

    }

    _last_clk_state = digitalRead(_gpio_clk);

}

/**
 * Método para establecer un Set en las salidas en el Flip Flop tipo JK.
 */
void LogicGatesFlipFlopJK::setear()
{

    digitalWrite(_gpio_Q, HIGH);
    digitalWrite(_gpio_Qnot, LOW);

}

/**
 * Método para establecer un Reset en las salidas en el Flip Flop tipo JK.
 */
void LogicGatesFlipFlopJK::resetear()
{

    digitalWrite(_gpio_Q, LOW);
    digitalWrite(_gpio_Qnot, HIGH);

}

/**
 * Método que devuelve el estado de la salida Q del Flip Flop tipo JK.
 */
uint8_t LogicGatesFlipFlopJK::obtenerQ()
{

    return digitalRead(_gpio_Q);

}

/**
 * Método que devuelve el estado de la salida Q negada del Flip Flop tipo JK.
 */
uint8_t LogicGatesFlipFlopJK::obtenerQnegada()
{

    return digitalRead(_gpio_Qnot);

}
