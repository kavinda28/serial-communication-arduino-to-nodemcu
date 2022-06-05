//Arduino to NodeMCU Lib
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

//Initialise Arduino to NodeMCU (5=Rx & 6=Tx)
SoftwareSerial nodemcu(6, 5);


void setup() {
  Serial.begin(9600);
  nodemcu.begin(9600);


}

void loop() {

 StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.createObject();
   //Assign collected data to JSON Object
  data["distance"] = 101;
  data["statusSensor"] = 303; 
  data["statusSensor2"] = 202; 
  data["statusSensor3"] = 404; 

  //Send data to NodeMCU
  data.printTo(nodemcu);
  jsonBuffer.clear();


  delay(2000);


}
