#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

class Student
{
	int rollno;
	string ID;
	string s_name;
	string f_name;
	class Date
	{
	public:
		int dd;
		int mm;
		int yyyy;
	}DOB;
	string b_group;
	string email;
	string mob_num;
	string addr;
	class sclass
	{
	public:
		int clss;
		char section;
	}c;
	float marks;
	string password;
	Student *next;
public:
	/**student**/
	void registration(Student **);
	string login(void);
	void save_into_file(Student *);
	/**admin**/
	void print_all(Student *);
	void view(Student *);


};






/**********admin***********/

void Student::print_all(Student *ptr)
{
	if(ptr==0)
	{
		cout<<"no record found"<<endl;
		return;
	}
	while(ptr)
	{
		cout<<ptr->mob_num<<" "<<ptr->rollno<<" "<<ptr->s_name<<" "<<ptr->DOB.dd<<"/"<<ptr->DOB.mm<<"/"<<ptr->DOB.yyyy<<" ";
		cout<<ptr->b_group<<" "<<ptr->email<<" "<<ptr->addr<<" "<<ptr->c.clss<<endl;

		ptr=ptr->next;
	}
	cout<<"all record printd sucessfully..."<<endl;
}







/**student**/
string Student::login(void)
{
	string pass,mob;
	cout<<"Enter Mobile No.:";
	cin>>mob;
	cout<<"Enter Password\t:";
	cin>>pass;
	size_t res;

	string s;
	ifstream fin;
	fin.open("student.txt");

	while(getline(fin,s))
	{
		string match = mob + " " + pass;
 		res = s.rfind(match); // pos=0 limits the search to the prefix
		if(res==0)
		{
			return s;
		}
	}
	fin.close();
	return "";
}



void Student::registration(Student **ptr)
{
	Student *_new,*last;
	_new=new Student();
	cout<<"enter the details..."<<endl;
	cout<<"Mobile No.\t:";
	cin>>_new->mob_num;
	cout<<"Password\t:";
	cin>>_new->password;
	cout<<"Roll number\t:";
	cin>>_new->rollno;
	cout<<"Name\t\t:";
	cin>>_new->s_name;
	cout<<"Date of Birth\t:";
	cin>>_new->DOB.dd>>_new->DOB.mm>>_new->DOB.yyyy;
	cout<<"Blood group\t:";
	cin>>_new->b_group;
	cout<<"Email\t\t:";
	cin>>_new->email;
	cout<<"Address\t\t:";
	cin>>_new->addr;
	cout<<"Class\t\t:";
	cin>>_new->c.clss;


	if(*ptr==0 || _new->rollno < (*ptr)->rollno)
	{
		_new->next=*ptr;
		*ptr=_new;
	}
	else
	{
		last=*ptr;
		while((last->next != 0) && (_new->rollno > last->next->rollno))
			last=last->next;
		_new->next=last->next;
		last->next=_new;
	}
	char ch;
	cout<<"submit(y/n)"<<endl;
	cin>>ch;
	if(ch=='y')
		save_into_file(*ptr);
}

void Student::save_into_file(Student *ptr)
{
	fstream fout;
	fout.open("student.txt", std::ios_base::app | std::ios_base::in);//apanding mode
	
	while(ptr)
	{
		fout<<ptr->mob_num<<" "<<ptr->password<<" "<<ptr->rollno<<" "<<ptr->s_name<<" "<<ptr->DOB.dd<<"/"<<ptr->DOB.mm<<"/"<<ptr->DOB.yyyy<<" ";
		fout<<ptr->b_group<<" "<<ptr->email<<" "<<ptr->addr<<" "<<ptr->c.clss<<endl;

		ptr=ptr->next;
	}
	cout<<"saved sucessfully..."<<endl;
}

void after_login(string );// related to  student login system