
/*
Pr No: 02
Title: Read for the formulas in propositional calculus. Write a function that reads such a formula and creates its binary tree representation. What is the complexity of your function?
Class: SE Computer Engineering
Roll no: 46
Batch: 'C'
Started On: 11/1/2018
Completed On: 18/1/2018
*/

//Input: P & (Q | R)  = ( (P & Q) | (P & R) ) = ( (P&Q) | (P&R) ) 
//Postfix : PQ&PR&|
//OUTPUT  : P & Q | P & R

#include<iostream>
using namespace std;

struct node
{ 
   char data;
   struct node *left;
   struct node *right;   
}*root;




char Prop_Form[20];		//Global Variables
char postfix[20];

void Prop_Form_to_postfix()
{   
   int i, j, top;
   char stack[5];
   char garbage;
   
   i = j = 0;
   top = -1;
   
   cout<<"\n\n\t Enter Input(Prop_Form) Expression: ";
   cin>>Prop_Form;
   
   for(i=0; Prop_Form[i] != '\0'; i++)
   {
      if(Prop_Form[i] == 'P' || Prop_Form[i] == 'Q' || Prop_Form[i] == 'R')
      {
          postfix[j] = Prop_Form[i];
                  j++;
      }
      if(Prop_Form[i] == '&' ||Prop_Form[i] == '|')
      {
          top++;         
          stack[top] = Prop_Form[i];
      }
      if(Prop_Form[i] == '(')
      {
          top++;         
          stack[top] = Prop_Form[i];
      }
      if(Prop_Form[i] == ')' )
      {
         while( stack[top] != '(' )
         {
             postfix[j] = stack[top];
             top--;
             j++;
         }
         garbage = stack[top];
             top--;
      }
   }
   
   while( top != -1 )
   {
         postfix[j] = stack[top];
         top--;
         j++;
   }
   
   postfix[j] = '\0';
   
   cout<<"\n\n\t The Postfix Expression : "<<postfix;
   
}


struct node *create_BTtree()
{
      int i, top = -1;
      struct node *temp, *tmp1, *tmp2;
      struct node *stack[5];
      
      for(i=0; postfix[i] != '\0'; i++)
      {
          if(postfix[i] == 'P' || postfix[i] == 'Q' || postfix[i] == 'R')
          {
              temp = new struct node;	//1. Create Node
              
              temp->data = postfix[i];	//2. Assign data & Pointers
              
              temp->left = NULL;
              temp->right = NULL;
              
              top++;         		//3. Push to Stack
              stack[top] = temp; 
              
          }
          if(postfix[i] == '&' ||postfix[i] == '|' )          
          {
              temp = new struct node;	//1. Create Node
              
              temp->data = postfix[i];  //2. Assign data & Pointers            
              
              temp->right = stack[top--];
              temp->left = stack[top--];
              
              top++;         		//3. Push to Stack
              stack[top] = temp; 
             
          }
      }
      
      return stack[top--];
      
}


void In_order(struct node *R)
{
   if(R)
   {
      In_order(R->left); 
      cout<<"  "<<R->data;       
      In_order(R->right);
          
   }
}



int main()
{
  root = NULL;
  
  Prop_Form_to_postfix();
  
  root = create_BTtree();
  
  cout<<"\n\n\t The Post-oreder Tree Traversal: ";
  In_order(root);
  
  cout<<"\n\n";
  return 0;
}


/*
student@ubuntu:~$ g++ Pr_2B23.cpp -o a
student@ubuntu:~$ ./a


	 Enter Input(Prop_Form) Expression: ((P&Q)|(P&R))


	 The Postfix Expression : PQ&PR&|

	 The Post-oreder Tree Traversal:   P  &  Q  |  P  &  R


*/


























































