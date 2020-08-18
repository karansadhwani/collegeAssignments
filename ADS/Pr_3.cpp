/*
Pr No: 03
Title:You have a business with several offices; you want to lease phone lines to connect them up
with each other; and the phone company charges different amounts of money to connect
different pairs of cities. You want a set of lines that connects all your offices with a minimum
total cost. Solve the problem by suggesting appropriate data structures.

Class: SE Computer Engineering
Batch: C
Roll no: 46	
Started On: 15-Jan-2018
Completed On: 22-Jan-2018
*/

#include<iostream>		// HEADER FILES
using namespace std;

class Graph			// CLASS TO IMPLEMENT GRAPH DATA STRUCTURE USING ARRAY
{
   int Mtx[5][5]; 
   int nodes;

   
   public:
   
     void create_Graph();
     void disp_Graph();   
     char* city(int x);
     int unvisited(int route[], int v);
     void find_Min_Cost();
}G1;


char* Graph :: city(int x)		// FUNCTION TO RETURN OFFICE NAME FOR INDEX: 0-3
{
   if(x == 0)
      return "Office-1";
   if(x == 1)
      return "Office-2";
   if(x == 2)
      return "Office-3";
   if(x == 3)
      return "Office-4";                  
}


void Graph :: create_Graph()		// FUNCTION TO CREATE GRAPH's ARRAY REPRESENTATION
{
    int i, j;
    int dist;
    
    cout<<"\n\n\t Enter the no of Offices/Cities: ";
    cin>>nodes;
    
    for(i=0; i<nodes; i++)
    {
       for(j=0; j<nodes; j++)
       {
          cout<<"\n\n Enter cost to connect "<<city(i)<<" to "<<city(j)<<" (Lakhs):";         
          cin>>Mtx[i][j];
       }
    }
}




void Graph :: disp_Graph()		// FUNCTION TO DISPLAY GRAPH's ARRAY REPRESENTATION
{
    int i, j;
    
    cout<<"\n\n\t --- Graph Representation using Matrix ---";
    for(i=0; i<nodes; i++)
    {
       cout<<"\n\n\t\t";
       for(j=0; j<nodes; j++)
       {
          cout<<"  "<<Mtx[i][j];          
       }
    }
}

     

int Graph :: unvisited(int route[], int v)	// FUNCTION TO CHECK UNVISITED VERTEX OF GRAPH
{
   for(int l = 0; l<nodes; l++)
   {
       if(route[l] == v)
          return 0;
   }
   return 1;
}




void Graph :: find_Min_Cost()		// FUNCTION TO FIND MIN_COST
{
   int i, j, temp, cnt = 0;
   int row, col;
   int min, min_cost;
   int route[5];
   
   min = min_cost = 0;
   row = col = 0;
   route[cnt] = row;
       
   do
   {    
       min = 999;   
       for(j=0; j<nodes; j++)
       {
          if(unvisited(route, j) )
          {
             col = j;
             if(min > Mtx[row][col])
             {
                min = Mtx[row][col];
                temp = col;
             }
          }
       }

       row = temp;
       cnt = cnt + 1;
       route[cnt] = row;
       min_cost = min_cost + min;
       
     }while(cnt < nodes-1);
       
     cout<<"\n\n\t Lease Line's Route: ";
     for(i=0; i<nodes; i++)
        cout<<"-->"<<city( route[i] );
        
     cout<<"\n\n\t Needed Min Cost: "<<min_cost<<" Lakhs";     
}




int main()
{

   cout<<"\n\n -----*** Lease Line Network Setup using Graph Data Structure ***-----";

   G1.create_Graph();
   
   G1.disp_Graph();
   
   G1.find_Min_Cost();

   cout<<"\n\n";
   
   return 0;
   
}




/*--------------------OUTPUT-------------------------------------

student@IOE-L1LAB:~$ g++ Pr_3BC.cpp -o a

Pr_3BC.cpp: In member function ‘char* Graph::city(int)’:
Pr_3BC.cpp:34:14: warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
       return "Office-1";
              ^
Pr_3BC.cpp:36:14: warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
       return "Office-2";
              ^
Pr_3BC.cpp:38:14: warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
       return "Office-3";
              ^
Pr_3BC.cpp:40:14: warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
       return "Office-4";                  
              ^
student@IOE-L1LAB:~$ ./a


 -----*** Lease Line Network Setup using Graph Data Structure ***-----

	 Enter the no of Offices/Cities: 4


 Enter cost to connect Office-1 to Office-1 (Lakhs): 0


 Enter cost to connect Office-1 to Office-2 (Lakhs): 6


 Enter cost to connect Office-1 to Office-3 (Lakhs): 2


 Enter cost to connect Office-1 to Office-4 (Lakhs): 4


 Enter cost to connect Office-2 to Office-1 (Lakhs): 6


 Enter cost to connect Office-2 to Office-2 (Lakhs): 0


 Enter cost to connect Office-2 to Office-3 (Lakhs): 1


 Enter cost to connect Office-2 to Office-4 (Lakhs): 3


 Enter cost to connect Office-3 to Office-1 (Lakhs): 2


 Enter cost to connect Office-3 to Office-2 (Lakhs): 1


 Enter cost to connect Office-3 to Office-3 (Lakhs): 0


 Enter cost to connect Office-3 to Office-4 (Lakhs): 2


 Enter cost to connect Office-4 to Office-1 (Lakhs): 4


 Enter cost to connect Office-4 to Office-2 (Lakhs): 3


 Enter cost to connect Office-4 to Office-3 (Lakhs): 5


 Enter cost to connect Office-4 to Office-4 (Lakhs): 0


	 --- Graph Representation using Matrix ---

		  0  6  2  4

		  6  0  1  3

		  2  1  0  2

		  4  3  5  0

	 Lease Line's Route: -->Office-1-->Office-3-->Office-2-->Office-4

	 Needed Min Cost: 6 Lakhs

student@IOE-L1LAB:~$ 
*/






