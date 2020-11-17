#include "system.h"
#include "periphs.h"
#include <iob-uart.h>
#include "iob_timer.h"
#include "iob_knn.h"
#include "random.h" //random generator for bare metal


///////////////////////////////////////////////////////////////////
int main() {

  unsigned long long elapsed;
  unsigned int elapsedu;

  //init uart and timer
  uart_init(UART_BASE, FREQ/BAUD);
  uart_printf("\nInit timer\n");
  uart_txwait();

  timer_init(TIMER_BASE);
  //read current timer count, compute elapsed time
  //elapsed  = timer_get_count();
  //elapsedu = timer_time_us();

  //generate random seed 
  random_init(1337);


  signed int input;
  signed int output;
  signed int lastOutput = 0;
  for (int i=0; i<100; i++) {
    input =  cmwc_rand();
    output = 2* lastOutput + input;
    uart_printf("Iteration = %d Input = %d Output =%d\n",i,input,output);
    lastOutput=output;
   
  }


}


