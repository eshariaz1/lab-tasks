#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std ; 

void  buble (int arr[] , int size)
{
    for(int i = 1 ; i<size; i++)
    {
        for(int j = 0 ; j<size-i ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr [j];
                arr[j]=arr[j+1];
                arr[j+1]= temp ; 
            }
            for(int k = 0 ; k<size; k++)
            {
                cout<<arr[k]; 
            }
            cout<<endl;
        }
    }
     cout<<"sorted array is : "<<endl;
     cout<<"bubble sort "<<endl;
    for(int i = 0 ;i<size ; i++)
    {
        cout<<arr[i];
         cout<<endl;
    }
   
}

  void selection(int arr[],int size)
  {    
      for (int i = 0; i < size - 1; i++)
      {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
           if (min!=i)
              {
                     int temp = arr[i];
                   arr[i] = arr[min];
                   arr[min] = temp;
                   
                    for(int k = 0 ; k<size; k++)
              {
                 cout<<arr[k]; 
              }
                     cout<<endl;
                  
              }
              
              
      }
      
       cout<<"sorted array is : "<<endl;
       cout<<"selection"<<endl;
    for(int i = 0 ;i<size ; i++)
    {
        cout<<arr[i];
         cout<<endl;
    }
  }


 void insert(int arr[],int size)
 {  int j ; 
    for(int i =1 ; i<size ; i++)
    {
        int min = arr[i];
        j=i-1;
        
        while(j>=0 && arr[j]>min)
        {
            arr[j+1]=arr[j];      
            j--;  
        }
        arr[j+1]=min ; 
        
        for(int k = 0 ; k<size; k++)
              {
                 cout<<arr[k]; 
              }
                     cout<<endl;
    }
                 
                 
                 
                 
       cout<<"sorted array is : "<<endl;
       cout<<"insertion sort "<<endl;
    for(int i = 0 ;i<size ; i++)
    {
        cout<<arr[i];
         cout<<endl;
    }
 }

int main ()
{  
    int size  ; 
    cout<<"enter the size of the array : "<<endl;
    cin>>size ;
    int *arr=new int [size];
    cout<<"taking input ofr the array "<<endl;
    for (int i = 0 ; i<size ; i++)
    {
        cin>>arr[i];
        
    } 
  //    buble(arr,size);
     selection(arr,size);
     insert(arr,size);
    delete[] arr;
    
    return 0 ; 
}