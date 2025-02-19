#include<stdio.h> 
#include<stdlib.h> 
void push();
void pop(); 
void display(); 
int n,a[20],top=-1;
int main()
{
int c;
printf("enter size of stack\n");
scanf("%d",&n);
while(1)
{
printf ("Enter choice: 1.push 2.pop 3.display 4.exit\n");
scanf("%d",&c);
switch(c)
{
case 1: push();
break;
case 2: pop();
break; 
case 3: display();
break;
case 4: exit(0);
default:printf("invalid choice");
}
}
return 0;
}
void push()
{
int e;
if(top==n-1)
printf("stack is full\n");
else
{
printf("enter element to be pushed\n"); 
scanf("%d",&e);
top++; 
a[top]=e;
}
}
void pop()
{
if(top==-1)
printf("stack is empty\n");
else
{
printf("popped element is %d\n",a[top]);
top--;
}
}
void display()
{
int i; 
if(top==-1)
printf("stack is empty\n");
else
{
printf("the elements of the stack are:\n");
for(i=0;i<=top;i++)
printf("%d\n",a[i]);
}
}