#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
int front,rear; //Global Variables
int n,arr[20];

int main()
{
int i;
int c;
front=rear=-1;
printf("Enter the size of the Queue\n");
scanf("%d",&n);
while(1)
{
printf("\n1.Add Element to the Queue\n");
printf("2.Delete Element from the Queue\n");
printf("3.Display the Queue\n");
printf("4.Exit the Program\n");
printf("-----------------------------------\n");
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
default:printf("You have entered a wrong choice\n");
}
}
return 0;
}

void enqueue()
{
int e;
if(rear==n-1)
printf("The Queue is already Full\n");
else
{
if(front==-1) // If first element, setting front to 0
front=0;
printf("Enter the element to be inserted\n");
scanf("%d",&e);
rear++;
arr[rear]=e; // Inserting Element to the Queue
}
}

void dequeue()
{
if(front==-1)
printf("The Queue is Empty\n");
else
{
printf("%d is removed from the queue\n",arr[front]);  // Checking if its the last element(only element) in the queue
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
printf("The Queue is Empty\n");
else
{
printf("\nElements of the Queue Are:\n");
for(i=front;i<=rear;i++)
{
printf("%d\t",arr[i]);
}
printf("\nFront= %d, Rear= %d",front,rear);
}
}