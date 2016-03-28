/* philmain.c    */

#include <stdlib.h>
#include <stdio.h>

#include  "philtable.h"

#define TIME_MAIN_THREAD 60

#define PHILNUM 5


void * philosopher(int * a); 

int main(void) {
 printf("\nStarting Simulation. [%d seconds] [%d philosophers] [Random Eat Times]\n", TIME_MAIN_THREAD, PHILNUM);
 printf("H - Hungry \t T - Thinking \t E - Eating\n");
 void * tab = tableinit(philosopher);
 sleep(TIME_MAIN_THREAD);  // Wait a while then exit
 printfoodeaten();
 printf("Main Thread Done.\n");
 return 0;
}

void * philosopher(int * who) {
 while (1){
   sleep(rand() % 2 + 1);
   pickup_forks((*who));
   sleep(1);
   putdown_forks((*who));
 }
}