# Libreria-QTR-Modificada-
Version 1.1 STABLE
Ultima revisión ->09/06/2015

Libreria Modificada By Michael Vargas
respetando los derechos de autor de Pololu

#Caracteristicas

-Se puede guardar y restaurar valores de calibracion desde la EEPROM

-Ajustar parametros de ruido,flancos de comparacion

-4 Nuevas funciones añadidas

#Nuevas Funciones

-Guarda los valores de calibración en la EEPROM

      bool recordCalibration(); Devuelve un 1 lógico si se guardaron los valores adecuadamente
      
-Se restauran los valores calibrados

     bool restoreCalibration(); Devuelve un 1 lógico si se restauraron los valores adecuadamente
     
-Limpia la EEPROM almacenados

    bool clearEEPROM(char led); //Devuelve un 1 lógico cuando termina de borrar los valores char LED, introducir el pin de una salida como indicativo visual para iniciar y finalizar la funcion, como un LED
    
-Calibración con un tiempo determinado en milisegundos

    void calibration(int time,unsigned char readMode=QTR_EMITTERS_ON ,char led);
    
        time= Tiempo en milisegundos para calibrar, readMode=sensores encendidos o apagados, led = añadir el pin de alguna salida para indicar que la calibracion termino, de forma visual podria ser un LED

#EXTRAS

-Si se desea usar la EEPROM y la libreria a la vez, la libreria ya tiene asignada la directiva por lo tanto solo es llamar las funciones que se encuentran en EEPROMEx

#Código de Ejemplo

Se encuentra en la ruta examples/QTR_MOD...


#Contactame

msvargas97@gmail.com

@MichaelVargas97