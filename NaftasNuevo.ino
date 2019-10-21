/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
 */
// Pin 2-8 is connected to the 7 segments of the display.
 #define TPO_CAMBIO_PRECIO 100000

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;
int DP= 22; //ES EL PUNTO

int D5 = 29;
int D6 = 30;
int D7 = 31;
int D8 = 32;


int d[8]={4,3,2,1};
int i=0;
// the setup routine runs once when you press reset:
void setup() {    
  Serial.begin(9600);            
  // initialize the digital pins as outputs.
//Nafta Super
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);
  pinMode(DP, OUTPUT);    
  pinMode(D5, OUTPUT);  
  pinMode(D6, OUTPUT);  
  pinMode(D7, OUTPUT);  
  pinMode(D8, OUTPUT);
  revalorar();
}

void ActualizaDisplay(void)
  {
  static unsigned long tiempo=0;
  static unsigned char etapa=0;
  switch (etapa)
  {
  case 0:
        numeroI(d[i]);  //FIJA EL DATO
        Segmento(i+1);  //ACTIVA EL DIGITO
        tiempo=millis();
        etapa=1;
        break;
  case 1: 
      if ((millis()-tiempo)<1) break;
      Segmento(0);  //DESACTIVA TODOS LOS DIGITOS
      i++;
      if(i>7) i=0;
      etapa=0;
  default:
    break;  
  }
  
  }
void ActualizaPrecio(void)
  {
   static unsigned long  tiempo=0;
  if ((millis()-tiempo)>TPO_CAMBIO_PRECIO){
    revalorar();
    tiempo=millis();
    }
  }
  
// the loop routine runs over and over again forever:
void loop() {
    ActualizaDisplay();
    ActualizaPrecio();
}

void revalorar(){
for (int j = 0; j < 8; j++){
        if((j!=0)&&(j!=4)){ 
        d[j]=random(0,9);
        }
    }
d[0]=3;
d[4]=4;
}

void numeroI(int n){
    switch (n)
    {
    case 1:digitalWrite(pinB, HIGH);   
          digitalWrite(pinC, HIGH);   
          digitalWrite(pinG, LOW);   
          digitalWrite(pinF, LOW);   
          digitalWrite(pinA, LOW);   
          digitalWrite(pinD, LOW);   
          digitalWrite(pinE, LOW); 
          break;
    case 2:digitalWrite(pinB, HIGH);   
          digitalWrite(pinC, LOW);   
          digitalWrite(pinG, HIGH);   
          digitalWrite(pinF, LOW);   
          digitalWrite(pinA, HIGH);   
          digitalWrite(pinD, HIGH);   
          digitalWrite(pinE, HIGH); 
          break;
    case 3:digitalWrite(pinB, HIGH);   
          digitalWrite(pinC, HIGH);   
          digitalWrite(pinG, HIGH);   
          digitalWrite(pinF, LOW);   
          digitalWrite(pinA, HIGH);   
          digitalWrite(pinD, HIGH);   
          digitalWrite(pinE, LOW); 
          break;
    case 4:digitalWrite(pinB, HIGH);   
          digitalWrite(pinC, HIGH);   
          digitalWrite(pinG, HIGH);   
          digitalWrite(pinF, HIGH);   
          digitalWrite(pinA, LOW);   
          digitalWrite(pinD, LOW);   
          digitalWrite(pinE, LOW); 
          break;
    case 5:digitalWrite(pinB, LOW);   
          digitalWrite(pinC, HIGH);   
          digitalWrite(pinG, HIGH);   
          digitalWrite(pinF, HIGH);   
          digitalWrite(pinA, HIGH);   
          digitalWrite(pinD, HIGH);   
          digitalWrite(pinE, LOW); 
          break;
    case 6:digitalWrite(pinB, LOW);   
          digitalWrite(pinC, HIGH);   
          digitalWrite(pinG, HIGH);   
          digitalWrite(pinF, HIGH);   
          digitalWrite(pinA, HIGH);   
          digitalWrite(pinD, HIGH);   
          digitalWrite(pinE, HIGH);  
        break;
    case 7:digitalWrite(pinB, HIGH);   
          digitalWrite(pinC, HIGH);   
          digitalWrite(pinG, LOW);   
          digitalWrite(pinF, LOW);   
          digitalWrite(pinA, HIGH);   
          digitalWrite(pinD, LOW);   
          digitalWrite(pinE, LOW); 
          break;
    case 8:digitalWrite(pinB, HIGH);   
          digitalWrite(pinC, HIGH);   
          digitalWrite(pinG, HIGH);   
          digitalWrite(pinF, HIGH);   
          digitalWrite(pinA, HIGH);   
          digitalWrite(pinD, HIGH);   
          digitalWrite(pinE, HIGH); 
          break;
    case 9:digitalWrite(pinB, HIGH);   
          digitalWrite(pinC, HIGH);   
          digitalWrite(pinG, HIGH);   
          digitalWrite(pinF, HIGH);   
          digitalWrite(pinA, HIGH);   
          digitalWrite(pinD, LOW);   
          digitalWrite(pinE, LOW); 
          break;
    case 0:digitalWrite(pinB, HIGH);   
          digitalWrite(pinC, HIGH);   
          digitalWrite(pinG, LOW);   
          digitalWrite(pinF, HIGH);   
          digitalWrite(pinA, HIGH);   
          digitalWrite(pinD, HIGH);   
          digitalWrite(pinE, HIGH); 
          break;

    default:
      break;
    }
}

