const int sensorPin = A0;

int lectura_min = 0;
int lectura_max = 1023;
int salida_min = 0, salida_max = 100;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, lectura_min, lectura_max, salida_min, salida_max);
  
  Serial.print(salida_min); Serial.print(",");
  Serial.print(salida_max); Serial.print(",");
  Serial.println(sensorValue);
}
