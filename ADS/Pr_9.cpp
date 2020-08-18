/*
Pr No: 09
Title  : Read the marks obtained by students of second year in an online examination of particular
	subject. Find out maximum and minimum marks obtained in that subject. Use heap data
	structure. Analyze the algorithm.
Batch: 'C'
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
}*root;


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
     
     if(Parent->marks < Parent->left->marks)
     {
           marks = Parent->marks;
           Parent->marks = Parent->left->marks;
           Parent->left->marks = marks;
     }
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
 
 void Minheapify(struct BinNode *Parent)
{
     int marks;
     
     if(Parent->marks > Parent->left->marks)
     {
           marks = Parent->marks;
           Parent->marks = Parent->left->marks;
           Parent->left->marks = marks;
     }
     if(Parent->marks > Parent->right->marks)
     {
           marks = Parent->marks;
           Parent->marks = Parent->right->marks;
           Parent->right->marks = marks;
     }
}
 
 void create_Minheap(struct BinNode *Root)
 {
      Minheapify(Root->left);
      Minheapify(Root->right);
      Minheapify(Root);
      Minheapify(Root->left);
      Minheapify(Root->right);            
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


int main()
{
     
     
     root = NULL;
     
     cout<<"\n\n\t * * * * * Creating Binary Tree";
     root = create_bintree(root);
     
     cout<<"\n\n\t * * * * * Creating Max Heap Tree : ";
     create_Maxheap(root);    
     
     disp_Bintree(root); 
     cout<<"\n\n\t Maximum marks at Root = "<<root->marks;

     cout<<"\n\n\t * * * * * Creating Min Heap Tree : ";
     create_Minheap(root);    
     
     disp_Bintree(root); 
     cout<<"\n\n\t Minimum marks at Root = "<<root->marks;


    cout<<"\n\n";
    return 0;
}


/*-----------------OUTPUT------------------------
student@IOE-L1LAB:~$ g++ Pr_9B.cpp -o a
student@IOE-L1LAB:~$ ./a


	 * * * * * Creating Binary Tree
	 
	 Enter marks: 5

	 Enter marks: 8

	 Enter marks: 12

	 Enter marks: 22

	 Enter marks: 21

	 Enter marks: 16

	 Enter marks: 19


	 * * * * * Creating Max Heap Tree :  22  21  5  8  19  12  16

	 Maximum marks at Root = 22

	 * * * * * Creating Min Heap Tree :  5  8  22  21  12  19  16

	 Minimum marks at Root = 5

student@IOE-L1LAB:~$ 


*/


