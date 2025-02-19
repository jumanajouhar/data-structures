#include<stdio.h>

void main()
{
int A[10][10],B[10][3],i,j,m,n,s;

printf("Enter row size of matrix:");
scanf("%d",&m);
printf("Enter column size of matrix:");
scanf("%d",&n);
printf("Enter elements of the matrix\n");
for(i=0;i<m;i++){
printf("Enter the elements of row %d:",i+1);
for(j=0;j<n;j++){
scanf("%d",&A[i][j]);
}
}


printf("The sparse matrix is:\n");
for(i=0;i<m;i++){
for(j=0;j<n;j++){
printf("%d\t",A[i][j]);
}
printf("\n");
}

B[0][0]=m;
B[0][1]=n;
s=1;

for(i=0;i<m;i++){
for(j=0;j<n;j++){
if(A[i][j]!=0)
{
B[s][2]=A[i][j];
B[s][0]=i;
B[s][1]=j;
s=s+1;
}
}
}

B[0][2]=s-1;

printf("The triplet representation of the sparse matrix is\n");

for(i=0;i<s;i++){
for(j=0;j<3;j++){
printf("%d\t",B[i][j]);
}
printf("\n");
}
}