#include "Adafruit_DHT.h"

#define LED_PIN D7
#define DHT_DATA_PIN 2  

// DHT TYPES
//#define DHT_TYPE DHT11	// DHT 11 
#define DHT_DEVICE_TYPE DHT22		// DHT 22 (AM2302)
//#define DHT_TYPE DHT21    // DHT 21 (AM2301)

// internal variables
DHT dht(DHT_DATA_PIN, DHT_DEVICE_TYPE);
int led_on_state = 0;

// public variables (for curling)
double tempF = 0, tempC = 0, humidity = 0;



void setup() {    

    Particle.variable("tempF", tempF);
    Particle.variable("tempC", tempC);
    Particle.variable("humidity", humidity);

    pinMode(LED_PIN, OUTPUT);

    Serial.begin(9600); 

	dht.begin();
}

void loop() {

    // alternate the LED_PIN between high and low
    // to show that we're still alive
    digitalWrite(LED_PIN, (led_on_state) ? HIGH : LOW);
    led_on_state = !led_on_state;

    // DHT22 max read time is 0.5Hz
	delay(2000);

    // Reading temperature or humidity takes about 250 milliseconds
	humidity = dht.getHumidity();
	tempC = dht.getTempCelcius();
	tempF = dht.getTempFarenheit();
  
    // Check if any reads failed and exit early 
	if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}

    float hi = c2f(dht.getHeatIndex());
	//float dp = dht.getDewPoint();
	//float k = dht.getTempKelvin();

	Serial.print(Time.timeStr());
	Serial.print("- Humid: "); 
	Serial.print(humidity);
	Serial.print("% - ");
	Serial.print("Temp: "); 
	Serial.print(tempF);
	Serial.print("°F / ");
	Serial.print(tempC);
	Serial.print("°C ");
	Serial.print(" - HeatI: ");
	Serial.print(hi);
	Serial.println("°F");
}

// celcius to fahrenheit
float c2f(float c)
{
    return 1.8 * c + 32;
}