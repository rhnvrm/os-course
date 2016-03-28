/* philtable.c    */

#include  <sys/types.h>
#include  <pthread.h>

#include <stdio.h>
#include <stdlib.h>

#define PHILNUM 5

typedef enum {thinking, hungry, eating} philstat;

typedef struct tablestruct {
 pthread_t t[PHILNUM];
 int self[PHILNUM];
 pthread_mutex_t mutex;
 pthread_cond_t condition[PHILNUM];
 philstat status[PHILNUM];
 int foodEaten[PHILNUM];
} table;

table * tab;

void printstate(void){
 /* Prints out state of philosophers as, say, TEHHE, meaning */
 /* that philosopher 0 is thinking, philosophers 1 and 4 are eating, and*/
 /* philosophers 2 and 3 are hungry.*/
 static char stat[] = "THE";
 int i;
 for (i=0; i<PHILNUM; i++) {
   printf("%5c", stat[(int)(tab->status)[i]]);
 }
 printf("\n");
}
  
void printfoodeaten(void){
 /* Prints out state of philosophers as, say, TEHHE, meaning */
 /* that philosopher 0 is thinking, philosophers 1 and 4 are eating, and*/
 /* philosophers 2 and 3 are hungry.*/
 printf("Total Food Eaten: \n");
 int i;
 for (i=0; i<PHILNUM; i++) {
   printf("%5d", (tab->foodEaten)[i]);
 }
 printf("\n");
}

int test (int i) {
 if (
     ((tab->status)[i] == hungry) &&
     ((tab->status)[(i+1)% PHILNUM] != eating) &&
     ((tab->status)[(i-1+PHILNUM)% PHILNUM] != eating)) {
   (tab->status)[i] = eating;
   pthread_cond_signal(&((tab->condition)[i]));
   return 1;
 }
 return 0;
}

void pickup_forks(int k) {
 pthread_mutex_lock(&(tab->mutex));
 (tab->status)[k] = hungry;
 printstate();
 if (!test(k)) {
   pthread_cond_wait(&((tab->condition)[k]), &(tab->mutex));
 }
 printstate();
 pthread_mutex_unlock(&(tab->mutex));
}

void putdown_forks(int k) {
 pthread_mutex_lock(&(tab->mutex));
 (tab->status)[k] = thinking;
 (tab->foodEaten)[k]++;
 printstate();
 test((k+1)%PHILNUM);
 test((k-1+PHILNUM)%PHILNUM);
 pthread_mutex_unlock(&(tab->mutex));
}

table * tableinit(void *(* philosopher)(void *)) {
 int i;

 tab = (table *) malloc (sizeof(table));
 if(pthread_mutex_init(&(tab->mutex), NULL) != 0) {
   perror("pthread_mutex_init");
   exit(1);
 }
 for (i=0; i<PHILNUM; i++) {
   (tab->self)[i] = i;
   (tab->status)[i] = thinking;
   if(pthread_cond_init(&((tab->condition)[i]), NULL) 
      != 0) {
     perror("pthread_cond_init");
     exit(1);
   }
 }
 for (i=0; i<PHILNUM; i++) {
   if (pthread_create(&((tab->t)[i]),NULL,
         philosopher, &((tab->self)[i]))!= 0) {
     perror("pthread_create");
     exit(1);
   }
 }
 return tab;
}