int LINE_PIN = 8;
int M1_PIN = 9;
int M2_PIN = 10;

int data;

void setup() {
  // put your setup code here, to run once:
  pinMode(LINE_PIN, INPUT);
  pinMode(M1_PIN, OUTPUT);
  pinMode(M2_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  data = digitalRead(LINE_PIN);
  if (data == 1) {
    analogWrite(M1_PIN, 0);
    analogWrite(M2_PIN, 100);
  }
  else {
    analogWrite(M1_PIN, 100);
    analogWrite(M2_PIN, 0);
  }
}