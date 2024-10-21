/**
 * 
 */

#ifndef LogicGatesFlipFlopJK_h
#define LogicGatesFlipFlopJK_h

    #include "LogicGates.h"

    class LogicGatesFlipFlopJK : public LogicGates
    {

        public:

            LogicGatesFlipFlopJK(uint8_t gpio_J, uint8_t gpio_K, uint8_t gpio_Q, uint8_t gpio_Qnot, uint8_t gpio_clk);

            void actualizar();
            void setear();
            void resetear();
            uint8_t obtenerQ();
            uint8_t obtenerQnegada();

        private:

            uint8_t _gpio_J;
            uint8_t _gpio_K;
            uint8_t _gpio_Q;
            uint8_t _gpio_Qnot;
            uint8_t _gpio_clk;
            bool _last_clk_state;

    };

#endif
