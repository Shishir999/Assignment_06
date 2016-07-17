#include<stdio.h>
#include<stdlib.h>
struct queue {
	int data;
	struct queue *next;
}*newnode,*temp,*all;

typedef struct queue nodetype;
nodetype *rear=NULL;
nodetype *front=NULL;

/* Functions Involved */
int insert(int);
int delet();
int display();
int queue_count();
int count=0;
//Main function
int main()
{
	int choice,n;
	while(1)
	{
			printf("\n1. Insert\n2. Delete\n3. Display\n4. Count\n5. Exit"); //main menu display
			printf("\nEnter your choice");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1: printf("Enter data : ");
        				scanf("%d", &n);
            			insert(n);
						break;
				case 2: delet();
						break;
				case 3: display();
						break;
					case 4: queue_count();
							break;
				case 5: exit(1);
				default : printf("Wrong entry please enter correct choice !!! ");
						break;
			}
	}
}
// function to insert the element in queue
int insert(int n)
{
	if(rear==NULL)
	{
		newnode=(nodetype*)malloc(sizeof(nodetype));   
		newnode->data=n;
		newnode->next=NULL;
		rear=newnode;
		front=newnode;
	}
	else
	{
			newnode=(nodetype*)malloc(sizeof(nodetype));
			newnode->data=n;
			//rear->next=newnode;
			newnode->next=NULL;
			front->next=newnode;
			rear=newnode;
	}
	count++;
}
// function to delete element in queue
int delet()
{
	if (front==NULL)
	{
		printf("The queue list is empty");
	}
	else if(front->next=NULL)
	{
		temp=front;
		rear=NULL;
		front=NULL;
		printf("\nDeleted element is %d",temp->data);
		free(temp);
		
	}
	else
	{
		temp=front;
		front=front->next;
		printf("\nDeleted intem is %d",temp->data);
		free(temp);
	}
	count--;
}
// function to display the elements of the queue
int display()
{
	all=front;
	if(all==NULL)
	{
		printf("The queue list is empty \n");
	}
	while(all!=NULL)
	{
			printf("\t\t%d",all->data);
			all=all->next;
	}
}
// function to count the element is queue
int queue_count()
{
	printf("Total count in queue is %d ",count);
}
