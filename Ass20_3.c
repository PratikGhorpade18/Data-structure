//ADDITION OF EVEN ELEMENTS FROM LL
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


void EvenSum(PNODE head)
{
	int iAns=0;
	int iCnt=0;
	while(head!=NULL)
	{
	
			if((head)->data%2==0)
			{
				iAns=iAns+(head)->data;	
			
			}	
			
		
		head=(head)->next;
		
	}
	printf("%d",iAns);
		
		
	
	
}

int main()
{
	int iRet=0;
	PNODE first=NULL;
	
	
	InsertFirst(&first,41);
	InsertFirst(&first,32);
	InsertFirst(&first,20);
	InsertFirst(&first,11);
	
	
	EvenSum(first);
	
	return 0;
}

