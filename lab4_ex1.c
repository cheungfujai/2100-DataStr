#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int a[], int n)
{
    int i, j, minIndex;
 
    printf("sorting array of length %d...\n",n);
    for (i = 0; i < n; i++)
    {
        // in selection sort we find the smallest element
        // from array and put it aside, then we
        // find the next smallest in the remaining array
        // again, and go on and go on
        
        // print it out to easily visualize
        for (int i=0;i<n;i++) {
            printf("%d ",a[i]);
        }
        printf("\n");

    
        // find the minimum in remaining array
        minIndex = i;
        for (j = i+1; j < n; j++) {
           if (a[j] < a[minIndex])
              minIndex = j;
        }

        // swap the found minimum element with the current i element
        swap(&a[minIndex], &a[i]);
        
    }
    
    for (int i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    
}

int main()
{
    int a[] = {1,4,5,2,3,6,7,8};
    int b[] = {6,12,15,16,18,
                4,11,2,5,6,
                7,10,12,5,6,
                90,4,88,72,32,
                66,54,12,0,1,
                300,57,19,6,2};
    
    selectionSort(a, 8);
    selectionSort(b, 30);
    
    return 0;
}
