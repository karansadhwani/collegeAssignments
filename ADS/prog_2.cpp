#include<iostream>
#include<cstring>
using namespace std;
class student
{

        int rno,cls;
        char tpn[12];
        char dln[10];
        char dob[10];
        char add[80];
        char name[20],bg[3];
        char div[30];
public:
friend class info;
static int count;
student()
{
        strcpy(name,"KARAN SADHWANI" );
        strcpy(dob,"16/04/1999" );
        strcpy(add,"NASHIK ROAD" );
        rno=36;
        strcpy(bg,"A+");
        strcpy(div,"A");
        strcpy(dln,"98932569");
        strcpy(tpn,"7350952544");
}
student(int rno,char tpn[],char dln[] ,char dob[],char add[] ,char name[],char bg[],char div[])
{
        strcpy(this->name,name);
        strcpy(this->dob,dob);
        strcpy(this->add,add);
        this->rno=rno;
        strcpy(this->bg,bg);
        strcpy(this->div,div );
        strcpy(this->dln,dln );
        strcpy(this->tpn,tpn );
}

~student()
{

        cout<<"Constructor is Destroyed\n";
}
};
class info
{
student p;
public:
void getdata()
{
        cout<<"ENTER THE NAME :";
        cin>>p.name;
        cout<<"ENTER ROLL NO. :";
        cin>>p.rno;
        cout<<"ENTER THE TELEPHONE NO. :";
        cin>>p.tpn;
        cout<<"ENTER THE DIVISION :";
        cin>>p.div;
        cout<<"BLOOD GROUP :";
        cin>>p.bg;
        cout<<"ENTER THE ADDRESS:";
        cin>>p.add;
}
void display()
{
        cout<<" NAME :";
        cout<<p.name<<"\n";
        cout<<" ROLL NO. :";
        cout<<p.rno<<"\n";
        cout<<" TELEPHONE NO. :";
        cout<<p.tpn<<"\n";
        cout<<" DIVISION :";
        cout<<p.div<<"\n";
        cout<<"BLOOD GROUP :";
        cout<<p.bg<<"\n";
        cout<<"ADDRESS: "<<p.add<<endl;
}
};

int student::count=0;
int main()
{
student j(1,"7350952544","9899666","16/04/1999"," nashik road","karan sadhwani","a+","b");
        info mn;
        mn.display();
        student m;
        info *a;
        char c;
        int n,i;
        cout<<"ENTER THE  NO. OF STUDENT:";
        cin>>n;
        a=new info[n];
        for( i=0;i<n;i++){
        a[i].getdata();
  
}
        for(i=0;i<n;i++){
        a[i].display();
  
}



return 0;

}
