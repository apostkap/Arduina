#include <LiquidCrystal.h>
#include <Servo.h>

Servo myservo; 
int x=0;
int met=0;
int k=90;
int f1=0;
int f2=0;
int p=1;
  unsigned long T = 0;           
  unsigned long LN = 0;     
  unsigned long TT = 0;     
  unsigned long LL = 0;    
byte hurt1[8] = {
  0b00000,
  0b01110,
  0b10001, 
  0b10001,
  0b10000,
  0b10000,
  0b01000,
  0b01000,};
byte hurt2[8] = {
  0b00000,
  0b01110,
  0b10001,
  0b10001,
  0b00001,
  0b00001,
  0b00010,
  0b00010,};
byte hurt3[8] = {
  0b00100,
  0b00010,
  0b00010,
  0b00001,
  0b00000,
  0b00000,
  0b00000,
  0b00000,};
byte hurt4[8] = {
  0b00100,
  0b01000,
  0b01000,
  0b10000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,};

  byte pi[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b00000,};

  byte L[8] = {
  0b00100,
  0b01010,
  0b01010,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b00000,};
  byte S[8] = {
  0b11111,
  0b01000,
  0b00100,
  0b00010,
  0b00100,
  0b01000,
  0b11111,
  0b00000,};
  byte thita[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b11111,
  0b10001,
  0b10001,
  0b11111,
  0b00000,};

 
LiquidCrystal lcdA(10,13,7,6,5,4);
LiquidCrystal lcdB(12,11,7,6,5,4);

void setup()
  {
  myservo.attach(9); 
  myservo.write(90);
  pinMode(0, OUTPUT);
  pinMode (1, INPUT); 
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);  
  lcdA.begin(16,2); 
  lcdB.begin(16,2); 
  lcdA.createChar(4,hurt1);
  lcdA.createChar(5,hurt2);
  lcdA.createChar(6,hurt3);
  lcdA.createChar(7,hurt4);
  lcdA.createChar(3,pi);
  lcdA.createChar(2,L);
  lcdA.createChar(1,S);
  lcdA.createChar(0,thita);
  lcdB.createChar(4,hurt1);
  lcdB.createChar(5,hurt2);
  lcdB.createChar(6,hurt3);
  lcdB.createChar(7,hurt4);
  lcdB.createChar(3,pi);
  lcdB.createChar(2,L);
  lcdB.createChar(1,S);
  lcdB.createChar(0,thita);
  }
 
