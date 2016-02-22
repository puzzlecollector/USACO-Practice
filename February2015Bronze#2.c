#include <stdio.h> 
#include <string.h> 

char str[100005]; 

int main(){
	int n; 
	scanf("%d\n",&n); 
	for (int i = 0; i < n; i++){
		scanf("%c",&str[i]);  
	}
	long long numC = 0, numO = 0, numW = 0;  
	for (int i = 0; i < n; i++){
		if (str[i] == 'C') numC++; 
		else if (str[i] == 'O') numO += numC; 
		else if (str[i] == 'W') numW += numO; 
	}
	printf("%lld\n",numW);  
	return 0; 
}
