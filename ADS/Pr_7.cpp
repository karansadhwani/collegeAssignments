/*
Pr No: 07
Title: Given sequence k = k1 <k2 < ... < kn of n sorted keys, with a search probability pi for each
	key ki . Build the Binary search tree that has the least search cost given the access probability
	for each key.
	
Class: Computer Engineering
Batch: 'C'
Started On: 12/02/2018
Completed On: 16/02/2018
*/

#include<iostream>
using namespace std;

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
}*root;

struct BST *create_BST(struct BST *R)
{
    struct BST *temp;
   
    temp = new struct BST;	//Step 1: Allocate Memory
   
    cout<<"\n\n\t Enter data for root: ";	//Step 2: Assigning Data & Pointers
    cin>>temp->data;
   
    temp->left = NULL;
    temp->right = NULL;
   
    if(R == NULL)
       R = temp;
      
    return R;   
}

struct BST *createNode()
{
   struct BST *tmp;
   
   tmp = new struct BST;	//Step 1: Allocate Memory
   
   cout<<"\n\n\t Enter data for new node: ";	//Step 2: Assigning Data & Pointers
   cin>>tmp->data;
   
   tmp->left = NULL;
   tmp->right = NULL;
   
   return tmp;
   
}

struct BST *insert(struct BST *Root, struct BST *NewNode)
{
    if(NewNode->data < Root->data)
    {
       if(Root->left == NULL)
          Root->left = NewNode;
       else
          insert(Root->left, NewNode);   
    }
    else
    {
       if(Root->right == NULL)
          Root->right = NewNode;
       else
          insert(Root->right, NewNode);   
    }
}

void disp_inorder(struct BST *R)
{
   if(R != NULL)
   {
      disp_inorder(R->left);
      cout<<"  "<<R->data;      
      disp_inorder(R->right);      
   }
}



void search(struct BST *Root)
{
    struct BST *temp;
    float cost = 0;

    int di = 0;
    temp = Root;
    
    cout<<"\n\n\tSr. \t Node \t Pi \t di \t cost \n";
    while(temp)
    {
        cout<<"\n\t "<<di+1;
        cout<<"\t "<<temp->data;
        cout<<"\t 0.1";
        cout<<"\t "<<di;
        cout<<"\t "<<0.1 * di;

        cost = cost + (0.1 * di);

        temp = temp->right;
        di = di + 1;
    } 
    cout<<"\n\t Total Cost: "<<cost;
    
}


int main()
{
    int cnt,i;

    root = NULL;	
    
    root = create_BST(root);   

    struct BST *newNode; 
    
    cout<<"\n\n\t How many nodes you wanna insert: ";
    cin>>cnt;
    
    for(i=0; i<cnt; i++)
    {
        newNode = createNode();
        insert(root, newNode);
    }
   
    cout<<"\nInorder traversal::";
    disp_inorder(root);
   
    search(root);

    cout<<"\n\n";
    
    return 0;
}    
    
/*--------------------------OUTPUT-------------------------
student@IOE-L1LAB:~/SYCO-07$ gedit Pr_7A.cpp
student@IOE-L1LAB:~/SYCO-07$ g++ Pr_7A.cpp -o a
student@IOE-L1LAB:~/SYCO-07$ ./a


	 Enter data for root: 10


	 How many nodes you wanna insert: 9


	 Enter data for new node: 11


	 Enter data for new node: 12


	 Enter data for new node: 13


	 Enter data for new node: 14


	 Enter data for new node: 15


	 Enter data for new node: 16


	 Enter data for new node: 17


	 Enter data for new node: 18


	 Enter data for new node: 19

Inorder traversal::  10  11  12  13  14  15  16  17  18  19

	Sr. 	 Node 	 Pi 	 di 	 cost 

	 1	 10	 0.1	 0	 0
	 2	 11	 0.1	 1	 0.1
	 3	 12	 0.1	 2	 0.2
	 4	 13	 0.1	 3	 0.3
	 5	 14	 0.1	 4	 0.4
	 6	 15	 0.1	 5	 0.5
	 7	 16	 0.1	 6	 0.6
	 8	 17	 0.1	 7	 0.7
	 9	 18	 0.1	 8	 0.8
	 10	 19	 0.1	 9	 0.9

	 Total Cost: 4.5
*/





















































































