/* Practical No:-5

Title:-Consider telephone book database of N clients. Make use of a hash table implementation to
        quickly look up client‘s telephone number.
Roll no :46
Batch:C
Started on:29-1-2018
Completed on:2-2-2018  */


#include<iostream>
#include<string.h>
using namespace std;

int table_size=10;

struct tel_db
{
	char name[10];
	long int tel_no;
}ht[10];



void accept()
{
	char nm[10];
	int i,j,cnt,record,key;

	cout<<"Enter the no. of Client : ";
	cin>>record;

	for(i=0;i<record;i++)
	{
		cout<<"Enter the name of client"<<i+1<<":";
		cin>>nm;


		j=cnt=0;
		while(nm[j]!='\0')
			{
				cnt=cnt+nm[j];
				j++;
			}

			key=cnt % table_size;

		strcpy(ht[key].name, nm);
		cout<<"Enter the telephone no.:";
		cin>>ht[key].tel_no;
	}

}


void display()
{
	int i;
	cout<<"Index Name Tel_no";
	for(i=0;i<table_size;i++)
	{

	cout<<"\n    "<<i;

	cout<<"     "<<ht[i].name;
	cout<<"     "<<ht[i].tel_no;
	cout<<"\n";

	}
}


void lookup()
{
	int i,j,key,cnt;

	char nm[10];
	cout<<"\n\n Enter client name:";
	cin>>nm;
	j=cnt=0;

	while(nm[j]!='\0')
	{
	cnt=cnt+nm[j];
	j++;
	}

	key=cnt % table_size;

	cout<<"Telephone no:"<<ht[key].tel_no;
}


int main()
{

	cout<<"------Hash Table------"<<endl;
	accept();
	display();
	lookup();
	cout<<"\n\n";

	return 0;
}



/*  student@localhost:~$ gedit pr_5.cpp
student@localhost:~$ g++ pr_5.cpp -o a
student@localhost:~$ ./a

------Hash Table------
Enter the no. of Client : 2
Enter the name of client1:sam
Enter the telephone no.:121

Enter the name of client2:pam
Enter the telephone no.:2222

Index Name Tel_no
    0          0

    1     sam     121

    2          0

    3          0

    4          0

    5          0

    6          0

    7          0

    8     pam     2222

    9          0


 Enter client name:pam
Telephone no:2222
*/













