int LINE_PIN = 8;
int M1_PIN = 9;
int M2_PIN = 10;

int SPEED = 75;

int sensor;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(LINE_PIN, INPUT);
  pinMode(M1_PIN, OUTPUT);
  pinMode(M2_PIN, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  sensor = digitalRead(LINE_PIN);
  if (sensor == 1) {
    analogWrite(M1_PIN, 0);
    analogWrite(M2_PIN, 0);
  }
  else {
    analogWrite(M1_PIN, SPEED);
    analogWrite(M2_PIN, SPEED);
  }
}