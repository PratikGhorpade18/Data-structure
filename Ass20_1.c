// DISPLAY ALL ELEMENT WHICH ARE PERFECT NUMBER IN LL

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


int DisplayPerfect(PNODE head)
{
	int iAns=0;
	int iCnt=0;
	int temp=0;
	
	while(head!=NULL)
	{
		temp=head->data;
		for(iCnt=1;iCnt<=((head)->data)/2;iCnt++)
		{
			if((head)->data%iCnt==0)
			{
				iAns=iAns+iCnt;			
			}
			
		}
		
		if(temp==iAns)
		{
			printf("%d ",temp);
		}
		iAns=0;
	

		head=head->next;
	}

	
}

int main()
{
	int iRet=0;
	PNODE first=NULL;
	
	InsertFirst(&first,89);
	InsertFirst(&first,6);
	InsertFirst(&first,17);
	InsertFirst(&first,28);
	InsertFirst(&first,11);
	
	
	DisplayPerfect(first);
	
	return 0;
}

