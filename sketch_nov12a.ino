const int buttonPin = 2; 
const int ledPin = 3;     
int buttonState = 0;
int lastButtonState = LOW;
int mode = 0; // 

unsigned long previousMillis = 0;
bool ledOn = true;


const long slowInterval = 1000;   
const long mediumInterval = 500;  
const long fastInterval = 150;    
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  
  digitalWrite(ledPin, LOW); 
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH && lastButtonState == LOW) {
    mode++;
    if (mode > 3) {
      mode = 0; 
    }
    
    
    previousMillis = millis();
    ledOn = true;
    delay(50); 
  }
  lastButtonState = buttonState;

  
  unsigned long currentMillis = millis();

  if (mode == 0) {
    
    digitalWrite(ledPin, LOW);
  } 
  else if (mode == 1) {
    
    if (currentMillis - previousMillis >= slowInterval) {
      previousMillis = currentMillis;
      ledOn = !ledOn;
      digitalWrite(ledPin, ledOn ? LOW : HIGH);
    }
  } 
  else if (mode == 2) {
    
    if (currentMillis - previousMillis >= mediumInterval) {
      previousMillis = currentMillis;
      ledOn = !ledOn;
      digitalWrite(ledPin, ledOn ? LOW : HIGH);
    }
  } 
  else if (mode == 3) {
    
    if (currentMillis - previousMillis >= fastInterval) {
      previousMillis = currentMillis;
      ledOn = !ledOn;
      digitalWrite(ledPin, ledOn ? LOW : HIGH);
    }
  }
}


