/**
 * LogicGatesFlipFlopT.cpp - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Definición de la clase LogicGatesFlipFlopT, referida a la gestión de Flip Flops de tipo T.
 */

#include "LogicGatesFlipFlopT.h"

/**
 * Constructor de la clase LogicGatesFlipFlopT indicando como argumentos los pines del
 * conexionado del Flip Flop tipo T.
 * 
 * @param:
 *  - uint8_t gpio_T: Pin de conexión de la entrada T del Flip Flop.
 *  - uint8_t gpio_Q: Pin de conexión de la salida Q del Flip Flop.
 *  - uint8_t gpio_Qnot: Pin de conexión de la salida Q negada del Flip Flop.
 *  - uint8_t gpio_clk: Pin de conexión de la entrada de reloj clk del Flip Flop.
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
    _gpio_clk = gpio_clk;
    _last_clk_state = false;

    pinMode(_gpio_Q, OUTPUT);
    pinMode(_gpio_Qnot, OUTPUT);
    digitalWrite(_gpio_Q, LOW);
    digitalWrite(_gpio_Qnot, HIGH);

}

/**
 * Método que debe invocarse constantemente para actualizar el estado de las salidas
 * del Flip Flop tipo T tras comprobar las entradas del mismo.
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
 * Método para establecer un Set en las salidas en el Flip Flop tipo T.
 */
void LogicGatesFlipFlopT::setear()
{

    digitalWrite(_gpio_Q, HIGH);
    digitalWrite(_gpio_Qnot, LOW);

}

/**
 * Método para establecer un Reset en las salidas en el Flip Flop tipo T.
 */
void LogicGatesFlipFlopT::resetear()
{

    digitalWrite(_gpio_Q, LOW);
    digitalWrite(_gpio_Qnot, HIGH);

}

/**
 * Método que devuelve el estado de la salida Q del Flip Flop tipo T.
 */
uint8_t LogicGatesFlipFlopT::obtenerQ()
{

    return digitalRead(_gpio_Q);

}

/**
 * Método que devuelve el estado de la salida Q negada del Flip Flop tipo T.
 */
uint8_t LogicGatesFlipFlopT::obtenerQnegada()
{

    return digitalRead(_gpio_Qnot);

}
