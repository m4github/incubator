//Incubator for fun with cusins :-*
#include <DHT.h>
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

#define relay 10 
void setup() {
   
Serial.begin(9600); 
Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {

 int t = dht.readTemperature();
 int h = dht.readHumidity(); 

if (isnan(h) || isnan(t) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
}
 Serial.print("Temperature = ");
 Serial.print(t);
 Serial.print("   ");
 Serial.print("Humidity = ");
 Serial.print(h);
 Serial.println("");
 if (t >=27)
  digitalWrite(relay,HIGH);
  else {
    digitalWrite(relay, LOW);
  }
  delay(2000); // Delays 2 secods
}
