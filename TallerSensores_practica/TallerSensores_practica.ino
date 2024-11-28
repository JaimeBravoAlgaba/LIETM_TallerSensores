const int potPin = A0;
const int ledPin = 9;

int lectura_min = 0, lectura_max = 1023;
int salida_min = 0, salida_max = 255;

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);
  potValue = map(potValue, lectura_min, lectura_max, salida_min, salida_max);
  
  Serial.print(salida_min); Serial.print(",");
  Serial.print(salida_max); Serial.print(",");
  Serial.println(potValue);

  analogWrite(ledPin, potValue);
  delay(5);
}
