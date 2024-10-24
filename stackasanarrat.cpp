#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std ; 

class stacks
{
  int capacity ; 
  int *arr; 
  int index ; 
  
  public :
  
  stacks(){}
  stacks(int c)
  {
      capacity = c ; 
      arr= new int[c];
      index = -1 ; 
  }
  
  
  void push (int val)
  {
      if(index==capacity-1)
      {
          cout<<"poop : overflow "<<endl;
      }
      else
      {
        index++;
        arr[index]=val ; 
      }
  }
  
  void pop()
  {
     if(index==-1)
     {
         cout<<"poop : underflow "<<endl;
         return ; 
     }
     else 
     {
         index--;  return ; 
     }
  }   // ending po pfunction 
  
    void isempty()
    {
        
       if(index==-1)
     {
         cout<<"poop : stack is empty  "<<endl;
         return ; 
     }
     else if(index>-1)
     {
         cout<<"poop : the stack is not empty "<<endl;   return ; 
     }  
        
    }    // empty function 
    
    void top ()
    {
      if(index==-1)
     {
         cout<<"poop : stack is empty so no top element   "<<endl;
         return ; 
     }
     else if(index>-1)
     {
         cout<<"poop : the stack is not empty  the top element is :  " << arr[index]<<endl;   return ; 
     }  
           
        
    }    // top element function 
    
    void isfull()
    {
       if(index==capacity-1)
      {
          cout<<"poop : overflow full  "<<endl;
      }
      else
      {
        cout<<"not full "<<endl
      } 
      
    }    // full function ending 
    
    
  
   ~stacks()
    {
        delete[] arr;
    }
  
  void display()
  { 
      
    for(int i = 0 ; i<=index ; i++)
    {
        cout<<"the value is :  "<<arr[i] <<endl;
    }
      
  }  
    
};


int main ()
{  
   //  stacks obj ; 
   int cap ; 
   cout<<"enter the capacity you want to give :"<<endl ; 
   cin>>cap ; 
     stacks obj1(cap);
     obj1.push(1);
     obj1.push(2);
     obj1.push(3);
     cout<<"displaying after calling the push function "<<endl;
     obj1.display(); 
      obj1.pop();
     cout<<"displaying after calling the pop function "<<endl;
     obj1.display();
      obj1.isempty();
     cout<<"displaying after calling the empty function "<<endl;
     obj1.display();
     obj1.top();
     cout<<"displaying after calling the top function "<<endl;
     obj1.display();
    
    return 0 ; 
}