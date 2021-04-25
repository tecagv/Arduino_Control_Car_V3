//Código base Smart Car Arduino
// Servo, Sensor, Bluetooth

// Alexandre Garcez Vieira
// tecagv@terra.com.br
// Skype: tecagv@live.com
// Licença: CC BY-NC-SA
//https://br.creativecommons.org/

#include <Servo.h>
Servo servo1;                    

int izqA = 5;
int izqB = 6;
int derA = 9;
int derB = 10;
int vel = 100;            
int estado = 'c';         

int pecho = 2;            
int ptrig = 3;

int duracion, distancia;  


void setup()  {

  Serial.begin(9600);    
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);

  pinMode(pecho, INPUT);   
  pinMode(ptrig, OUTPUT);

  pinMode(13, OUTPUT);
  pinMode(30, OUTPUT); //Sirene
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(50, OUTPUT);

  servo1.attach(11, 660, 1400);  

}

void loop()  {

  if (Serial.available() > 0) {    
    estado = Serial.read();
  }
  if (estado == 'a') {       //Frente
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(derA, vel);
    analogWrite(izqA, vel);
    digitalWrite(50, LOW);
  }
  if (estado == 'b') {      //Essquerda
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(derA, 0);
    analogWrite(izqA, vel);
    digitalWrite(50, LOW);
  }
  if (estado == 'c') {     
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(derA, 0);
    analogWrite(izqA, 0);
    digitalWrite(30, LOW);
    digitalWrite(40, LOW);
    digitalWrite(41, LOW);
    digitalWrite(50, HIGH);
  }
  if (estado == 'd') {      //Direita
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(izqA, 0);
    analogWrite(derA, vel);
    digitalWrite(50, LOW);
  }

  if (estado == 'e') {      //Atrás
    analogWrite(derA, 0);
    analogWrite(izqA, 0);
    analogWrite(derB, vel);
    analogWrite(izqB, vel);
    digitalWrite(50, LOW);
  }

  if (estado == 'f') {          //Andar   

    digitalWrite(ptrig, HIGH);   
    delay(0.01);
    digitalWrite(ptrig, LOW);

    duracion = pulseIn(pecho, HIGH);          
    distancia = (duracion / 2) / 29;          
    delay(10);

    if (distancia <= 30 && distancia >= 2) {  
      digitalWrite(13, HIGH);                

      analogWrite(derB, 0);             
      analogWrite(izqB, 0);
      analogWrite(derA, 0);
      analogWrite(izqA, 0);
      delay (200);

      analogWrite(derB, vel);          
      analogWrite(izqB, vel);
      delay(500);

      analogWrite(derB, 0);            
      analogWrite(izqB, 0);
      analogWrite(derA, 0);
      analogWrite(izqA, vel);
      delay(600);

      digitalWrite(13, LOW);
    }
    else {                            
      analogWrite(derB, 0);
      analogWrite(izqB, 0);
      analogWrite(derA, vel);
      analogWrite(izqA, vel);
    }
  }
  if (estado == 'g') {               
    servo1.write(30);                
    delay(1000);                     

    servo1.write(90);                
    delay(700);                      

    servo1.write(150);               
    delay(700);
  }
  if (estado == 'h') {             
    digitalWrite(40, HIGH);
  }
  if (estado == 'm') {
    digitalWrite(13, 0);
  }
  if (estado == 'i') {
    digitalWrite(30, HIGH);       
  }
  if (estado == 'n') {
    digitalWrite(derB, 0);
  }
  if (estado == 'j') {
    digitalWrite(41, HIGH);
  }
  if (estado == 'o') {
    digitalWrite(derA, 0);
  }
  if (estado == 'k') {
    digitalWrite(izqB, 1);
  }
  if (estado == 'p') {
    digitalWrite(izqB, 0);
  }
  if (estado == 'l') {
    digitalWrite(izqA, 1);
  }
  if (estado == 'q') {
    digitalWrite(30, HIGH);
    digitalWrite(40, HIGH);
    digitalWrite(41, HIGH);
    digitalWrite(50, HIGH);
  }
}





