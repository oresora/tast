#include <mbed.h>
#include <relay.h>
#include "init.h"
#include <tsushinn.h>


DualShock3 controler(PC_10,PC_11,9600);

int main() {

  // put your setup code here, to run once:
  

  while(1) {
  
    controler.StateHold();
  }
}