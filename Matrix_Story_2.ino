#include "LedControlMS.h"
#define NumMatrix 1 //numero de matrices a ocupar

const int buttonPin = 3; //pin del boton a ocupar
int numerodepulsaciones; //para que se muestren en Monitor de serie
int contador;
int buttonState = 0; //estado de boton encendido o apagado

int espera=200;
int time=0;
  
LedControl lc=LedControl(12,11,10,NumMatrix);

int Datos;
byte Planet[] = {
  B00000000,
  B00000000,
  B00111100,
  B00111100,
  B00111100,
  B00111100,
  B00000000,
  B00000000};

byte Sputnik[] = {
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00101000,
  B01000100,
  B10000010};

byte Apollo[] = {
  B01000010,
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B01100110,
  B10100101,
  B10000001};

byte Sword[] = {
  B00000011,
  B00000111,
  B00001110,
  B11011100,
  B01111000,
  B00110000,
  B01011000,
  B10000100};
  
byte Health[] = {
  B00000000,
  B01101100,
  B11111110,
  B11111110,
  B11111110,
  B01111100,
  B00111000,
  B00010000};

byte Wound[] = {
  B00000000,
  B01101100,
  B11110010,
  B11100010,
  B11100010,
  B01100100,
  B00111000,
  B00010000};

byte Death[] = {
  B00000000,
  B01101100,
  B10010010,
  B10000010,
  B10000010,
  B01000100,
  B00101000,
  B00010000};

void setup() {
  Serial.begin (9600);
  
  pinMode (buttonPin, INPUT);
  pinMode (NumMatrix, OUTPUT);
  for (int i=0; i< NumMatrix ; i++)
     {
        lc.shutdown(i,false);         
        lc.setIntensity(i,8);    
        lc.clearDisplay(i);      
     }
}

void loop() {
 // int espera=200;
 //int time=0;
   
    if(digitalRead(buttonPin)==HIGH&&millis()-time>espera)//Esta parte la deje como estaba en el programa anterior
    {                                                     //no enteindo bien la funcion millis (parecido a delay?)
      numerodepulsaciones++;
      Serial.print(numerodepulsaciones);
    }

    if(numerodepulsaciones == 10)
    numerodepulsaciones=0;

    switch(numerodepulsaciones) //muchos if, queremos que aparezcan las vocales
                                //cada vez que apretamos el boton
    {
     case 0:
      digitalWrite(NumMatrix,LOW); //off
      break;

      case 1:
      digitalWrite(NumMatrix,HIGH); //on
      lc.clearDisplay (NumMatrix);
      break;

      case 2:
      digitalWrite (NumMatrix,HIGH); //inicio de la historia
      Representar(Planet,5000);
      break;

      case 3:
      digitalWrite (NumMatrix,HIGH); 
      Representar(Sputnik,5000);
      break;

      case 4:
      digitalWrite (NumMatrix,HIGH);
      Representar(Apollo,5000);
      break;

      case 5:
      digitalWrite (NumMatrix,HIGH);
      Representar(Sword,5000);
      break;

      case 6:
      digitalWrite (NumMatrix,HIGH);
      Representar(Health,5000);
      break;

     //case 7:
     //digitalWrite (NumMatrix,HIGH);
     //Representar(Sword,5000);
     //break;

      case 7:
      digitalWrite (NumMatrix,HIGH);
      Representar(Wound,5000);
      break;

     //case 9:
     //digitalWrite (NumMatrix,HIGH);
     //Representar(Sword,5000);
     //break;

      case 8:
      digitalWrite (NumMatrix,HIGH);
      Representar (Death,5000);
      break;

      case 9:
      digitalWrite (NumMatrix,HIGH);
      Representar (Apollo,5000);
      break;
      
      case 10:
      time=millis();
    }

    delay (500);
 }


void Representar(byte *Datos,int retardo) //Funcion para la representacion de bytes de datos
{
for (int i = 0; i < 8; i++) {
    lc.setColumn(0,i,Datos[7-i]);
    }
}
