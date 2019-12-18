#include "Tlc5940.h"               // don't forget to download the Tlc5940 lib from arduino playground and place it in you lib folder ( http://tlc5940arduino.googlecode.com/files/Tlc5940_r014_2.zip )
#include "digitalIOPerformance.h"  // don't forget to download the digitalIOPerformance lib from arduino playground and place it in you lib folder ( https://github.com/projectgus/digitalIOPerformance )
#define LayerOne 14                // Gate of 1.MOSFET which connects to Layer "a" (anodes of all Strings in Layer "a")
#define LayerTwo 15                // Gate of 2.MOSFET which connects to Layer "b" (anodes of all StringS in Layer "b")
#define LayerThree 16              // Gate of 3.MOSFET which connects to Layer "c" (anodes of all Strings in Layer "c")
#define LayerFour 17               // Gate of 4.MOSFET which connects to Layer "d" (anodes of all Strings in Layer "d")
#define LayerFive 18               // Gate of 4.MOSFET which connects to Layer "d" (anodes of all Strings in Layer "d")
#define LayerSix 19               // Gate of 4.MOSFET which connects to Layer "d" (anodes of all Strings in Layer "d")
#include <avr/pgmspace.h>

const int col = 36;
const int row = 122;
 
int LayerDuration = 4000;   // ON time of each Layer in microseconds      
int layer = 0;              // starting with Layer 0 (Layer "a")
unsigned long oldMicros = 0;// starting counter to decide when if(micros()>=oldMicros)is true to change active layer, count++1, MatrixUpdate(); don't know what micros() is? Look here: http://arduino.cc/de/Reference/Micros#.UygzAIWmWd4
int count=0;                // starting counter which is included in if() statement to change the shown picture, not necessary when using a static picture
int stretch=25;             // set timer for the change of the shown picture, if animation should move really fast then low stretch value, if animation should move really slow than big stretch value
                 // set brightness for all Strings(4095=20mA, 0=0ma, 1000=4.88mA,....). If you want individually brightness for a String you have to change the value in tab "function"
int q;
int colorchange = 0;// used in functions for-loop
                // used in functions as counter

void setup()    
{
  pinMode(LayerOne, OUTPUT);                   // declare arduino nano pin A0(LayerOne) as OUTPUT
  pinMode(LayerTwo, OUTPUT);                   // declare arduino nano pin A1(LayerTwo) as OUTPUT
  pinMode(LayerThree, OUTPUT);                 // declare arduino nano pin A2(LayerThree) as OUTPUT
  pinMode(LayerFour, OUTPUT);                      // declare arduino nano pin A3(LayerFour) as OUTPUT
  pinMode(LayerFive, OUTPUT); 
  pinMode(LayerSix, OUTPUT); 
  Tlc.init();                                  // configures the arduino to use the tlc5940, be sure to connect the arduino correctly to the tlc 
  q=0;//all int start with value 0

void loop(){
  if(micros()>= oldMicros){                                           // waits until LayerDuration is reached and than goes through cycle
    oldMicros=micros()+LayerDuration;   
   if(count==0){wall(row);}                                  
   CubeUpdate(layer,4095,0,0);                                                 // sets the values for the tlc5940 Outputs and puts all MOSFET Gates HIGH (not active) except for one MOSFET Low (active) -->this layer is ON, also look under tab "function"  
   layer++;                                                           // layer counter +1, so MatrixUpdate(layer) will affect the next layer during the next if() cycle 
   count++;                                                           // count counter +1, to change the picture in next if() cycle
   if(layer==7){
    layer = 1;
   }                                                       // we only have 5 layers, so we start with layer 1 again if layer counter goes to 6                                          
   if(count==stretch){count=0;}                                    // we have 8 static picture for the moving sine wave, so if count counter would hit the 9.(not existing) pic, it goes back to count=0
   }
   }
