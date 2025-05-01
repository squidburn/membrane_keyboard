#include<membrane_keyboard.h>
int membrane_keyboard::rcread() {
    int v=npos;
    for(int i=0; i<col; i++) {
        digitalWrite(pins[i],LOW);
        for(int j=col; j<col+4; j++) {
            if(digitalRead(pins[j])==LOW) {
                v=(i+1)*10+j+1-4;
            }
        }
        digitalWrite(pins[i],HIGH);
    }
    return v;
}
char membrane_keyboard::read() {
    int k=rcread();
    if(k!='E')
        return keys[k/10][k%10];
    return npos;
}
