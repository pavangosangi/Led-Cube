#include "digitalIOPerformance.h"

void CubeUpdate(int layerno, int rbright, int gbright, int bbright){ 

  int count = 0;
  int GREENLEDs[216];
  int REDLEDs[216];
  int BLUELEDs[216];
  for(int i=0;i<216;i++){
    GREENLEDs[i]=0;
    REDLEDs[i]=0;
    BLUELEDs[i]=0;
  }
  for(int i=35;i>=0;i--) {
    for (int j = 0; j < 6 ; j++) {
      if(bitRead(pgm_read_byte(&(hello[q][i])),j) == 1){
        if(colorchange==0) {
          REDLEDs[count]=rbright;
        } else if (colorchange == 1){
          GREENLEDs[count]=rbright;
        } else {
          BLUELEDs[count]=rbright;
        }
      } 
      count++;
    }
  }
  if(layerno == 1){                 
    for(int i=0;i<36;i++) {
      Tlc.set(i, REDLEDs[i]);    
    }
    for(int i=0;i<36;i++) {
      Tlc.set(48+i, GREENLEDs[i]);
    }
    for(int i=0;i<36;i++) {
      Tlc.set(96+i, BLUELEDs[i]);
    }
       
    digitalWrite(LayerOne, HIGH);   // sets LayerOne (pin A0) High (not active)--> Layer one OFF
    digitalWrite(LayerTwo, HIGH);   // sets LayerTwo (pin A1) High (not active)--> Layer two OFF
    digitalWrite(LayerThree, HIGH); // sets LayerThree (pin A2) High (not active)--> Layer three OFF
    digitalWrite(LayerFour, HIGH);  // sets LayerFour (pin A3) High (not active)--> Layer four OFF
    digitalWrite(LayerFive, HIGH);
    digitalWrite(LayerSix, HIGH);
    Tlc.update();                   // writes the values for the LEDs brightness to the tlc
    delay(1);                                // give the tlc some time to let the value settle
    digitalWrite(LayerOne, LOW);    // sets LayerOne (pin A0) Low (active)--> Layer one ON
    
  }
  
    if(layerno == 2){
        for(int i=0;i<36;i++) {
          Tlc.set(i, REDLEDs[i+36]);    
        }
        for(int i=0;i<36;i++) {
          Tlc.set(48+i, GREENLEDs[i+36]);
        }
        for(int i=0;i<36;i++) {
          Tlc.set(96+i, BLUELEDs[i+36]);
        }
    digitalWrite(LayerOne, HIGH);  // same as if(layerno==1)
    digitalWrite(LayerTwo, HIGH);
    digitalWrite(LayerThree, HIGH);
    digitalWrite(LayerFour, HIGH);
    digitalWrite(LayerFive, HIGH);
    digitalWrite(LayerSix, HIGH);
    Tlc.update();
    delay(1);
    digitalWrite(LayerTwo, LOW);  // sets LayerTwo (pin A1) Low (active)--> Layer two ON
    
  }
  
  
  if(layerno == 3){
         for(int i=0;i<36;i++) {
          Tlc.set(i, REDLEDs[i+72]);    
        }
        for(int i=0;i<36;i++) {
          Tlc.set(48+i, GREENLEDs[i+72]);
        }
        for(int i=0;i<36;i++) {
          Tlc.set(96+i, BLUELEDs[i+72]);
        }
    
    
    digitalWrite(LayerOne, HIGH);   // same as if(layerno==1)
    digitalWrite(LayerTwo, HIGH);
    digitalWrite(LayerThree, HIGH);
    digitalWrite(LayerFour, HIGH);
    digitalWrite(LayerFive, HIGH);
    digitalWrite(LayerSix, HIGH);
    Tlc.update();
    delay(1);
    digitalWrite(LayerThree, LOW);   // sets LayerThree (pin A2) Low (active)--> Layer three ON 
    
  }
  
  
  if(layerno == 4){
                for(int i=0;i<36;i++) {
          Tlc.set(i, REDLEDs[i+108]);    
        }
        for(int i=0;i<36;i++) {
          Tlc.set(48+i, GREENLEDs[i+108]);
        }
        for(int i=0;i<36;i++) {
          Tlc.set(96+i, BLUELEDs[i+108]);
        }
    digitalWrite(LayerOne, HIGH);  // same as if(layerno==1)
    digitalWrite(LayerTwo, HIGH);
    digitalWrite(LayerThree, HIGH);
    digitalWrite(LayerFour, HIGH);
    digitalWrite(LayerFive, HIGH);
    digitalWrite(LayerSix, HIGH);
    Tlc.update();
    delay(1);
    digitalWrite(LayerFour, LOW);  // sets LayerFour (pin A3) Low (active)--> Layer four ON
    
  }
  
  if(layerno == 5){
               for(int i=0;i<36;i++) {
          Tlc.set(i, REDLEDs[i+144]);    
        }
        for(int i=0;i<36;i++) {
          Tlc.set(48+i, GREENLEDs[i+144]);
        }
        for(int i=0;i<36;i++) {
          Tlc.set(96+i, BLUELEDs[i+144]);
        }
    digitalWrite(LayerOne, HIGH);  // same as if(layerno==1)
    digitalWrite(LayerTwo, HIGH);
    digitalWrite(LayerThree, HIGH);
    digitalWrite(LayerFour, HIGH);
    digitalWrite(LayerFive, HIGH);
    digitalWrite(LayerSix, HIGH);
    Tlc.update();
    delay(1);
    digitalWrite(LayerFive, LOW);  // sets LayerFour (pin A3) Low (active)--> Layer four ON
    
  }
  
  if(layerno == 6){
                for(int i=0;i<36;i++) {
          Tlc.set(i, REDLEDs[i+180]);    
        }
        for(int i=0;i<36;i++) {
          Tlc.set(48+i, GREENLEDs[i+180]);
        }
        for(int i=0;i<36;i++) {
          Tlc.set(96+i, BLUELEDs[i+180]);
        }
    digitalWrite(LayerOne, HIGH);  // same as if(layerno==1)
    digitalWrite(LayerTwo, HIGH);
    digitalWrite(LayerThree, HIGH);
    digitalWrite(LayerFour, HIGH);
    digitalWrite(LayerFive, HIGH);
    digitalWrite(LayerSix, HIGH);
    Tlc.update();
    delay(1);
    digitalWrite(LayerSix, LOW);  // sets LayerFour (pin A3) Low (active)--> Layer four ON
    
  }}
    
  void wall(int row){
      if(q==row-1){
        q=0;
        if(colorchange == 0) {
          colorchange = 1;
        } else if(colorchange == 1){
          colorchange = 2;
        } else {
          colorchange = 0;
        }
      } else {
        q=q+1;
      }
 }
    
   
