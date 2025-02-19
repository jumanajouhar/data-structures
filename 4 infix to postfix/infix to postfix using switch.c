#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void push(char);
char pop();
int prece(char);
void to_post(char []);
int top=-1;
char in_fix[20];
char stack[20];

int main(){

    puts("Enter the infix expression:");
    gets(in_fix);
    puts("Postfix expression:");
    to_post(in_fix);
    getchar();
    return 0;
}


void push(char item){
    if(top>=19){
    printf("Stack overflow");
    
    }
    else{
   	 top++;
   	 stack[top]=item;
   	 }
}

char pop(){
    char p;
    if(top==-1)
    printf("Stack underflow");
    else{
   	 p=stack[top];
   	 top--;
   	 }
    return p;
}

int prece(char ch)
{    if(ch=='^')
    return 3;
    else if (ch=='*'||ch=='/')
    return 2;
    else if (ch=='+'||ch=='-')
    return 1;
    else
    return 0;
}
void to_post(char in_fix[]){
    char s,t;
    char post[20];
    static int index=0,pos=0;
    int len;
    push('(');
    len=strlen(in_fix);
    in_fix[len]=')';
    in_fix[len+1]='\0';
    
    while(index<=len){
    s=in_fix[index];
    switch(s)
    {
   	 case '(':
   		 push(s);
   		 break;
   	 case ')':
   		 t=pop();
   		 while(t!='('){
   			 post[pos++]=t;
   			 t=pop();
   			 
   		 }
   		 break;
   	 case '+':
   	 case '-':
   	 case '*':
   	 case '/':
   	 case '^':
   	 
   		 while(prece(s)<=prece(stack[top])){
   			 t=pop();
   			 post[pos]=t;
   			 pos++;
   		 
   		 }
   		 push(s);
   		 break;
   	 
   	 default:
   		 post[pos]=s;
   		 pos++;
   		 break;    
   	 
   	 }
  	 index++;
    }
    while(top>=0){
   	 t=pop();
   	 post[pos]=t;
   	 pos++;
    }
    post[pos]='\0';
    puts(post);
    
    
}    
