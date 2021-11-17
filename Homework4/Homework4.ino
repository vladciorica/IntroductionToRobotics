const int pinSW = 3;
const int pinX = A0;
const int pinY = A1;
int xValue = 0;
int yValue = 0;
bool switchState = LOW;
bool lastState  = HIGH;

int minThreshold = 350;
int maxThreshold = 700;

bool joyMoved = LOW;
int index = 0;
bool currentState = HIGH;

int currentTime = 0;
int lastTime = 0;

const int dataPin = 12; // DS
const int latchPin =  11; // STCP
const int clockPin = 10; // SHCP

const int segD1 = 7;
const int segD2 = 6;
const int segD3 = 5;
const int segD4 = 4;

int displayDigit = 0;
const int displayCount = 4;

const int displayDigits[] = {
  segD1, segD2, segD3, segD4
};

int digitArray[10] = {
//A B C D E F G DP 
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110, // 9
};

int digitsValues[] = {
  0,0,0,0
};

bool dpStates[] = {
  HIGH,LOW,LOW,LOW
};

void setup() {
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  pinMode(pinSW,INPUT_PULLUP);
  pinMode(pinX,INPUT);
  pinMode(pinY,INPUT);
  
  for (int i = 0; i < displayCount; i++) {
    pinMode(displayDigits[i], OUTPUT);
    digitalWrite(displayDigits[i],LOW);
  }
}


void loop() {
  
  for(int i = 0 ; i < displayCount; i++){
    showDigit(i);
    writeReg(digitArray[digitsValues[i]],dpStates[i]);
    if(currentState == HIGH && displayDigit == i){ 
        currentTime = millis();
        if(currentTime - lastTime > 250){
            dpStates[i] = !dpStates[i];
            writeReg(digitArray[digitsValues[i]],dpStates[i]);
            lastTime = currentTime;
          }
        
    }
    delay(6);
  }
  xValue = analogRead(pinX);
  yValue = analogRead(pinY);
  switchState = digitalRead(pinSW);
  index = digitsValues[displayDigit];
  if(currentState == LOW){
      if(xValue > maxThreshold && joyMoved == false){
        index++;
        joyMoved = true;
      }
    
      if(xValue < minThreshold && joyMoved == false){
        index--;
        joyMoved = true;
      }
    
      if(index > 9)
        index = 0;
      if(index < 0)
        index = 9;
    
      if(xValue > minThreshold && xValue < maxThreshold)
        joyMoved = false;

      if(switchState == LOW && switchState != lastState){
          dpStates[displayDigit] = HIGH;
          currentState = HIGH;
          joyMoved = LOW;
      }
    
      digitsValues[displayDigit] = index;
      lastState = switchState;
  }
  else{
    int changedDigit = displayDigit;
    if(yValue > maxThreshold && joyMoved == false){
        changedDigit--;
        joyMoved = true;
      }
    
      if(yValue < minThreshold && joyMoved == false){
        changedDigit++;
        joyMoved = true;
      }
    
      if(changedDigit > displayCount - 1)
        changedDigit = 0;
      if(changedDigit < 0)
        changedDigit = displayCount - 1;
    
      if(yValue > minThreshold && yValue < maxThreshold)
        joyMoved = false;

      if(switchState == LOW && switchState != lastState){
          dpStates[displayDigit] = HIGH;
          currentState = LOW;      
          joyMoved = LOW;
      }
      if(changedDigit != displayDigit){
        dpStates[displayDigit] = LOW;
        displayDigit = changedDigit;
      }
      lastState = switchState;
  }
}


void showDigit(int digit) {
  for (int i = 0; i < displayCount; i++) {
    digitalWrite(displayDigits[i], HIGH);
  }
  digitalWrite(displayDigits[digit], LOW);
}

void writeReg(int digit, bool dpState) {
  if(dpState == HIGH)
    digit++;
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  digitalWrite(latchPin, HIGH);
}
