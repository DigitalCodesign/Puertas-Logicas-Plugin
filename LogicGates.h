/**
 * LogicGates.h - Librería para compatibilizar funcionamiento del Entrenador de Puertas
 * Logicas con MentorBit.
 * 
 * Creado el 17/10/2024 - ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase LogicGate, referida
 * al Entrenador de Puertas Lógicas y las funcionalidades emuladas por software.
 * 
 * -> Timers.
 * -> Contadores.
 * -> Flip-Flops.
 * -> Detectores de Flanco.
 * -> Generador de Señales.
 */

#ifndef LogicGates_h
#define LogicGates_h

    #include <Arduino.h>
    #include <MentorPort.h>

    class LogicGates
    {

        public:

            static const uint8_t GPIO_A10 = PIN_A10;
            static const uint8_t GPIO_A11 = PIN_A11;
            static const uint8_t GPIO_D35 = 35;
            static const uint8_t GPIO_D36 = 36;
            static const uint8_t GPIO_D37 = 37;
            static const uint8_t GPIO_D38 = 38;
            static const uint8_t GPIO_D3 = 3;
            static const uint8_t GPIO_D2 = 2;

            static const uint8_t GPIO_A12 = PIN_A12;
            static const uint8_t GPIO_A13 = PIN_A13;
            static const uint8_t GPIO_D39 = 39;
            static const uint8_t GPIO_D40 = 40;
            static const uint8_t GPIO_D41 = 41;
            static const uint8_t GPIO_D42 = 42;
            static const uint8_t GPIO_D13 = 13;
            static const uint8_t GPIO_D44 = 44;

            static const uint8_t MILISEGUNDOS = 0x20;
            static const uint8_t MICROSEGUNDOS = 0x21;

            LogicGates();
            // Counter methods
            void crearContador(uint8_t gpio_entrada);
            uint16_t sumarContador();
            uint16_t restarContador();
            void reiniciarContador();
            // Flip-Flop methods
            uint8_t actualizarFlipFlopD(uint8_t gpio_entrada, uint8_t gpio_clk);
            uint8_t actualizarFlipFlopT(uint8_t gpio_entrada, uint8_t gpio_clk);
            uint8_t actualizarFlipFlopSR(uint8_t gpio_entrada, uint8_t gpio_clk);
            uint8_t actualizarFlipFlopJK(uint8_t gpio_entrada, uint8_t gpio_clk);
            uint8_t obtenerFlipFlopD();
            uint8_t obtenerFlipFlopT();
            uint8_t obtenerFlipFlopSR();
            uint8_t obtenerFlipFlopJK();
            // Edge Detector methods
            uint8_t comprobarFlancoSubida(uint8_t gpio_entrada);
            uint8_t comprobarFlancoBajada(uint8_t gpio_entrada);
            // Signal Generator methods
            void iniciarGenerador(uint8_t gpio_salida, unsigned long periodo, double frecuencia);
            uint8_t actualizarGenerador();
            // BCD methods
            void obtenerBinario(uint8_t puerto_entrada);
            uint8_t obtenerSegmento(uint8_t segmento);

        private:

            Port _port_1;
            Port _port_2;

    };

#endif
