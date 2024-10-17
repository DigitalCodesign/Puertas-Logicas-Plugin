/**
 * LogicGates.cpp - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Lógicas con MentorBit.
 * 
 * Creado el 17/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Definición de la clase LogicGates, referida al Entrenador de Puertas Lógicas y
 * las funcionalidades emuladas por software.
 */

#include "LogicGates.h"

/**
 * Constructor de la clase para Puertas Lógicas
 */
LogicGates::LogicGates() {

    _port_1.type = 'g';
    _port_1.location = 0x03;
    _port_1.gpios[0] = LogicGates::GPIO_D35;
    _port_1.gpios[1] = LogicGates::GPIO_D36;
    _port_1.gpios[2] = LogicGates::GPIO_D37;
    _port_1.gpios[3] = LogicGates::GPIO_D38;
    _port_1.gpios[4] = LogicGates::GPIO_D3;
    _port_1.gpios[5] = LogicGates::GPIO_D2;
    _port_1.gpios[6] = LogicGates::GPIO_A10;
    _port_1.gpios[7] = LogicGates::GPIO_A11;

    _port_2.type = 'g';
    _port_2.location = 0x04;
    _port_2.gpios[0] = LogicGates::GPIO_D39;
    _port_2.gpios[1] = LogicGates::GPIO_D40;
    _port_2.gpios[2] = LogicGates::GPIO_D41;
    _port_2.gpios[3] = LogicGates::GPIO_D42;
    _port_2.gpios[4] = LogicGates::GPIO_D13;
    _port_2.gpios[5] = LogicGates::GPIO_D44;
    _port_2.gpios[6] = LogicGates::GPIO_A12;
    _port_2.gpios[7] = LogicGates::GPIO_A13;

}
