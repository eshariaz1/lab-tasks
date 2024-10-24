#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std ; 

class Node
{
    public : 
    int val ; 
    Node *next ;
    
  Node(){}
  Node(int v)
  {
      val = v ; 
      next = nullptr ; 
  }
    
};

class Queue
{
    Node * head ; 
    Node * tail ; 
    int size ; 
    public : 
    
    Queue()
    {
        head = nullptr ; 
        tail = nullptr ; 
        size = 0 ; 
    }
    
    void Enqueue(int v)
    {   
        Node * newnode = new Node (v);
        Node * current = head ; 
        
      if (head==nullptr)
      {
       // newnode=head ; 
        newnode->next = nullptr ; 
        head = newnode ; 
        tail = newnode ; 
        size++;
      }
      else 
      {
        while(current->next!=nullptr)
        {
            current= current->next ; 
        }
        current->next = newnode ; 
        newnode->next = nullptr ; 
        tail=newnode; 
        size++;
      }
        cout<<"adding an element in the Queue "<<endl;
    }
    
    void Deque()
    {
        if (head==nullptr)
        {
            cout<<"the Queue is empty so cannot delete anything "<<endl;
           return ;  
        }
        else 
        {
            Node *todel ; 
            todel=head ; 
            head=head->next ; 
            if(head==nullptr)
            {
                tail = nullptr ; 
            }
            delete todel ; 
            size--;
        }
        cout<<"deleting an element in the Queue "<<endl;
    }
    
   bool Isempty()
{
    if (head == nullptr)
    {
        cout << "the Queue is empty" << endl;
        return true;
    }
    else
    {
        cout << "the Queue is not empty" << endl;
        return false;
    }
}

    
    int checksize()
    {
        cout<<"the size of the Queue is "<< size<<endl;
        return size ; 
    }
    
    void Display()
    {
         Node * current = head ; 
         
        if(current==nullptr)
        {
            cout<<"there is no elemnt in the Queue so returning empty "<<endl;
            return ; 
        }
        else
        { 
        
            while(current!=nullptr)
            {    
            
                cout<<"the value is  "<<  current->val <<endl ;
                current=current->next ; 
            }     
        }
    }
    
    
    void QueueLikeStack() {
    Queue tempQueue;        // Temporary queue
    Queue stackLikeQueue;   // This will hold the final values in a stack-like manner

    // Transfer all elements from the main queue to the temporary queue
    Node* curr = head;
    while (curr) {
        tempQueue.Enqueue(curr->val);
        curr = curr->next;
    }

    // Transfer all elements from the temporary queue to the stackLikeQueue
    while (!tempQueue.Isempty()) {
        stackLikeQueue.Enqueue(tempQueue.head->val);
        tempQueue.Deque();
    }

    // Display the stackLikeQueue
    stackLikeQueue.Display();
}
    
    int applyOperation(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; // Handle zero division separately if needed
        default: return 0; // This shouldn't happen
    }
}

void passwordDecryption(const string& password) {
    Queue alphabets, numbers, arithmetic;
    
    for(char c : password) {
        if(isalpha(c)) {
            alphabets.Enqueue(c);
        } else if(isdigit(c)) {
            numbers.Enqueue(c-'0');  // Convert char to int and enqueue
        } else if(c == '+' || c == '-' || c == '*' || c == '/') {
            arithmetic.Enqueue(c);
        }
    }

    // Only apply arithmetic operations if there are more than one operators
    if(arithmetic.checksize() > 1) {
        char high_precedence_ops[] = {'/', '*', '-', '+'};
        for(char op : high_precedence_ops) {
            while(!arithmetic.Isempty() && arithmetic.head->val == op) {
                arithmetic.Deque();
                int a = numbers.head->val; numbers.Deque();
                int b = numbers.head->val; numbers.Deque();
                int result = applyOperation(a, b, op);
                numbers.Enqueue(result);
            }
        }
    }

    // Print the decrypted password
    cout << "Decrypted Password: ";
    
    // Print alphabets
    while(!alphabets.Isempty()) {
        cout << (char)alphabets.head->val;
        alphabets.Deque();
    }
    
    // Print numbers
    while(!numbers.Isempty()) {
        cout << numbers.head->val;
        numbers.Deque();
    }
    
    // Print arithmetic operators
    while(!arithmetic.Isempty()) {
        cout << (char)arithmetic.head->val;
        arithmetic.Deque();
    }
    
    cout << endl;
}

void roundRobin(int quantum) {
    while (!isEmpty()) {
        int curTask = head();  // get the task at the front of the queue
        Deque();                // remove the task from the front of the queue

        if (curTask > quantum) {
            cout << "Execution Time: " << curTask << endl;
            cout << "Remaining Time: " << curTask - quantum << endl;
            cout << "Task is not completed, it is being re-scheduled" << endl;
            Enqueue(curTask - quantum);  // enqueue the remaining time
        } else {
            cout << "Execution Time: " << curTask << endl;
            cout << "Remaining Time: " << curTask - quantum << endl;
            cout << "Task is completed, it is removed from queue" << endl;
        }
    }
}


    
};

int main ()
{
    Queue obj;
    int choice;
    int value;
    int quantum;
    string password;

    while (true) {
        cout << "------------------Menu------------------" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Check if Queue is empty" << endl;
        cout << "5. Check size of Queue" << endl;
        cout << "6. Run Round Robin scheduling" << endl;
        cout << "7. Display Queue Like Stack" << endl;
        cout << "8. Password Decryption" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to enqueue: ";
            cin >> value;
            obj.Enqueue(value);
        } else if (choice == 2) {
            obj.Deque();
        } else if (choice == 3) {
            obj.Display();
        } else if (choice == 4) {
            obj.Isempty();
        } else if (choice == 5) {
            obj.checksize();
        } else if (choice == 6) {
            cout << "Enter the time quantum for Round Robin scheduling: ";
            cin >> quantum;
            obj.roundRobin(quantum);
        } else if (choice == 7) {
            obj.QueueLikeStack();
        } else if (choice == 8) {
            cout << "Enter the encrypted password: ";
            cin >> password;
            obj.passwordDecryption(password);
        } else if (choice == 9) {
            return 0;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0; 
}

