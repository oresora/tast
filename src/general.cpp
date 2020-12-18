#include<mbed.h>
#include<general.h>
#include<init.h>
int is(int n){
    return !!n;
}

void pwm_drive_write(double vol){
    for(int i=0; i<4; i++){
        motor_pwm[i].write(vol);
    }
}