int oddLedState = HIGH;
int evenLedState = LOW;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(1, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {

  // Toggle even led state
  evenLedState = (evenLedState == LOW) ? HIGH : LOW;

  // put your main code here, to run repeatedly:
  digitalWrite(2, evenLedState);
  digitalWrite(4, evenLedState);
  digitalWrite(6, evenLedState);
  digitalWrite(8, evenLedState);
  digitalWrite(10, evenLedState);

  // Toggle odd led state
  oddLedState = (oddLedState == LOW) ? HIGH : LOW;
  digitalWrite(1, oddLedState);
  digitalWrite(3, oddLedState);
  digitalWrite(5, oddLedState);
  digitalWrite(7, oddLedState);
  digitalWrite(9, oddLedState);
  digitalWrite(11, oddLedState);

  delay(820);
}
