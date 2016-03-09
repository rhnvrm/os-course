/*
1. Write a program  which when executed creates 3 processes out of which one is children and one 
is grandchild process? Print the process-id of each of the processes[5]
*/
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	pid_t p1, p2, p3;
	
	p1 = fork();

	
	if(p1 > 0){ // parent process
		printf("Parent PID: \t%d\n", getpid());
	}
	else if(p1 == 0){ //child process

		pid_t p2 = fork();

		if(p2 > 0){ // child process
			printf("Child PID: \t%d\n", getpid());
		}
		else if(p2 == 0){ //grandchild process
			printf("G-child PID: \t%d\n", getpid());
		}

	}





	return 0;
}