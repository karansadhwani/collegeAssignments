/*
 Practical no::4
 Title::
      Tour operator organizes guided bus trips across the Maharashtra. Tourists may have different
      preferences. Tour operator offers a choice from many different routes. Every day the bus
      moves from starting city S to another city F as chosen by client. On this way, the tourists can
      see the sights alongside the route travelled from S to F. Client may have preference to choose
      route. There is a restriction on the routes that the tourists may choose from, the bus has to take
      a short route from S to F or a route having one distance unit longer than the minimal distance.
      Two routes from S to F are considered different if there is at least one road from a city A to a
      city B which is part of one route, but not of the other route.
  Roll no :46
  Batch: C
  Started on:
  Completed on:
*/


#include<iostream>
using namespace std;


struct Node
{
  char data;
  int weight;
  struct Node *Down;
  struct Node *Next;

}*Head;

int vertex;

void Adjlist()
{
   int i,j,degree;

   struct Node *temp,*temp1,*temp2;

   cout<<"\n\nEnter The No of Locations to Visit: ";
   cin>>vertex;

   for(i=0; i<vertex; i++)
   { 
      
      temp=new struct Node;

      cout<<"\n\n Enter Location "<<i+1<<" : ";
      cin>>temp->data;

      temp->weight = 0;

      temp->Down=NULL;
      temp->Next=NULL;

      if(Head == NULL)
      {
         Head = temp;
         temp1 = Head;
      }
      else
      { 
         temp1->Down = temp;
         temp1 = temp1->Down;
      }

      cout<<"\n\n Degree Of Vertex/neighbouring Places: "<<temp1->data<<" :";
      cin>>degree;
     

     for(j=0; j<degree; j++)
     {
       temp = new struct Node;

       cout<<"\n\t Enter neighbour of Place/Vertex "<<temp1->data<<" To:";
       cin>>temp->data;

       cout<<"\n\t Enter The Distance from "<<temp1->data<<" :";
       cin>>temp->weight;

       temp->Down = NULL;
       temp->Next = NULL;

       if(temp1->Next == NULL)
       {
          temp1->Next = temp;
          temp2 = temp;
       }
       else
       {
          temp2->Next = temp;
          temp2 = temp2->Next;
       }
     }
   
   }
}

void display()
{
  struct Node *temp1,*temp2;

  temp1 = Head;

  while(temp1 != NULL)
  {
     cout<<"\n "<<temp1->data<<"--:";
     temp2 = temp1->Next;

     while(temp2 != NULL)
     {
        cout<<"---->"<<temp2->data<<"( "<<temp2->weight<<" )";
        temp2 = temp2->Next;
     }
    temp1 = temp1->Down;
    cout<<"\n |";
  }
}



int unvisited(char route[], int cnt, char data)
{
    int i=0;
    while(i < cnt)
    {
       if(route[i] == data)
          return 0;
	i++;
    } 
    return 1;    
}

void min_Sptree()
{
    struct Node *temp1,*temp2;
    char route[10];
    int cnt = 0;
    int min = 0;
    int cost = 0;
    int i = 0;
    char vtx;

    temp1 = Head;
    route[cnt++] = temp1->data;
 
    while(i < vertex-1)
    {
        min  = 999;
        temp2 = temp1->Next;
         
       	while(temp2)
        {
           if(min > temp2->weight && unvisited(route, cnt, temp2->data))
           {
              min = temp2->weight;
	      vtx = temp2->data;
           }

           temp2 = temp2->Next;
        }

        cost = cost + min;
        route[cnt++] = vtx;
 
	temp1 = Head;
        while(temp1->data != vtx)
           temp1 = temp1->Down;

        i++;
    }

    cout<<"\n\n\t Route: ";
    for(i=0; i<cnt; i++)
       cout<<route[i]<<"---->";

    cout<<"\n\n\t Minimum Spanning Tree's (MST) Min Cost: "<<cost;
    
     
}


int main()
{

  cout<<"\n\n -------- Shortest path for Tour --------\n\n";

  Adjlist();

  cout<<"\n\n -------- Adjacency List Representation -------\n\n";
  display();

   
  min_Sptree();

  cout<<"\n\n";

  return 0;

}

/*---------------OUTPUT------------------------

student@IOE-L1LAB:~$ g++ Pr_4B.cpp -o a
student@IOE-L1LAB:~$ ./a


 -------- Shortest path for Tour --------



Enter The No of Locations to Visit: 3


 Enter Location 1 : A


 Degree Of Vertex/neighbouring Places: A :2

	 Enter neighbour of Place/Vertex A To:B

	 Enter The Distance from A :80

	 Enter neighbour of Place/Vertex A To:C

	 Enter The Distance from A :60


 Enter Location 2 : B


 Degree Of Vertex/neighbouring Places: B :2

	 Enter neighbour of Place/Vertex B To:A

	 Enter The Distance from B :80

	 Enter neighbour of Place/Vertex B To:C

	 Enter The Distance from B :50


 Enter Location 3 : C


 Degree Of Vertex/neighbouring Places: C :2

	 Enter neighbour of Place/Vertex C To:A

	 Enter The Distance from C :60

	 Enter neighbour of Place/Vertex C To:B

	 Enter The Distance from C :50


 -------- Adjacency List Representation -------


 A--:---->B( 80 )---->C( 60 )
 |
 B--:---->A( 80 )---->C( 50 )
 |
 C--:---->A( 60 )---->B( 50 )
 |

	 Route: A---->C---->B---->

	 Minimum Spanning Tree's (MST) Min Cost: 110

student@IOE-L1LAB:~$ 


*/


  

