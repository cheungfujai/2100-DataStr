#include <stdio.h>
 
// Linear search function - just search one by one; this function
// should return -1 if no match is found
int linearSearch(int a[], int lastIndex, int x)
{
   // lastIndex is the last index of the array
   // x is the number to search for in the array
   // INSERT YOUR CODE HERE
   
   //        a[], lastIndex = 11, x = 91
   
    int middle = 0, firstIndex = 0;
       
        while (firstIndex <= lastIndex){  
            
            middle = (firstIndex + lastIndex) / 2;   
            
            if (a[middle] < x){  
                printf("<<<   a[%d] = %d\n", middle, a[middle]);
                firstIndex = middle + 1;
            }
            
            else if (a[middle] > x){
                printf(">>>   a[%d] = %d\n", middle, a[middle]);
                lastIndex = middle - 1;
            }
            
            else 
                return x;
            
        }
        
        return -1;
        
        



}
 
int main(void)
{
   int a[] = {23, 31, 40, 52, 62, 71, 87, 91, 100, 101, 120, 131}; // 12 sorted
   int size = 12;
   int x = 91;
   int result = linearSearch(a, size-1, x); // a, 11, 91
   if (result == -1) // result = -1, no match found
        printf("* Element is not found in list\n");
   else  // result = 0, match found
        printf("* Element is found at index %d\n",result);
   return 0;
}