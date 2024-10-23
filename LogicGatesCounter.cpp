/**
 * LogicGatesCounter.cpp - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Definición de la clase LogicGatesCounter, referida a la gestión de Contadores.
 */

#include "LogicGatesCounter.h"

/**
 * Constructor de la clase LogicGatesCounter indicando como argumento el pin donde
 * recibir los pulsos para realizar la cuenta progresiva.
 * 
 * @param:
 *  - uint8_t gpio_entrada: Pin de conexionado de la señal de entrada del Contador.
 */
LogicGatesCounter::LogicGatesCounter(uint8_t gpio_entrada)
{

    _count = 0;
    _gpio_in = gpio_entrada;
    _last_state = false;

}

/**
 * Método que debe invocarse continuamente para comprobar el estado de la entrada del
 * Contador y actualizar la cuenta del mismo.
 * 
 * @return:
 *  - uint16_t: Devuelve el valor actual de la cuenta que lleva el Contador.
 */
uint16_t LogicGatesCounter::comprobar()
{

    bool current_state = digitalRead(_gpio_in);
    if(current_state && !_last_state) ++_count;
    _last_state = current_state;

    return _count;

}

/**
 * Método que reinicia la cuenta del Contador a cero.
 */
void LogicGatesCounter::reiniciar()
{

    _count = 0;

}
