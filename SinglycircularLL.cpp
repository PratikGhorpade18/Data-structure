// PPA CHI PUNYAI (15 wasoolllllllll)

#include<iostream>
using namespace std;

struct node 
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


class SinglyCLL
{
	private:
	PNODE head;          // charactristics
	PNODE tail;
	int icnt;
	
	public:         	// behaviours
	SinglyCLL();
	
	void InsertFirst(int no);
	void InsertLast(int no);
	void InsertAtPos(int no,int ipos);
	void DeleteFirst();
	void DeleteLast();
    void DeleteAtPos(int ipos);
	void Display();
	int Count();	
};

SinglyCLL::SinglyCLL()
{
	head=NULL;
	tail=NULL;
	icnt=0;
}

    void SinglyCLL::InsertFirst(int no)
    {
		PNODE newn=NULL;
		
		newn= new NODE;
		
		newn->data=no;
		newn->next=NULL;
		
		if((head==NULL)&&(tail==NULL))   //LL empty
		{
			head=newn;
			tail=newn;
			
		}
		else    // if LL contains At least one node
		{
			
			newn->next=head;
			head=newn;
		}
		
      tail->next=head;
    }


	void SinglyCLL::InsertLast(int no)
	{
		PNODE newn=NULL;
		
		newn= new NODE;
		
		newn->data=no;
		newn->next=NULL;
		
		if((head==NULL)&&(tail==NULL))   //LL empty
		{
			head=newn;
			tail=newn;
			
		}
		else             // if LL contains At least one node
		{
			tail->next=newn;
            tail=newn;	
		}
      tail->next=head;
	}
	
	
	void SinglyCLL::InsertAtPos(int no,int pos)
	{
		int size=0;
		
		size=Count();
		
		
		if((pos<0)||(pos>size+1))
		{
			return;
		}
		
		if(pos==1)
		{
			InsertFirst(no);
		}
		else if(pos==size+1)
		{
			InsertLast(no);
		}
		else
		{
			PNODE temp=head;
			int icnt=0;
			PNODE newn=NULL;
		
	     	newn= new NODE;
		    newn->data=no;
		    newn->next=NULL;
		
			for(icnt=1;icnt<pos-1;icnt++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			temp->next=newn;
		
		}
	}
	
	
	void SinglyCLL::DeleteFirst()
	{	
		if((head==NULL)&&(tail==NULL))   //empty
		{
			return;
		}
		else if(head==tail)          // at least one
		{
			delete head;
			head=NULL;
			tail=NULL;
		}
		else                           //morer than one
		{
			
			head=head->next;
			delete tail->next;
			tail->next=head;
		}
	}
	
	
	void SinglyCLL::DeleteLast()
	{
		
		if((head==NULL)&&(tail==NULL))   //empty
		{
			return;
		}
		else if(head==tail)          // at least one
		{
			delete head;
			head=NULL;
			tail=NULL;
		}
		else                           //morer than one
		{
			PNODE temp=NULL;
			temp=head;
			
			while(temp->next!=tail)
			{
				temp=temp->next;
			}
			
          delete temp->next;
		  tail=temp;
		  tail->next=head;
		
		}
		
	}
	
	
    void SinglyCLL::DeleteAtPos(int pos)
	{
		int size=0;
		
		size=Count();
		int icnt=0;
		
		if((pos<0)||(pos>size))
		{
			return;
		}
		
		if(pos==1)
		{
			DeleteFirst();
		}
		else if(pos==size)
		{
			DeleteLast();
		}
		else
		{
			
			PNODE temp1=head;
			int icnt=0;
			
		   	for(icnt=1;icnt<pos-1;icnt++)
			{
				temp1=temp1->next;
			}
			
             PNODE temp2= temp1->next;
			temp1->next=temp2->next;
			delete temp2;
			
		}	
	}
	
	
	void SinglyCLL::Display()
	{
		PNODE temp=head;
		if((head==NULL)&&(tail==NULL))
		{
			
			return;
		}
		do
		{
		cout<<" "<<temp->data<<"|->";
		temp=temp->next;
		}while(temp!=head);
		
		cout<<endl;
		
	}
	
	
	int SinglyCLL::Count()
	{
		PNODE temp=NULL;
		int icnt=0;
		temp=head;
		
		if((head==NULL)&&(tail==NULL))
		{
			
			return 0;
		}
		do
		{
		icnt++;
		temp=temp->next;
		}while(temp!=head);
			
		
		return icnt;
	}
	
	
	
	
int main()
{
	SinglyCLL obj;
	int iret=0;
	
	obj.InsertFirst(101);
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.Display();
	iret=obj.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj.InsertLast(111);
	obj.Display();
	iret=obj.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj.DeleteFirst();
	obj.Display();
	iret=obj.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj.DeleteLast();
	obj.Display();
	iret=obj.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj.InsertAtPos(127,3);
	obj.Display();
	iret=obj.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj.DeleteAtPos(3);
    obj.Display();
	iret=obj.Count();
	cout<<"Count is : " <<iret<<endl;
     cout<<"\n";
	 
	
	return 0;
}