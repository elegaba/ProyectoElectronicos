/*
 Para mayor descripcion de las funciones de la libreria Neonextion visitar
 https://dannixon.github.io/NeoNextion/index.html
 por la libreria dht, ver archivos dht.h y dht.cpp ṕara mayor explicacion
 */
#include <Arduino.h>
#include <dht.h>
#include <Nextion.h>
#include <NextionPage.h>
#include <NextionNumber.h>
#include <SoftwareSerial.h>
//******NEXTION*********Lib: Neonextion********************
SoftwareSerial nextionSerial(8, 9); // RX, TX
Nextion nex(nextionSerial);//Variable del puerto serie
NextionPage pgNumber(nex, 0, 0, "main");
NextionNumber Temp(nex, 0, 4, "nTemp");//Variable temperatura en pantalla
NextionNumber Humed(nex, 0, 5, "nHumed");//Variable Humedad en pantalla
//Sensor DHT
dht DHT;
#define DHT11_PIN 2
//Inicio de codigo
void setup(){
  Serial.begin(9600);//Puerto hardware
  nextionSerial.begin(9600);//Puerto software para la nextion
  nex.init();
nextionSerial.println(pgNumber.show());//Funcion para mostrar una pantalla
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  nextionSerial.println(Temp.setValue(DHT.temperature));
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  nextionSerial.println(Humed.setValue(DHT.humidity));
  delay(3000);
}
