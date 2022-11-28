
void initSerialPort(){
  uart.begin(57600);
}

void serialTimer(int timer){
  static unsigned long t = 0;
  if(millis() - t > timer){
    serialMaster();
    t = millis();
  }
}

void serialMaster(){
  static int lengthGlobalState = sizeof(globalState) / sizeof(globalState[0]);
  String acc = "$";
  unsigned int crc = 0;
  static int lengthBufferComand = 3;
  unsigned int bufferComand[lengthBufferComand]; // буфер команд управления всегда+1 для CRC
  static unsigned long errorTimer = 0;

  
  for(byte i = 0; i < lengthGlobalState; i++){ // расчет CRC
    crc += globalState[i];
  }
  
  for(byte i = 0; i < lengthGlobalState; i++){ // формируем посылку 
    if(lengthGlobalState - 1 == i){
      acc+= crc;
      acc+= ";";
    }else{
      acc+= globalState[i];
      acc+= " ";
    }  
  }
  
  uart.println(acc); // отправляем посылку

   if(parsePacket((int*)bufferComand)){
    //globalState[2] = 1; //данные были приняты и они правильной структуры
    crc = 0; //очищаем преведущую CRC
    for(byte i = 0; i < lengthBufferComand - 1; i++){ // расчет CRC
      crc += bufferComand[i];
    }
    
    if(bufferComand[lengthBufferComand - 1] == crc){ //проверка контрольной суммы пройдена

      //выполняем перенос принятых данных в глобальное состояние
      globalState[0] = bufferComand[0]; // значение аттенюатора
      globalState[1] = bufferComand[1]; // пустой слот
      globalState[3] = bufferComand[3]; // номер пакета

    }else{
       //uart.println("Error CRC !!");//обработка ошибки
    } 
  }else{
    //globalState[2] = 0; // данные не были приняты
  }
  
}



boolean parsePacket(int *intArray) {
    if (uart.available()) {
        uint32_t timeoutTime = millis();
        int value = 0;
        byte index = 0;
        boolean parseStart = 0;

        while (millis() - timeoutTime < 100) {
            if (uart.available()) {
                timeoutTime = millis();
                if (uart.peek() == '$') {
                    parseStart = true;
                    uart.read();
                    continue;
                }
                if (parseStart) {
                    if (uart.peek() == ' ') {
                        intArray[index] = value / 10;
                        value = 0;
                        index++;
                        uart.read();
                        continue;
                    }
                    if (uart.peek() == ';') {
                        intArray[index] = value / 10;
                        uart.read();
                        return true;
                    }
                    value += uart.read() - '0';
                    value *= 10;
                }
                else
                {
                    uart.clear(); //возможно не будет работать нужна очистка 
                }
            }
        }
    }
    return false;
}
