#include <QTRSensors.h>

#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2
#define TIME_CALIBRATION 2500 // Tiempo en milisegundos para calirbar los sensores
// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {3, 4, 5, 6, 7, 8, 9, 10},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];


void setup()
{
Serial.begin(9600);
TEST_QTR();
}

/*
Unos valores que probe en linea blanca  que funcionan, y podria decir que hasta mejor que antes,  son estos :

             position = qtrrc.readLine(sensorValues,QTR_EMITTERS_ON, 1 , 0 , 400 , 30);
             position = qtrrc.readLine(sensorValues,QTR_EMITTERS_ON, 1 , 500 , 400 , 50);
             position = qtrrc.readLine(sensorValues,QTR_EMITTERS_ON, 1 , 500 , 500 , 50);
             position = qtrrc.readLine(sensorValues,QTR_EMITTERS_ON, 1 , 300 , 500 , 100);

Valores para linea negra:
 position = qtrrc.readLine(sensorValues,QTR_EMITTERS_ON, 0 , 0 , 400 , 30);
position = qtrrc.readLine(sensorValues,QTR_EMITTERS_ON, 0 , 0 , 300 , 50);
position = qtrrc.readLine(sensorValues,QTR_EMITTERS_ON, 0 , -200 , 200 , 100);
*/
void loop()
{
  // read calibrated sensor values and obtain a measure of the line position from 0 to 5000
  // To get raw sensor values, call:
  //  qtrrc.read(sensorValues); instead of unsigned int position = qtrrc.readLine(sensorValues);
  unsigned int position = qtrrc.readLine(sensorValues,QTR_EMITTERS_ON, 0 , 0 , 300 , 50);

  // print the sensor values as numbers from 0 to 1000, where 0 means maximum reflectance and
  // 1000 means minimum reflectance, followed by the line position
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  //Serial.println(); // uncomment this line if you are using raw values
  Serial.println(position); // comment this line out if you are using raw values
  
  delay(250);
}

void TEST_QTR() {
  Serial.println("Encendiendo sensores");
  qtrrc.emittersOn();
  Serial.println("Calibrando...");
  qtrrc.calibration(TIME_CALIBRATION);
  Serial.println("Calibracion finalizada");
  Serial.println("Guardando calibracion");
  qtrrc.recordCalibration();
  delay(4000);
  Serial.println("Reiniciando valores");
 qtrrc.resetCalibration();
 calibrationValues();
 delay(4000);
 Serial.println("Restaurando Valores");
 qtrrc.restoreCalibration();
 delay(4000);
Serial.println("Valores Restaurados");
 calibrationValues();
 Serial.print("Se usaron las primeras ");
 Serial.print((NUM_SENSORS*4)-1);
 Serial.println(" posiciones de la EEPROM");
  delay(4000);
  Serial.println("Borrando valores de la EEPROM");
  qtrrc.clearEEPROM();
  delay(4000);
  
  calibrationValues();
}
void calibrationValues(void) { //Función para mostrar valores de calibración por medio del BT
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMinimumOn[i]);
    Serial.print(' ');
  }
  Serial.println();

  // print the calibration maximum values measured when emitters were on
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMaximumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
}
