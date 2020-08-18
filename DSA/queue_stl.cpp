#include<iostream>
#include<queue>
using namespace std;


int main()
{
	int choice,ele;
	char ans;
	queue<int>q;
	do{
		cout<<"1.Insert the element \n2.Delete the element \n3.Size \n4.Display rear \n5.Display front"<<endl;
			cout<<"Enter your choice: "<<endl;
			cin>>choice;
			switch(choice)
			{
				case 1: cout<<"Enter the element to be inserted: "<<endl;
						cin>>ele;
						q.push(ele);
						break;
			 	case 2: ele=q.front();
			 			q.pop();
			 			cout<<"Deleted element is: "<<ele<<endl;
			 			break;
			 	case 3: cout<<"Size of stack is: "<<q.size()<<endl;
						break;
				case 4: cout<<"Element at rear: "<<q.back()<<endl;
					   	break;
				case 5: cout<<"Element at front: "<<q.front()<<endl;
						break;
			   default: cout<<"Incorrect choice!!!";
					    break;		 			
			 					
			}
		cout<<"Do you want to perform other operation? "<<endl;
		cin>>ans; 
	  }while(ans == 'y' || ans == 'Y');
}
