/**
 * 
 */

#ifndef LogicGatesSignal_h
#define LogicGatesSignal_h

    #include "LogicGates.h"

    class LogicGatesSignal : public LogicGates
    {

        public:

            LogicGatesSignal(uint8_t gpio_salida, unsigned long periodo, double frecuencia);

            uint8_t actualizarGenerador();

        private:

            uint8_t _gpio_out;
            double _frequency;
            unsigned long _period;

    }

#endif
