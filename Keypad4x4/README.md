# Keypad4x4 Library for ESP32

## Description / Descripción
A simple and efficient library to control 4x4 matrix keypads with the ESP32 board.  
Librería sencilla y eficiente para manejar teclados matriciales 4x4 con ESP32.

This library handles:  
- Key scanning (escaneo de teclas)  
- Debouncing (antirebote)  
- Stable reading (lectura estable)

## Installation / Instalación
1. Download or clone this repository into your Arduino libraries folder:  
   Documents/Arduino/libraries/Keypad4x4  
2. Restart Arduino IDE.  
3. Open example:  
   File → Examples → Keypad4x4 → Keypad4x4_Test

## Usage / Uso
```cpp
#include "Keypad4x4.h"

Keypad4x4 keypad;

void setup() {
    Serial.begin(115200);

    // Example pin configuration:
    // keypad.configKey(Row1, Row2, Row3, Row4, Column1, Column2, Column3, Column4);
    keypad.configKey(13,12,14,27, 26,25,33,32);
}

void loop() {
    char key = keypad.getKey();
    if (key != '\0') {
        Serial.print("Key pressed / Tecla: ");
        Serial.println(key);
    }
}
```

## Online Simulation / Simulación en línea

You can try the Keypad4x4 library in a Wokwi simulation:  

https://wokwi.com/projects/442738021011978241?authuser=0


## Pinout Example / Ejemplo de conexión

Row | GPIO | Column | GPIO
----|------|--------|------
R1  |  13  |   C1   |  26
R2  |  12  |   C2   |  25
R3  |  14  |   C3   |  33
R4  |  27  |   C4   |  32

## License / Licencia


This project is released under the MIT License.
