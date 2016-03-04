#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int* arr;
int* solution;

typedef struct
{
	int start;
	int end;
} parameters;


void swap(int *x, int *y){
	int t = *x;
	*x = *y;
	*y = t;
}

void *sort(void *params){

	parameters* param = (parameters*)params;

	int begin = param->start, end = param->end;

	//printf("%d %d\n", begin, end);

	for (int i = begin; i < end; ++i)
    {
        for (int j = begin + 1; j < end; ++j)
        {
            if (arr[i] > arr[j])
            {
                int a =  arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }

    for(int i = begin; i < end; i++)
		printf("%d ", arr[i]);
	printf("\n");


	pthread_exit(0);
}

void *merge(void* param){
	int* n = (int*)param;

	int i = 0, j = *n/2, k = 0;

    while (i < *n/2 && j < *n)
    {
        if (arr[i] < arr[j])       
            solution[k++] = arr[i++];

        else        
            solution[k++] = arr[j++];               
    }

    while (i < *n/2)  
        solution[k++] = arr[i++];


    while (j < *n)    
        solution[k++] = arr[j++];

    pthread_exit(0);

}

int main(){

	int n;

	//input number
	scanf("%d", &n);

	//allocate memory for array
	arr = (int *)malloc(n*sizeof(n));
	solution = (int *)malloc(n*sizeof(n));

	//input
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}


	//create parammeterssss

	parameters *left_params = (parameters *) malloc(sizeof(parameters));
	left_params->start = 0;
	left_params->end = n/2;

	parameters *right_params = (parameters *) malloc(sizeof(parameters));
	right_params->start = n/2;
	right_params->end = n ;


	//sort

	pthread_t tid_left, tid_right, tid_merge;
	pthread_attr_t attr;

	pthread_attr_init(&attr);

	pthread_create(&tid_left, &attr, sort, left_params);
	pthread_create(&tid_right, &attr, sort, right_params);

	pthread_join(tid_left, NULL);
	pthread_join(tid_right, NULL);

	pthread_create(&tid_merge, &attr, merge, &n);

	pthread_join(tid_merge, NULL);

	//output
	for(int i = 0; i < n; i++)
		printf("%d ", solution[i]);
	printf("\n");

	return 0;
}