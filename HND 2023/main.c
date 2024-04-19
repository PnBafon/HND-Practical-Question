#include <stdio.h>

int isdivisor(int a, int b){
	if (a % b == 0){
		return 1;
	}else {
		return 0;
	}
}

int nbdivisor(int n){
	int count=0, i; 
	
	for (i=1; i<=n; i++){
		if (isdivisor(n, i) == 1){
			count ++;
		} 
	}
	
	return count;	
}

int isprime(int n){
	if(nbdivisor(n) == 2){
		return 1;
	} else {
		return 0;
	};
}

int main() {
	int number, i; 
	printf("Enter a number to get the prime numbers less than or equal to the number: ");
	scanf("%d", &number);
	
	for (i=1; i<=number; i++){
		if(isprime(i) == 1){
			printf(" %d, ", i);
		}
	}
	
	return 0;
}