# particle-dht22

Project for reading a [DHT22](https://www.adafruit.com/product/385) temperature and humidity sensor using a Particle device and exposing the readings over HTTP.

### Get

`git clone blah --recursive`

### Build/Deploy

`particle flash dht22_zero particle-dht22.ino lib\adafruit_dht_library\firmware\Adafruit_DHT.h lib\adafruit_dht_library\firmware\Adafruit_DHT.cpp`

### Serial Monitor

`particle serial monitor`

You should get results like this:

    Sat Dec 24 15:45:41 2016 - Humid: 32.60% - Temp: 74.66°F / 23.70°C  - HeatI: 77.03°F
    Sat Dec 24 15:45:43 2016 - Humid: 32.60% - Temp: 74.66°F / 23.70°C  - HeatI: 77.03°F
    Sat Dec 24 15:45:45 2016 - Humid: 32.60% - Temp: 74.66°F / 23.70°C  - HeatI: 77.03°F
    Sat Dec 24 15:45:48 2016 - Humid: 32.60% - Temp: 74.66°F / 23.70°C  - HeatI: 77.03°F
    Sat Dec 24 15:45:50 2016 - Humid: 32.60% - Temp: 74.66°F / 23.70°C  - HeatI: 77.03°F

### HTTP

The three exposed variables are `humidity`, `tempC`, and `tempF`. This can be read from your device using:

`curl https://api.particle.io/v1/devices/{device_name_or_id}/tempF?access_token={your_access_token}`