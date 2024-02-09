#define TRIG 6
#define ECHO 5
#define M1 9
#define M2 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  printCurve(getDist(TRIG, ECHO), filtr(30, 50));
}

int getDist(int a, int b){
  digitalWrite(a, 0);
  delayMicroseconds(3);
  digitalWrite(a, 1);
  delayMicroseconds(10);
  digitalWrite(a, 0);  
  int cm = pulseIn(b, 1)/58.0;
  return cm;
}

void printCurve(int a, int b){
  Serial.println("Сигнал1, Сигнал2");
  Serial.print(a);
  Serial.print(',');
  Serial.print(b);
  Serial.println();
}

float filtr(int n, int t){
  float sum = 0;
  for (int i=0; i < n; i++){
    sum+=getDist(TRIG, ECHO);
    delay(t);
  }
  return (sum/n);
}