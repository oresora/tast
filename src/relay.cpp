#include <mbed.h>
#include <init.h>
#include <relay.h>
#include <general.h>

void relay_drive(int *target){
    static int spd[4]={0};
    for(int i=0; i<4; i++){
        target[i]=(target[i]<100)?0:target[i];
            if(target[i]>spd[i]){
                spd[i] += SMOOTH;
            if(target[i]<spd[i]){
                spd[i]=target[i];
            }
        }
        if(spd[i]>target[i]){
             spd[i] -= SMOOTH;
            if(target[i]>spd[i]){
                spd[i]=target[i];
            }       
        }
        pwm_drive_write(fabs(spd[i]/MAX_SPD));
        motor_sign_front[i]=(spd[i]>0);
        motor_sign_back[i]=(spd[i]<0);
   }
}