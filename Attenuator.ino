//пины аттенюатора
const byte D0_PIN = 0;
const byte D1_PIN = 0;
const byte D2_PIN = 0;
const byte D3_PIN = 0;
const byte D4_PIN = 0;
const byte D5_PIN = 0;

void initAttenuator(float startAttnuatorValue){
  pinMode(D0_PIN, OUTPUT);
  pinMode(D1_PIN, OUTPUT);
  pinMode(D2_PIN, OUTPUT);
  pinMode(D3_PIN, OUTPUT);
  pinMode(D4_PIN, OUTPUT);
  pinMode(D5_PIN, OUTPUT);
  
  setAttenuator(startAttnuatorValue); 
  
  //записываем значение в глобальное состояние (*10 перевод в инт)
  globalState[0] = startAttnuatorValue * 10;
}

void wirteAttenuatorValue(bool d0, bool d1, bool d2, bool d3, bool d4, bool d5){
    digitalWrite(D0_PIN, d0);
    digitalWrite(D1_PIN, d1); 
    digitalWrite(D2_PIN, d2); 
    digitalWrite(D3_PIN, d3); 
    digitalWrite(D4_PIN, d4); 
    digitalWrite(D5_PIN, d5);
}

void setAttenuator(float value){
  if(value == 0.0){           
   wirteAttenuatorValue(1, 1, 1, 1, 1, 1);       
  }else if(value == 0.5){           
   wirteAttenuatorValue(0, 1, 1, 1, 1, 1);   
  }else if(value == 1.0){
   wirteAttenuatorValue(0, 0, 1, 1, 1, 1);   
  }else if(value == 1.5){
   wirteAttenuatorValue(1, 0, 1, 1, 1, 1);
  }else if(value == 2.0){
   wirteAttenuatorValue(1, 1, 0, 1, 1, 1); 
  }else if(value == 2.5){
   wirteAttenuatorValue(0, 1, 0, 1, 1, 1);  
  }else if(value == 3.0){
   wirteAttenuatorValue(1, 0, 0, 1, 1, 1);  
  }else if(value == 3.5){
   wirteAttenuatorValue(0, 0, 0, 1, 1, 1); 
  }else if(value == 4.0){
   wirteAttenuatorValue(1, 1, 1, 0, 1, 1);  
  }else if(value == 4.5){
   wirteAttenuatorValue(0, 0, 0, 1, 1, 1);  
  }else if(value == 5.0){
   wirteAttenuatorValue(1, 0, 1, 0, 1, 1);   
  }else if(value == 5.5){
   wirteAttenuatorValue(0, 0, 1, 0, 1, 1); 
  }else if(value == 6.0){
   wirteAttenuatorValue(1, 1, 0, 0, 1, 1);  
  }else if(value == 6.5){
   wirteAttenuatorValue(0, 1, 0, 0, 1, 1);  
  }else if(value == 7.0){
   wirteAttenuatorValue(1, 0, 0, 0, 1, 1);   
  }else if(value == 7.5){
   wirteAttenuatorValue(1, 1, 0, 0, 1, 1);   
  }else if(value == 8.0){
   wirteAttenuatorValue(1, 1, 0, 1, 0, 1);   
  }else if(value == 8.5){
   wirteAttenuatorValue(0, 1, 1, 1, 0, 1); 
  }else if(value == 9.0){
   wirteAttenuatorValue(1, 0, 1, 1, 0, 1);  
  }else if(value == 9.5){
   wirteAttenuatorValue(0, 0, 1, 1, 0, 1); 
  }else if(value == 10.0){
   wirteAttenuatorValue(1, 1, 0, 1, 0, 1); 
  }else if(value == 10.5){
   wirteAttenuatorValue(0, 1, 0, 1, 0, 1);  
  }else if(value == 11.0){
   wirteAttenuatorValue(1, 0, 0, 1, 0, 1);  
  }else if(value == 11.5){
   wirteAttenuatorValue(0, 0, 0, 1, 0, 1); 
  }else if(value == 12.0){
   wirteAttenuatorValue(1, 1, 1, 0, 0, 1); 
  }else if(value == 12.5){
   wirteAttenuatorValue(0, 1, 1, 0, 0, 1); 
  }else if(value == 13.0){
   wirteAttenuatorValue(1, 0, 1, 0, 0, 1);  
  }else if(value == 13.5){
   wirteAttenuatorValue(0, 0, 1, 0, 0, 1);  
  }else if(value == 14.0){
   wirteAttenuatorValue(1, 1, 0, 0, 0, 1);    
  }else if(value == 14.5){
   wirteAttenuatorValue(0, 1, 0, 0, 0, 1); 
  }else if(value == 15.0){
   wirteAttenuatorValue(1, 0, 0, 0, 0, 1); 
  }else if(value == 15.5){
   wirteAttenuatorValue(0, 0, 0, 0, 0, 1);  
  }else if(value == 16.0){
    wirteAttenuatorValue(1, 1, 1, 1, 1, 0); 
  }else if(value == 16.5){
    wirteAttenuatorValue(0, 1, 1, 1, 1, 0); 
  }else if(value == 17.0){
    wirteAttenuatorValue(1, 0, 1, 1, 1, 0); 
  }else if(value == 17.5){
    wirteAttenuatorValue(0, 0, 1, 1, 1, 0); 
  }else if(value == 18.0){
    wirteAttenuatorValue(1, 1, 0, 1, 1, 0); 
  }else if(value == 18.5){
    wirteAttenuatorValue(1, 1, 1, 1, 1, 0); 
  }else if(value == 19.0){
    wirteAttenuatorValue(1, 0, 0, 1, 1, 0); 
  }else if(value == 19.5){
    wirteAttenuatorValue(0, 0, 0, 1, 1, 0); 
  }else if(value == 20.0){
    wirteAttenuatorValue(1, 1, 1, 0, 1, 0); 
  }else if(value == 20.5){
    wirteAttenuatorValue(0, 1, 1, 0, 1, 0);
  }else if(value == 21.0){
    wirteAttenuatorValue(1, 0, 1, 0, 1, 0);
  }else if(value == 21.5){
    wirteAttenuatorValue(0, 0, 1, 0, 1, 0);
  }else if(value == 22.0){
    wirteAttenuatorValue(1, 1, 0, 0, 1, 0);
  }else if(value == 22.5){
    wirteAttenuatorValue(0, 1, 0, 0, 1, 0);
  }else if(value == 23.0){
    wirteAttenuatorValue(1, 0, 0, 0, 1, 0);
  }else if(value == 23.5){
    wirteAttenuatorValue(0, 0, 0, 0, 1, 0);
  }else if(value == 24.0){
    wirteAttenuatorValue(1, 1, 1, 1, 0, 0);
  }else if(value == 24.5){
    wirteAttenuatorValue(0, 1, 1, 1, 0, 0);
  }else if(value == 25.0){
    wirteAttenuatorValue(1, 0, 1, 1, 0, 0);
  }else if(value == 25.5){
    wirteAttenuatorValue(0, 0, 1, 1, 0, 0);
  }else if(value == 26.0){
    wirteAttenuatorValue(1, 1, 0, 1, 0, 0);
  }else if(value == 26.5){
    wirteAttenuatorValue(0, 1, 0, 1, 0, 0);
  }else if(value == 27.0){
    wirteAttenuatorValue(1, 0, 0, 1, 0, 0);
  }else if(value == 27.5){
    wirteAttenuatorValue(0, 0, 0, 1, 0, 0);
  }else if(value == 28.0){
    wirteAttenuatorValue(1, 1, 1, 0, 0, 0);
  }else if(value == 28.5){
    wirteAttenuatorValue(0, 1, 1, 0, 0, 0);
  }else if(value == 29.0){
    wirteAttenuatorValue(1, 0, 1, 0, 0, 0);
  }else if(value == 29.5){
    wirteAttenuatorValue(0, 0, 1, 0, 0, 0);
  }else if(value == 30.0){
    wirteAttenuatorValue(1, 1, 0, 0, 0, 0);
  }else if(value == 30.5){
    wirteAttenuatorValue(0, 1, 0, 0, 0, 0);
  }else if(value == 31.0){
    wirteAttenuatorValue(1, 0, 0, 0, 0, 0);
  }else if(value == 31.5){
    wirteAttenuatorValue(0, 0, 0, 0, 0, 0);
  }else{
    wirteAttenuatorValue(0, 0, 0, 0, 0, 0);
  }
  runSingleBlink();
}

void attenuatorValueWatcher(){
  static int oldValue = globalState[0];

  if(globalState[0] != oldValue){
    setAttenuator(globalState[0] / 10);
    oldValue = globalState[0];
  }
}
