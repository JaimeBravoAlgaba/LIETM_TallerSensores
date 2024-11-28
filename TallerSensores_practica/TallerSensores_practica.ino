// Declaración de pines
const int potPin = A0;
const int ledPin = 9;

// Variables eléctricas
float Rf_min = 29.0, Rf_max = 90, R = 34.0;

// Rangos de lectura
int lectura_min = R/(R+Rf_max) * 1023;
int lectura_max = R/(R+Rf_min) * 1023;
int salida_min = 0, salida_max = 255;

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Medición: tomar el dato "crudo" del sensor
  int potValue = analogRead(potPin);

  // Ajuste de escala: traducir el dato crudo al rango que deseemos
  potValue = map(potValue, lectura_min, lectura_max, salida_min, salida_max);

  // Saturación: se asegura que la señal no exceda el rango de 0 a 255 para el PWM
  potValue = (potValue>255)? 255 : potValue;
  potValue = (potValue<0)? 0 : potValue;

  // Iluminar el LED y graficar
  analogWrite(ledPin, potValue);
  
  Serial.print(salida_min); Serial.print(",");
  Serial.print(salida_max); Serial.print(",");
  Serial.println(potValue);

  delay(5);
}
