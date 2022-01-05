//  Title: 8 x 5 Multi-Color LED Matrix driver, Arduino, text scroller (no other chips required).
//  Author: T. Sheflin
//  Date: 12/23/2021
//  Code idea from 10*8 LED Matrix with 4017 IC, By Vadim S. On 25.06.2009
//  Code and circuit posted to github.com/tpsheflin/8x5-Multi-Color-LED-Matrix-Driver
//  LED Matrix: CSM-58261EG-21, (Data Sheet for CSM-58261EG used)
//  HW: Arduino-UNO, 10 390 Ohm resistors and 36 jumper wires
//  

int color=1;

#define spc   {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000}
#define A     {B01110,B10001,B10001,B11111,B10001,B10001,B10001,B00000}
#define B     {B11110,B10001,B10001,B11110,B10001,B10001,B11110,B00000}
#define C     {B01110,B10001,B10000,B10000,B10000,B10001,B01110,B00000}
#define D     {B11110,B10001,B10001,B10001,B10001,B10001,B11110,B00000}
#define E     {B11111,B10000,B10000,B11110,B10000,B10000,B11111,B00000}
#define _F    {B11111,B10000,B10000,B11110,B10000,B10000,B10000,B00000}
#define G     {B01110,B10001,B10000,B10000,B10011,B10001,B01110,B00000}
#define H     {B10001,B10001,B10001,B11111,B10001,B10001,B10001,B00000}
#define I     {B01110,B00100,B00100,B00100,B00100,B00100,B01110,B00000}
#define J     {B11111,B00100,B00100,B00100,B00100,B10100,B01000,B00000}
#define K     {B10001,B10010,B10100,B11000,B10100,B10010,B10001,B00000}
#define L     {B10000,B10000,B10000,B10000,B10000,B10000,B11110,B00000}
#define M     {B10001,B11011,B10101,B10001,B10001,B10001,B10001,B00000}
#define N     {B10001,B10001,B11001,B10101,B10011,B10001,B10001,B00000}
#define O     {B01110,B10001,B10001,B10001,B10001,B10001,B01110,B00000}
#define P     {B11110,B10001,B10001,B11110,B10000,B10000,B10000,B00000}
#define Q     {B01110,B10001,B10001,B10001,B10001,B10010,B01101,B00000}
#define R     {B11110,B10001,B10001,B11110,B10100,B10010,B10001,B00000}
#define S     {B01111,B10000,B10000,B01110,B00001,B00001,B11110,B00000}
#define T     {B11111,B00100,B00100,B00100,B00100,B00100,B00100,B00000}
#define U     {B10001,B10001,B10001,B10001,B10001,B10001,B01110,B00000}
#define V     {B10001,B10001,B10001,B10001,B10001,B01010,B00100,B00000}
#define W     {B10001,B10001,B10001,B10001,B10101,B11011,B10001,B00000}
#define X     {B10001,B01010,B01010,B00100,B01010,B01010,B10001,B00000}
#define Y     {B10001,B10001,B01010,B00100,B00100,B00100,B00100,B00000}
#define Z     {B11111,B00001,B00010,B00100,B01000,B10000,B11111,B00000}
#define _0 {B01110,B10001,B10001,B10101,B10001,B10001,B01110,B00000}
#define _1 {B00100,B01100,B00100,B00100,B00100,B00100,B01110,B00000}
#define _2 {B01110,B10001,B00001,B00110,B01000,B10000,B11111,B00000}
#define _3 {B01110,B10001,B00001,B01110,B00001,B10001,B01110,B00000}
#define _4 {B10000,B10000,B10010,B11111,B00010,B00010,B00010,B00000}
#define _5 {B11111,B10000,B10000,B01110,B00001,B10001,B01110,B00000}
#define _6 {B01110,B10000,B10000,B11110,B10001,B10001,B01110,B00000}
#define _7 {B11111,B00001,B00010,B00100,B01000,B01000,B01000,B00000}
#define _8 {B01110,B10001,B10001,B01110,B10001,B10001,B01110,B00000}
#define _9 {B01110,B10001,B10001,B01111,B00001,B10001,B01110,B00000}
#define dsh{B00000,B00000,B00000,B01110,B00000,B00000,B00000,B00000}
#define bng{B00100,B00100,B00100,B00100,B00100,B00000,B00100,B00000}

