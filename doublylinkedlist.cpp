#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std ; 

class Node
{
    public: 
    int val ; 
    Node *next ; 
    Node *pre ; 
    
    public :
    
    Node(){}
    Node(int v)
    {
        val = v ; 
        next = nullptr ; 
        pre = nullptr ;
        
    }
    
} ; 

class linkedlist
{
    public :
    
    Node *head ; 
    Node *tail ; 
    
    linkedlist()
    {
        head = nullptr; 
        tail = nullptr; 
    }

    
     void addstart(int val)
     {
         Node *newnode = new Node(val) ; 
         
         Node *triveral =head ; 
         
         if(head==nullptr)
         {   
             
            // newnode->pre=head;
             //head->next=newnode ;
             
             //ASK HASHIR , MAHAM ,  NUR OR MAADEHAH 
              head = newnode;
              tail = newnode;
         }
         else
         {
            
            newnode->next = head;
            head->pre=newnode ; 
            head=newnode ; 
         }
     }   // start function 
     
     Node* midadd(int val ,int index)
     {
          Node *newnode = new Node(val) ; 
         
         Node *triversal =head ; 
         
         Node *temp = nullptr ; 
         int pos=1 ; 
         
         if(head==nullptr)
         {
             head=newnode ;
             tail =newnode ; 
             return head ;
         }
         else
         {
             while (triversal != nullptr && pos < index)
            {
                  temp = triversal;
                   triversal = triversal->next;
                    pos++;
             }

      /* if (pos == index)
        {
        newnode->next = triversal;
        newnode->pre = temp;
        temp->next = newnode;

        if (triversal != nullptr)
            triversal->pre = newnode;
         }
         }*/
         
           if (pos == index)
    {
        newnode->next = triversal;
        newnode->pre = triversal->pre;
        if (triversal->pre != nullptr)
            triversal->pre->next = newnode;
        triversal->pre = newnode;

        if (triversal == head)
            head = newnode;
    }
         
         }     
         
     }   // ending mid function 
     
     void endadd(int val)
     {
        Node * newnode = new Node (val); 
        if(tail->next==nullptr)
        {
            tail->next=newnode;
            newnode->next=nullptr;
            newnode->pre=tail ; 
           // tail=newnode;
            
        }
         
     }        // ending the end function 
     
     void delstart()
     {
        
        Node *temp = nullptr ; 
        
        temp=head ; 
        head=head->next ;
        if(head!=nullptr)
        {
            head->pre = nullptr ;
            head->next->pre=head ;
        }
        delete temp ; 
        temp = nullptr ; 
         
     }     // ending start function 
     
     void delmid(int index )
     {
         Node * temp = head ;
         Node * triversal = head ; 
         
         int pos= 1 ; 
         
         while ( pos<index)
         {
            temp=triversal ; 
            triversal=triversal->next ;
            pos++ ; 
             
         }
         Node *  del  ; 
         if(triversal!=nullptr && pos==index )
         {
              del  = triversal ; 
             
             triversal->pre->next= triversal->next;
             triversal->next->pre = triversal->pre ; 
                       
         }
        
        
        delete  del ;
         
         
     }   // del mid function ending 
     
    void delend()
 {   
     if (tail == nullptr)
     {
        return; // Empty list, do nothing
     }

     Node *del = tail;

     if (tail== nullptr)
     {
          head = nullptr;
     }
     else
     {
        
         tail = tail->pre;
        tail->next = nullptr;
     }

     delete del;   
     return ; 
   }      // delete from the end 
   
   void reverse ()
   {
       Node * pre = nullptr ; 
       Node * current = head ; 
       Node * last = nullptr ; 
       
       
       while(current)
       {
            last = current->next;
        current->next = current->pre;
        pre=current->next ;
        current = last;
       }
       // swapping head and tail pointers 
       
       Node * newhead = tail ; 
       tail = head; 
       head = newhead ; 
   }
   
   void palindrome()
    {
      Node *traverse= head ;
      Node * pre = nullptr ; 
      
      while(head!=tail && tail!=head->pre)   // FOR THE MIDDLE NODE FOR ODD NUMBERS AND EVEN NUMBERS 
      {
          
          if(head->val!=tail->val) 
        {   cout<<"it is not a palindrome "<<endl;
          return ;
        }
        head=head->next ; 
        tail=tail->pre ; 
         
      }
       
       cout<<"it is a palindrome "<<endl;
       return ; 
    }   // palindrome FUNCTION  ending 
    
    void delsame()
    {
        Node * pre = nullptr ; 
        Node  *current = head ;
        Node *last = nullptr ; 
         
        while(current!=nullptr && current->next!=nullptr)
        {
            last=current->next ;
             
            if(last->val==current->val)
            {   
                Node * del = current ; 
                pre->next=current->next;
                
                delete current ; 
                current = nullptr ; 
            }
            else
            {       pre =current ;
                current = current->next ; 
                 
            }
            
        }
    }
   
    void display()
    {
        Node *triversal = head ;
        while( triversal!=nullptr)
        {
            cout<<"the value is : "<<triversal->val<<endl;
            triversal=triversal->next ; 
        }
        
    }
    
    
};



int main ()
{  
     
    linkedlist obj ;
    obj.addstart(1) ;
    obj.addstart(2);
    obj.addstart(3) ;
    obj.addstart(4);
    obj.display();
    obj.midadd(5,2);
    cout<<"after the mid add function the output would be : "<<endl;
    obj.display();
    obj.endadd(25);
    cout<<"after calling the end adding function "<<endl;
    obj.display();
    obj.delstart();
     cout<<"after calling the delete start  function "<<endl;
    obj.display();
    obj.delmid(2);
     cout<<"after calling the delete mid  function "<<endl;
    obj.display();
     obj.delend();
    cout<<"after calling the delete end  function "<<endl;
    obj.display();
    cout<<"adding again at the start "<<endl;
    obj.addstart(31) ;
    obj.addstart(41);
     obj.display();
    obj.reverse();
    cout<<"after calling the  reverse   function "<<endl;
    obj.display();
    obj.palindrome();
    cout<<"after calling the palindrome function "<<endl;
    obj.display();
    obj.endadd(41);
    obj.delsame();
    cout<<"after calling the del same  function "<<endl;
    obj.display();
    
    return 0 ; 
}