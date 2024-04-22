#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Student{
	int RolNo;
	char name[20];
	int count;
	struct student* next;
};
int count = 0, RolNo;
struct Student* head = NULL;
char name[20];

// insertion into the list
struct Student* insert(int RolNo, char name[20]){
	struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
	
	if (newNode != NULL){
		newNode->RolNo = RolNo;
		strcpy(newNode->name, name);

		newNode->count = count ++;
//		update the head and this new node pointing addres 
		newNode->next = head;
		head = newNode;
	} else {
		printf("Error Occured Creating New Node!");
	}
	
	return head;
}


void printList(){
	struct Student* current = head;
	
	if(current != NULL){
		printf("-----------------------------\n");
		printf(" RolNo  |    Name \n");
		printf("-----------------------------\n");
		while(current != NULL ){	
			printf("%d\t    %s\n", current->RolNo, current->name);
			current = current->next;
		}
		printf("-----------------------------\n");
	} else{
		printf("\n List is empty! \n");
	}
	
}

void sort() {
    int i, j, size, tempRolNo;
    char tempName[20];
    struct Student* current;
    struct Student* next;

    size = head->count + 1;
    
    for (i = 1; i <= size ; i++) {
        current = head;
        next = head->next;

        for (j = 1; j < size ; j++) {
            if (current->RolNo > next->RolNo) {
                tempRolNo = current->RolNo;
                strcpy(tempName, current->name);

                current->RolNo = next->RolNo;
                strcpy(current->name, next->name);

                next->RolNo = tempRolNo;
                strcpy(next->name, tempName);
            }

            current = current->next;
            next = next->next;
        }
    }
}

struct Student* deleteNode(int RolNo) {
    struct Student* current = head;
    struct Student* previous = NULL;

    if (current == NULL) {
        printf("Sorry, the list is empty!\n");
        return NULL;
    }

    while (current != NULL) {
        if (current->RolNo == RolNo) {
            if (previous == NULL) {
                // Deleting the head node
                head = current->next;
            } else {
                // Deleting a node in the middle or at the end
                previous->next = current->next;
            }

            free(current);
            printf("Node with RolNo %d deleted from the list.\n", RolNo);
            return head;
        }

        previous = current;
        current = current->next;
    }

    printf("Node with RolNo %d not found in the list.\n", RolNo);
    return head;
}

// receiving the users input 
void recieveInput(){
		printf("Enter Name: ");	
		getchar();
		gets(name);
		printf("Enter the Roll Number: ");
		scanf("%d", &RolNo); 
		
//		calling the writeToFile function					
		insert(RolNo, name);
}

int main() {

	int choice = 1, RolNo; 
	bool continueToWrite = true;
	
	while (continueToWrite){
		printf("\n 1 - Create node \n 2 - Delete a node \n 0 - close \n");
		scanf("%d", &choice);
		
		switch (choice){
			case 1: 
				recieveInput();
				printList();
				break;
			case 2: 
				printf("Please enter the rolno you wish to delete: ");
				scanf("%d", &RolNo);
				deleteNode(RolNo);
				printList();
				break;
			case 0: 
				continueToWrite = false;
				break;
			
			default: 
				printf("\a Sorry! Enter a valid choice \n");
				break;
		}
				
	}


	return 0;
}