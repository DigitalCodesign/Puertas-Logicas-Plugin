/**
 * LogicGatesBCD.cpp - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Definición de la clase LogicGatesBCD, referida a la gestión de BCDs.
*/

#include "LogicGatesBCD.h"

/**
 * Constructor de la clase LogicGatesBCD indicando como argumentos los pines de conexionado
 * de los 4 bits de entrada al BCD.
 * 
 * @param:
 *  - uint8_t bit_0: Conexionado del primer bit de entrada (LSB).
 *  - uint8_t bit_1: Conexionado del segundo bit de entrada.
 *  - uint8_t bit_2: Conexionado del tercer bit de entrada.
 *  - uint8_t bit_3: Conexionado del cuarto bit de entrada (MSB).
*/
LogicGatesBCD::LogicGatesBCD(uint8_t bit_0, uint8_t bit_1, uint8_t bit_2, uint8_t bit_3)
{

    _gpio_bit_0 = bit_0;
    _gpio_bit_1 = bit_1;
    _gpio_bit_2 = bit_2;
    _gpio_bit_3 = bit_3;

}

/**
 * Método que obtiene la lectura de los 4 bits de entrada al BCD.
 * 
 * @return:
 *  - uint8_t: Devuelve un binario de 4 bits con las lecturas del BCD.
*/
uint8_t LogicGatesBCD::leerEntradas()
{

    uint8_t bcd_inputs = 0;

    bcd_inputs |= digitalRead(_gpio_bit_0) << 0;
    bcd_inputs |= digitalRead(_gpio_bit_1) << 1;
    bcd_inputs |= digitalRead(_gpio_bit_2) << 2;
    bcd_inputs |= digitalRead(_gpio_bit_3) << 3;

    return (bcd_inputs > 0b1001) ? 0b1001 : bcd_inputs;

}
