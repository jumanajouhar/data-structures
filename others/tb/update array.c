#include <stdio.h>
void main() {
 int A[] = {1,3,5,7,8};
 int k = 3, n = 5, item = 10;
 int i, j;
 printf("The original array elements are :\n");
 for(i = 0; i<n; i++) {
 printf("A[%d] = %d \n", i, A[i]);
 }
 
 A[k-1] = item;
 printf("The array elements after updation :\n");
 for(i = 0; i<n; i++) {
 printf("A[%d] = %d \n", i, A[i]);
 }
}