void loop()
      {  
       f1=0;
       f2=0;
       if (p==1)
            {
            digitalWrite(0, HIGH);                         
            delayMicroseconds(50);                    
            digitalWrite(0, LOW);    
            T = pulseIn(1, HIGH); 
            LN = (T*340)/2;                   
            LN=LN/10000;                        
            if(LN < 40 && k<170 && LN>1)
                  {
                  k=k+5;
                  f1=5;
                  myservo.write(k);
                  met=0;
                  delay(40);
                  } 
            }
       if (f1==0)
            {
            digitalWrite(2, HIGH);                         
            delayMicroseconds(50);                         
            digitalWrite(2, LOW);    
            TT = pulseIn(3, HIGH); 
            LL = (TT*340)/2;                   
            LL=LL/10000;                        
            if(LL < 40 && k>10 && LL>1)
                  {
                  k=k-5;
                  f2=5;
                  p=2;
                  myservo.write(k);
                  met=0;
                  delay(40);
                  } 
            else 
                  {p=1;}
            }
       if (f1==0 && f2==0)
            { met=met+1;
              if (met==5){ 
              k=90;
               myservo.write(k);
                 delay(80);
               met=0;
             }          
            if (x<94){x=x+1;} else {x=1;}
            if (x==1 || x==3 || x==5 || x==7){   
                  lcdA.clear();
                  lcdB.clear();
                  lcdA.setCursor(1,0);
                  lcdA.print("88888888888888");
                  lcdA.setCursor(1,1);
                  lcdA.print("88888888888888");
                  delay(900);
            }
            else if (x==2 || x==4 || x==6 || x==8){
                  lcdA.clear();
                  lcdB.clear();
                  lcdB.setCursor(1,0);
                  lcdB.print("88888888888888");
                  lcdB.setCursor(1,1);
                  lcdB.print("88888888888888");
                  delay(900);
            }
            else if (x==9){     
                  lcdA.clear();
                  lcdB.clear();                     
                  lcdA.setCursor(5,0);
                  lcdA.print("E");
                  lcdA.write(byte(3));
                  lcdA.print("A");
                  lcdA.write(byte(2));
                  lcdA.setCursor(1,1);
                  lcdA.print("E");
                  lcdA.write(byte(2));
                  lcdA.print("E");
                  lcdA.print("Y");
                  lcdA.write(byte(0));
                  lcdA.print("E");
                  lcdA.print("P");
                  lcdA.print("O");
                  lcdA.print("Y");
                  lcdA.write(byte(3));
                  lcdA.print("O");
                  lcdA.write(byte(2));
                  lcdA.print("H");
                  lcdA.write(byte(1));
                  lcdB.setCursor(5,0);
                  lcdB.print("E");
                  lcdB.write(byte(3));
                  lcdB.print("A");
                  lcdB.write(byte(2));
                  lcdB.setCursor(1,1);
                  lcdB.print("E");
                  lcdB.write(byte(2));
                  lcdB.print("E");
                  lcdB.print("Y");
                  lcdB.write(byte(0));
                  lcdB.print("E");
                  lcdB.print("P");
                  lcdB.print("O");
                  lcdB.print("Y");
                  lcdB.write(byte(3));
                  lcdB.print("O");
                  lcdB.write(byte(2));
                  lcdB.print("H");
                  lcdB.write(byte(1));
                  delay(1000);  
            }
            else if ((x==10) || (x==11) || (x==12)|| (x==13)){
                  delay(1000);
            }
            else if ((x==14) || (x==28) || (x==42)|| (x==56)){
                  lcdA.clear();
                  lcdA.setCursor(2,0);
                  lcdA.print("HELLO");
                  lcdB.clear();
                  lcdB.setCursor(9,0);
                  lcdB.print("HELLO");
                  delay(500);
            }
            else if ((x>14 && x<21) || (x>28 && x<35) || (x>42 && x<49)|| (x>56 && x<63)){
                  lcdA.scrollDisplayRight();
                  lcdB.scrollDisplayLeft();
                  delay(500);
            }
            else if ((x==21 ) || (x==35) || (x==49)|| (x==63)){
                  lcdA.clear();
                  lcdA.setCursor(8,1);
                  lcdA.print("HELLO"); 
                  lcdB.clear();
                  lcdB.setCursor(3,1);
                  lcdB.print("HELLO"); 
                  delay(500);       
            }
                  else if ((x>21 && x<28) || (x>35 && x<42) || (x>49 && x<56)|| (x>64 && x<70)){
                  lcdA.scrollDisplayLeft();
                  lcdB.scrollDisplayRight();
                  delay(500);       
            }
            else if (x==70){
                  lcdA.clear();              
                  lcdA.setCursor(4,0);
                  lcdA.print("My name is");
                  lcdA.setCursor(6,1);
                  lcdA.print("Arduina");
                  lcdB.clear();
                  lcdB.setCursor(4,0);
                  lcdB.print("My name is");
                  lcdB.setCursor(6,1);
                  lcdB.print("Arduina");
                  delay(1000);
            }
            else if (x>70 && x<77){
                  delay(1000);
            }     
            else if (x==77 || x==81 || x==85 ){     
                  lcdA.clear();
                  lcdA.setCursor(7,0);
                  lcdA.print("* *");
                  lcdA.setCursor(7,1);
                  lcdA.print(" -");
                  lcdB.clear();
                  lcdB.setCursor(7,0);
                  lcdB.print("* *");
                  lcdB.setCursor(7,1);
                  lcdB.print(" -");
                  delay(500);
            }
            else if (x==78 || x==82 || x==86 ){
                  lcdA.setCursor(7,1);
                  lcdA.print(" o");
                  lcdB.setCursor(7,1);
                  lcdB.print(" o");
                  delay(500);
            }
            else if (x==79 || x==83 || x==87 ){
                  lcdA.setCursor(7,1);
                  lcdA.print(" v");
                  lcdB.setCursor(7,1);
                  lcdB.print(" v");
                  delay(500);
            }
            else if (x==80 || x==84 || x==88){ 
                  lcdA.setCursor(7,1);
                  lcdA.print(" ^");
                  lcdB.setCursor(7,1);
                  lcdB.print(" ^");
                  delay(500);
            }     
            else if (x==89 || x==91 || x==93){      
                  lcdA.clear();
                  lcdA.setCursor(2,0);
                  lcdA.write(byte(4));
                  lcdA.write(byte(5));
                  lcdA.setCursor(7,0);
                  lcdA.write(byte(4));
                  lcdA.write(byte(5));
                  lcdA.setCursor(12,0);
                  lcdA.write(byte(4));
                  lcdA.write(byte(5));
                  lcdB.clear();
                  lcdB.setCursor(2,0);
                  lcdB.write(byte(4));
                  lcdB.write(byte(5));
                  lcdB.setCursor(7,0);
                  lcdB.write(byte(4));
                  lcdB.write(byte(5));
                  lcdB.setCursor(12,0);
                  lcdB.write(byte(4));
                  lcdB.write(byte(5));
                  lcdA.setCursor(2,1);
                  lcdA.write(byte(6));
                  lcdA.write(byte(7));
                  lcdA.setCursor(7,1);
                  lcdA.write(byte(6));
                  lcdA.write(byte(7));
                  lcdA.setCursor(12,1);
                  lcdA.write(byte(6));
                  lcdA.write(byte(7));
                  lcdB.setCursor(2,1);
                  lcdB.write(byte(6));
                  lcdB.write(byte(7));
                  lcdB.setCursor(7,1);
                  lcdB.write(byte(6));
                  lcdB.write(byte(7));
                  lcdB.setCursor(12,1);
                  lcdB.write(byte(6));
                  lcdB.write(byte(7));
                  delay(1000);
            }
            else if (x==90 || x==92 || x==94 ){
                  lcdA.clear();
                  lcdB.clear();
                  delay(500);
            }
         }
      }  

   

    
