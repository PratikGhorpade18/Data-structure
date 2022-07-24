/// MAXIMUM NUMBER FROM LINKED LIST

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


int Max(PNODE head)
{
	int iMax=0;
	iMax=head->data;
	
	while(head!=NULL)
	{
		if((head->data)>iMax)
		{
			iMax=head->data;
		}
		head=head->next;
	}
	return iMax;
}

int main()
{
	int iRet=0;
	PNODE first=NULL;
	
	
	InsertFirst(&first,240);
	InsertFirst(&first,320);
	InsertFirst(&first,230);
	InsertFirst(&first,110);
	
	
	iRet=Max(first);
	printf("Max no  is %d",iRet);
	
	return 0;
}

