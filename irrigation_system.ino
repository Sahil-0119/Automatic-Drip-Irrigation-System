int soilSensor = A0;      
int pump = 8;             
int moistureValue = 0;    
int threshold = 500;      

void setup() {
  Serial.begin(9600);
  pinMode(pump, OUTPUT);
  digitalWrite(pump, LOW);
}

void loop() {
  moistureValue = analogRead(soilSensor);
  Serial.print("Soil Moisture: ");
  Serial.println(moistureValue);

  if (moistureValue > threshold) {
    digitalWrite(pump, HIGH);   // Turn ON pump
    Serial.println("Pump ON: Soil is dry");
  } else {
    digitalWrite(pump, LOW);    // Turn OFF pump
    Serial.println("Pump OFF: Soil is wet");
  }

  delay(1000);
}
