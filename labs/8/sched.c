#include <stdio.h>
 
typedef struct {
	int bt; //burst
	int p; //p id
	int wt; // wait time
	int tat; // turn around time
}process;

#define TIMESLICE 5

process P[20];

/*void swap_process(process *p1, process *p2){
	process *t = *p1;
	*p1 = *p2;
	*p2 = t;
}
*/
int cmpfunc (const void * a, const void * b)
{
   return ( (*(process*)a).bt - (*(process*)b).bt );
}


int main()
{
    int i,j,n,total=0,temp,algo;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&P[i].bt);
        P[i].p=i+1;         
    }

    printf("Choose algorithm:\n1. FCFS\n2. SJF\n3. RR\n?");
    scanf("%d", &algo);
    if(algo == 1){
    	; //do nothing
    }
    else if(algo == 2){
    	qsort(P, n, sizeof(process), cmpfunc);
    }
    else if(algo == 3){
    	int current = 0, time_left = 0;
    	for(int i = 0; i < n; i++)
    		time_left += P[i]->bt; //total bursts

    	while(time_left) {
    	    if(P[current] > 0){
    	    	time_left -= P[current]->bt;
    	    }
    	}

    }
    else{
    	return -1; //invalid input
    }

	if(algo <= 2) {	
	
		P[0].wt=0;            
	 
	    for(i=1;i<n;i++)
	    {
	        P[i].wt=0;
	        for(j=0;j<i;j++)
	            P[i].wt+=P[j].bt;
	 
	        total+=P[i].wt;
	    }
	 
	    avg_wt=(float)total/n;      
	    total=0;
	 }
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        P[i].tat=P[i].bt+P[i].wt;     
        total+=P[i].tat;
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",P[i].p,P[i].bt,P[i].wt,P[i].tat);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);


    return 0;
}