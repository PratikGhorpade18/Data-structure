//return second largest number from LL

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE head,int no)
{
	PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	
	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		newn->next=*head;
		*head=newn;
	}
}


void SecMax(PNODE head)
{
	int iAns=0;
	int iMax=(head)->data;
	int SecMax=(head)->next->data;
	
	while(head!=NULL)
	{
		if(iMax<(head)->data)
		{
			SecMax=iMax;
			iMax=(head)->data;
		}
		
		head=head->next;
	}
	printf("%d",SecMax);
	
		
		
	
	
}

int main()
{
	int iRet=0;
	PNODE first=NULL;
	
	
	InsertFirst(&first,41);
	InsertFirst(&first,32);
	InsertFirst(&first,20);
	InsertFirst(&first,11);
	
	
	SecMax(first);
	
	return 0;
}

