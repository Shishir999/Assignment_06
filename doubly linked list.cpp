#include<stdio.h>
#include<stdlib.h>
// creating structure
struct doubly{
	int data;
	struct doubly *next;
	struct doubly *prev;
}*newnode,*temp,*temp1,*all;
typedef struct doubly NodeType;
NodeType *head=NULL;
NodeType *tail=NULL;

//functions declaration
void insert_beg(int);
void insert_end(int);
void del_beg();
void del_end();
void link_count();
void display();

int count=0;

//Main function
int main()
{
	int choice,n;
	while(1)
	{
		printf("\n1. Insert at beginning\n2. Insert at End\n3. Delete from beginning\n4. Delete from End\n5. Display total\n6. Count elements\n7. Exit");
		printf("\nEnter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1 : printf("Enter data : ");
        		scanf("%d", &n);
            	insert_beg(n);
				break;
		case 2 : printf("Enter data : ");
        		scanf("%d", &n);
            	insert_end(n);
				break;
		case 3: del_beg();
				break;
		case 4: del_end();
				break;
		case 5 : display();
				break;
		case 6: link_count();
				break;
		case 7: exit(1);
		default : printf("Wrong entry please enter correct choice !!! ");
				break;
		}
	}
}
void insert_beg(int n)
{
	if(head==NULL)
	{
		newnode=(NodeType*)malloc(sizeof(NodeType));
		newnode->data=n;
		newnode->next=NULL;
		newnode->prev=NULL;
		head=newnode;
		tail=newnode;
	}
	else
	{
		newnode=(NodeType*)malloc(sizeof(NodeType));
		newnode->data=n;
		newnode->next=head;
		newnode->prev=NULL;
		head->next=NULL;
		head->prev=newnode;
		tail=head;
		head=newnode;
	}
	count++;
}
void insert_end(int n)
{
	if(head=NULL)
	{
			newnode=(NodeType*)malloc(sizeof(NodeType));
			newnode->data=n;
			newnode->next=NULL;
			newnode->prev=NULL;
			head=newnode;
			tail=newnode;
	}
	else
	{
			newnode=(NodeType*)malloc(sizeof(NodeType));
			newnode->data=n;
			newnode->next=NULL;
			newnode->prev=tail;
			tail->next=newnode;
			tail=newnode;
	}
	count++;
}
void del_beg()
{
	if (head==NULL)
	{
		printf("List is empty");
	}
	else if(head->next==NULL)
	{
		temp=head;
		head=NULL;
		printf("Deleted item is %d ",temp->data );
		free(temp);
	}	
	if(head!=NULL)
	{
		temp=head;
		temp1=head->next;
		head=temp1;
		temp1->prev=NULL;
		printf("Deleted item is %d ",temp->data );
		free(temp);	
	}
	count--;
}
void del_end()
{
	if(head==NULL)
	{
		printf("The list is empty");
	}
	else if(head->next=NULL)
	{
		temp=head;
		head=NULL;
		printf("Deleted item is %d ",temp->data );
		free(temp);
	}
	if(head!=NULL)
	{
		temp=tail;
		temp1=tail->prev;
		tail=temp1;
		temp1->next=NULL;
		printf("Deleted item is %d ",temp->data );
		free(temp);	
	
	}
	count--;
}
void display()
{
	all=head;
	if(all==NULL)
	{
		printf("\t\tThe list is empty \n");
	}
	else
	{
			printf("\t\t%d",all->data);
			all=all->next;
		while(all!=head)
			{
				printf("\t\t%d",all->data);
				all=all->next;
			}
	}
	
}
void link_count()
{
	printf("Total item in list is %d",count);
}
