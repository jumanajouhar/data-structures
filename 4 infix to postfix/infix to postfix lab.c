#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 20
char stack[SIZE];
int top = -1;

void push(char item)
{
if(top>=SIZE-1)
printf("Stack overflow");
else{
top++;
stack[top]=item;
}
}

char pop()
{
char item;
if(top<0)
{
printf("Stack underflow");
getchar();
exit(1);
}
else
{
item=stack[top];
top--;
return(item);
}
}

int op(char symbol)
{
if(symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-')
return(1);
else
return(0);
}

int precedence(char symbol)
{
if(symbol=='^')
return(3);
else if (symbol=='*'||symbol=='/')
return (2);
else if (symbol=='+'||symbol=='-')
return(1);
else
return(0);
}


void infixtopostfix(char infix[],char postfix[]){
int i=0,j=0;
char item,x;
push('(');
strcat(infix,")");
item=infix[i];
while(item!='\0')
{
if(item=='(')
push(item);
else if(isdigit(item)||isalpha(item))
{
postfix[j] = item;
j++;
}
else if(op(item)== 1)
{
x=pop();
while(op(x)== 1&&precedence(x)>=precedence(item))
{
postfix[j]=x;
j++;
x = pop();
}
push(x);
push(item);
}
else if(item==')')
{
x = pop();
while(x!='(')
{
postfix[j]=x;
j++;
x=pop();
}
}
else
{
printf("Invalid infix expression");
getchar();
exit(1);
}
i++;
item = infix[i];
}
if(top>0)
{
printf("Invalid infix expression");
getchar();
exit(1);
}
postfix[j]='\0';
}

int main()
{
char infix[SIZE], postfix[SIZE];
printf("Enter infix expression: ");
gets(infix);
infixtopostfix(infix,postfix);
printf("Postfix expression is: ");
puts(postfix);
return 0;
}