#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
}*temp,*newnode,*top;
void push()
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter data : ");scanf("%d",&newnode->data);
newnode->link=top;
top=newnode;
}
void pop()
{
if (top!=NULL)
top=top->link;
}
void display()
{
if (top==NULL)
printf("Stack is Empty");
else
{
temp=top;
printf("Stack is : \n");
while (temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->link;
}
}
}
void main()
{
int choice,k=0;
while (k==0)
{
printf("\n\n1)Push\n2)Pop\n3)Display\n4)Exit\nEnter the choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1:
push();
printf("Operation Complete\n");
display();
break;
case 2:
pop();
printf("Operation Complete\n");
display();
break;
case 3:
printf("Displaying ");
display();
break;
case 4:
printf("Exit\n");
k=1;
break;
default:
printf("Invalid Entry: Return to Menu");
}
}
}

