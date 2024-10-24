#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std ; 
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next;

    Node() {}
    Node(int v)
    {
        val = v;
        next = nullptr;
    }

};
template<class T>
class Queue
{
    Node* front;
    Node* rear;
  //  int size;
public:

    Queue()
    {
        front = nullptr;
        rear = nullptr;
    //    size = 0;
    }

    void insert(int v)
    {
        Node* newnode = new Node(v);
        Node* current = front;

        if (front == nullptr)
        {
            // newnode=head ; 
            newnode->next = nullptr;
            front = newnode;
            rear = newnode;
      //      size++;
        }
        else
        {
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newnode;
            newnode->next = nullptr;
            rear = newnode;
        //    size++;
        }
        cout << "adding an element in the Queue " << endl;
    }
    void Display()
    {
        Node* current = front;

        if (current == nullptr)
        {
            cout << "there is no elemnt in the Queue so returning empty " << endl;
            return;
        }
        else
        {

            while (current != nullptr)
            {

                cout << "the value is  " << current->val << endl;
                current = current->next;
            }
        }
    }
    
 /*   void Sorting (Node *current , Node*nextcurrent )
    {
        Node * current = front ; 
        Node * nextcurrent = current->next ; 
        int temp ; 
        if (current==nullptr && nextcurrent == nullptr )
        {
            return ; 
        }
        else 
        {
            if (current->val>nextcurrent->val)
            {
                temp = current->val ; 
                current->val = nextcurrent->val ; 
                nextcurrent->val = current->val ; 
            }
            Sorting(current->next , nextcurrent->next) ; 
        }
        
    } */

/*void Sorting(Node* current)
{  
    int temp;  
    if (current == nullptr || current->next == nullptr)
    {
        return;
    }
    
    Node* nextcurrent = current->next;

    if(current->val > nextcurrent->val)
    {
        temp = current->val;
        current->val = nextcurrent->val;
        nextcurrent->val = temp;
    }
    Sorting(current->next);
    if(current->val > nextcurrent->val)
    {
        temp = current->val;
        current->val = nextcurrent->val;
        nextcurrent->val = temp;
    }
}*/

  void sort(Node* current)
{
    if (current == nullptr)
        return;

    sorting(current, current->next);

    sort(current->next);
}

void sorting(Node* current, Node* last)
{
    if (last == nullptr)
        return;

    if (current->val > last->val)
    {
        int temp = current->val;
        current->val = last->val;
        last->val = temp;
    }

    sorting(current, last->next);
    
}


    
    void Callsorting()
    {
        Queue<int>obj ; 
        obj.sort(front);    
        obj.sorting(front,rear);
    }
} ;

int main ()
{
    Queue<int> obj;
    obj.insert(1); 
    obj.insert(8); 
    obj.insert(-1); 
    obj.insert(9); 
    obj.insert(4); 
    obj.insert(2); 
    obj.insert(5); 
    obj.insert(0); 
    obj.Display();
    obj.Callsorting();
    cout<<"AFTER SORTING  : "<<endl;
    obj.Display();
    return 0 ; 
}
