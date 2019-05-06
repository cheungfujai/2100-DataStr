#include <stdio.h>

void Sum (int box[], int digi, int* result){
    
    int i, j;

    for (i = 0; i < digi; i++){
        *result += box [i]; 
    }

}

int main()

{
 
    int a[] = {3, 5, 6, 1};

    int  result  =   0;
    Sum (a , 4, &result); 
    printf ("%d\n" , result);

}