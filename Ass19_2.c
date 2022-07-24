/// LAST OCCURANCE IN LINKED LIST

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


int LastOcc(PNODE head,int no)
{
	int iCnt=0;
	int iCount=0;
	while(head!=NULL)
	{
		iCnt++;
		if((head->data)==no)
		{
			iCount=iCnt;
		}
		head=head->next;
		
	}
	return iCount;
}


int main()
{
	int iRet=0;
	PNODE first=NULL;
	
	
	InsertFirst(&first,70);
	InsertFirst(&first,30);
	InsertFirst(&first,50);
	InsertFirst(&first,40);
	InsertFirst(&first,30);
	InsertFirst(&first,20);
	InsertFirst(&first,10);
	
		
	iRet=LastOcc(first,30);
	printf("Element found at position no :%d",iRet);
	
	
	return 0;
}

