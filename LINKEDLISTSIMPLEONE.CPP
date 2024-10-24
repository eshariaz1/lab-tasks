#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std; 

class Node
{
public:
    int val;
    Node* next;
    Node(){}
    Node(int va)
    {
        val = va;
        next = nullptr;
    }
    
};

class linkedlist
{
    public :
    
    Node *head;
    
     linkedlist() : head(nullptr) {}
     
     // adding an element in the start 
     
     void insert(int val)
     {
         Node * T = head ; 
         Node *newnode=new Node(val);
         if (head==nullptr)
         {
             newnode->next=head;
             head=newnode;
         }
         else
         {
             newnode->next=head;
             head=newnode;  // ask nur or maadehah 
         }
         
     }
     
      // INSERTING IN THE END  
      
      void end(int val)
      {
         Node * T = head ; 
         Node *newnode=new Node(val);
         if (head==nullptr)
         {
             newnode->next=head;
             head=newnode;
         }
         else 
         {
             Node *temp = head ; 
             while(temp->next!=nullptr)
             {
                 temp=temp->next ; 
                 
             }
             cout<<temp->val<<endl;
            temp->next=newnode;
            cout<<temp->next->val<<endl;
            
         }
          
      }
      // insert in the middle 
      
      void middle(int val,int index)
      {
        Node * T = head ; 
         Node *newnode=new Node(val);
         if (head==nullptr)
         {
             newnode->next=head;
             head=newnode;
         }  
         else 
         {    int pos = 1 ; 
              Node *temp = head ; 
             while(pos < index - 1 )
             {
                 temp=temp->next ;
                 pos++;
                 
             }
              
             newnode->next=temp->next ;  
            // ask nur or maadehah 
             temp->next = newnode ; 
             
             
             
         }
          
      }
      
      // delete function 
      
      void del()
      {
       Node *temp = head ; 
       head=head->next ; 
      }
      
      // deleting from the end 
      
      void delend()
      {
         Node * temp = head ; 
           if (head==nullptr)
         {
            cout<<"the does not have any value to delete"<<endl;
         }  
         if (head->next == nullptr)
         {
          delete head;
          
          head = nullptr;
          
          return;
         }
         while(temp->next->next!=nullptr)
         {
            temp=temp->next ;  
         }
         delete temp->next;
        temp->next = nullptr;
           
      }
      
      // dleeting in the middle 
      
      void delmid(int index)
      {
         Node * T = head ; 
         Node * temp = head ; 
         
         int pos=1 ;
         
         while(pos<index-1)
         {
            temp=temp->next ;  
            pos++ ; 
         }
       
         Node* toDelete = temp->next;
           temp->next = temp->next->next;
         
         delete toDelete;
      }
      
      Node* reverse ()
      {
           Node* last = nullptr;
    Node* current = head;
    Node* pre = nullptr;

    while (current != nullptr) {
        last = current->next;
       current->next = pre;
        pre = current;
        current = last;
    }

    head = pre; // Update the head to the new head of the reversed list

    return head;
      }
      
      Node* rereverse(Node* current, Node* prev)
      {
       if (current == nullptr)
       {
          
          head = prev;  // Update the head to the new head of the reversed list
          
          return prev;  // Return the new head of the reversed list
       
           
       }

     
     Node* nextNode = current->next;
    
    
    current->next = prev;

    return rereverse(nextNode, current);
    
          
      }

void rereverse()

{
    if (head == nullptr)
        return;

    head = rereverse(head, nullptr);
}
       
       void sort ()
       {
           Node *current = head ; 
           
           
           while(current->next!=nullptr)
           {
               Node*last =current->next ; 
            
            while(last!=nullptr)   
               {
                   if (current->val>last->val)
                   {
                       int temp = current->val;
                current->val = last->val;
                     last->val = temp;
                   }
                   
                  last=last->next ;  
               }
               current=current->next ; 
           }
           
       }
     
     void display()
     {
         Node * T = head ; 
        while(T !=nullptr)
        {
            cout<<"the value is : "<<T->val<<endl;
            T=T->next ; 
        }
         
     }
     
};
int main()
{
    linkedlist obj ; 
    
    obj.insert(5);
    obj.insert(2);
    cout<<"inserting in the start "<<endl;
    obj.display();
    
    obj.end(1);
    cout<<"inserting in the end "<<endl;
    obj.display();
    obj.middle(4,3);
    cout<<"inserting in the middle "<<endl;
    obj.display();
    obj.del();
    cout<<"deleting in the start  "<<endl;
    obj.display();
    obj.delend();
    cout<<"deleting from the end "<<endl;
    obj.display();
     obj.insert(0);
    obj.insert(9);
    cout<<"inserting in the start "<<endl;
    obj.display();
    obj.delmid(2);
    cout<<"deleting from the mid  "<<endl;
    obj.display();
    obj.reverse();
    cout<<"after reversing the list "<<endl;
    obj.display();
    obj.rereverse();
    cout<<"after  recursively reversing the list "<<endl;
    obj.display();
    obj.sort();
    cout<<"after  sorting  the list "<<endl;
    obj.display();
    
    return 0;
}