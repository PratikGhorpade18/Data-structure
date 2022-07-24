//SINGLY LINKED LIST WITH GENERIC FORM

#include<iostream>
using namespace std;

template <class T>
struct node
{
	T data;
	struct node *next;
};

template <class T>
class SinglyLL
{
	public :
	    struct node<T> *head;
		int Count;
		
		SinglyLL();
		void InsertFirst(T );
		void InsertLast(T );
		void Display();
		int Countnode();
		void DeleteFirst();
		void DeleteLast();
		void InsertAtPos(T,T);
		void DeleteAtPos(T);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
	head=NULL;
	Count=0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
	struct node<T> *newn=NULL;
	newn=new node<T>;
	newn->data=no;
	newn->next=NULL;
	
	if(head==NULL)
	{
		head= newn;
	}
	else
	{
		newn->next=head;
		head=newn;
	}
	Count++;
	
}
	
	
	template <class T>
void SinglyLL<T>::InsertLast(T no)
{
	struct node<T> *newn=NULL;
	newn=new node<T>;
	newn->data=no;
	newn->next=NULL;
	
	if(head==NULL)
	{
		head= newn;
	}
	else
	{
		struct node<T> *temp=head;
		
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
	Count++;
}
	
	
	template <class T>
	void SinglyLL<T>::Display()
	{
		cout<<"Elements from Linked List are:"<<endl;
		struct node<T> *temp=head;
		while(temp!=0)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}


template <class T>
	int SinglyLL<T>::Countnode()
	{
		
		return Count;
	}



template <class T>
void SinglyLL<T>::DeleteFirst()
{
   if(head==NULL)
   {
     return;
   }
   else 
   {
     	struct node<T> *temp=head;
        head=temp->next;
        delete temp;
   }
Count--;
}   
	
	
template <class T>
void SinglyLL<T>::DeleteLast()
{
   if(head==NULL)
   {
     return;
   }
   else if(head->next==NULL)
   {
	   delete head;
	   head=NULL;
   }
   else
   {
     	struct node<T> *temp=head;
        while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
        delete (temp->next);
		temp->next=NULL;
   }
Count--;
}   

template <class T>
void SinglyLL<T>::InsertAtPos(T no,T pos)
{
	int icnt;
	int size=Countnode();
	
	if((pos<0)||(pos>size+1))
	{
		cout<<"position invalid"<<endl;
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
	struct node<T>	*temp=head;
	struct node<T> *newn=NULL;
	newn =new node<T>;
	newn->data=no;
	newn->next=NULL;
	
	for(icnt=1;icnt<(pos-1);icnt++)
	{
		temp=temp->next;
	}
	newn->next=temp->next;
	temp->next=newn;
	}
	Count++;
}


template <class T>
void SinglyLL<T>::DeleteAtPos(T pos)
{
	int icnt;
	int size=Countnode();
	
	if((pos<0)||(pos>size))
	{
		cout<<"position invalid"<<endl;
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
	struct node<T>	*temp=head;
	struct node<T> *tempdelete=NULL;
	
	for(icnt=1;icnt<(pos-1);icnt++)
	{
		temp=temp->next;
	}
	tempdelete=temp->next;
	temp->next=temp->next->next;
	delete tempdelete;
	}
	Count--;
}



int main()
{
	SinglyLL<int>obj1;
	SinglyLL<float>obj2;
	SinglyLL<char>obj3;
	
	obj1.InsertFirst(11);
	obj1.InsertFirst(21);
	obj1.InsertFirst(51);
	obj1.InsertFirst(101);
	obj1.Display();
	cout<<"Number of nodes are:"<<obj1.Countnode()<<endl;
	
	obj1.InsertLast(1);
	obj1.Display();
	cout<<"Number of nodes are:"<<obj1.Countnode()<<endl;
	
	obj1.DeleteFirst();
	obj1.Display();
	cout<<"Number of nodes are:"<<obj1.Countnode()<<endl;
	
	obj1.DeleteLast();
	obj1.Display();
	cout<<"Number of nodes are:"<<obj1.Countnode()<<endl;
	
	obj1.InsertAtPos(18,3);
	obj1.Display();
	cout<<"Number of nodes are:"<<obj1.Countnode()<<endl;
	
	obj1.DeleteAtPos(3);
	obj1.Display();
	cout<<"Number of nodes are:"<<obj1.Countnode()<<endl;
	
	
	
	obj2.InsertFirst(11.12);
	obj2.InsertFirst(21.3);
	obj2.InsertFirst(51.3);
	obj2.InsertFirst(101.5);
	obj2.Display();
	cout<<"Number of nodes are:"<<obj2.Countnode()<<endl;
	
	obj2.InsertLast(1.8);
	obj2.Display();
	cout<<"Number of nodes are:"<<obj2.Countnode()<<endl;
	
	obj2.DeleteFirst();
	obj2.Display();
	cout<<"Number of nodes are:"<<obj2.Countnode()<<endl;
	
	obj2.DeleteLast();
	obj2.Display();
	cout<<"Number of nodes are:"<<obj2.Countnode()<<endl;
	
	obj2.InsertAtPos(18,3);
	obj2.Display();
	cout<<"Number of nodes are:"<<obj2.Countnode()<<endl;
	
	obj2.DeleteAtPos(3);
	obj2.Display();
	cout<<"Number of nodes are:"<<obj2.Countnode()<<endl;
	
	
	obj3.InsertFirst('T');
	obj3.InsertFirst('A');
	obj3.InsertFirst('R');
	obj3.InsertFirst('P');
	obj3.Display();
	cout<<"Number of nodes are:"<<obj3.Countnode()<<endl;
	
	obj3.InsertLast('K');
	obj3.Display();
	cout<<"Number of nodes are:"<<obj3.Countnode()<<endl;
	
	obj3.DeleteFirst();
	obj3.Display();
	cout<<"Number of nodes are:"<<obj3.Countnode()<<endl;
	
	obj3.DeleteLast();
	obj3.Display();
	cout<<"Number of nodes are:"<<obj3.Countnode()<<endl;
	
	obj3.InsertAtPos('D',3);
	obj3.Display();
	cout<<"Number of nodes are:"<<obj3.Countnode()<<endl;
	
	obj3.DeleteAtPos(3);
	obj3.Display();
	cout<<"Number of nodes are:"<<obj3.Countnode()<<endl;
	
	return 0;
}
