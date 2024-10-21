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
            LogicGatesTimer(unsigned long tiempo, uint8_t unidad);

            void iniciar();
            void establecer(unsigned long tiempo, uint8_t unidad);
            bool comprobar();

        private:

            unsigned long _start_time;
            unsigned long _objetive_time;
            bool _use_milliseconds;
            bool _enable;

    };

#endif
