#include "header.h"
int main()
{
    system("clear");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############   Student Record Management System                ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t----------------------------------------------------------------------------");

	printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =               Student Record              =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....\n");

    Student *headptr=0;
    Student obj;
    string login_s;
    while(1)
    {
        int n;
        cout<<"\t1)Student\t\t2)Admin"<<endl;
        cin>>n;
        if(n==1)
        {
            int sop;
            cout<<"\t\t1)Registration\t\t2)login"<<endl;
            cin>>sop;
            switch(sop)
            {
                case 1: obj.registration(&headptr);break;
                case 2: login_s=obj.login();
                if(login_s != "")
                    after_login(login_s);
                else
                    cout<<"login failed"<<endl;
                break;

                default : cout<<"chose wrong option"<<endl;
            }
        }
        else if(n==2)
        {
            int aop;
            cout<<"1)Print all data"<<endl;
            cin>>aop;
            switch(aop)
            {
                case 1:obj.print_all(headptr);break;
            }
        }
        else
            cout<<"chose wrong option"<<endl;
    }
}