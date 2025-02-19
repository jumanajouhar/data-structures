#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
}*front=NULL,*rear ,*temp,*p;
void enqueue(int);
void dequeue();
void display();
void main()
{
	int n=0;
	int item;
	while(n!=4)
	{
		printf("Enter your choice:\n1:enqueue\n2:dequeue\n3:display\n4:Exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter the item\n");
				scanf("%d",&item);
			    enqueue(item);
			    display();
				break;
			case 2:
			    dequeue();
			    display();
				break;
			case 3:
			    display();
				break;
			case 4:
				exit(0);
			default:
				printf("invalid choice\n");
								
		}
		
		
	}
	
}
void enqueue(int item)
{
	temp=(struct node *)malloc(sizeof(struct node));
	if (front==NULL)
	{
		temp->link=NULL;
		front=temp;
			temp->data=item;
	}
	else
	{
		rear=front;
		while(rear->link!=0)
		{ 
			rear=rear->link;
		}
		rear->link=temp;
		temp->data=item;
		temp->link=NULL;
}

}
void dequeue()
{
	if(front==NULL)
	{
		printf("Deletion not possible\n");
	}
	else
	{
		temp=front;
		if(front->link==NULL)
		{
			front=NULL;
		}
		else
		{
			front=front->link;	
		}
		printf("Deleted element is %d\n",temp->data);
		free(temp);
	}
}
void display()
{
	if(front==NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		p=front;
		printf("the elements are\n");
		while(p!=NULL)
		{
			printf("%d\n",p->data);
			p=p->link;
		}
		
	}
}