#include<iomanip>
#include<iostream>
#include<string.h>
using namespace std ; 

class node 
{  
   public : 
   
  int val ; 
  node *next ; 
  node *previous ; 
  
  node (){}
  node(int v)
  {
      val = v ; 
      next = nullptr ; 
      previous = nullptr ; 
  }
};

class linkedlist
{
    node *head ; 
    
    public : 
    
    linkedlist(){ head= nullptr ; }
    
     void insertatbegninning(int val)
     {
        node* newNode = new node(val);

        if (head==nullptr)
        {
            head = newNode;
         //  newNode=head;
            head->next = head;
            head->previous = head;
        } 
        else 
        {
            node* last = head->previous;

            newNode->next = head;
            head->previous = newNode;
            newNode->previous = last;
            last->next = newNode;

            head = newNode;
        }
    }

    void insertattheend(int v)
    {
    node *newnode = new node(v);

    if (head == nullptr)
    {
        cout << "List is empty so calling the function  Inserting at the beginning." << endl;
        insertatbegninning(v);
        return;
    }
    else
    {
        node *triverse = head;

        while (triverse->next != head)
        {
            triverse = triverse->next;
        }

        triverse->next = newnode;
        newnode->previous = triverse;
        newnode->next = head;
        head->previous = newnode;
    }
     cout << "Inserted " << v << " at the end." << endl;
   }

   void insertbeforeanode(int n , int v)
   {
      int count = 0 ; 
      
      node * triverse = head ; 
      node * newnode = new node(v);
      
      if (head==nullptr)
      {  
          cout<<"since head is empty so adding the value by using insert at the beginning function "<<endl;
          insertatbegninning(v);
      }
      
      while(triverse!=head && count<n)
      {
          triverse=triverse->next ;
          count++;
      }
        newnode->next = triverse->next ; 
       triverse->next = newnode ; 
       newnode->previous=triverse ; 
       triverse->next->previous= newnode ; 
       
       cout<<"inserting "<< v <<" at position " << n-1 <<endl;
   }
    
    void insertafteranode(int n , int v)
   {
      int count = 1 ; 
      
      node * triverse = head ; 
      node * newnode = new node(v);
      
      if (head==nullptr)
      {  
          cout<<"since head is empty so adding the value by using insert at the beginning function "<<endl;
          insertatbegninning(v);
      }
      
      while( count<n)
      {
          triverse=triverse->next ;
          count++;
      }
        newnode->next = triverse->next ; 
       triverse->next = newnode ; 
       newnode->previous=triverse ; 
       triverse->next->previous= newnode ; 
       
       cout<<"inserting "<< v <<" at position " << n+1 <<endl;
   }
   
   void deleteatbeginning()
   {
     node * temp = head ; 
    node * triverse = head ; 
    node * move = head ; 
    
    if (head==nullptr)
    {
        cout<<"there is no element in the list "<<endl;
        return ; 
    }
    else if (temp->next == head) 
    {
            head = nullptr;
    }
    else 
    {
    while(move->next!=head)
    {
        move=move->next ;
    }
    
        node *last = head;
        head = head->next;
        move->next = head;
        head->previous = move;

        delete last;
        
    }
      cout<<"after deleting the value at the first node "<<endl; 
       
   }
   
   void deleteatend()
   {
        node * temp = head ; 
    node * triverse = head ; 
    node * move = head ; 
    
    if (head==nullptr)
    {
        cout<<"there is no element in the list "<<endl;
        return ; 
    }
    else if (temp->next == head) 
    {
            head = nullptr;
            return ; 
    }
    else 
    {
    while(move->next->next!=head)
    {
        move=move->next ;
    }
        
    //    node *last = move->next;
        move->next = head;
        head->previous = move;

       // delete last;
        
    }
      cout<<"after deleting the value at the end node "<<endl; 
       
   }
   

 void deleteatspecific(int n)
   {
       node * current = head ; 
       int count = 1 ; 
     
       if (head==nullptr)
    {
        cout<<"there is no element in the list "<<endl;
        return ; 
    }
    else if (n==1) 
    {     
         cout<<"there is only one element so deleting that one "<<endl;
            head = nullptr;
            return ; 
    }
    else 
    {
         do
    {
        current = current->next;
     
         count = count + 1;
    } 
    while (current != head && count<n);
       node *del = current->next;
        current->next = current->next->next;
        if (current->next != head)
        {
            current->next->previous = current;
        }

        delete del;
    }
   
       cout<<"deleting node from this  index number "<< n << "  from the linked list  "<<endl;
   }
    
    void deletemid()
    {
        node * triverse = head ; 
        
        int count =  0 ;  int check ;  
       do
    {
        triverse = triverse->next;
     
         count = count + 1;
    } 
    while (triverse != head);
        check = count/2 ; 
        cout<<"the middle index of the list is "<< check <<endl;
        cout<<"now calling the deleting at a spwcific index function "<<endl;
        deleteatspecific(check);
        
    }
    
    
    void display()
    {
        node *triverse;
        triverse = head;

        if (head != nullptr)
        {
            do
            {
                std::cout << "the value is  :  " << triverse->val << std::endl;
                triverse = triverse->next;
            } while (triverse != head);
        }
    }
    
};


int main ()
{
   
   linkedlist obj ; 
   
   obj.insertatbegninning(3);
    obj.insertatbegninning(2);
    obj.insertatbegninning(1);
   obj.display();
   
   obj.insertattheend(5);
   obj.display();
   obj.insertbeforeanode(3,0);
   obj.display();
   obj.insertafteranode(3,4);
   obj.display();
   obj.deleteatbeginning();
   obj.display();
    obj.deleteatend();
    obj.display();
    obj.deleteatspecific(3);
    obj.display();
    obj.insertattheend(5);
   obj.display();
    obj.deletemid();
    obj.display();
    return 0 ; 
}