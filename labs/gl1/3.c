#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <dirent.h>

//DIR *opendir(const char *name);

int main(int argc, char *argv[]){

	if(argc == 2){

		if(opendir(argv[1]) == NULL)
			printf("Directory <%s> was not found\n", argv[1]);
		else{
			printf("Directory <%s> exists\n", argv[1]);
		}

	}
	else{
		printf("Usage: opendir <dir>\n");
	}

	return 0;
}