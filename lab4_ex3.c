#include <stdio.h>

int b[100];  // temporary array used for merging

void DoMerging(int a[], int startIndex, int midIndex, int endIndex) {
   // Here we should merge the subllists a[startIndex] to a[midIndex] with
   // a[midIndex+1] to a[endIndex] together into b[], in ascending order
   // Please consult lecture notes for an example of how the merge is done!
   // Please use b[] as temporary array for merging!       
    
    int ai, aj, i;
    
    ai = startIndex;
    aj = midIndex + 1;
    
    for (i = startIndex; i <= endIndex; i++){
        // printf("%d,%d,%d,%d,%d\n", a[ai], a[aj], ai,aj, midIndex);
        if (a[ai] >= a[aj] && aj <= endIndex||ai>midIndex){
          //  printf("\n%d %d\n", a[aj], aj);
            b[i] = a[aj];
            aj = aj + 1;
            
        }
        else if (a[ai] < a[aj] && ai <= midIndex||aj>endIndex){
            b[i] = a[ai];
            ai = ai + 1;
        }
    }
    
    
   // INSERT CODE HERE
   
   

    // copy the result from b[] back to a[]
    int k;
    printf("Merge Result: ");
    for(k = startIndex; k <= endIndex; k++){
      a[k] = b[k];
      printf("%d ", b[k]);
    }
    printf("\n");
 
}

void MergeSort(int a[], int startIndex, int endIndex) {
    // this is the recursive function for MergeSort
    // we separate the list into two sublists and call mergesort again;
    // the sublist is marked by startIndex and endIndex
   int midIndex;
   
   if(startIndex < endIndex) {
      // more than one element, pls sort! 
      midIndex = (startIndex + endIndex) / 2;
      MergeSort(a, startIndex, midIndex);
      MergeSort(a, midIndex+1, endIndex);
      DoMerging(a, startIndex, midIndex, endIndex);
   } else { 
     // only one element, no need to sort!
     return;
   }   
}


int main() { 
   int i;
   int a[] = { 17, 22, 10, 22, 49, 30, 25, 2 };

   printf("Original: ");
   for(i = 0; i < 8; i++)
      printf("%d ", a[i]);
   printf("\n");

   MergeSort(a, 0, 7); // in the beginning, we put in the whole list, which is from 
                       // 0 to 7

   printf("Final Result: ");
   for(i = 0; i < 8; i++)
      printf("%d ", a[i]);
   printf("\n");

}
