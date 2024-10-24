#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std ; 

class Node
{
    public :
    Node*right ; 
    Node*left ; 
    int data ; 
    Node(){}
    Node(int d){data = d ; right = nullptr ; left = nullptr ; }
};
class Binarytree
{
    Node * root ; 
    public : 
    Binarytree(){root=nullptr ; }
    
    Node* insert(Node *current, Node* newnode)
{       int checkheight ; 
    if(current == nullptr)
    {
        current = newnode;
    }
    else if(newnode->data < current->data)
    {
        current->left = insert(current->left, newnode);
    }
    else if(newnode->data > current->data)
    {
        current->right = insert(current->right, newnode);
    }
    else
    {
        cout << "no duplicates" << endl;
    }
    //return current;
    
    checkheight = Getbalancefactor(current);
    if(checkheight>1 && newnode->data<current->left->data)
    { return Rightrotation(current);}
    if(checkheight<-1 && newnode->data>current->right->data)
    { return Leftrotation(current);}
    if(checkheight>1 && newnode->data>current->left->data)
    { current->left= Leftrotation(current->left); return Rightrotation(current);}
    if(checkheight<-1 && newnode->data<current->right->data)
      {   current->right=Rightrotation(current->right); return Leftrotation(current); 
      }     root = current;
      return root ; 
}
 Node * Rightrotation(Node * y) {
    Node * x = y -> left;
    Node * T2 = x -> right;

    // Perform rotation  
    x -> right = y;
    y -> left = T2;

    return x;
  }

  Node * Leftrotation(Node * x) {
    Node * y = x -> right;
    Node * T2 = y -> left;

    // Perform rotation  
    y -> left = x;
    x -> right = T2;

    return y;
  }



     int Getbalancefactor(Node *current)
     {
         if(current==nullptr){ return -1 ; }
         else {return Height(current->left)-Height(current->right); }
     }


     int Height(Node *current)
     {  int left_height,right_height;
         if(current==nullptr)
         { return -1 ; }
         else 
         {
              left_height=Height(current->left);
              right_height=Height(current->right);
         }
         if(left_height>right_height)
         { return(left_height+1);}
         if(right_height>left_height)
         {return(right_height+1); }
     }
    
    void callinsert(int val)
{
    Node *newnode = new Node(val); 
    if (root == nullptr) {
        root = newnode; 
    } else {
        insert(root, newnode);
    }
}
    
     void display(Node* current)
    {
        if (current == nullptr) return;
        cout << current->data << " ";
        display(current->left);
        
        display(current->right);
    }
    
    void display()
    {
        display(root);
    }
};

int main ()
{
    Binarytree obj ; 
    obj.callinsert(10);
    obj.callinsert(12);
    obj.callinsert(7);
    obj.callinsert(30);
    obj.callinsert(2);
    obj.callinsert(25);
    obj.callinsert(45);
    obj.display();
}
