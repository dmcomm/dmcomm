#include <DMComm.h>

const byte pinAnalog = A3;
const byte pinOut = A2;
const byte pinNotOE = A1;
const byte pinLed = 13;

const int logBufSize = 1000;

DMComm dmcomm(pinAnalog, pinOut, pinNotOE);
byte logBuffer[logBufSize];

void setup() {
    Serial.begin(9600);
    dmcomm.begin();
    dmcomm.setPinLed(pinLed);
    dmcomm.setSerial(Serial);
    dmcomm.setLogBuffer(logBuffer, logBufSize);
}

void loop() {
    //Japanese D-3 trade courage egg
    dmcomm.beginComm(dmcomm.PROTOCOL_V);
    dmcomm.sendPacket(0x8C0F);
    int8_t ret = dmcomm.receivePacket();
    if (ret == 0) {
        dmcomm.sendPacket(0x480F);
        dmcomm.receivePacket();
    }
    Serial.println();
    delay(10000);
}
