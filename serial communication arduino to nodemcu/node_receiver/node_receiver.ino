#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include  <ESP8266WiFi.h>




//D6 = Rx & D5 = Tx

SoftwareSerial nodemcu(D5, D6);


void setup() {
  // Initialize Serial port
  Serial.begin(9600);
  nodemcu.begin(9600);
  while (!Serial) continue;
}
void loop() {
  

   StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.parseObject(nodemcu);

 if (data == JsonObject::invalid()) {
    //Serial.println("Invalid Json Object");
    jsonBuffer.clear();
    return;
  }

  Serial.println("JSON Object Recieved");
  
  Serial.print("Recieved Humidity:  ");
  float hum = data["statusSensor3"];

  Serial.println(hum);

  
  Serial.print("statusSensor:  ");
  float IR1 = data["statusSensor"];

  Serial.println(IR1);
  
   Serial.print("statusSensor2:  ");
  float IR2 = data["statusSensor2"];

  Serial.println(IR2);

  

  Serial.print("Recieved distance:  ");
  float dist = data["distance"];

  Serial.println(dist);
  Serial.println("-----------------------------------------");
 
 
}
