//declare all the segments pins
const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;
const int pinG = 8;
const int pinDP = 9;
const int buzzerPin = 13;
const int antennaPin = A5;

int antennaValue = 0;
const int beepSound = 100;
const int segSize = 8;
const int noOfDigits = 10;
bool dpState = LOW;
bool state = HIGH;
int index = 0;
int displayDigit;

const int maxVoltageValue = 255;
const int maxAnalogValue = 1023;
const int numReadings = 5;
int readings[numReadings + 1];                // the readings from the analog input                          
int total = 0;                            // the running total
int average = 0;                          // final average of the probe reading

int segments[segSize] = {
   pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};

bool digitMatrix[noOfDigits][segSize - 1] = {
// a  b  c  d  e  f  g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};


void displayNumber(byte digit, bool decimalPoint){
  for(int i = 0 ; i < segSize - 1; i++){
    digitalWrite(segments[i], digitMatrix[digit][i]);  
  }
  digitalWrite(pinDP, decimalPoint);
}

void displayNothing()
{
  for(int i = 0 ; i < segSize - 1; i++){
    digitalWrite(segments[i], LOW);  
  }
}

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < segSize; i++){
    pinMode(segments[i],OUTPUT);
  }
  pinMode(buzzerPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:  
  antennaValue = analogRead(antennaPin);
  if( antennaValue >= 1)
  {
    Serial.print("Valoarea citita: ");
    Serial.println(antennaValue);
    index++;
    total -= readings[index];
    readings[index] = antennaValue;
    total += antennaValue;
    Serial.print("Valoarea totala: ");
    Serial.println(total);
    average = total / numReadings;
    if(index >= numReadings)
      index = 0;
    Serial.print("Valoarea medie: ");
    Serial.println(average);
    displayDigit = map(average,1,maxAnalogValue,0,noOfDigits - 1);
    Serial.print("Cifra afisata: ");
    Serial.println(displayDigit);
    if(displayDigit >= 1)
    {
      displayNumber( displayDigit , dpState);
      delay(500);
      tone(buzzerPin, average); 
    }
    else
    {
      displayNothing();
      noTone(buzzerPin); 
    }    
  }
}
