#pragma once
#include <Arduino.h>

class Keypad4x4 {
public:
    Keypad4x4();

    // Configuración única de pines
    void configKey(int fila1, int fila2, int fila3, int fila4,
                   int col1, int col2, int col3, int col4);

    // Leer tecla con antirebote
    char getKey();

private:
    int filas[4];
    int columnas[4];

    char ultimaTecla;
    unsigned long lastDebounceTime;
    const unsigned long DEBOUNCE_MS = 200;

    char scan(); // escaneo interno
};
