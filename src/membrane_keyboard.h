#include<Arduino.h>
#define X4 4
#define X3 3
class membrane_keyboard {
private:
    char keys[5][5]={
    {'0','0','0','0','0'},
    {'0','1','2','3','A'},
    {'0','4','5','6','B'},
    {'0','7','8','9','C'},
    {'0','#','0','*','D'}
    };
    int col;
    const int *pins;
public:
    const int npos='E';
    /*
Input Type:
4X4 X4 need 8 GPIO
3X4 X3 need 7 GPIO
Enter the pins array:
Note: The array wiring is from left to right
    */
    membrane_keyboard(const int type,const int *Pins) {
        pins=Pins;
        col=type;

        for(int i=0; i<type+4; i++) {
            if(i<type)
                pinMode(Pins[i],OUTPUT);
            else
                pinMode(Pins[i],INPUT_PULLUP);
        }
    }
    /*
Output characters
    */
    char read();
    /*
Output Characters Output Rows and Columns 1,No input returns "E"
    */
    int rcread();
};
