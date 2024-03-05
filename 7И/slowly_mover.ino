//создание переменных
int left = 9, right = 10, trig = 6, echo = 5;
int Start = 80, Stop = 10;

//настройка портов
void setup() {
  // put your setup code here, to run once:
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

//основной цикл программы - запуск функции motors с параметрами фильтра, стартовой и финишной точки
void loop() {
  // put your main code here, to run repeatedly:
  motors(filtr(10, 10), Start, Stop);
}

//принимающая и возвращающая функция для определения дистанции с датчика расстояния
int dist(int x, int y){
  digitalWrite(x, 0);
  delayMicroseconds(3);
  digitalWrite(x, 1);
  delayMicroseconds(10);
  digitalWrite(x, 0);
  int cm = pulseIn(y, 1)/58.0;
  return cm;
}

//принимающая и возвращающая функция реализующая программный фильтр по среднему значению
int filtr(int count, int t){
  int sum = 0;
  for (int i=0; i < count; i++){
    sum += dist(trig, echo);
    delay(t);
  }
  return (sum/count);
}

//принимающая функция, реализующая уменьшение скорости робота в зависимости от уменьшения расстояния до препятствия
void motors(int dist, int start_, int stop_){
  int sped = ((dist-stop_)/(start_-stop_))*255; // маппирование - преобразование из одного диапазона значений в другой
  //int sped = map(dist, stop_, start_, 0, 255);
  analogWrite(right, round(sped));
  analogWrite(left, round(sped));
}