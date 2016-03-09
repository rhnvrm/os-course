/*
2. Write a program or shellscript which creates one child and 
waits until this child terminates. 
Child should prompt the user by printing "Shall I terminate?" 
on STDOUT. Once the user enters, YES, it should terminate. 
After child terminates, the parent prints "Process id <pid> is terminating" 
on STDOUT and after that it terminates. [10]
*/

/* Skeleton Code Problem 2 */
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	pid_t pid;
	int choice;
	int status;
   //Do a man fork on bash prompt
   //create child process, check pid returned by the fork to decide parent/child
   //Write appropriate printf. 

	pid = fork();

	if(pid < 0){
		printf("Error in fork()\n");
	}
	else if(pid == 0){ // child process
		
		do {
			printf("%s\n", "Shall I Terminate? [y=1/n=0] ");
			scanf("%d", &choice);
			
		}while(choice != 1);
		
	}
	else if(pid > 0){ // parent process
		wait(&status);
		printf("Process id <%d> is terminating\n", pid);
		printf("My PID was: <%d>\n", getpid());
	}

	return 0; 
}