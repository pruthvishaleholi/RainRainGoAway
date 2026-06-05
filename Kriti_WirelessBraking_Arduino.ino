String pinValue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    pinValue = Serial.read();
    Serial.print(pinValue);
  }
  if (pinValue == "49") {
    digitalWrite(7, HIGH);
  }
  else {
    digitalWrite(7, LOW);
  }
  
}
