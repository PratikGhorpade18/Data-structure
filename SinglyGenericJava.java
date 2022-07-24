//SINGLY LINKED LIST WITH GENERIC FORM  In java
 
 
 import java.lang.*;
 import java.util.*;
 
 
 class node
 {
	public int data;
	public node next;   //struct node  *next;
 }
 
 class SinglyLL
 {
	public node head;
    public int Count;

    public SinglyLL()
     {
       head=null;
       Count =0;
	 }	   
	 
	 public void InsertFirst(int no)
	 {
		 node newn= new node();
		 newn.data=no;
		 newn.next=null;
		 
		 if(head==null)
		 {
			 head=newn;
		 }
		 else
		 {
			 newn.next=head;
			 head=newn;
		 }
		 Count++;
	 }
		
		
		public void InsertLast(int no)
    {
        node newn = new node();

        newn.data = no;
        newn.next = null;

        if(head == null)
        {
            head = newn;
        }
        else
        {
            node temp = head;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        Count++;
    }
		
		
		public void DeleteFirst()
		{
			if(head==null)
			{
				return;
			}
			else if(Count==1)
			{
				head=null;
			}
			else
			{
				node temp= head;
				head=temp.next;
				temp=null;
			}
			Count--;
		}
		
		
		
		public void DeleteLast()
		{
			if(head==null)
			{
				return;
			}
			else if(Count==1)
			{
				head=null;
			}
			else
			{
				node temp= head;
				while(temp.next.next!=null)
				{
					temp=temp.next;
				}
				
				temp.next=null;
				
			}
			Count--;
		}
		
	
	
public void InsertAtPos(int no,int pos)
{
	if((pos<1)||(pos>Count+1))
	{
		return;
	}
	
	if(pos==1)
	{
		InsertFirst(no);
	}
	else if(pos==(Count+1))
	{
		InsertLast(no);
	}
	else
	{
		node temp=head;
		 node newn= new node();
		 newn.data=no;
		 newn.next=null;
		for(int i=0;i<pos-1;i++)
		{
			temp=temp.next;
		}
		newn.next=temp.next;
		temp.next=newn;
		
	}
	Count++;
}


/*public void DeleteAtPos(int pos)
{
	if((pos<1)||(pos>Count))
	{
		return;
	}
	
	if(pos==1)
	{
		DeleteFirst();
	}
	else if(pos==(Count))
	{
		DeleteLast();
	}
	else
	{
		node temp=head;
		
		for(int i=0;i<pos-1;i++)
		{
			temp=temp.next;
		}
		
		temp.next=temp.next.next;
		
	}
	Count--;
}*/
public void DeleteAtPos(int pos)
	{
		if((pos<1)||(pos>Count))
		{
			return;
		}
		
		if(pos==1)
		{
			DeleteFirst();
		}
		else if(pos==Count)
		{
			DeleteLast();
		}
		else
		{
			node temp=head;
			
			for(int i=1;i<pos-1;i++)
			{
				temp=temp.next;
			}
			
			temp.next=temp.next.next;
			
			
			
			
		}
		Count--;
	}


    public void Display()
	{
      node temp= head;
      System.out.println("Elements in Linked List are:");
	  while(temp!=null)
	  {
		  System.out.print(" "+temp.data+" ");
		  temp=temp.next;
	  }
	      System.out.println(" NULL ");
		
	}

	public int Countnode()
	{
		return Count;
	}
	
}
 
 
 
 
 
 class program222
 {
	 public static void main(String a[])
	 {
	   SinglyLL obj=new SinglyLL();	
      
	  obj.InsertFirst(51);
	  obj.InsertFirst(21);
	  obj.InsertFirst(11);

	   obj.InsertLast(101);
	   obj.InsertLast(111);
	 
	 obj.Display();
	 System.out.println("number of elements are: "+obj.Countnode());
	 
	 obj.DeleteFirst();
	 obj.DeleteLast();
	 obj.Display();
	 System.out.println("number of elements are: "+obj.Countnode());
	 
	 obj.InsertAtPos(55,4);
	 obj.Display();
	 System.out.println("number of elements are: "+obj.Countnode());
	 
	 obj.DeleteAtPos(4);
	 obj.Display();
	 System.out.println("number of elements are: "+obj.Countnode());
	 
	 
	 }
	 
 }