#include <init.h>

BufferedSerial pc(USBTX,USBRX);

PwmOut motor_pwm[MOTOR_NUM]={PwmOut (PA_0)
                            ,PwmOut (PA_1)
                            ,PwmOut (PA_2)
                            ,PwmOut (PA_3)
                            ,PwmOut (PA_4)
                            ,PwmOut (PA_5)
                            ,PwmOut (PA_6)
                            ,PwmOut (PA_7)
};

DigitalOut motor_sign_front[MOTOR_NUM]={DigitalOut (PB_0)
                                       ,DigitalOut (PB_1)
                                       ,DigitalOut (PB_2)
                                       ,DigitalOut (PB_3)
                                       ,DigitalOut (PB_4)
                                       ,DigitalOut (PB_5)
                                       ,DigitalOut (PB_6)
                                       ,DigitalOut (PB_7)
};
DigitalOut motor_sign_back[MOTOR_NUM]={DigitalOut (PC_0)
                                      ,DigitalOut (PC_1)
                                      ,DigitalOut (PC_2)
                                      ,DigitalOut (PC_3)
                                      ,DigitalOut (PC_4)
                                      ,DigitalOut (PC_5)
                                      ,DigitalOut (PC_6)
                                      ,DigitalOut (PC_7)
};