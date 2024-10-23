/**
 * LogicGatesFlipFlopD.h - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase LogicGatesFlipFlopD, referida
 * a la gestión de Flip Flops de tipo D.
 */

#ifndef LogicGatesFlipFlopD_h
#define LogicGatesFlipFlopD_h

    #include "LogicGates.h"

    class LogicGatesFlipFlopD : public LogicGates
    {

        public:

            LogicGatesFlipFlopD(uint8_t gpio_D, uint8_t gpio_Q, uint8_t gpio_Qnot, uint8_t gpio_clk);

            void actualizar();
            void setear();
            void resetear();
            uint8_t obtenerQ();
            uint8_t obtenerQnegada();

        private:

            uint8_t _gpio_D;
            uint8_t _gpio_Q;
            uint8_t _gpio_Qnot;
            uint8_t _gpio_clk;
            bool _last_clk_state;

    };

#endif
