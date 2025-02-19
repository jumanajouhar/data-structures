#include<stdio.h>
#include<stdlib.h>
struct node
{
int rollno;
char name[10];
struct node *next;
}*head=NULL,*current=NULL;
void push();
void pop();
void traverse();
void main()
{
int choice,w;
do
{
printf("1-push\n2-pop\n3-traverse\n");
printf("enter your choice:");
scanf("%d",&choice);
switch (choice)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
traverse();
break;
default:
printf("your choice is wrong\n");
break;
}
printf("do you want to continue if yes enter 1");
scanf("%d",&w);
}while(w==1);
}
void push()
{
struct node *newnode=(struct node *)malloc(sizeof(struct node));
printf("enter the details of student\n");
printf("enter the name:");
scanf("%s",newnode->name);
printf("enter the rollno:");
scanf("%d",&newnode->rollno);
newnode->next=NULL;
if(head==NULL)
{
head=newnode;
current=newnode;
}
else
{
current->next=newnode;
current=newnode;
}
}
void pop()
{
struct node *ptr=head;
if(head==NULL)
{
printf("the list is empty\n");
} 
else if(ptr->next==NULL)
{
ptr=NULL;
printf("stack is empty\n");
}
else
{
while(ptr->next!=current)
{
ptr=ptr->next;
}
ptr->next=NULL;
}
}
void traverse()
{
struct node *ptr;
ptr=head;
if(head!=NULL)
{
printf("the details of students are:\n");
while(ptr!=NULL)
{
printf("name-%s\nrollno-%d\n",ptr->name,ptr->rollno);
ptr=ptr->next;
}
}
else
printf("empty linked list\n");
}