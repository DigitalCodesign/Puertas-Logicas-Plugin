/**
 * LogicGatesFlipFlopSR.h - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase LogicGatesFlipFlopSR, referida
 * a la gestión de Flip Flops de tipo SR.
 */

#ifndef LogicGatesFlipFlopSR_h
#define LogicGatesFlipFlopSR_h

    #include "LogicGates.h"

    class LogicGatesFlipFlopSR : public LogicGates
    {

        public:

            LogicGatesFlipFlopSR(uint8_t gpio_S, uint8_t gpio_R, uint8_t gpio_Q, uint8_t gpio_Qnot, uint8_t gpio_clk);

            void actualizar();
            void setear();
            void resetear();
            uint8_t obtenerQ();
            uint8_t obtenerQnegada();

        private:

            uint8_t _gpio_S;
            uint8_t _gpio_R;
            uint8_t _gpio_Q;
            uint8_t _gpio_Qnot;
            uint8_t _gpio_clk;
            bool _last_clk_state;

    };

#endif
