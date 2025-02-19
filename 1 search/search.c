#include<stdio.h>
void linear(int[],int,int);
void sort(int[],int);
void binary(int[],int,int);

int main(){
    int a[10],n,c,i,key;
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    printf("Enter elements of array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter element to be searched:\n");
    scanf("%d",&key);
    printf("Enter choice: 0 for linear search and 1 for binary search\n");
    scanf("%d",&c);
    if(c==0){
        linear(a,n,key);
    } else if(c==1) {
        binary(a,n,key);
    } else {
        printf("Invalid choice");
    }
    return 0;
}

void linear(int a[],int n,int key){
    int f=0,i;
    for(i=0;i<n;i++){
        if(a[i]==key){
            printf("Element is found at position %d\n",i+1);
            f=1;
        }
    }
    if(f==0){
        printf("Element not found");
    }
}

void sort(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-(i+1);j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }  
}

void binary(int a[],int n,int key){
  int low=0,mid,high=n-1;
  sort(a,n);
  mid=(low+high)/2;
  while(low<=high){
      if(key>a[mid]){
          low=mid+1;
      } else if(key<a[mid]) {
          high=mid-1;
      } else {
          printf("Element is found at position %d after sorting",mid+1);
          break;
      }
      mid=(low+high)/2;
  }
      if(low>high){
          printf("Element not found");
      }
}