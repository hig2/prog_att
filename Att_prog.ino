#include <GyverWDT.h>

int globalState[4] = {
  0, //0 значение аттенюатора (x / 10)
  0, //1 пустой слот
  0, //2
  0  //3 CRC
};

void setup() {
  initAttenuator(31.5);
  initSerialPort();
  initLed();

  Watchdog.enable(RESET_MODE, WDT_PRESCALER_512);
}

void loop() {
  attenuatorValueWatcher();
  ledWatcher();
  serialTimer(100);
  
  Watchdog.reset();
}
