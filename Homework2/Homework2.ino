const int ledPinGreenCars = 11;
const int ledPinYellowCars = 10;
const int ledPinRedCars = 9;
const int ledPinGreenPeople = 5;
const int ledPinRedPeople = 3;
const int buttonPin = 12;
const int buzzerPin = 13;
bool buttonValue = LOW;
bool previousValue = HIGH;
bool ledGreenCarsValue = HIGH, ledYellowCarsValue = LOW, ledRedCarsValue = LOW;
bool ledGreenPeopleValue = LOW, ledRedPeopleValue = HIGH;
const int beepSound = 100;
int reading = HIGH;
int previousReading = HIGH;
unsigned int lastDebounceTime = 0;
unsigned int debounceDelay = 50;
unsigned int startState2 = 0, startState3 = 0, startState4 = 0, buttonPressTime = 0;
unsigned int waitState1Duration = 2000, state2Duration = 3000, state3Duration = 5000, state4Duration = 5000;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPinGreenCars,OUTPUT);
  pinMode(ledPinYellowCars,OUTPUT);
  pinMode(ledPinRedCars,OUTPUT);
  pinMode(ledPinGreenPeople,OUTPUT);
  pinMode(ledPinRedPeople,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(buzzerPin,OUTPUT);
  Serial.begin(9600);
}

void outputAllLeds()
{
  digitalWrite(ledPinGreenCars,ledGreenCarsValue);
  digitalWrite(ledPinYellowCars,ledYellowCarsValue);
  digitalWrite(ledPinRedCars,ledRedCarsValue);
  digitalWrite(ledPinGreenPeople,ledGreenPeopleValue);
  digitalWrite(ledPinRedPeople,ledRedPeopleValue);
}

void semaforState1()
{
  ledGreenCarsValue = HIGH;
  ledYellowCarsValue = LOW; 
  ledRedCarsValue = LOW;
  ledGreenPeopleValue = LOW; 
  ledRedPeopleValue = HIGH;
  outputAllLeds();
  Serial.println("Am ajuns in state 1");
}

void semaforState2()
{
  buttonPressTime = millis();
  while(millis() - buttonPressTime < waitState1Duration){
    
  }
  startState2 = millis();
  ledGreenCarsValue = LOW;
  ledYellowCarsValue = HIGH; 
  ledRedCarsValue = LOW;
  ledGreenPeopleValue = LOW; 
  ledRedPeopleValue = HIGH;
  outputAllLeds();
  while(millis() - startState2 < state2Duration){
        
  }
  Serial.println("Am ajuns in state 2");
}

void semaforState3()
{
  startState3 = millis();
  ledGreenCarsValue = LOW;
  ledYellowCarsValue = LOW; 
  ledRedCarsValue = HIGH;
  ledGreenPeopleValue = HIGH; 
  ledRedPeopleValue = LOW;
  outputAllLeds();
  while(millis() - startState3 < state3Duration){
    tone(buzzerPin, beepSound); 
    delay(500);        
    noTone(buzzerPin);    
    delay(500);  
  }
  Serial.println("Am ajuns in state 3");
}

void semaforState4()
{
  startState4 = millis();
  ledGreenCarsValue = LOW;
  ledYellowCarsValue = LOW; 
  ledRedCarsValue = HIGH;
  ledGreenPeopleValue = HIGH; 
  ledRedPeopleValue = LOW;
  outputAllLeds();
  while(millis() - startState4 < state4Duration)
  {
    ledGreenPeopleValue = HIGH;
    outputAllLeds();
    tone(buzzerPin, beepSound); 
    delay(250);        
    noTone(buzzerPin);    
    delay(250);      
    ledGreenPeopleValue = LOW;
    outputAllLeds();
    tone(buzzerPin, beepSound); 
    delay(250);        
    noTone(buzzerPin);    
    delay(250);      
  }
  Serial.println("Am ajuns in state 4");
}

void loop() {
  // put your main code here, to run repeatedly:
  outputAllLeds();
  reading = digitalRead(buttonPin);
  if(reading != previousReading){
    lastDebounceTime = millis();
  }
  if(millis() - lastDebounceTime > debounceDelay){
    if(reading != buttonValue){
      buttonValue = reading;
      if(buttonValue == LOW){
        semaforState2();
        semaforState3();
        semaforState4();
        semaforState1();
      }
    }
  }
  previousReading = reading;
}
