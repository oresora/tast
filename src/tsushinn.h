#ifndef _TSUSHINN_H_
#define _TSUSHINN_H_

#include "mbed.h"
#include <cmath>

class DualShock3{
public:

    DualShock3(PinName, PinName, int);
    void StateHold(void);

    class button{
    public:
        bool flg = 0;
        bool press = 0/*, press_storage*/;
        bool toggle = 0/*, toggle_storage*/;
        short pressure = 0/*, pressure_storage*/;
        int count = 0/*, count_storage*/;
    };

    class JoyStick{
    public:
        short x = 0/*, x_storage*/;
        short y = 0/*, y_storage*/;
        double deg = 0;
        double rad = 0;
    };

    button Circle;
    button Cross;
    button Triangle;
    button Square;
    button Up;
    button Down;
    button Left;
    button Right;
    button L1;
    button R1;
    button L2;
    button R2;
    button L3;
    button R3;
    button Select;
    button Start;
    button PS;
    JoyStick jsl;
    JoyStick jsr;

private:

    #define DEAD_BAND       4
    #define FROM_MAX_PLUS   112
    #define FROM_MAX_MINUS  127
    #define TO_MAX          255
    #define M_PI            3.14159265358979323846

    UnbufferedSerial* SCI;

    void getButton(void);
    void getJoyStick(void);

    short DeadBand(short js);
    double getRadians(JoyStick *);
    double getAngles(JoyStick *);
    bool pushCount(button *);
    short getPressure(short);

    void DataReceive(void);

    bool is(uint8_t);
    short i_abs(short);
    short map(short, short, short, short, short);

    bool Update = 0;
	/*static */char data_num = 0;
	/*static */uint8_t rx_data[16] = {0};
    uint8_t rx_buff;
    double Radians = 0;
};

#endif