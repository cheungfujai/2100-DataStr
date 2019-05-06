#include <stdio.h>

void PrintArray(int* arrayHead){

	// the array is assumed to be terminated by a zero element
	int* current; // pointer for travesing the array

	// insert your code here
    int count = 5;
	int i;
	for (i = 0; i < count; i++){
		printf("%d ", *arrayHead);
		arrayHead++;
		count++;
		if(*arrayHead == 0){
		    break;
		}
	}

}

int main(){
	
	int a[] = {5, 4, 3, 2, 1, 2, 3, 4, 0};
	PrintArray(a);
	return 0;

}