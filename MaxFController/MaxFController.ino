const int ledCount = 10;

const int buttonPin1 = 2;
const int buttonPin2 = 3;
int ledPins[] = {
  4,5,6,7,8,9,10,11,12,13
};

void setup() {
  pinMode(buttonPin1,INPUT);
  pinMode(buttonPin2,INPUT);

   for(int thisLed= 0; thisLed<ledCount; thisLed++){
    pinMode(ledPins[thisLed],OUTPUT);
  }
  Serial.begin(9600);

}

void loop() {
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int sensorValue = analogRead(A0);
  int LEDnumber = sensorValue / 103;

  for(int leds = 0; leds<ledCount; leds++){
    digitalWrite(ledPins[leds],LOW);
  }
  digitalWrite(ledPins[LEDnumber],HIGH);

  String outputString = String(sensorValue) + "," + String(buttonState1) +"," + String(buttonState2);
  
  Serial.println(outputString);
  delay(50);
}
