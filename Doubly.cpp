#include<iostream>
using namespace std;

template <class T>
struct node 
{
  T data;
  struct node *next;
  struct node *prev;
};

template <class T>
class Doubly
{
	private:
	struct node<T> *head;
	int icnt;
	
	public:
	
	Doubly();
	
	void Display();
	int Count();
	void InsertFirst(T);
	void InsertLast(T);
	void DeleteFirst();
	void DeleteLast();
	void InsertAtPos(T,T);
	void DeleteAtPos(T);
};

template <class T>
Doubly<T>::Doubly()
{
	head=NULL;
	icnt=0;
	
}

template <class T>
void Doubly<T>::Display()
{
	struct node<T> *temp=NULL;
	temp=head;
	while(temp!=NULL)
	{
		cout<<" "<<(temp->data);
		temp=temp->next;
	}
	cout<<endl;
}

template<class T>
int Doubly<T>::Count()
{
	int icnt=0;
	struct node<T> *temp=NULL;
    temp=head;
	while(temp!=NULL)
	{
		icnt++;
		temp=temp->next;
	}
	return icnt;
}
	


template <class T>
void Doubly<T>::InsertFirst(T no)
{
	struct node<T> *newn=NULL;
	newn= new node<T>;
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
  if(head==NULL)
  {
	  head=newn;
  }
  else
  {
	  newn->next=head;
	  head->prev=newn;
	  head=newn;
  }
}


template <class T>
void Doubly<T>::InsertLast(T no)
{
   struct node<T> *newn=NULL;
   struct node<T> *temp=NULL;
	newn= new node<T>;
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
  if(head==NULL)
  {
	  head=newn;
  }
  else
  {
    temp= head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newn;
	newn->prev=temp;
  }
}


template <class T>
void Doubly<T>::DeleteFirst()
{
	if(head==NULL)
	{
		return;
	}
	
	if(head->next==NULL)
	{
		delete head;
		head=NULL;
	}
	else 
	{
		head=head->next;
		delete(head->prev);
		head->prev=NULL;
	}
}
	

template <class T>
void Doubly<T>::DeleteLast()
{
	struct node<T> *temp=NULL;
	if(head==NULL)
	{
		return;
	}
	
	if(head->next==NULL)
	{
		delete head;
		head=NULL;
	}
	else
	{
		temp=head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		delete (temp->next);
		temp->next=NULL;
	}
}


template <class T>
void Doubly<T>::InsertAtPos(T no,T pos)
{
	struct node<T> *temp=NULL;
	struct node<T> *newn=NULL;
	
	int size=0;
	size=Count();
	int i=0;
	
	if((pos<0)||(pos>size+1))
	{
		cout<<"INVALID POSITION";
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
	   newn= new node<T>;
      newn->data=no;
	  newn->next=NULL;
	  newn->prev=NULL;
	  
	  temp=head;
	  
	  for(i=1;i<pos-1;i++)
	  {
		  temp=temp->next;
	  }
	    newn->next=temp->next;
		temp->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
		
	}
}

template <class T>
void Doubly<T>::DeleteAtPos(T pos)
{
	struct node<T> *temp=NULL;
	int size=0,i=0;
	size=Count();
	
	if((pos<0)||(pos>size))
	{
		cout<<"INVALID POSITION";
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
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		delete temp->next->prev;
		temp->next->prev=temp;
	}
}

	
int main()
{
	Doubly<int>obj;
	Doubly<float> obj2;
	Doubly<char> obj3;
	
	int iret=0;
	
	cout<<"I_N_T_E_G_E_R"<<endl;
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
	 
	
	cout<<"F_L_O_A_T"<<endl;
	
	obj2.InsertFirst(11.12);
	obj2.InsertFirst(21.3);
	obj2.InsertFirst(51.3);
	obj2.InsertFirst(101.5);
	obj2.Display();
	iret=obj2.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj2.InsertLast(11.1);
	obj2.Display();
	iret=obj2.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj2.DeleteFirst();
	obj2.Display();
	iret=obj2.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj2.DeleteLast();
	obj2.Display();
	iret=obj2.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj2.InsertAtPos(12.7,3);
	obj2.Display();
	iret=obj2.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj2.DeleteAtPos(3);
    obj2.Display();
	iret=obj2.Count();
	cout<<"Count is : " <<iret<<endl;
     cout<<"\n";
	
	
	cout<<"C_H_A_R_A_C_T_E_R"<<endl;
	
	obj3.InsertFirst('K');
	obj3.InsertFirst('I');
	obj3.InsertFirst('T');
	obj3.InsertFirst('A');
	obj3.InsertFirst('R');
	obj3.InsertFirst('P');
	obj3.Display();
	iret=obj3.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj3.InsertLast('G');
	obj3.Display();
	iret=obj3.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj3.DeleteFirst();
	obj3.Display();
	iret=obj3.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj3.DeleteLast();
	obj3.Display();
	iret=obj3.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj3.InsertAtPos('P',1);
	obj3.InsertAtPos('T',7);
	obj3.Display();
	iret=obj3.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj3.DeleteAtPos(7);
    obj3.Display();
	iret=obj3.Count();
	cout<<"Count is : " <<iret<<endl;
     cout<<"\n";  
	 
	
	
	return 0;
}