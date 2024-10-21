/**
 * LogicGates.h - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 17/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase LogicGate, referida
 * al Entrenador de Puertas Lógicas y las funcionalidades emuladas por software.
 * 
 * -> Timers.
 * -> Contadores.
 * -> Flip-Flops.
 * -> Detectores de Flanco.
 * -> Generador de Señales.
 */

#include <Arduino.h>

#ifndef LogicGates_h
#define LogicGates_h

    #include <MentorPort.h>

    class LogicGates : public MentorPort
    {

        public:

            static const uint8_t PUERTO_GENERICO_1 = 0x03;
            static const uint8_t GPIO_A10 = PIN_A10;
            static const uint8_t GPIO_A11 = PIN_A11;
            static const uint8_t GPIO_D35 = 35;
            static const uint8_t GPIO_D36 = 36;
            static const uint8_t GPIO_D37 = 37;
            static const uint8_t GPIO_D38 = 38;
            static const uint8_t GPIO_D3 = 3;
            static const uint8_t GPIO_D2 = 2;

            static const uint8_t PUERTO_GENERICO_2 = 0x04;
            static const uint8_t GPIO_A12 = PIN_A12;
            static const uint8_t GPIO_A13 = PIN_A13;
            static const uint8_t GPIO_D39 = 39;
            static const uint8_t GPIO_D40 = 40;
            static const uint8_t GPIO_D41 = 41;
            static const uint8_t GPIO_D42 = 42;
            static const uint8_t GPIO_D13 = 13;
            static const uint8_t GPIO_D44 = 44;

            static const uint8_t MILISEGUNDOS = 0x20;
            static const uint8_t MICROSEGUNDOS = 0x21;
            static const uint8_t TIPO_D = 0x22;
            static const uint8_t TIPO_T = 0x23;
            static const uint8_t TIPO_SR = 0x24;
            static const uint8_t TIPO_JK = 0x25;

            LogicGates();

        private:

            MentorPort::Port _port_1;
            MentorPort::Port _port_2;

    };

#endif
