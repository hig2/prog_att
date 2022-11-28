const byte LED_PIN = 0;

bool singleBlinkFlag = false;

void initLed(){
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void runSingleBlink(){
  singleBlinkFlag = true;
}

void singleBlink(){
  static unsigned long t = 0;
  static bool flag = false;
  const int delayBlink = 500;
  
  if(singleBlinkFlag){
    if(!flag){
      t = millis();
      flag = true;
      digitalWrite(LED_PIN, HIGH);
    }else if((millis() - t) > delayBlink){
      digitalWrite(LED_PIN, LOW);
      flag = false;
      singleBlinkFlag = false;
    }
  }
}


void ledWatcher(){
  singleBlink();
}
