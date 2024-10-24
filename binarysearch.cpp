#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std ; 

int  binary (int arr[] , int size,int n)
{
    int last = size-1 ;  int middle ;  int first= 0 ; 
    bool found =false ;  int pos = -1  ; 
    while(!found && first<=last)
    { 
           
     middle =  (first+last)/2 ; 
     
     if (arr[middle]==n)
     {
        cout<<"the number is found in the middle "<< arr[middle]<<endl;
        found = true  ; 
         return middle ; 
     }
    else if (arr[middle]>n)
    {
     last = middle-1 ;     
     pos = middle;
    }
    else if (arr[middle]<n)
    {
        first=middle+1;
        pos=middle;
    }
        
    }
    
     return pos ; 
}

int main ()
{  
    int size  ; 
    cin>>size ;
    int *arr=new int [size];
    for (int i = 0 ; i<size ; i++)
    {
        cin>>arr[i];
    }
    
    int number ; 
    cin>> number ; 
    int show ; 
    show = binary(arr,size,number);
    cout<<show ; 
    
    
    delete[] arr;
    
    return 0 ; 
}