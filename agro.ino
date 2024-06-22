#include <Servo.h>

Servo servo;
Servo mator;
int manr = 8;
int mijin = 9;
int xoshor = 10;
int lmanr = 2;
int lmijin = 3;
int lxoshor = 4;
int buzzer = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(manr, INPUT);
  pinMode(mijin, INPUT);
  pinMode(xoshor, INPUT);
  servo.attach(7);
  mator.attach(6);
  mator.write(90);
  servo.write(180);
  Serial.begin(9600);
  pinMode(lmanr, OUTPUT);
  pinMode(lmijin, OUTPUT);
  pinMode(lxoshor, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  delay(3000);
}
void bunker()
{
  servo.write(140);
  delay(500);
  servo.write(180);
  delay(1000);
}

void loop() {
  if ((digitalRead(manr) == 0) && (digitalRead(mijin) == 0) && (digitalRead(xoshor) == 0))

  {
    mator.write(130);
    bunker();
    digitalWrite(lmanr, LOW);
    digitalWrite(lmijin, LOW);
    digitalWrite(lxoshor, LOW);
    digitalWrite(buzzer, LOW);

  }
  else if ((digitalRead(manr) == 1) && (digitalRead(mijin) == 0) && (digitalRead(xoshor) == 0))
  {
    mator.write(90);
    servo.write(180);
    digitalWrite(lmanr, HIGH);
    digitalWrite(lmijin, LOW);
    digitalWrite(lxoshor, LOW);
    digitalWrite(buzzer, HIGH);
    delay(5000);

  }
else if ((digitalRead(manr) == 0) && (digitalRead(mijin) == 1) && (digitalRead(xoshor) == 0))
  {
    mator.write(90);
    servo.write(180);
    digitalWrite(lmanr, LOW);
    digitalWrite(lmijin, HIGH);
    digitalWrite(lxoshor, LOW);
    digitalWrite(buzzer, HIGH);
    delay(5000);

  }
  else if ((digitalRead(manr) == 0) && (digitalRead(mijin) == 0) && (digitalRead(xoshor) == 1))
  {
    mator.write(90);
    servo.write(180);
    digitalWrite(lmanr, LOW);
    digitalWrite(lmijin, LOW);
    digitalWrite(lxoshor, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(5000);

  }



}
