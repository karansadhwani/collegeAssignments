/*
Pr No: 12
Title: Department maintains a student information. The file contains roll number, name, division and address. Allow user to add, delete information of student. Display information of particular employee. If record of student does not exist an appropriate message is displayed. If it is, then the system displays the student details. Use sequential file to main the data.
*/

#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct Student
{
   int Roll;
	char Name[20];
	char Addr[20];
};

int main()
{	
	Student s1,s2;
	int i, cnt = 3;
	
	ofstream fout;
	fout.open("Stud_Info", ios::out | ios::binary);    // open output file
	if(!fout)
	{
		 cout<<"File can\'t be opened..!!\n";
		 exit(1);
	}
   else
   {
	   for(i=0; i<cnt; i++)
	   {
	     cout<<"\n\n Enter Student's Roll: ";
	     cin>>s1.Roll;
	     cout<<"\n Enter Student's Name: ";
	     cin>>s1.Name;
	     cout<<"\n Enter Student's Address: ";
	     cin>>s1.Addr;

	     fout.write((char *) & s1, sizeof(Student));    // write to file	      
      }          
   }
   fout.close();	  // close connection
   
	                     // read it back now
	ifstream fin;
	fin.open("Stud_Info", ios::in | ios::binary);    // open input file
		
	
	cout<<"\n\n Students Records:----*********";
	cout<<"\n\n Roll  Name  Address\n";
	for(i=0; i<cnt; i++)
	{
	   fin.read((char *) & s2, sizeof(Student));     // read structure 
	   
	   cout<<"\n "<<s2.Roll;
	   cout<<"\t "<<s2.Name; 
	   cout<<"   "<<s2.Addr; 
	}
	
	fin.close();
	
	cout<<"\n\n";
	return 0;

}


/*
student@IOE-L1LAB:~$ g++ Pr_12ABCD.cpp -o a
student@IOE-L1LAB:~$ ./a


 Enter Student's Roll: 11

 Enter Student's Name: Yash

 Enter Student's Address: Nashik


 Enter Student's Roll: 19

 Enter Student's Name: Bharati

 Enter Student's Address: Pimplagaon


 Enter Student's Roll: 32

 Enter Student's Name: Suvidnya

 Enter Student's Address: Nashik


 ***---Students Records:----*********

 Roll  Name  Address

 11	 Yash   Nashik
 19	 Bharati   Pimplagaon
 32	 Suvidnya   Nashik

*/
