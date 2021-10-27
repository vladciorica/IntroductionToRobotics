const int ledPinRed = 11;
const int ledPinGreen = 10;
const int ledPinBlue = 9;
const int potPinRed = A0;
const int potPinGreen = A1;
const int potPinBlue = A2;
const int maxAnalogValue = 1023;
const int maxVoltageValue = 255;
int brightnessRed = 0, brightnessGreen = 0, brightnessBlue = 0;
int potValueRed = 0,potValueGreen = 0, potValueBlue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPinRed,OUTPUT);
  pinMode(ledPinGreen,OUTPUT);
  pinMode(ledPinBlue,OUTPUT);
  pinMode(potPinRed,INPUT);
  pinMode(potPinGreen,INPUT);
  pinMode(potPinBlue,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValueRed = analogRead(potPinRed);
  brightnessRed = map(potValueRed,0,maxAnalogValue,0,maxVoltageValue);
  potValueGreen = analogRead(potPinGreen);
  brightnessGreen = map(potValueGreen,0,maxAnalogValue,0,maxVoltageValue);
  potValueBlue = analogRead(potPinBlue);
  brightnessBlue = map(potValueBlue,0,maxAnalogValue,0,maxVoltageValue);
  analogWrite(ledPinRed,brightnessRed);
  analogWrite(ledPinGreen,brightnessGreen);
  analogWrite(ledPinBlue,brightnessBlue);
}
