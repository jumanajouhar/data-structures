#include <stdio.h>
void main() {
 int A[] = {1,3,5,7,8};
 int item = 10, k = 3, n = 5;
 int i = 0, j = n;
 printf("The original array elements are :\n");
 for(i = 0; i<n; i++) {
 printf("A[%d] = %d \n", i, A[i]);
 }
n++;
 while( j >= k) {
 A[j+1] = A[j];
 j--;
 }
 A[k] = item;
 printf("The array elements after insertion :\n");
 for(i = 0; i<n; i++) {
 printf("A[%d] = %d \n", i, A[i]);
 }
}