#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *link;
}*top=NULL,*temp,*p=NULL;
void display(){
temp=top;
if(temp==NULL){
printf("Stack is empty");
}else{
while(temp!=NULL){
printf("%d ",temp->data);
temp=temp->link;
}
}
}
void push(){
int data;
p=(struct node*)malloc(sizeof(struct node));
printf("Enter the data:");
scanf("%d",&p->data);
p->link=top;
if(top==NULL){
top=p;
top->link=NULL;
}
else{
p->link=top;
top=p;
}
top=p;
display();
}
void pop(){
if(top==NULL){
printf("Stack Underflow");
}
else{
printf("Popped element:%d",top->data);
top=top->link;
}
}
void main(){
int ch;
while(1){
printf("\n>>>>MENU<<<<\n");
printf("1.push\n2.pop\n3.display\n4.exit\n");
printf("Enter choice:");
scanf("%d",&ch);
switch(ch){
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("Invalid choice");
}
}
}