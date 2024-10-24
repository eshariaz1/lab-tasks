#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std ; 


class Node
{
    public :
    Node * left ; 
    Node * right ; 
    int value ; 
    
    Node() {
    value = 0;
    left = NULL;
    right = NULL;
  }
  Node(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
};

class AVLTree
{
  public:
    Node * root;
    AVLTree()
    {
       root = NULL;
    }
   bool isTreeEmpty() 
   {
    if (root == NULL)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  
  int Height(Node *current)
  {
     if (current==NULL)
     {
         return -1 ; 
     }
     else 
     {
      // compute the height of each subtree 
      int lheight = Height(current->left);
      int rheight = Height(current->right);

      // use the larger one 
      if (lheight > rheight)
        {
            return (lheight + 1);
        }
      else
      {
          return (rheight + 1);
      }
  }
  }
  
   int Getbalancefactor(Node * current)
  {
       if (current == NULL)
       {
          return -1;
       }
       else
       {
          return Height(current->left) - Height(current->right);
       }
  }
  
   Node * minValueNode(Node * node) 
  {
    Node * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL)
    {
      current = current -> left;
    }
    return current;
   }
    // left rotstion 
    
   Node * Leftrotation(Node* current)
  {
    Node * newroot = current->right ; 
    Node * nullnode = newroot->left;
    newroot->left = current ; 
    current->right = nullnode ; 
    return newroot ; 
  }
    // right rotation 
  
  Node * Rightrotation(Node* current)
  {
    Node * newroot = current->left ;
    Node * nullnode = newroot->right ; 
    newroot->right = current ; 
    current->left = nullnode ; 
    return newroot ;   
  }
  
  // insert function 
  Node* insert(Node *current, Node* newnode)
 {       
      int checkheight ;

    if(current == nullptr)
    {
        current = newnode;
        return current ; 
    }
    else if(newnode->value< current->value)
    {
        current->left = insert(current->left, newnode);
    }
    else if(newnode->value > current->value)
    {
        current->right = insert(current->right, newnode);
    }
    else
    {
        cout << "no duplicates" << endl;
        return current ; 
    }
   
    checkheight = Getbalancefactor(current);
    // left left heavy ( right right rotation  ) 
    
    if(checkheight>1&& newnode->value<current->left->value)
    {
       return  Rightrotation(current);
    }
    // right right heavy  ( left left rotation )
    
    else if (checkheight<-1 && newnode->value>current->right->value)
    {
        return Leftrotation(current);
    }
    // left right heavy (RL ROTATION )
    else if(checkheight>1 && newnode->value>current->left->value)
    {
        current->left =  Leftrotation(current->left);
       
         return Rightrotation(current);
    }
    // right left heavy  ( LR  rotation )
    
    else if (checkheight<-1 && newnode->value<current->right->value)
    {
    current->right = Rightrotation(current->right);
    
     return Leftrotation(current);
    }
      return current ; 
  }
  
  void callinsert(int val) {
    Node *newnode = new Node(val);
    root = insert(root, newnode);
}
 
  Node * deletenode(Node * current , int data)
  {
      Node * todelete ; 
      
   if(current==nullptr)
   {
       return nullptr ; 
   }
   else if (data<current->value)
   {
       current->left = deletenode(current->left , data);
   }
   else if (data>current->value)
   {
       current->right = deletenode(current->right ,data);
   }
   else
   {
    if(current->left==nullptr)     // with the right child 
    {
        todelete = current->right ; 
        current=nullptr ; 
        delete current;
        return todelete ; 
    }
    else if(current->right==nullptr)    // with the left child 
    {
        todelete = current->left ; 
        current=nullptr ; 
        delete current;
        return todelete ; 
    }
    else      // with both the child  
    {
         // node with two children: Get the inorder successor (smallest  in the right subtree)
        
          Node * temp = minValueNode(current->right);
          current->value = temp->value;
          // Delete the inorder successor 
         current->right = deletenode(current->right, temp->value);
    }          
   }       // the else finished  bascially like bst code till here 
      
      int checkheight = Getbalancefactor(current);
      // left left heavy(right right rotation )
      
      if(checkheight==2 && Getbalancefactor(current->left)>=0)
      {
          return Rightrotation(current);
      }
      
      // right right heavy(left left rotation)
      
      else if (checkheight==-2 && Getbalancefactor(current->right)<=-0 )
      {
          return Leftrotation(current);
      }
      
      // right left  rotation (left right   heavy )  which means left subtree  ka right  wala part heavy is causing imbalance 
      // check the diagram from the notes 
      
      else if (checkheight==2 && Getbalancefactor(current->left)==-1)
      {
          current->left = Leftrotation(current->left);
          return Rightrotation(current);
      }
      
      // left right rotation (right left  heavy )  which means right subtree ka left wala part heavy is causing imbalance 
      // check the diagram from the notes 
      
      else if (checkheight==-2 && Getbalancefactor(current->right)==1)
      {
          current->right = Rightrotation(current->right);
          return Leftrotation(current);
      }
      return current ; 
  }
 
   void calldelete(int val)
{
    if (root == nullptr)
    {
        return ;  
     }
     else
     {
         deletenode(root, val);
     }
 }
 
  // PRINT FUNCTION 
  void printTree(Node* root, string indent, bool last) {
        // Print the arm
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }
        // Print the node value
        if (root != nullptr) {
            cout << root->value << endl;
            // Recur to left and right subtrees
            printTree(root->left, indent, false);
            printTree(root->right, indent, true);
        } else {
            cout << "null" << endl;
        }
    }

    // Public function to call printTree
    void displayTree() {
        printTree(this->root, "", true);
    }
  
};
int main() {
    AVLTree avl;
    int choice, value;

    while (true) {
        cout << "\nAVL Tree Menu" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Print AVL Tree" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                avl.callinsert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                avl.calldelete(value);
                break;
            case 3:
                cout << "AVL Tree:" << endl;
                avl.displayTree();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
