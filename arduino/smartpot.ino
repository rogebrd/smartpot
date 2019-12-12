#include <DHT.h>
#include <DHT_U.h>

int lightAnalogPin = 14;
int lightDigitalPin = 2;
int tempAnalogPin = 15;
int tempAnalogValue = 0;
int lightAnalogValue = 0;
int lightDigitalValue = 0;
DHT dht = DHT(tempAnalogPin, DHT22);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(lightAnalogPin, INPUT);
  pinMode(lightDigitalPin, INPUT);
  pinMode(tempAnalogPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  dht.begin();
  Serial.print("Starting up application.");
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  lightAnalogValue = analogRead(lightAnalogPin);
  Serial.print("Current Analog Light Value: ");
  Serial.print(lightAnalogValue);
  Serial.println();
  lightDigitalValue = digitalRead(lightDigitalPin);
  Serial.print("Current Digital Light Value: ");
  Serial.print(lightDigitalValue);
  Serial.println();
  tempAnalogValue = dht.read(); // Reads the data from the sensor
  float t = dht.readTemperature(true); // Gets the values of the temperature
  float h = dht.readHumidity(); // Gets the values of the humidity
  Serial.print("Current Analog Temp Value: ");
  Serial.print(t);
  Serial.print(" humidity ");
  Serial.print(h);
  Serial.println();
  Serial.print("--------------------------------------------------------------------");
  Serial.println();
  delay(10000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