void Segmento(int valor){
  switch(valor)//NAFTA SUPER 39.68
  {
  case 0: 
        digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH); 
        digitalWrite(D5, HIGH);
        digitalWrite(D6, HIGH);
        digitalWrite(D7, HIGH);
        digitalWrite(D8, HIGH);
        digitalWrite(DP, LOW); 
        break; 
  case 1:
        digitalWrite(D1, LOW);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH); 
        digitalWrite(D5, HIGH);
        digitalWrite(D6, HIGH);
        digitalWrite(D7, HIGH);
        digitalWrite(D8, HIGH);
        digitalWrite(DP, LOW);  
        break;
  
  case 2:digitalWrite(D1, HIGH);
        digitalWrite(D2, LOW);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH); 
        digitalWrite(DP, HIGH);
        digitalWrite(D5, HIGH);
        digitalWrite(D6, HIGH);
        digitalWrite(D7, HIGH);
        digitalWrite(D8, HIGH);   
        break; 
  
  case 3:digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, LOW);
        digitalWrite(D4, HIGH); 
        digitalWrite(DP, LOW); 
        digitalWrite(D5, HIGH);
        digitalWrite(D6, HIGH);
        digitalWrite(D7, HIGH);
        digitalWrite(D8, HIGH);    
        break;              

  case 4:digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, LOW); 
        digitalWrite(DP, LOW);
        digitalWrite(D5, HIGH);
        digitalWrite(D6, HIGH);
        digitalWrite(D7, HIGH);
        digitalWrite(D8, HIGH);    
        break;

 case 5:digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH); 
        digitalWrite(D5, LOW);
        digitalWrite(D6, HIGH);
        digitalWrite(D7, HIGH);
        digitalWrite(D8, HIGH);
        digitalWrite(DP, LOW);  
        break;

 case 6:digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH); 
        digitalWrite(D5, HIGH);
        digitalWrite(D6, LOW);
        digitalWrite(D7, HIGH);
        digitalWrite(D8, HIGH);
        digitalWrite(DP, HIGH);  
        break;

 case 7:digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH); 
        digitalWrite(D5, HIGH);
        digitalWrite(D6, HIGH);
        digitalWrite(D7, LOW);
        digitalWrite(D8, HIGH);
        digitalWrite(DP, LOW);  
        break;

 case 8:digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH); 
        digitalWrite(D5, HIGH);
        digitalWrite(D6, HIGH);
        digitalWrite(D7, HIGH);
        digitalWrite(D8, LOW);
        digitalWrite(DP, LOW);  
        break;
  }
  }
