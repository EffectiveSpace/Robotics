int trig = 6, echo = 5, left = 9, right = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //printRes(getDist(trig, echo), filtr(10, 50));
  int cm = filtr(10, 20);
  if (cm < 30){
    robot_left(left, right, 200);
    robot_forward(left, right);
    delay(200);
    robot_right(left, right, 200);
  }
  else{
    robot_forward(left, right);
  }
  
}

int getDist(int a, int b){
  digitalWrite(a, 0);
  delayMicroseconds(3);
  digitalWrite(a, 1);
  delayMicroseconds(10);
  digitalWrite(a, 0);
  int dist = pulseIn(b, 1)/58.0;
  return dist;
}

void printRes(int a, int b){
  Serial.println("Сигнал1, Сигнал2");
  Serial.print(a);
  Serial.print(',');
  Serial.print(b);
  Serial.println();
}

float filtr(int num, int t){
  float sum = 0;
  for (int i = 0; i < num; i++){
    sum += getDist(trig, echo);
    delay(t);
  }
  return (sum/num);
}

void robot_left(int x, int y, int t){
  analogWrite(x, 0);
  analogWrite(y, 127);
  delay(t);
}

void robot_right(int x, int y, int t){
  analogWrite(x, 127);
  analogWrite(y, 0);
  delay(t);
}

void robot_forward(int x, int y){
  analogWrite(x, 127);
  analogWrite(y, 127);
  
}
