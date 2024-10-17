/**
 * 
 */

#ifndef LogicGatesCounter_h
#define LogicGatesCounter_h

    #include "LogicGates.h"

    class LogicGatesCounter : public LogicGates
    {

        public:

            LogicGatesCounter(uint8_t gpio_entrada);

            uint16_t comprobarContador();
            void reiniciarContador();

        private:

            uint8_t _gpio_in;
            uint16_t _count;

    }

#endif
