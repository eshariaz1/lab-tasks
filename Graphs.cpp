#include<iostream>
#include<iomanip>
#include<string.h>
#include<vector>
#include<list>

using namespace std ; 

class Edgeclass
{   public : 

    int nodedesid ; 
    int weight ; 
    
    Edgeclass(){}
    Edgeclass(int d , int w ){nodedesid=d ; weight = w ; }
     void Setweight(int w)
      { weight = w; }
     int Getnodedesid() 
      {  return nodedesid; }
     int Getweight()
      { return weight; }
       void Setedgevalues(int id , int w) 
     {
         nodedesid = id;
         weight = w;
         
     }
};

class Node
{ 
    public : 
   string nodename ; 
   int  nodeid ; 
   list<Edgeclass> edgelist ;
   Node(){}
   Node(string name , int id ){ nodename = name ; nodeid =id ;  }
   void Setnodename(string n ){nodename = n ; }
   void Setnodeid (int i ){ nodeid = i ; }
   string Getnodename(){return nodename ; }
   int Getnodeid(){return nodeid;}
   list<Edgeclass> Getedgelist(){ return edgelist ; }
    
     void Printedgelist() 
     {
    cout << "[";
    for (auto it = edgelist.begin(); it != edgelist.end(); it++) 
    {
      cout << it -> Getnodedesid() << "(" << it -> Getweight() << ") ---> ";
    }
           cout << "]";
         cout << endl;
    }
};

class Graph
{
    public : 
    vector<Node> nodevector ; 
   
   
   void Addvertex(Node obj)
   {
       bool check =Checkvertex(obj.Getnodeid()); 
      if(check)
      { cout<<"the id already exist in the graph "<<endl; return ; }
      nodevector.push_back(obj);
      cout<<"the new vertex/node added succesfully "<<endl;
       
   }
   
   bool Checkvertex(int id )
   {
       for(int i = 0 ; i<nodevector.size(); i++)
       {
           if(nodevector.at(i).Getnodeid()==id)
           {
               return true ; 
           }
       }
       return false ; 
   }
   
    void Addedgebyid(int fromVertex, int toVertex, int weight) 
    {
    bool check1 = Checkvertex(fromVertex);
    bool check2 = Checkvertex(toVertex);
    bool check3 = checkIfEdgeExistByID(fromVertex, toVertex);
    if ((check1 && check2 == true)) 
    {
      if (check3 == true)
      {
        cout << "Edge between " << Getnodebyid(fromVertex).Getnodename() << "(" << fromVertex << ") and "
        << Getnodebyid(toVertex).Getnodename() << "(" << toVertex << ") Already Exist" << endl;
      }
      else
      {
        for (int i = 0; i < nodevector.size(); i++) 
        {
          if (nodevector.at(i).Getnodeid() == fromVertex) {
            Edgeclass e(toVertex, weight);
            
            nodevector.at(i).edgelist.push_back(e);
          } 
          else if (nodevector.at(i).Getnodeid() == toVertex)
          {
            Edgeclass e(toVertex, weight);
            nodevector.at(i).edgelist.push_back(e);
          }
        }
        cout << "Edge between " << fromVertex << " and " << toVertex << " added Successfully" << endl;
      }
    } else {
      cout << "Invalid Vertex ID entered.";
    }
  }
   
    Node Getnodebyid(int id)
   {
       Node tempobj ;  
       for(int i = 0 ; i<nodevector.size(); i++)
       {
           tempobj= nodevector.at(i);
           if(tempobj.Getnodeid()==id)
           {
               return tempobj ; 
           }
           
       }
       return tempobj; 
   }
   
     bool checkIfEdgeExistByID(int source, int des) 
     {
        Node verobj = Getnodebyid(source);
           list <Edgeclass> obj;
           obj = verobj.Getedgelist();
        for (auto it = obj.begin(); it != obj.end(); it++)
        {
           if (it -> Getnodedesid() == des) 
           {
                return true ; 
            }
        }
             return false ; 
   }
    
    
     void printGraph() {
    for (int i = 0; i < nodevector.size(); i++) {
      Node temp;
      temp = nodevector.at(i);
      cout << temp.Getnodename() << " (" << temp.Getnodeid() << ") --> ";
      temp.Printedgelist();
    }
  }
};

int main ()
{
   Graph objgraph ; Node objnode ;   int  sourcenode ; int  Desnode ; int w ; 
   string name; int id ; cout<<"Enter the name of the Node/Vertex "<<endl; 
   cin>> name ; cout<<"Enter the id of the Node/Vertex"<<endl; cin>> id ; 
   objnode.Setnodename(name); objnode.Setnodeid(id);
   objgraph.Addvertex(objnode);
   cout<<"Enter the id of the  source Node/Vertex"<<endl; cin>> sourcenode ; 
   cout<<"Enter the id of the destination  Node/Vertex"<<endl; cin>> Desnode ; 
   cout<<"Enter weight"<<endl; cin>> w ; 
   objgraph.Addedgebyid(sourcenode, Desnode, w);
   
   
    return 0 ; 
}

