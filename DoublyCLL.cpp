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
class DoublyCLL
{
	private:
	struct node<T> *head;
	struct node<T> *tail;
	
	public:
	DoublyCLL();
	
	void InsertFirst(T);
	void InsertLast(T);
	void Display();
	int Count();
	void DeleteFirst();
	void DeleteLast();
	void InsertAtPos(T,T);
	void DeleteAtPos(T);
};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
	
	head=NULL;
	tail=NULL;
}


template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
   struct node<T> *newn=NULL;
  newn= new node<T>;
  newn->data=no;
  newn->next=NULL;
  newn->prev=NULL;
  
  if((head==NULL)&&(tail==NULL))
  {
	  head=newn;
	  tail=newn;
  }
  else
  {
	  newn->next=head;
	  head->prev=newn;
	  head=newn;
  }
  tail->next=head;
  head->prev=tail;
}


template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
	 struct node<T> *newn=NULL;
  newn= new node<T>;
  newn->data=no;
  newn->next=NULL;
  newn->prev=NULL;
  
   if((head==NULL)&&(tail==NULL))
  {
	  head=newn;
	  tail=newn;
  }
  else
  {
   tail->next=newn;
   newn->prev= tail;
    tail=newn;
  }
  tail->next=head;
  head->prev=tail;
}


template <class T>
void DoublyCLL<T>::Display()
{
	struct node<T> *temp=NULL;
	temp=head;
	do
	{
		cout<<" "<<temp->data;
		temp=temp->next;
	}while(temp!=head);
	cout<<endl;
}

template <class T>
int DoublyCLL<T>::Count()
{
	struct node<T> *temp=NULL;
	temp=head;
	int icnt=0;
	do
	{
		icnt++;
		temp=temp->next;
	}while(temp!=head);
	cout<<endl;
	
	return icnt;
}
	
	
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
	if((head==NULL)&&(tail==NULL))
	{
		return;
	}
	
	if(head->next==NULL)
	{
		delete head;
		head=NULL;
		tail=NULL;
	}
	else
	{
     head=head->next;
     delete tail->next;  
	}
	tail->next=head;
	head->prev=tail;
}
	
	
template <class T>
void DoublyCLL<T>::DeleteLast()
{
	
	if((head==NULL)&&(tail==NULL))
	{
		return;
	}
	
	if(head->next==NULL)
	{
		delete head;
		head=NULL;
		tail=NULL;
	}
	else
	{
		tail=tail->prev;
	   delete tail->next;
	}
	tail->next=head;
	head->prev=tail;
}
	
	
	
template <class T>
void DoublyCLL<T>::InsertAtPos(T no,T pos)	
{
	struct node<T> *newn=NULL;
	struct node<T> *temp=NULL;
	int size=0,i=0;
	size=Count();
	
  if((pos<0)||(pos>size+1))
 {
	cout<<"invalid position";
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
	newn->prev=temp;
	temp->next=newn;
  }
}



template <class T>
void  DoublyCLL<T>::DeleteAtPos(T pos)
{
	struct node<T> *temp=NULL;
	int size=0,i=0;
	size=Count();
	
  if((pos<0)||(pos>size))
 {
	cout<<"invalid position";
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
	temp= head;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
   temp->next=temp->next->next;
   delete temp->next->prev;
   temp->next->next->prev=temp->next;
  }
}



int main()
{
   DoublyCLL<int>obj;
	DoublyCLL<float> obj2;
	DoublyCLL<char> obj3;
	
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