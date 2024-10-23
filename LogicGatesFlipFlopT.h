/**
 * LogicGatesFlipFlopT.h - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase LogicGatesFlipFlopT, referida
 * a la gestión de Flip Flops de tipo T.
 */

#ifndef LogicGatesFlipFlopT_h
#define LogicGatesFlipFlopT_h

    #include "LogicGates.h"

    class LogicGatesFlipFlopT : public LogicGates
    {

        public:

            LogicGatesFlipFlopT(uint8_t gpio_T, uint8_t gpio_Q, uint8_t gpio_Qnot, uint8_t gpio_clk);

            void actualizar();
            void setear();
            void resetear();
            uint8_t obtenerQ();
            uint8_t obtenerQnegada();

        private:

            uint8_t _gpio_T;
            uint8_t _gpio_Q;
            uint8_t _gpio_Qnot;
            uint8_t _gpio_clk;
            bool _last_clk_state;

    };

#endif
