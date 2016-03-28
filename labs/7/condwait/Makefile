all:  
	gcc -g -o philmain.o -Wall -c philmain.c 

	gcc -g -o philtable.o -Wall -c philtable.c 

	gcc -pthread -g -o dining philmain.o philtable.o -lpthread


clean:
	rm philmain.o philtable.o



