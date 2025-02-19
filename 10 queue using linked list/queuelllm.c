#include<stdio.h>
#include<stdlib.h>
struct node
{
int rollno;
char name[20];
struct node *next;
}
*head=NULL,*current=NULL;
void push();
void pop();
void traverse();
void main()
{
int choice,w;
do
{
printf("1-push\n2-pop\n3-traverse\n");
printf("enter your choice\n");
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
printf("do you want to continue if yes enter 1\n");
scanf("%d",&w);
}while(w==1);
}
void push()
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
printf("enter the rollno\n");
scanf("%d",&newnode->rollno);
printf("enter the name\n");
scanf("%s",newnode->name);
if(head!=NULL)
{
current->next=newnode;
current=newnode;
}
else
{
newnode->next=NULL;
head=newnode;
current=newnode;
}
}
void pop()
{
if(head!=NULL)
{
head=head->next;
if(head==NULL)
{
printf("now the queue become empty\n");
}
}
else
{
printf("the queue is empty\n");
}
}
void traverse()
{
struct node *ptr;
ptr=head;
if(head!=NULL)
{
printf("the details of students are\n");
while(ptr!=NULL)
{
printf("name-%s\nrollno-%d\n",ptr->name,ptr->rollno);
ptr=ptr->next;
}
}
else
printf("empty queue\n");
}