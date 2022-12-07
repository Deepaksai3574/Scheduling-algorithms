import java.util.Scanner;

class Node{
	Node prev;
	int data;
	Node next;
	Node()
	{
		prev = null;
		data = 0;
		next= null;
	}
		Node(int x)
		{
			prev = null;
			data = x;
			next = null;
		}
	}
class DLLapp
{
	Node head;
	DLLapp(){
	    head = new Node();
		head = null;
	}
	void insertfront(int x)
	{
		if(head == null) {
			head = new Node(x);
		}
		else
		{
			Node temp = new Node(x);
			temp.next = head;
			head.prev = temp;
			head = temp;		
			
		}
	}
	void insertlast(int x)
	{
		if(head == null)
			head = new Node(x);
		else
		{
		Node temp = head;
		while(temp.next!= null) {
			temp = temp.next;
			
		}
		   Node t = new Node(x);
			temp.next = t;
			t.prev = temp;
		}
	}
	void display()
	{
		Node temp = head;
		while(temp != null){
		System.out.println(temp.data);
		temp = temp.next;}
	}
	void reverse_display()
	{
		Node temp=head;
		while(temp.next!=null){
		    temp=temp.next;
		}
		while(temp.prev!=null){
			 System.out.println(temp.data); 
		   temp=temp.prev;
		   System.out.println(temp.data);
		}
		
	}
	void deletefront() 
	{
	    if (head==null) {
		    System.out.println(" LIST IS EMPTY");
		    return;
		    }
		    head= head.next;
	}
	void deletelast()
	{
		if (head==null)
		    System.out.println(" LIST IS EMPTY");
		else if(head.next==null)
		    head=null;
		    else
		    {Node p=head,temp=head;
		    while(temp.next!=null)
		    {p=temp;
		    temp=temp.next;}
		    p.next=null;
		    }
	}
	void Insertmid(int x)
	{
		if(head == null)
    		head = new Node(x);
    	else
    	{
    		Node temp = new Node(x);
    		Node ptr = head;
    		int len = 0;
    		while(ptr!=null)
    		{
    			len++;
    			ptr = ptr.next;
    		}
    		int count = ((len%2)==0)?(len/2):
    			(len+1)/2;
    		ptr = head;
    		int i=0;
    		while(i!=count) {
    			temp.next = ptr.next;
    		temp.prev = ptr;
    		ptr.next.prev = temp;
    		ptr.next = temp;
    		}
    	}
    }
	}
	public class DLL{

		 

	    public static void main(String[] args) {
	        
	        DLLapp D1= new DLLapp();
	        Scanner sc = new Scanner(System.in);
	        int choice = 0;
	        while (choice!= 8) {
	        System.out.println("1.insertfront 2.insertlast 3. deletefront 4.deletelast 5.Insertmid 6.reverse_display 7.display 8.end");
	        choice = sc.nextInt();
	        switch(choice)
	        {
	        case 1: System.out.println("enter the element to insert front");
	        D1.insertfront(sc.nextInt()); break;
	        case 2: System.out.println("Enter the element to insert back");
	        D1.insertlast(sc.nextInt());break;
	        case 3:D1.deletefront();break;
	        case 4:D1.deletelast();break;
	        case 5:System.out.println("Enter the element to add in middle of array");D1.Insertmid(sc.nextInt());break;
	        case 6: System.out.println("The reverse display of the elements "); D1.reverse_display();
	        break;
	        case 7: D1.display();
	        break;
	        
	        case 8: break;
	        }
	        }

	    }

	 

	}
