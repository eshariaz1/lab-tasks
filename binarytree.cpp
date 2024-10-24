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
    
    void insert(int val)
 {    
      Node *newnode = new Node(val);
      Node *current = root; 

     if(root == nullptr)
     {
         root = newnode; 
         newnode->left = nullptr; 
         newnode->right = nullptr;
     }
      else 
      {
         while(current != nullptr)
         {
             if(val < current->data)
             {
                 if(current->left)
                 {
                     current = current->left;
                 }
                 else
                 {
                     current->left = newnode; 
                     newnode->left = nullptr; 
                     newnode->right = nullptr;
                     break; 
                 }
             }
             else if(val > current->data)
             {
                 if(current->right)
                 {
                     current = current->right;
                 }
                 else
                 {
                     current->right = newnode; 
                     newnode->left = nullptr; 
                     newnode->right = nullptr;
                     break; 
                 }
             }
            else 
            {
                 cout << "cannot insert duplicates" << endl; 
                 break; 
            }
          }
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
    
  void find(int val)
{
    Node *current = root;

    if (current == nullptr)
    {
        cout << "the tree is empty" << endl;
        return;
    }
    else
    {
        while (current != nullptr)
        {
            if (val > current->data)
            {    current = current->right;}
            else if (val < current->data)
            { current = current->left;}
            else if (val == current->data)
            {cout << "found " << val << endl; break;}
        }
        if (current == nullptr)
        { cout << "not found " << val << endl ;   }
    }
}

   void makedelete(Node *&current)
{ 
    Node * tempdelete ;

    if(current->right == nullptr)
    { 
        tempdelete = current ; 
        current = current->left ; 
        delete tempdelete;  // Properly delete the node
    }
    else if(current->left == nullptr)
    {
        tempdelete = current ; 
        current = current->right ; 
        delete tempdelete;  // Properly delete the node
    }
    else
    {  tempdelete=current->right ; 
         while(tempdelete->left)
         { tempdelete=tempdelete->left; }
         tempdelete->left=current->left;
         tempdelete=current ; 
         current=current->right ; 
         delete tempdelete ;  
     }
 }


 void deletenode(Node *&current , int val)
 {
     if(current==nullptr)
     {cout<<"not found "<<endl; return ;  }
     else if(val>current->data)
     {deletenode(current->right,val);}
     else if(val<current->data)
     {deletenode(current->left,val);}
     else{makedelete(current); }
       
 }
  
 void calldelete(int val)
 {  deletenode(root , val);  }
 void callheight()
 { int totalheight = height(root);
   if(totalheight>0)
   { cout<<endl<<"the height is :"<< totalheight <<endl;}
 }
 void calldiameter()
 { int totaldiameter = diameter(root) ; if(totaldiameter>0){ cout<<endl<<"the diameter is : "<<totaldiameter<<endl;}}
  void callisbalanced()
  { bool total = isbalanced(root);  if(total){cout<<"is balanced"<<endl;}else{cout<<"not balanced "<<endl;}  }
 /*  void callisidentical()
 { bool total = isidentical(root,root); if(total){cout<<"is identical"<<endl;}else{cout<<"not identical "<<endl;} }*/
  
  int height(Node *current)
  {
      if (current == nullptr)
      {  return 0;}
      int leftheight = height(current->left);  // Recursively calculate left subtree height
      int rightheight = height(current->right); // Recursively calculate right subtree height
      int answer = max(leftheight,rightheight)+1;
      return answer ; 
  }

  int diameter(Node *current)
  {
      if(current==nullptr){return 0 ; }
      int leftdiameter=diameter(current->left) ;  // recursively calling the left diameter 
      int rightdiameter= diameter(current->right); // recursively calling the right diameter 
      int totaldiameter = height(current->left)+ height(current->right)+1 ;
      int total = max(leftdiameter,max(rightdiameter,totaldiameter)) ;
      return total ; 
  }
  
  bool isbalanced(Node*current)
  {
      if(current==nullptr){return true ; }
      
      bool leftbalance = isbalanced(current->left);
      bool rightbalance=isbalanced(current->right);
      bool diff = abs(height(current->left)-height(current->right))<=1 ;
      if(leftbalance && rightbalance && diff)
      { return 1 ;  }
      else{  return 0 ; }
      
  }
  
/*  bool isidentical(Node *p1 , Node *p2)
  {
      if(p1==nullptr &&p2 ==nullptr){ return true ; }
      if(p1!=nullptr && p2==nullptr){return false ;  }
      if(p1==nullptr && p2!=nullptr){return false ;  }
      bool leftidentical = isidentical(p1->left,p2->left);
      bool rightidentical= isidentical(p1->right,p2->right);
      bool value = p1->data==p2->data ;
      if(left&&right&&value){return true ; }
      else{return false ; }
  }*/
};

int main ()
{
    Binarytree obj ; 
    obj.insert(10);
    obj.insert(12);
    obj.insert(7);
    obj.insert(30);
    obj.insert(2);
    obj.insert(25);
    obj.insert(45);
    obj.display();
    //obj.find(45);
    //obj.calldelete(25); cout<<endl;
    //obj.display();
    obj.callheight();
    obj.calldiameter();
    obj.callisbalanced();
    //obj.callisidentical();
  
    
}
