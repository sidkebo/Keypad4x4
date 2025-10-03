#include <Arduino.h>
#include "Keypad4x4.h"

Keypad4x4 keypad;	//crea el objeto de tipo Keypad4x4  

void setup(){
    Serial.begin(115200);
    // Configuración de pines en una sola llamada
    keypad.configKey(13,12,14,27,26,25,33,32);

//keypad.configKey(Fila1,Fila2,Fila3,Fila4,Columna1,Columna2,Columna3,Columna4);
//     ************PINES DEL KEYPAD 4x4**************
//    |     |      |    |       |         |         |         | 
// Fila1  Fila2 Fila3 Fila4 Columna1  Columna2  Columna3  Columna4
}

void loop(){
    char tecla = keypad.getKey();
    if(tecla != '\0'){
        Serial.printf("Tecla presionada: %c\n", tecla);
    }
}
