#include<Arduino.h>
#include<membrane_keyboard.h>
int pins[8]={ 4,5,6,7,15,16,17,18 };
membrane_keyboard keyboard(X4,pins);
void setup() {
    Serial.begin(115200);
}
void loop() {
    char key=keyboard.read();
    if(key!=keyboard.npos) { // 检测到按键
        Serial.printf("Key: %c\n",key);
    }
}