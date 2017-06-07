#include <LEDProgress.h>

#include <DHT_U.h>
#include <DHT.h>

#include <Adafruit_Sensor.h>

#define DHTPIN 7    
#define DHTTYPE DHT11

int leds[4] = {6,9,10,11};
int nleds = 4;
int debug = 0;

DHT dht(DHTPIN, DHTTYPE);
LEDProgress ledprogress(leds, nleds, 100);

void setup() {
  if (debug) Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  
  if (debug) {
    Serial.print("Humidity ");
    Serial.println(h);
  }
  
  ledprogress.setProgress(h);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
}
