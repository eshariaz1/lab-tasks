#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std ; 

class Node
{
    public: 
    int val ; 
    Node *next ; 
   
    
    public :
    
    Node(){}
    Node(int v)
    {
        val = v ; 
        next = nullptr ; 
        
        
    }
    
} ; 

class linkedlist
{
    public :
    
    Node *head ; 
  
    
    linkedlist()
    {
        head = nullptr; 
       
    }
    
    void addstart(int val )
    {
        Node *triversal = head ; 
        Node * newnode = new Node(val);
        if(head==nullptr)
        { 
          head = newnode ; 
          newnode->next = head ; 
          return ; 
          
        }
        else
        {
        while(triversal->next!=head)
        {
            triversal=triversal->next ; 
        }
        triversal->next = newnode ; 
        newnode->next  = head ; 
        head = newnode ; 
        }
        
    }            // start function ended 

    void addmid(int val , int index)
    {
        Node * newnode = new Node (val);
         Node *triversal = head;
          Node *pre = nullptr;
        
        int pos = 1 ; 
        while(triversal->next!=head &&pos!=index)
        {   
             pre = triversal ;
            triversal=triversal->next ; 
            
            pos++;
        }
        
         newnode->next  = triversal ; 
        pre->next = newnode ;
     
        
    }   // MID FUNCTION ENDING 
    
     void addend(int val )
    {
        Node *triversal = head ; 
        Node * newnode = new Node(val);
        if(head==nullptr)
        { 
          head = newnode ; 
          newnode->next = head ; 
          return ; 
          
        }
        else
        {
        while(triversal->next!=head)
        {
            triversal=triversal->next ; 
        }
        triversal->next = newnode ; 
        newnode->next  = head ; 
        //head = newnode ; 
        }
        
    }      // adding in the end 
    
    
    
     void delstart()
     {   
         Node * triversal = head ;
         Node * temp = head ; 
         
         while(triversal->next!=head)
         {
             triversal=triversal->next ; 
         }
         
         head=head->next ; 
         triversal->next = head ; 
     }
     
     void enddel ()
     {
         
         Node * triversal = head ;
         
         while(triversal->next->next!=head)
         {
             triversal=triversal->next ; 
         }
         triversal->next = head ; 
        //  Node * del =triversal->next->next ;
          
       //  delete del ; 
         
     }
     
     
    void display()
    {
       Node *triversal = head;
    cout << "the value is : " << head->val << endl; // Print the head value
    triversal = triversal->next; // Move to the next node

    while (triversal != head)
    {
        cout << "the value is : " << triversal->val << endl;
        triversal = triversal->next;
    }
        
    }
    
    
};



int main ()
{  
     
    linkedlist obj ;
   obj.addstart(1);
    obj.addstart(2);
     obj.addstart(3);
      obj.addstart(4);
   cout<<"after calling the star function "<<endl;
    obj.display();
    obj.addmid(5,3); 
    cout<<"after calling the mid add  function "<<endl;
    obj.display();
    obj.addend(0);
   cout<<"after calling the  add at the end function "<<endl;
    obj.display();
    
    obj.delstart(); 
    cout<<"after calling the delete at the first index   function "<<endl;
    obj.display();
     obj.enddel(); 
    cout<<"after calling the delete at the last index    function "<<endl;
    obj.display();
    
    
    return 0 ; 
}