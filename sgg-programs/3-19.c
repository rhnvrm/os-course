// 3-19.c SGG

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	pid_t pid;

	pid = fork();

	if(pid == 0){
		while(1);
	}
	else{
		return 0;
	}

}