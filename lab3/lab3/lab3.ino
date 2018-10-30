
const int pushBtn = 2;
const int red = 12;
const int green = 13;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 10;
unsigned long previousMillis;

int buttonState;
int lastButtonState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode (pushBtn, INPUT);
  pinMode (red, OUTPUT);
  pinMode (green, OUTPUT);

  digitalWrite (green, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (millis() - previousMillis >= 2000)
    toggleLeds();
  
  int reading = digitalRead(pushBtn);
   if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;
      
      if (buttonState == HIGH) {
        //if (digitalRead(red) == HIGH) //change when only red led is on
          toggleLeds();
      }
    }
  }
  lastButtonState = reading;
}

void toggleLeds (){
  digitalWrite (red, !digitalRead(red));
  digitalWrite (green, !digitalRead(green));
  previousMillis = millis();
}
