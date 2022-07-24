// FIND PRIME NUMBERS FROM LL
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


void DisplayPrime(PNODE head)
{
	int iAns=0;
	int iCnt=0;
	while(head!=NULL)
	{
		for(iCnt=2;iCnt<=((head)->data)/2;iCnt++)
		{
			if((head)->data%iCnt==0)
			{
				
				break;	
			}	
			
		}
		if(head->data%iCnt!=0)
		{
		printf("%d ",head->data);
	}
		
		head=head->next;
	}
		
	
	
}

int main()
{
	int iRet=0;
	PNODE first=NULL;
	
	InsertFirst(&first,89);
	InsertFirst(&first,22);
	InsertFirst(&first,41);
	InsertFirst(&first,17);
	InsertFirst(&first,20);
	InsertFirst(&first,11);
	
	
	DisplayPrime(first);
	
	return 0;
}

