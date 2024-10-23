/**
 * LogicGatesCounter.h - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase LogicGatesCounter, referida
 * a la gestión de Contadores.
 */

#ifndef LogicGatesCounter_h
#define LogicGatesCounter_h

    #include "LogicGates.h"

    class LogicGatesCounter : public LogicGates
    {

        public:

            LogicGatesCounter(uint8_t gpio_entrada);

            uint16_t comprobar();
            void reiniciar();

        private:

            uint8_t _gpio_in;
            uint16_t _count;
            bool _last_state;

    };

#endif
