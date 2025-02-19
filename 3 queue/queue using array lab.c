#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
int n,a[20],front,rear;

int main()
{
int c,front=rear=-1;
printf("enter maximum size of queue:\n");
scanf("%d",&n);
while(1)
{
printf("enter choice: 1.enqueue 2.dequeue 3.display 4.exit\n");
scanf("%d",&c);
switch(c)
{
case 1:enqueue();
break;
case 2:dequeue();
break;
case 3:display();
break;
case 4:exit(0);
default:printf("invalid choice\n");
}
}
return 0;
}

void enqueue()
{
int e;
if(rear==n-1)
printf("queue is full\n");
else
{
if(front==-1)
front=0;
printf("Enter the element to be inserted\n");
scanf("%d",&e);
rear++;
a[rear]=e;
}
}

void dequeue()
{
if(front==-1)
printf("queue is empty\n");
else
{
printf("%d is removed from the queue\n",a[front]);
if(front==rear)
front=rear=-1;
else
front++;
}
}
void display()
{
int i;
if(front==-1)
printf("queue is empty\n");
else
{
printf("elements of the queue are:\n");
for(i=front;i<=rear;i++)
{
printf("%d\n",a[i]);
}
}
}