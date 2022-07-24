#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE head,int no )
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
		newn->next= *head;
		*head=newn;
	}
}


void  InsertLast(PPNODE head,int no)
{
 PNODE temp=NULL;	
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
	 temp= *head;
	 while(temp->next!=NULL)
	 {
	  temp=temp->next;
	 }
	temp->next=newn;
 }

}

void Display(PNODE head)
{
	printf("\nElements in LL are ");
	while(head!=NULL)
	{
		printf(" %d ",head->data);
	    head=head->next;
	}
	
}


int Count(PNODE head)
{
	int icnt=0;
	while(head!=NULL)
	{
		icnt++;
		head=head->next;
	}
  return icnt;
}

void DeleteFirst(PPNODE head)
{
	PNODE temp=NULL;
	
	if(*head==NULL)
	{
		return;
	}
	else
	{
	temp= *head;
	*head=temp->next;
	free(temp);
	}
}
	

void DeleteLast(PPNODE head)
{
	PNODE temp=NULL;
	
	if(*head==NULL)
	{
		return;
	}
	else if((*head)->next==NULL)
	{
		free(*head);
		*head=NULL;
	}
	else 
	{
		temp= *head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
}
	
	
void InsertAtPos(PPNODE head,int no,int pos)
{
	PNODE newn=NULL;
	PNODE temp=NULL;
	int size=0, icnt=0;
	
	size=Count(*head);
	
	if((pos<1)||(pos>size+1))
	{
		printf("\ninvalid position");
		return;
	}
	
	if(pos==1)
	{
		InsertFirst(head,no);
	}
	else if(pos==size+1)
	{
		InsertLast(head,no);
	}
	else
	{
		newn=(PNODE)malloc(sizeof(NODE));
		
		newn->data=no;
		newn->next=NULL;
		
		temp= *head;
		for(icnt=1;icnt<pos-1;icnt++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
		
	}
}


void DeleteAtPos(PPNODE head,int pos)
{
	PNODE temp=NULL;
	PNODE tempdelete=NULL;
	int size=0,icnt=0;
	size=Count(*head);
	if((pos<1)||(pos>size))
	{
		printf("\ninvalid position");
		return;
	}
	
	if(pos==1)
	{
		DeleteFirst(head);
	}
	else if(pos==size)
	{
		DeleteLast(head);
	}
	else
	{
		temp= *head;
		for(icnt=1;icnt<(pos-1);icnt++)
		{
			temp=temp->next;
		}
		tempdelete=temp->next;
		temp->next=temp->next->next;
		free(tempdelete);
	}
}  
	
	

int main()
{
 PNODE first=NULL;
 int iret=0;
 
 InsertFirst(&first,111);
 InsertFirst(&first,101);
 InsertFirst(&first,51);
 InsertFirst(&first,21);
 InsertFirst(&first,11);
 

Display(first);
iret=Count(first);
printf("\nNumber of Elements in LL are: %d\n",iret);


InsertLast(&first,1);
Display(first);
iret=Count(first);
printf("\nNumber of Elements in LL are: %d\n",iret);



DeleteFirst(&first);
Display(first);
iret=Count(first);
printf("\nNumber of Elements in LL are: %d\n",iret);



DeleteLast(&first);
Display(first);
iret=Count(first);
printf("\nNumber of Elements in LL are: %d\n",iret);


InsertAtPos(&first,18,2);
Display(first);
iret=Count(first);
printf("\nNumber of Elements in LL are: %d\n",iret);


DeleteAtPos(&first,2);
Display(first);
iret=Count(first);
printf("\nNumber of Elements in LL are: %d\n",iret);

return 0;
}