import java.util.Scanner;

class Nodes
{ int data;
  Nodes next;
  Nodes()
  {data = 0;
   next = null;
  } 
   Nodes(int a)
   { data= a;
      next = null;
   }
    
}

 

class SLLp
{  Nodes head = null;

 

   SLLp()
   {
       head= null;
   }
   SLLp(int a)
   {
       head= new Nodes(a);
   }
    void insertfront(int x)
    {
        if (head==null)
        { head = new Nodes(x);
        }
        else
        { Nodes temp=new Nodes(x);
             temp.next= head;
             head = temp;
        }
            
    
    }
    void insertback(int x)
    {
        Nodes temp = head;
        while (temp.next!=null)
        { temp = temp.next;
        }
        Nodes t1= new Nodes(x);
        temp.next = t1;
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
    { if (head==null)
    System.out.println(" LIST IS EMPTY");
    else if(head.next==null)
    head=null;
    else
    {Nodes p=head,temp=head;
    while(temp.next!=null)
    {p=temp;
    temp=temp.next;}
    p.next=null;
    }
    }
    int search(int x)
    {
    return 0;
    }
    void display()
    {
        Nodes temp = head;
        while (temp!=null)
        {System.out.println(temp.data);
          temp = temp.next;
        }
                
        
    }
    void insertmid(int x)
    {
    	if(head == null)
    		head = new Nodes(x);
    	else
    	{
    		Nodes temp = new Nodes(x);
    		Nodes ptr = head;
    		int len = 0;
    		while(ptr!=null)
    		{
    			len++;
    			ptr = ptr.next;
    		}
    		int count = ((len%2)==0)?(len/2):
    			(len+1)/2;
    		ptr = head;
    		while(--count>1)
    			ptr = ptr.next;
    		temp.next = ptr.next;
    		ptr.next = temp;
    		
    	}
    }
    
}
public class SLLde {

 

    public static void main(String[] args) {
        
        SLLp L1= new SLLp();
        Scanner sc = new Scanner(System.in);
        int choice = 0;
        while (choice!= 7) {
        System.out.println("1.insertfront 2.insertback 3.deletefront 4.deletelast 5.display 6.Insertmid 7.end");
        choice = sc.nextInt();
        switch(choice)
        {
        case 1: System.out.println("enter the element to insert front");
        L1.insertfront(sc.nextInt()); break;
        case 2: System.out.println("Enter the element to insert back");
        L1.insertback(sc.nextInt());break;
        case 3: System.out.println("The deleted element is "); L1.deletefront();
        break;
        case 4: System.out.println("The deleted element is " );L1.deletelast(); 
        break;
        case 5: L1.display();break;
        case 6: System.out.println("Enter the element to add in the middle of the list");L1.insertmid(sc.nextInt()); break;
        case 7: break;
        }
        }

    }

 

}
