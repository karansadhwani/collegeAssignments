#include "iostream"
#include "iomanip"
using namespace std;
class personal
{
 protected:
        char name[20];
        char address[30];
        char DOB[10];
        char gender[2];
public:
        void get_personal();        

};

class professional
{
protected:
        int exp_years;
        char college[20];
        char department[10];
        char expert[20];
public:
        void get_professional();
                
};

class academic
{
protected:
        int year_passed;
        int marks;
        float percentage;
        char grade[10];
public:
      void get_academic();  

};

class biodata:public personal,public professional, public academic
{
public:
        void display();
        
};

void personal::get_personal(){
        cout<<"Enter the name of the student"<<endl;
        cin>>name;
        cout<<"Enter the address"<<endl;
        cin>>address;
        cout<<"Enter the Date Of Birth"<<endl;
        cin>>DOB;
        cout<<"Enter the Gender (M/F)"<<endl;
        cin>>gender;
}

void professional:: get_professional(){
        cout<<"Enter the Years Of EXPERIENCE"<<endl;
        cin>>exp_years;
        cout<<"Enter the college name from which you have passed out Engineering"<<endl;
        cin>>college;
        cout<<"Enter Your Department"<<endl;
        cin>>department;
        cout<<"Enter the field in which you are Expert"<<endl;
        cin>>expert;

}

void academic::get_academic(){
        cout<<"Enter the passed out year"<<endl;
        cin>>year_passed;
        cout<<"Enter the marks scored in Final Year (Out of 1000)"<<endl;
        cin>>marks;
        cout<<"Enter the Percentage scored in Final Year "<<endl;
        cin>>percentage;
        cout<<"Class Got in Final Year(distinction,first,second....)"<<endl;
        cin>>grade;
}

void biodata :: display(){
        cout<<"..........>>>> BIODATA <<<<.........."<<endl<<endl;
        
        
        cout<<"..........>>>> Personal Information <<<<.........."<<endl;
        cout<<"Name"<<setw(20)<<"Address"<<setw(20)<<"DOB"<<setw(20)<<"gender"<<endl;
        cout<<name<<setw(18)<<address<<setw(22)<<DOB<<setw(18)<<gender<<endl<<endl;
        
        
        cout<<"..........>>>> Professional Information <<<<.........."<<endl;
        cout<<"Years of Experience"<<setw(20)<<"College"<<setw(20)<<"Department"<<setw(20)<<"Expert In:"<<endl;
        cout<<exp_years<<setw(35)<<college<<setw(25)<<department<<setw(18)<<expert<<endl<<endl;
        
        
        cout<<"..........>>>> Academic Information <<<<.........."<<endl;
        cout<<"Passed out Year"<<setw(20)<<"Marks"<<setw(20)<<"Percentage"<<setw(20)<<"Class"<<endl;
        cout<<year_passed<<setw(30)<<marks<<setw(20)<<percentage<<setw(20)<<grade<<endl;
}

int main(){
        biodata b;
        b.get_personal();
        b.get_professional();
        b.get_academic();
        b.display();


return 0;
}
