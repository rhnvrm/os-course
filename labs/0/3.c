#include <bits/stdc++.h>

int main(){
	
	char str[80];

	scanf("%s",str);

	int len;
	for(len = 0; str[len] != '\0'; len++);
	len--;

	printf("%d\n", len);


	
	for(int i = 0; i <= len/2; i++){
		char temp = str[i];
		str[i] = str[len-i];
		str[len-i] = temp;
	}


	printf("%s\n", str);

	return 0;
}

