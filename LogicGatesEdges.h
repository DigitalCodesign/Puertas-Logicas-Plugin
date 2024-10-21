/**
 * 
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
