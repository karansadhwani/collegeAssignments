/*
Practical No: Implement the Heap/Shell sort algorithm implemented in Java demonstrating heap/shell data
		   structure with modularity of programming language.
Class: SE
Batch: C
Roll No: 46			

*/

/*
Pr No: 09
Title  : Read the marks obtained by students of second year in an online examination of particular
	subject. Find out maximum and minimum marks obtained in that subject. Use heap data
	structure. Analyze the algorithm.
Batch: 'B'
Started On : 22/03/2018
Completed On: 22/03/2018	
*/

#include<iostream>
using namespace std;

struct BinNode
{
     int marks;
     struct BinNode *left;
     struct BinNode *right;
}*root,*last;


struct BinNode * createNode()
{
     struct BinNode * tmp;
     
     tmp = new struct BinNode;
     
     cout<<"\n\t Enter marks: ";
     cin>>tmp->marks;
     
     tmp->left = NULL;
     tmp->right = NULL;
     
     return tmp;     
}


struct BinNode * create_bintree(struct BinNode *Root)
{
      int i, level=3;
      
      for(i=0; i<level; i++)
      {
           if(i == 0)
           {
                if(Root == NULL)
                   Root = createNode();
                else
                   cout<<"\n\t Root is not initialised !!!";   
           }
           if(i == 1)
           {
                 Root->left = createNode();
                 Root->right = createNode();
           }
           if(i == 2)
           {
                 Root->left->left = createNode();
                 Root->left->right = createNode();
                 
                 Root->right->left = createNode();
                 Root->right->right = createNode();
           }
      }
      
      return Root;
}

void Maxheapify(struct BinNode *Parent)
{
     int marks;
     if(Parent->left)
     if(Parent->marks < Parent->left->marks)
     {
           marks = Parent->marks;
           Parent->marks = Parent->left->marks;
           Parent->left->marks = marks;
     }
     if(Parent->right)
     if(Parent->marks < Parent->right->marks)
     {
           marks = Parent->marks;
           Parent->marks = Parent->right->marks;
           Parent->right->marks = marks;
     }
}


 void create_Maxheap(struct BinNode *Root)
 {
      Maxheapify(Root->left);
      Maxheapify(Root->right);
      Maxheapify(Root);
      Maxheapify(Root->left);
      Maxheapify(Root->right);            
 }
 
 
void  disp_Bintree(struct BinNode *Root)
{
    if(Root)
    {
         cout<<"  "<<Root->marks;
         disp_Bintree(Root->left);
         disp_Bintree(Root->right);
    }
}


void swap(struct BinNode *r,struct BinNode *l)
{
	int m;
	m=r->marks;
	r->marks=l->marks;
	l->marks=m;
}


struct BinNode*  Delnode(struct BinNode *R)
{
	cout<<"\tSorted List: ";
	last = new struct BinNode;
	
	last = R->right->right;
	swap(R,last);
	R->right->right=NULL;
	cout<<last->marks<<"  ";
	Maxheapify(R);
	
	last=R->right->left;
	swap(R,last);
	R->right->left=NULL;
	cout<<last->marks<<"  ";
	Maxheapify(R);
	
	last = R->left->right;
	swap(last,R);
	R->left->right=NULL;
	cout<<last->marks<<"  ";
	Maxheapify(R);
	
	last = R->left->left;
	swap(last,R);
	R->left->left=NULL;
	cout<<last->marks<<"  ";
	Maxheapify(R);
	
	last = R->right;
	swap(last,R);
	R->right=NULL;
	cout<<last->marks<<"  ";
	Maxheapify(R);
	
	last = R->left;
	swap(last,R);
	R->left=NULL;
	cout<<last->marks<<"  ";
	Maxheapify(R);

	cout<<R->marks<<endl;
	
}

int main()
{
     
     
     root = NULL;
     
     cout<<"\n\n\t * * * * * Creating Binary Tree";
     root = create_bintree(root);
     
     cout<<"\n\n\t * * * * * Creating Max Heap Tree : ";
     create_Maxheap(root);    
     
     disp_Bintree(root); 
     cout<<"\n\n\t Maximum marks at Root = "<<root->marks<<endl;

     Delnode(root);
    
     
   
    return 0;
}
/*
OUTPUT:

student@IOE-L1LAB:~/Documents/SE_29_ADSL$ ./a.out


	 * * * * * Creating Binary Tree
	 Enter marks: 40

	 Enter marks: 30

	 Enter marks: 20

	 Enter marks: 70

	 Enter marks: 50

	 Enter marks: 80

	 Enter marks: 100


	 * * * * * Creating Max Heap Tree :   100  50  30  40  80  20  70

	 Maximum marks at Root = 100
	Sorted List: 100  80  70  50  40  30  20

*/
