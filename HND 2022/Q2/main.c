#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//void writeToFile(int RolNo, char name[50]);
int RolNo; 
bool keepReading = true;
char name[50];


void writeToFile(int RolNo, char name[50]){
	FILE* file = fopen("register.txt", "a");
	if(file != NULL){
		const char* text = name;
//	Writing to file
		fprintf(file, "\n %d", RolNo);
		fprintf(file, "\t|    %s", name);
		fclose(file);
	} else {
		printf("Unable to open file.");
	}
}


void readFile(){
//	reading and printing data from the file 
	FILE* fileRead = fopen("register.txt", "r");
	if (fileRead != NULL){
		char buffer[100];
		printf("-----------------------------\n");
		printf(" RolNo  |    Name \n");
		printf("-----------------------------\n");
		while (fgets(buffer, sizeof(buffer), fileRead) != NULL){
			printf("%s", buffer);
		}
		fclose(fileRead);
		printf("\n-----------------------------\n");
	}
}

//  Receive Users input 
void recieveInput(){
		printf("Enter Name: ");	
		getchar();
		gets(name);
		printf("Enter the Roll Number: ");
		scanf("%d", &RolNo); 
		
//		calling the writeToFile function					
		writeToFile(RolNo, name);
}

int main() {

	int choice = 1; 
	bool continueToWrite = true;
	
	while (continueToWrite){
		printf("\n 1 - Write to file \n 2 - Read File \n 0 - Stop writing to file \n");
		scanf("%d", &choice);
		
		switch (choice){
			case 1: 
				recieveInput();
				break;
			case 2: 
				readFile();
				break;
			case 0: 
				continueToWrite = false;
				break;
			
			default: 
				printf("\a Sorry! Enter a valid choice \n");
				break;
		}
				
	}

	readFile();

	return 0;
}