//const int numChars = 22;  //number of characters to display + 1
//byte chars[numChars][8]={spc,M,E,R,R,Y,spc,C,H,R,I,S,T,M,A,S,spc,_2,_0,_2,_1};
//const int numChars = 21;
//byte chars[numChars][8]={spc,H,A,P,P,Y,spc,N,E,W,spc,Y,E,A,R,spc,_2,_0,_2,_2};
//const int numChars = 40;
//byte chars[numChars][8]={spc,A,B,C,D,E,_F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,spc,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,spc};
const int numChars = 47;
byte chars[numChars][8]={spc,M,U,L,T,I,dsh,C,O,L,O,R,spc,L,E,D,spc,M,A,T,R,I,X,spc,D,R,I,V,E,R,spc,_F,O,R,spc,A,R,D,U,I,N,O,bng,bng,bng,spc};


// 1-dimensional array of row pin numbers:
int ROW[8] = {2,3,4,5,6,7,8,9};  
// 1-dimensional array of green column pin numbers:
int COL_G[5] = {14,15,16,17,18};  
// 1-dimensional array of red column pin numbers:
int COL_R[5] = {1,10,11,12,13};


void setup()
{
   // iterate over the pins:
  for(int i = 0; i<8; i++){    // initialize pins as output: 
    pinMode(ROW[i],OUTPUT);  
  }  
  
  for(int i = 0; i<5; i++){    // initialize pins as output:
    pinMode(COL_G[i],OUTPUT);
    pinMode(COL_R[i],OUTPUT); 
  }
  Clear();
}

void loop()
{
 show(15);    //scroll speed
}

void show(int loops)
{ 
  for(int x=0;x<numChars-1;x++) //loop over chars
  { 
   for (int z=0;z<5;z++) //scroll 1 bit at a time
   {  
    for(int t=0;t<loops;t++) //delay we get with loops
    {
     for(int y=0;y<8;y++) //loop over the array of bytes in #define
     {
       byte temp = chars[x][y]; 
       byte temp_2=chars[x+1][y];							                //code remnants from port ctrl and 4017 chip
       byte port_val = (temp<<z)+(temp_2>>6-z);              	//PORTD = (t...
       wrt_val(port_val, x, color);
       //delayMicroseconds(800);  								             //time every row is one
       //Clear();                                            	//PORTD=B00000000; fixes ghosting   
       digitalWrite(ROW[y],HIGH);                              //digitalWrite(clock,HIGH);
       //delay(2); //longer delay if needed
       delayMicroseconds(800);                               	//delayMicroseconds(5);
       digitalWrite(ROW[y],LOW);                               //digitalWrite(clock,LOW);
     }
    }
   }
  }
  color++;  //change color of displayed chars
  if(color==4){
    color=1;
  }
}


void wrt_val(byte port_val, int x, int color)
{
  for(int c = 4; c >= 0; c--) {  
    bool bit_val = ((port_val>>(c)) & HIGH);
    //write the col bits to active row
    if (color==3){
      digitalWrite(COL_R[4-c],!bit_val);                      //COL_R[4-c] letters scrolls left, COL_R[c] letters scroll right and reversed
      digitalWrite(COL_G[4-c],!bit_val);
    }
    else if (color==2) {
      digitalWrite(COL_R[4-c],!bit_val);
    }
    else {
      digitalWrite(COL_G[4-c],!bit_val);                      //COL_R[4-c] letters scrolls left, COL_R[c] letters scroll right and reversed
    }
  }
}


void Clear()                         	//clear all outputs
{  
  for(int i = 0;i<8;i++) {  
    digitalWrite(ROW[i],LOW);  		  //Anode side of LEDs
  }  
  for(int i = 0;i<5;i++) {  
    digitalWrite(COL_G[i],HIGH);		//Cathode side of Green LEDs
    digitalWrite(COL_R[i],HIGH);		//Cathode side of Red LED
  }
}  


void test()							 	//used for deguging
{
  digitalWrite(ROW[3],1);
  digitalWrite(COL_R[2],0);
  delay(50);
  Clear();
}
