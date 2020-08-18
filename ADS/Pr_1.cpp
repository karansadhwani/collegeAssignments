/*
Pr No: 01
Title: For given expression eg. a-b*c-d/e+f construct inorder sequence and traverse it using
postorder traversal(non recursive).
Class: SE Computer Engineering
Batch: 'C'
Roll no: 46
Started On: 4/1/2018
Completed On: 8/1/2018
*/

// Infix -> Postfix -> Create_Tree  ->  Traverse by Postorder

struct node
{ 
   char data;
   struct node *left;
   struct node *right;   
}*root;


#include<iostream>
using namespace std;

char infix[20];		//Global Variables
char postfix[20];

void infix_to_postfix()
{   
   int i, j, top;
   char stack[5];
   char garbage;
   
   i = j = 0;
   top = -1;
   
   cout<<"\n\n\t Enter Input(Infix) Expression: ";
   cin>>infix;
   
   for(i=0; infix[i] != '\0'; i++)
   {
      if(infix[i] == 'a' || infix[i] == 'b' || infix[i] == 'c' || infix[i] == 'd' || infix[i] == 'e' || infix[i] == 'f')
      {
          postfix[j] = infix[i];
                  j++;
      }
      if(infix[i] == '+' ||infix[i] == '-' ||infix[i] == '*' ||infix[i] == '/')
      {
          top++;         
          stack[top] = infix[i];
      }
      if(infix[i] == '(')
      {
          top++;         
          stack[top] = infix[i];
      }
      if(infix[i] == ')' )
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


struct node *create_tree()
{
      int i, top = -1;
      struct node *temp, *tmp1, *tmp2;
      struct node *stack[5];
      
      for(i=0; postfix[i] != '\0'; i++)
      {
          if(postfix[i] == 'a' || postfix[i] == 'b' || postfix[i] == 'c' || postfix[i] == 'd' || postfix[i] == 'e' ||postfix[i]== 'f')
          {
              temp = new struct node;	//1. Create Node
              
              temp->data = postfix[i];	//2. Assign data & Pointers
              
              temp->left = NULL;
              temp->right = NULL;
              
              top++;         		//3. Push to Stack
              stack[top] = temp; 
              
          }
          if(postfix[i] == '+' ||postfix[i] == '-' ||postfix[i] == '*' ||postfix[i] == '/')          
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


void post_order(struct node *R)
{
   if(R)
   {
      post_order(R->left); 
      post_order(R->right);
      cout<<"  "<<R->data;     
   }
}



int main()
{
  root = NULL;
  
  infix_to_postfix();
  
  root = create_tree();
  
  cout<<"\n\n\t The Post-oreder Tree Traversal: ";
  post_order(root);
  
  cout<<"\n\n";
  return 0;
}


/*
student@IOE-L1LAB:~$ g++ Pr_1B.cpp -o a
student@IOE-L1LAB:~$ ./a


	 Enter Input(Infix) Expression: ((a+b)*(c-d))/(e+f)


	 The Postfix Expression : ab+cd-*ef+/

	 The Post-oreder Tree Traversal:   a  b  +  c  d  -  *  e  f  +  /

*/
























































