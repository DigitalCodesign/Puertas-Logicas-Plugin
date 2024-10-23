/**
 * LogicGatesBCD.h - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase LogicGatesBCD, referida
 * a la gestión de BCDs.
*/

#ifndef LogicGatesBCD_h
#define LogicGatesBCD_h

    #include "LogicGates.h"

    class LogicGatesBCD : public LogicGates
    {

        public:

            LogicGatesBCD(uint8_t bit_0, uint8_t bit_1, uint8_t bit_2, uint8_t bit_3);

            uint8_t leerEntradas();

        private:

            uint8_t _gpio_bit_0;
            uint8_t _gpio_bit_1;
            uint8_t _gpio_bit_2;
            uint8_t _gpio_bit_3;

    };

#endif
