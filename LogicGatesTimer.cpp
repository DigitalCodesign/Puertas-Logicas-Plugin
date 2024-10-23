/**
 * LogicGatesTimer.cpp - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 18/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Definición de la clase LogicGateTimer, referida a la gestión de temporizadores.
 */

#include "LogicGatesTimer.h"

/**
 * Constructor de la clase LogicGatesTimer sin argumentos para crear una instancia vacía
 * que utilizar posteriormente.
 */
LogicGatesTimer::LogicGatesTimer()
{

    _start_time = 0;
    _objetive_time = -1;
    _use_milliseconds = true;
    _enable = false;

}

/**
 * Constructor de la clase LogicGatesTimer indicando como argumentos los parámetros para
 * el temporizador deseado.
 * 
 * @param:
 *  - unsigned long tiempo: Tiempo objetivo del Temporizador.
 *  - uint8_t unidad: Indicador de unidad temporal heredada de la clase LogicGates.
 *      Puede tomarse el valor LogicGates::MILISEGUNDOS ó LogicGates::MICROSEGUNDOS.
 */
LogicGatesTimer::LogicGatesTimer(unsigned long tiempo, uint8_t unidad)
{

    _start_time = 0;
    _objetive_time = tiempo;
    _use_milliseconds = (unidad == LogicGates::MILISEGUNDOS);
    _enable = false;

}

/**
 * Método para habilitar el inicio del Temporizador.
 */
void LogicGatesTimer::iniciar()
{

    _start_time = millis();
    _enable = true;

}

/**
 * Método para configurar un Temporizador.
 * 
 * @param:
 *  - unsigned long tiempo: Tiempo objetivo del Temporizador.
 *  - uint8_t unidad: Indicador de unidad temporal heredada de la clase LogicGates.
 *      Puede tomarse el valor LogicGates::MILISEGUNDOS ó LogicGates::MICROSEGUNDOS.
 */
void LogicGatesTimer::establecer(unsigned long tiempo, uint8_t unidad)
{

    _start_time = 0;
    _objetive_time = tiempo;
    _use_milliseconds = (unidad == LogicGates::MILISEGUNDOS);

}

/**
 * Método que requiere consultarse a menudo para comprobar el estado del Temporizador
 * respecto al objetivo configurado.
 * 
 * @return: Booleano false si el objetivo temporal no se ha alcanzado. Booleano true si
 *      el objetido temporal ha podido alcanzarse.
 */
bool LogicGatesTimer::comprobar()
{

    if(((_use_milliseconds ? millis() : micros()) - _start_time) > _objetive_time)
        return true;

    return false;

}
