   /* philtable.h   -- Here are the calls we can make on the monitor
    *                  representing the dining philosophers
    */

   void * tableinit(void *(*)(int *)); // argument is the function
                                       // representing the philosopher
   void printstate(void);
   void pickup(int k);
   void putdown(int k);
