#include <stdio.h>
#include <stdlib.h>

int isdivisor(int a, int b){
	if(a%b == 0){
		return 1;
	}else {
		return 0;
	}
}

int nbdivisor(int numb){
	int number_times = 0, i;
	for (i=1; i<= numb; i++){
		if(isdivisor(numb,i) == 1){
			number_times += 1;
			continue;
		}
	}
	
	return number_times;
}

int isprime(int n){
	if(nbdivisor(n) == 2){
		return 1;
	} else{
		return 0;
	}
}

int main() {
	int number = 0, i=0;
	printf("Enter a number: ");
	scanf("%d", &number);
	
	for(i=1; i<=number; i++){
		if(isprime(i) == 1){
			printf(" %d ", i);
		}
	}
	
	
	return 0;
}