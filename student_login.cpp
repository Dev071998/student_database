#include <iostream>
using namespace std;
void view_details(string );
//void modify_details(string );
void split_string(string );

string res[13];


void after_login(string s)
{
	int op;
	cout<<"\t\t\t\twelcome to your account"<<endl;
	cout<<"1)View details\t2)Modify"<<endl;
	cin>>op;
	switch(op)
	{
		case 1 : view_details(s);break;
		//case 2 : modify_details(s);break;
		default : cout<<"chose wrong option"<<endl;
	}
}

void split_string(string s)
{   
    int i=0;
    string delimiter = " ";

    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos)
    {
        token = s.substr(0, pos);
        res[i++]=token;
        s.erase(0, pos + delimiter.length());
    }
    res[i++]=s;
}


void view_details(string s)
{
	split_string(s);
	cout<<"Roll number\t:"<<res[2]<<endl;
	cout<<"Name\t\t:"<<res[3]<<endl;
	cout<<"Class\t\t:"<<res[8]<<endl;
	//cout<<"Marks\t\t:"<<endl;
	cout<<"DOB\t\t:"<<res[4]<<endl;
	cout<<"Blood group\t:"<<res[5]<<endl;
	cout<<"Email id\t:"<<res[6]<<endl;
	cout<<"Mobile No.\t:"<<res[0]<<endl;
	cout<<"Address\t\t:"<<res[7]<<endl;
}