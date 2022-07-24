// ADDITION OF DIGITS OF NUMBERS IN LL
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


void SumDigit(PNODE head)
{
	int iAns=0;
	int iCnt=0;
	int idig=0;
	int isum=0;
	int iNo=0;
	while(head!=NULL)
	{
		iNo=(head)->data;
		while(iNo!=0)
		{
			
			idig=iNo%10;
			isum=isum+idig;
			iNo=iNo/10;	
			
		}
		printf("%d ",isum);
		isum=0;
		head=head->next;
		
	}

		
	
		

	
}

int main()
{
	int iRet=0;
	PNODE first=NULL;
	
	InsertFirst(&first,640);
	InsertFirst(&first,240);
	InsertFirst(&first,20);
	InsertFirst(&first,230);
	InsertFirst(&first,110);
	
	
	SumDigit(first);
	
	return 0;
}

