/*
Practical No: 8
Title: A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
	deleting keywords, updating values of any entry. Provide facility to display whole data sorted
	in ascending/ Descending order. Also find how many maximum comparisons may require for
	finding any keyword. Use Height balance tree and find the complexity for finding a keyword
Class: SE Comp		
Batch: C 		
Roll No: 46
*/
#include<iostream>
#include<cstring>
using namespace std;

struct Node
{
	char key[15];
	char mean[15];
	struct Node *l;
	struct Node *r;
	int bf;
}*temp;

struct Node* createHBT(struct Node *h)
{
	temp=new(struct Node);
	cout<<"Enter the Keyword: ";
	cin>>temp->key;
	cout<<"Enter the meaning of "<<temp->key<<": ";
	cin>>temp->mean;
	temp->l=NULL;
	temp->r=NULL;
	h=temp;
	return h;
}

void insertKey(struct  Node *h,char keyword[])
{
	if(strcmp(keyword,h->key)<0)
	{
		if(h->l!=NULL)
			insertKey(h->l,keyword);
		else
		{
			temp=new(struct Node);
			strcpy(temp->key,keyword);
			cout<<"Enter the meaning of "<<keyword<<": ";
			cin>>temp->mean;
			temp->l=NULL;
			temp->r=NULL;
			h->l=temp;
		}
	}
	else if(strcmp(keyword,h->key)>0)
	{
		if(h->r!=NULL)
			insertKey(h->r,keyword);
		else
		{
			temp=new(struct Node);
			strcpy(temp->key,keyword);
			cout<<"Enter the meaning of "<<keyword<<": ";
			cin>>temp->mean;
			temp->l=NULL;
			temp->r=NULL;
			h->r=temp;
		}
	}
}

void display(struct Node *h)
{
	if(h!=NULL)
	{
	display(h->l);
	cout<<endl<<"  "<<h->key<<"\t\t "<<h->mean;	
	display(h->r);
	}
}

int search(struct Node *h, char keyword[]){
	int f=0;
	if(strcmp(keyword,h->key)==0){
		cout<<"\nKey Found.";
		cout<<"\n"<<h->key<<"\t\t  "<<h->mean;
		f=1;
	}
	else if(strcmp(keyword,h->key)<0)
	{
		if(h->l!=NULL)
			search(h->l,keyword);
	}
	else if(strcmp(keyword,h->key)>0)
	{
		if(h->r!=NULL)
			search(h->r,keyword);
	}
return f;
}
		
int main()
{
	struct Node *Head=new(struct Node);
	int ch,i;
	char c,k[15];
	do{
		cout<<"------ Height Balanced Tree ------\n1. Create HBT\n2. Insert Node\n3. Display Tree\n4. Search Key\n5.Exit";
		cout<<"\nWhich operation do you want to perform: ";
		cin>>ch;
		switch(ch){
			case 1:
				Head=createHBT(Head);
			break;
			
			case 2:
				cout<<"Enter the keyword: ";
				cin>>k;
				insertKey(Head,k);
			break;
			
			case 3:
				cout<<" Keyword      Meaning      Balance Factor";
				display(Head);
			break;
			
			case 4:
				cout<<"Enter the keyword: ";
				cin>>k;
				
				i=search(Head,k);
				if(i==0)
				cout<<"Key Not Found !!!";
			break;
			
			case 5:
				c='N';
			break;
		}
		if(c!='N'){
		cout<<"\nDo you want to continue?...=> ";
		cin>>c;
		}
	}while(c=='y'||c=='Y');
	
return 0;
}

