#include <stdio.h>
#include <stdbool.h>

float marks[6];


int main() {
    float mark;
    int i;

    for (i = 0; i < 6; i++) {
        bool mark_condition = true;
        printf("Enter mark: ");
        scanf("%f", &mark);

        while (mark_condition) {
            if (mark > 20) {
                printf("Mark cannot be greater than 20 \n");
                printf("Enter mark: ");
                scanf("%f", &mark);
            } else {
                marks[i] = mark;
                mark_condition = false;
            }
        }
    }

    // Printing out the values in the marks array
    for (i = 0; i < 6; i++) {
        printf("%.1f \n", marks[i]);
    }

//     Invoking the swap function
    swap();
    // Printing out the values in the marks array
    printf("\n Printing all of this after swap \n");
    for (i = 0; i < 6; i++) {
        printf(" %.1f ", marks[i]);
    }

	sort(marks);

    return 0;
}

    
//    unsorted {1,2,4,5,3,6}
    
void sort(float arr[]) {
	
	int i;

    printf("\n Array before sort \n");
    for (i = 0; i < 6; i++) {
        printf("| %.1f | ", arr[i]);
    }
    
    for (int i = 1; i < 6 - 1; i++) {
    	
        for (int j = 2; j < 6 - i  ; j++) {
            	
            if (arr[j] > arr[j + 1]) {

            // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    
    printf("\n Array after sort \n");
    for (i = 0; i < 6; i++) {
        printf("| %.1f | ", marks[i]);
    }
}



int swap() {
    int i;

    printf("\n Array before swap \n");
    for (i = 0; i < 6; i++) {
        printf("| %.1f | ", marks[i]);
    }

    // Swapping the first and the last value
    float temp;
    temp = marks[0];
    marks[0] = marks[5];
    marks[5] = temp;

    // Printing the array after swap
    printf("\n Array after swap \n");
    for (i = 0; i < 6; i++) {
        printf("| %.1f | ", marks[i]);
    }
	
    return 0;
}
