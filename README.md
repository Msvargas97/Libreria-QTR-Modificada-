# Libreria-QTR-Modificada-
Version 1.1 STABLE
Ultima revisión ->09/06/2015

Copyright (c) 2014-2015 Michael Vargas.

#Caracteristicas

-Se puede guardar y restaurar valores de calibracion desde la EEPROM

-Ajustar parametros de ruido,flancos de comparacion

-4 Nuevas funciones añadidas

#Nuevas Funciones

-Guarda los valores de calibración en la EEPROM

      bool recordCalibration(); Devuelve un 1 lógico si se guardaron los valores adecuadamente
      
-Se restauran los valores calibrados

     bool restoreCalibration(); Devuelve un 1 lógico si se restauraron los valores adecuadamente
     
-Limpia la EEPROM almacenados por la funcion recordCalibration

    bool clearEEPROM(char led); //Devuelve un 1 lógico cuando termina de borrar los valores char LED, introducir el pin de una salida como indicativo visual para iniciar y finalizar la funcion, como un LED
    
-Calibración con un tiempo determinado en milisegundos

    void calibration(int time,unsigned char readMode=QTR_EMITTERS_ON ,char led);
    
        time= Tiempo en milisegundos para calibrar, readMode=sensores encendidos o apagados, led = añadir el pin de alguna salida para indicar que la calibracion termino, de forma visual podria ser un LED

#Código de Ejemplo

Se encuentra en la ruta examples/QTRRC_MOD

#EXTRAS

-Si se desea usar la EEPROM y la libreria a la vez, la libreria ya tiene asignada la directiva por lo tanto solo es llamar las funciones que se encuentran en EEPROMEx

-Reemplazar todos los archivos o la libreria como tal original de Pololu por esta

-Link de libreria Original de Pololu ->https://github.com/pololu/qtr-sensors-arduino

Creditos: 

-Arduino

-Pololu

#Contact me

email :msvargas97@gmail.com

Twitter:@MichaelVargas97
