/**
 * LogicGatesFlipFlopD.cpp - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Definición de la clase LogicGatesFlipFlopD, referida a la gestión de Flip Flops de tipo D.
 */

#include "LogicGatesFlipFlopD.h"

/**
 * Constructor de la clase LogicGatesFlipFlopD indicando como argumentos los pines del
 * conexionado del Flip Flop tipo D.
 * 
 * @param:
 *  - uint8_t gpio_D: Pin de conexión de la entrada D del Flip Flop.
 *  - uint8_t gpio_Q: Pin de conexión de la salida Q del Flip Flop.
 *  - uint8_t gpio_Qnot: Pin de conexión de la salida Q negada del Flip Flop.
 *  - uint8_t gpio_clk: Pin de conexión de la entrada de reloj clk del Flip Flop.
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
 * Método que debe invocarse constantemente para actualizar el estado de las salidas
 * del Flip Flop tipo D tras comprobar las entradas del mismo.
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
 * Método para establecer un Set en las salidas en el Flip Flop tipo D.
 */
void LogicGatesFlipFlopD::setear()
{

    digitalWrite(_gpio_Q, HIGH);
    digitalWrite(_gpio_Qnot, LOW);

}

/**
 * Método para establecer un Reset en las salidas en el Flip Flop tipo D.
 */
void LogicGatesFlipFlopD::resetear()
{

    digitalWrite(_gpio_Q, LOW);
    digitalWrite(_gpio_Qnot, HIGH);

}

/**
 * Método que devuelve el estado de la salida Q del Flip Flop tipo D.
 */
uint8_t LogicGatesFlipFlopD::obtenerQ()
{

    return digitalRead(_gpio_Q);

}

/**
 * Método que devuelve el estado de la salida Q negada del Flip Flop tipo D.
 */
uint8_t LogicGatesFlipFlopD::obtenerQnegada()
{

    return digitalRead(_gpio_Qnot);

}
