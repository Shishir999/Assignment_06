#include <stdio.h>
#include <stdlib.h>
/* Structure formation*/

struct circular{
	int data;
	struct circular *next;
}*newnode,*temp,*top1;

typedef struct circular NodeType;
NodeType *head=NULL;
NodeType *tail=NULL;

/* Functions involved*/
void insert_start(int);
void insert_end(int);
void disp();
void delete_start();
void delete_end();
void link_count();
int count=0;

/* Main Function of program*/
int main()
{
	int choice,n;
	while(1){
		printf("\n1. Insert at beginning\n2. Insert at end\n3. Display items\n4. Delete from beginning\n5. Delete from end\n6. Count total items\n7. Exit");  // Main Menu
		printf("\n\nEnter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : 
				printf("Enter the data to insert : ");
				scanf("%d",&n);
				insert_start(n);
				break;
			case 2 : 
				printf("Enter the data to insert : ");
				scanf("%d",&n);
				insert_end(n);
				break;
			case 3:	 
				disp();
				break;
			case 4 : delete_start();
					 break;
			case 5 : delete_end();
					 break;
			case 6 : link_count();
					 break;
			case 7 : 
				exit(1);
			default : 
				printf("Wrong entry please enter correct choice !!! ");
				break;
		}	
	}
	return 0;
}	

void insert_start(int n){
	if(head==NULL){           //If the list is empty folowing prcedure will take place
		newnode=(NodeType*)malloc(sizeof(NodeType)); //createing new node
		newnode->next=newnode;			//pointing created node with itself
		newnode->data=n;						//inserting data to created node
		head=newnode;				// assigning head as newnode
		tail=newnode;				// assigning tail as newnode
	}
	else{					//this procedure occur if the list is already filled with some value
		temp=(NodeType*)malloc(sizeof(NodeType));  //createing new node
		temp->data=n; 								//adding data to new node
		temp->next=head;						//pointing created node next with head present in list
		head=temp;
		tail->next=head;				// assigining created newnode as head
	} 
	count++;
}
void insert_end(int n)
{
	if(head==NULL)
	{
		newnode=(NodeType*)malloc(sizeof(NodeType)); //createing new node
		newnode->next=newnode;			//pointing created node with itself
		newnode->data=n;						//inserting data to created node
		head=newnode;				// assigning head as newnode
		tail=newnode;				// assigning tail as newnode
	}
	else
	{
		temp=(NodeType*)malloc(sizeof(NodeType));
		temp->data=n;
		tail->next=temp;
		temp->next=head;
		tail=temp;
	}
	count++;
}
void delete_start()
{
	if(head==NULL)
	{
		printf("\t\tThe list is empty");
	}
//	else if(head->next=NULL)
//	{
//		temp=head;
//		head=NULL;
//		tail=NULL;
//		printf("The deleted data is %d",temp->data);
//		free(temp);
//	}
	if(head!=NULL)
	{
	temp=head;
	head=head->next;
	tail->next=head;
	printf("The deleted data is %d",temp->data);
	free(temp);
	}
	
	count--;
}
void delete_end()
{
	if(head==NULL)
	{
		printf("\t\tThe list is empty")	;
	}
	else if(head==tail)
	{
		temp=head;
		printf("\t\tDeleted item is %d",temp->data);
		free(temp);
		head=NULL;
		tail=NULL;
	}
 else {
		temp=head;
	{
		while(head->next!=tail)
		temp=temp->next;
	}
		top1=temp->next;
		tail=temp;
		tail->next=head;
		printf("The deleted data is %d",top1->data);
		free(top1);
		
 }
 count--;
}
void disp(){
	top1=head;
	if(top1==NULL)
	{
		printf("The list is empty \n");
	}
	else
	{
			printf("%d-->",top1->data );
    		top1=top1->next;
		while(top1!=head)
		{
			printf("%d-->",top1->data);
			top1=top1->next;
	}
	}
	
}
void link_count()
{
	printf("Total items in list is %d ",count);
}
