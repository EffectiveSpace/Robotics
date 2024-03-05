//создание переменных
int m1 = 9, m2 = 10, trig = 6, echo = 5;
int _start = 80, _stop = 10;

//настройка портов
void setup() {
  // put your setup code here, to run once:
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

//основной цикл программы - запуск функции motors с параметрами фильтра, стартовой и финишной точки
void loop() {
  // put your main code here, to run repeatedly:
  motors(filtr(5, 10), _stop, _start);
}

//принимающая и возвращающая функция для определения дистанции с датчика расстояния
int dist(int a, int b){
  digitalWrite(a, 0);
  delayMicroseconds(3);
  digitalWrite(a, 1);
  delayMicroseconds(10);
  digitalWrite(a, 0);
  int cm = pulseIn(b, 1)/58.0;
  return cm;
}

//принимающая и возвращающая функция реализующая программный фильтр по среднему значению
int filtr(int count, int t){
  int sum = 0;
  for (int i = 0; i < count; i++){
    sum += dist(trig, echo);
    delay(t);
  }
  return (sum/count);
}

//принимающая функция, реализующая уменьшение скорости робота в зависимости от уменьшения расстояния до препятствия
void motors(int val, int x, int y){
  _speed = map(val, x, y, 0, 255); // маппирование - преобразование из одного диапазона значений в другой
  analogWrite(m1, round(_speed));
  analogWrite(m2, round(_speed));
}