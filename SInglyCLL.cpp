 #include<iostream>
 using namespace std;

template <class T>
struct node
{
	T data;
	struct node *next;
};

template <class T>
class Singlycll
{
	private:
	  struct node <T> *head;
	  struct node<T> *tail;
	  int icnt;
	  
	  public:
	   Singlycll();
	   
	   void InsertFirst(T );
	   void InsertLast(T );
	   void DeleteFirst();
	   void DeleteLast();
	   void Display();
	   int Count();
	   void InsertAtPos(T,T );
	   void DeleteAtPos(T );
	   
};

template <class T>
Singlycll<T>::Singlycll()
{
	head=NULL;
	tail=NULL;
	icnt=0;
}

template <class T>
void Singlycll<T>::InsertFirst(T no)
{
	struct node<T> *newn=NULL;
	newn= new  node<T>;
    newn->data=no;
    newn->next=NULL;
   
   if((head==NULL)&&(tail==NULL))
   {
	   head=newn;
	   tail=head;
   }
   else{
	    newn->next=head;
		head=newn;
   }
   tail->next=head;
	   
}

template <class T>
void Singlycll<T>:: InsertLast(T no)
{
	struct node<T> *newn=NULL;
	newn= new node<T>;
	newn->data=no;
	newn->next=NULL;
	
	if((head==NULL)&&(tail==NULL))
	{
		head=newn;
		tail=newn;
	}
	else
	{
		tail->next=newn;
		tail=newn;
	}
	tail->next=head;
}
	
	
	template <class T>
	void Singlycll<T>:: DeleteFirst()
	{
		if((head==NULL)&&(tail==NULL))
		{
			return;
		}
		else if(head==tail)
		{
			delete head;
			head==NULL;
			tail==NULL;
		}
		else
		{
		    
			head=head->next; 
			delete tail->next;
			tail->next=head;
		}
		
	}
	
	template <class T>
	void Singlycll<T>::DeleteLast()
	{
		if((head==NULL)&&(tail==NULL))
		{
			return;
		}
		else if(head==tail)
		{
			delete head;
			head==NULL;
			tail==NULL;
		}
		else
		{
			struct node<T> *temp=head;
			while(temp->next!=tail)
			{
				temp=temp->next;
			}
			delete temp->next;
			tail=temp;
			tail->next=head;
		}
	}
	
	
	template <class T>
void Singlycll<T>::Display()
{
	struct node<T> *temp=head;
	do 
	{
		cout<<" "<<(temp->data);
		temp=temp->next;
	}while(temp!=head);
		
	cout<<endl;
}
	
	template <class T>
	int Singlycll<T>::Count()
	{
		struct node<T> *temp=head;
	  int icnt=0;	
	do{
		icnt++;
		temp=temp->next;
	}while(temp!=head);
		
	return icnt;
		
	}
	
	
	template <class T>
	void Singlycll<T>::InsertAtPos(T no,T pos)
	{
		int i=0;
		int size=0;
		size=Count();
		if((pos<0)&&(pos>size+1))
		{
			cout<<"INVALID";
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
			struct node<T> *temp=head;
		struct node<T> *newn=NULL;
		newn= new node<T>;
		newn->data=no;
		newn->next=NULL;
		
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
		}
	}
		
		template <class T>
	void Singlycll<T>::DeleteAtPos(T pos)
	{
		int i=0;
		int size=0;
		size=Count();
		if((pos<0)&&(pos>size))
		{
			cout<<"INVALID";
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
			int i=0;
			struct node<T> *temp=head;
			
			
			for(i=1;i<pos-1;i++)
			{
				temp=temp->next;
			}
			struct node<T> *temp2= temp->next;
			temp->next=temp2->next;
			delete(temp2);
		}
	}
			
			
		
int main()
{
	
	
	
	Singlycll<int> obj;
	Singlycll<float> obj2;
	Singlycll<char> obj3;
	
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
	obj3.InsertAtPos('T',6);
	obj3.Display();
	iret=obj3.Count();
	cout<<"Count is : " <<iret<<endl;
	cout<<"\n";
	
	
	obj3.DeleteAtPos(6);
    obj3.Display();
	iret=obj3.Count();
	cout<<"Count is : " <<iret<<endl;
     cout<<"\n";
	 
	 
	return 0;
}
	