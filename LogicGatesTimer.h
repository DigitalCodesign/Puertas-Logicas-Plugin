/**
 * LogicGatesTimer.h - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase LogicGateTimer, referida
 * a la gestión de temporizadores.
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
