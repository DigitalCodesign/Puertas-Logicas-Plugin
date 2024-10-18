/**
 * 
 */

#ifndef LogicGatesSignal_h
#define LogicGatesSignal_h

    #include "LogicGates.h"

    class LogicGatesSignal : public LogicGates
    {

        public:

            LogicGatesSignal(uint8_t gpio_salida, uint16_t frecuencia);

            void iniciar();
            void detener();
            void editarFrecuencia(uint16_t frecuencia);
            uint8_t actualizar();

        private:

            bool _enable;
            uint8_t _gpio_out;
            uint16_t _frequency;
            unsigned long _period;
            unsigned long _last_time;

    }

#endif
