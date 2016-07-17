#include<stdio.h>
#include<stdlib.h>
struct stacklink{
	int data;
	struct stacklink *nnode;
}*top,*top1,*temp;

int push(int);
int pop();
int disp();
int create();
int total_count();

int count =0;

int main()
{
	int choice,n;
	printf("\n1. Push\n2. Pop\n3. Display\n4.Count\n5.Exit");
	while (1)
    {
	printf("\nEnter your choice ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("Enter data : ");
        		scanf("%d", &n);
            	push(n);
				break;
		case 2: pop();
				break;
		case 3: disp();
				break;
		case 4: total_count();
				break;
		case 5: exit(1);
		default : printf("Wrong entry please enter correct choice !!! ");
				break;
		}
	}
}
int push(int n)
{
	if(top==NULL)
	{
		top=(struct stacklink*)malloc(sizeof(struct stacklink));
		top->data=n;
		top->nnode=top;
	}
	else
		{
			temp=(struct stacklink*)malloc(sizeof(struct stacklink));
			temp->data=n;
			top->nnode=temp;
			temp->nnode=top;
			top=temp;
			
		}
		count++;
}

int pop()
{
	top1=top;
	if(top1==NULL)
	{
		printf("The stack is empty");
		
	}
	else
	{
		top1=top1->nnode;
		printf("The popped value is %d",top->data);
		free(top);
		top=top1;
		count--;
	}
}
int disp()
{
	top1=top;
	if(top1==NULL)
	{
		printf("The stack is empty");
	}
	while(top1!=NULL)
	{
			printf("\t\t%d",top1->data);
			top1=top1->nnode;
	}
	
}
//int create()
//{
//    top = NULL;
//}
int total_count()
{
	printf("Total number of elements in the stack is %d",count);
}

