/**
 * 
 */

#ifndef LogicGatesTimer_h
#define LogicGatesTimer_h

    #include "LogicGates.h"

    class LogicGatesTimer : public LogicGates
    {

        public:

            LogicGatesTimer();

            void crearTemporizador(unsigned long tiempo, uint8_t unidad);
            void iniciarTemporizador();
            bool comprobarTemporizador();

        private:

            unsigned long _start_time;
            unsigned long _objetive_time;
            bool _use_milliseconds;

    };

#endif
