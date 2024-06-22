

#include <Servo.h>
#include <HCSR04.h>

HCSR04 tak(A1, A0);
HCSR04 ver(A5, A4);
int takk;
int verr;

Servo ajm;
Servo dzaxm;
Servo tat;


int aj = 3;
int dzax = 2;
#define S0 7
#define S1 8
#define S2 9
#define S3 10
#define sensorSalida 12
int Rojo_Frec = 0;
int Verde_Frec = 0;
int Azul_Frec = 0;
void setup() {
  pinMode (aj, INPUT);
  pinMode (dzax, INPUT);
  ajm.attach(5);
  dzaxm.attach(6);
  tat.attach(11);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorSalida, INPUT);

  // Configura la escala de Frecuencia en 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  Serial.begin(9600);
  tat.write(0);

}
void rgb()
{
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  Rojo_Frec = pulseIn(sensorSalida, LOW);
  Serial.print(" R= "); Serial.print(Rojo_Frec);

  // Configura el filtor VERDE para tomar lectura
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  Verde_Frec = pulseIn(sensorSalida, LOW);
  Serial.print(" V= "); Serial.print(Verde_Frec);

  // Configura el filtor AZUL para tomar lectura
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  Azul_Frec = pulseIn(sensorSalida, LOW);
  Serial.print(" A= "); Serial.print(Azul_Frec);


  //Valores obtenidos en la calibracion del sensor, son propios de cada usuario

  if (Rojo_Frec < 40 && Verde_Frec > 70 && Azul_Frec < 70)  Serial.print(" . *** karmir **");
  //
  if (Rojo_Frec > 100 && Verde_Frec < 95 && Azul_Frec < 60)  Serial.print(" . *** kapuyt **");
  if (Rojo_Frec > 60 && Verde_Frec < 50 && Azul_Frec > 45)  Serial.print(" . *** Kanach **");
  if (Rojo_Frec < 55 && Verde_Frec < 55 && Azul_Frec > 15)  Serial.print(" . *** spitak **");

  Serial.println("*");
}
void kang() {
  ajm.write(90);
  dzaxm.write(90);
}
void arajj() {
  ajm.write(110);
  dzaxm.write(110);
}
void dzaxx() {
  ajm.write(110);
  dzaxm.write(70);
}
void ajj() {
  ajm.write(70);
  dzaxm.write(110);
}
void gic() {
  Serial.println(digitalRead(aj));
  Serial.println(digitalRead(dzax));

  if ((digitalRead(aj) == 0) && (digitalRead(dzax) == 0))
    arajj();
  if ((digitalRead(aj) == 1) && (digitalRead(dzax) == 0))
    ajj();
  if ((digitalRead(aj) == 0) && (digitalRead(dzax) == 1))
    dzaxx();
  if ((digitalRead(aj) == 1) && (digitalRead(dzax) == 1))
    arajj();
}
void her() {

  takk = (int(tak.dist()));
  verr = (int(ver.dist()));
  // Serial.println (takk);
  Serial.println (verr);
  delay(10);


}
void pat()
{
  her();

  if ((takk < 10) && (verr > 20)  )

    ajj();


  if ((takk > 12) && (verr > 20) )

    dzaxx();
  if ((takk < 12) && (takk > 10) && (verr > 20))
    arajj();
  if (((takk < 12) && (takk > 10)) && (verr < 20) )
    gic();
}
void kar() {
  tat.write(180);
  delay(1000);
  tat.write(0);
  delay(1000);
  arajj();
  delay(500);
  gic();
}
void loop() {
  rgb();
  her();
  if (Rojo_Frec < 55 && Verde_Frec < 55 && Azul_Frec > 15)
    gic();
  else if (Rojo_Frec < 40 && Verde_Frec > 70 && Azul_Frec < 70)
  {
    arajj();
    delay(500);
    pat();
  }
  else  if (Rojo_Frec > 60 && Verde_Frec < 50 && Azul_Frec > 45)
    kar();
}
