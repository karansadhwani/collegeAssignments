#include<iostream>
#include<stack>
using namespace std;
int main()
{
stack<int>a;
int item;
char ans;
int choice;
  {
     cout<<"\n Main menu:";
     cout<<"\n1.Push:";
     cout<<"\n2.Pop:";
     cout<<"\n3.   Display:";
     cout<<"\n Enter ur choice:";
     cin>>choice;
     switch(choice)
        case 1:
        cout<<"\n Enter the element to push";
        cin>>item;
        s.push(item);
        break;
        
        case 2:
        if(!s.empty())
        {
           s.pop();
           cout<<"pop item:";
           else
           cout<<"stack is empty:";
           break;
        }   

        case 3:
        if(!s.empty())
        {
           cout<<"element of stack:"<<s.top;
           else
           cout<<"stack is empty:";
           break;
        }
        
        cout<<"Do u want to continue?";
        cin>>ans;
         while(ans=='y')
  }
        
      
        return 0;
}   

        
        
