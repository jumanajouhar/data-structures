#include<stdio.h>
void main() {
 int A[] = {1,3,5,7,8};
 int item = 5, n = 5;
 int i = 0, j = 0;
 printf("The original array elements are :\n");
 for(i = 0; i<n; i++) {
 printf("A[%d] = %d \n", i, A[i]);
 }
 while( j < n){
 if( A[j] == item ) {
 break;
 }
 j = j + 1;
 }
 printf("Found element %d at position %d\n", item, j+1);
}
