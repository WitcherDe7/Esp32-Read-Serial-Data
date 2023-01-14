void setup() {
  // Start the serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // Check if there is data available on the serial connection
  if (Serial.available() > 0) {
    // Read the incoming data
    String incomingData = Serial.readString();
    // Extract the sensor values from the incoming data
    float humidity = incomingData.substring(incomingData.indexOf("Humidity: ") + 10, incomingData.indexOf(" %\t")).toFloat();
    float temperature = incomingData.substring(incomingData.indexOf("Temperature: ") + 13, incomingData.indexOf(" *C")).toFloat();
    double AQI = incomingData.substring(incomingData.indexOf("AQI: ") + 5, incomingData.indexOf("Ammonia")).toDouble();
    double amonia = incomingData.substring(incomingData.indexOf("Ammonia (ppm): ") + 16, incomingData.indexOf("CO2")).toDouble();
    double CO2ppm = incomingData.substring(incomingData.indexOf("CO2 (ppm): ") + 12).toDouble();
    // Print the sensor values
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");
    Serial.print("AQI: ");
    Serial.println(AQI);
    Serial.print("Ammonia (ppm): ");
    Serial.println(amonia);
    Serial.print("CO2 (ppm): ");
    Serial.println(CO2ppm);
  }
}
