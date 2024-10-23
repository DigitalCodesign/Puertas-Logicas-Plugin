/**
 * LogicGatesEdges.cpp - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Definición de la clase LogicGatesEdges, referida a la gestión de Detectores de Flanco.
 */

#include "LogicGatesEdges.h"

/**
 * Constructor de la clase LogicGatesFlipFlopD indicando como argumento el pin donde
 * obtener las lecturas en busca de Flancos.
 * 
 * @param:
 *  - uint8_t gpio_entrada: Pin de conexión donde detectar Flancos.
 */
LogicGatesEdges::LogicGatesEdges(uint8_t gpio_entrada)
{

    _gpio_in = gpio_entrada;
    _last_state = digitalRead(gpio_entrada);

}

/**
 * Método para detectar un cambio de Baja a Alta, es decir, Flanco de Subida.
 */
bool LogicGatesEdges::comprobarFlancoSubida()
{

    uint8_t actual_state = digitalRead(_gpio_in);
    uint8_t edge = (_last_state != actual_state) & actual_state;
    _last_state = actual_state;

    return edge ? true : false;

}

/**
 * Método para detectar un cambio de Alta a Baja, es decir, Flanco de Bajada.
 */
bool LogicGatesEdges::comprobarFlancoBajada()
{

    uint8_t actual_state = digitalRead(_gpio_in);
    uint8_t edge = (_last_state != actual_state) & !actual_state;
    _last_state = actual_state;

    return edge ? true : false;

}
