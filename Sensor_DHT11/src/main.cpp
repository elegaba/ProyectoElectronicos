#include <Arduino.h>
#include <dht.h>
#include <Nextion.h>
#include <NextionPage.h>
#include <NextionNumber.h>
#include <SoftwareSerial.h>
//Crear variable puerto serie "nextionSerial"
SoftwareSerial nextionSerial(8, 9); // RX, TX
Nextion nex(nextionSerial);
//Crear variables para el manejo de los objetos en la pantalla
NextionPage pgNumber(nex, 0, 0, "main");
NextionNumber Temp(nex, 0, 4, "nTemp");
NextionNumber Humed(nex, 0, 5, "nHumed");
//Sensor DHT
dht DHT;
#define DHT11_PIN 2
//Inicio de codigo
void setup(){
  Serial.begin(9600);
  nextionSerial.begin(9600);
  nex.init();
nextionSerial.println(pgNumber.show());
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
