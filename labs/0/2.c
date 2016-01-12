#include <bits/stdc++.h>

int main(){
	
	int sum = 0,temp;

	int arr[10];

	for(int i = 0; i < 10; i++){
		scanf("%d",&arr[i]);
	}

	std::sort(arr, arr+10);

	for(int i = 0; i < 10; i++){
		printf("%d ",arr[i]);
	}

	printf("\n");	

	return 0;
}

