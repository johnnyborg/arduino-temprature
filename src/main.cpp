// Libraries
#include <DHT.h>
#include <LiquidCrystal.h>

// Constants
#define DHTPIN 2          // what pin we're connected to
#define DHTTYPE DHT22     // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino

// Variables
float hum = 0.0;    //Stores humidity value
float temp = 0.0;   //Stores temperature value
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup()
{
    dht.begin();
    lcd.begin(16, 2);
}

void loop()
{
    // Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();

    // Print temp and humidity values to serial monitor
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(hum);
    lcd.print("%");

    delay(1000);
}
