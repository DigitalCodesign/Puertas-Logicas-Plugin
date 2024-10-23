/**
 * LogicGatesEdges.h - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase LogicGatesEdges, referida
 * a la gestión de Detectores de flanco.
 */

#ifndef LogicGatesEdges_h
#define LogicGatesEdges_h

    #include "LogicGates.h"

    class LogicGatesEdges : public LogicGates
    {

        public:

            LogicGatesEdges(uint8_t gpio_entrada);

            bool comprobarFlancoSubida();
            bool comprobarFlancoBajada();

        private:

            bool _last_state;
            uint8_t _gpio_in;

    };

#endif
