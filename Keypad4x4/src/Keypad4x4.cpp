#include "Keypad4x4.h"
#include "esp32-hal-gpio.h"
#include "esp32-hal.h"

static const char keymap[4][4] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

Keypad4x4::Keypad4x4() {
    ultimaTecla = '\0';
    lastDebounceTime = 0;
}

void Keypad4x4::configKey(int f1,int f2,int f3,int f4,int c1,int c2,int c3,int c4){
    filas[0]=f1; filas[1]=f2; filas[2]=f3; filas[3]=f4;
    columnas[0]=c1; columnas[1]=c2; columnas[2]=c3; columnas[3]=c4;

    // Configurar filas como salida, inicializar alto
    for(int i=0;i<4;i++){
        pinMode(filas[i], OUTPUT);
        digitalWrite(filas[i], HIGH);
    }

    // Configurar columnas como entrada con pull-up
    for(int i=0;i<4;i++){
        pinMode(columnas[i], INPUT_PULLUP);
    }

    ultimaTecla = '\0';
    lastDebounceTime = 0;
}

// Escaneo interno del keypad
char Keypad4x4::scan(){
    for(int fila=0; fila<4; fila++){
        // Activar solo fila actual
        for(int f=0; f<4; f++) digitalWrite(filas[f], (f==fila)? LOW:HIGH);

        delayMicroseconds(50); // pequeño retardo de estabilidad

        for(int col=0; col<4; col++){
            if(digitalRead(columnas[col])==LOW){
                return keymap[fila][col];
            }
        }
    }
    return '\0';
}

// Devuelve tecla detectada con antirebote
char Keypad4x4::getKey(){
    char t = scan();
    unsigned long now = millis();

    if(t != '\0'){
        if(t != ultimaTecla || (now - lastDebounceTime) > DEBOUNCE_MS){
            ultimaTecla = t;
            lastDebounceTime = now;

            // Esperar a que se suelte antes de devolver
            while(scan() == t) delay(1);
            ultimaTecla = '\0';
            return t;
        }
    } else {
        ultimaTecla = '\0';
    }
    return '\0';
}
