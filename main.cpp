#include <iostream>
#include "record.h"
#include<conio.h>
using namespace std;
#include<string.h>
#include<fstream>
int main()
{


	record r;
	 system("color  30 ");
	  cout<<"\n\n";
    cout<<"\t\t\t\t\t   o-o-o-o  o-o-o-o  o-o-o-o   o-o-o-o   o-o-o-o-o   o-o       o         o         o \n";
    cout<<"\t\t\t\t\t   o     o  o        o     o   o         o       o   o  o      o       o   o       o  \n";
    cout<<"\t\t\t\t\t   o     o  o        o     o   o         o       o   o   o     o      o     o      o\n";
    cout<<"\t\t\t\t\t   o-o-o-o  o-o-o-o  o-o-o-o   o-o-o-o   o       o   o    o    o     o       o     o\n";
    cout<<"\t\t\t\t\t   o        o        o  o            o   o       o   o     o   o    o-o-o-o-o-o    o \n";
    cout<<"\t\t\t\t\t   o        o        o   o           o   o       o   o      o  o   o           o   o \n";
    cout<<"\t\t\t\t\t   o        o-o-o-o  o     o   o-o-o-o   o-o-o-o-o   o       o-o  o             o  o-o-o-o\n";
    //cout<<"\t\t\t\t\t   -----------------------------------------------------------------------------------------"<<endl;

    cout<<"\t\t\t\t\t   _______________________________________________________________________________________\n";



     cout<<"\n\n\n\n";
    cout<<"\t\t\t\t\t\to-o-o-o-o-o   o-o-o-o-o-o-o           o          oo-o-o-o-o   o            o  \n";
    cout<<"\t\t\t\t\t\too        o         oo             oo   o        oo       o     o        o    \n";
    cout<<"\t\t\t\t\t\too        o         oo            oo     o       oo       o       o    o     \n";
    cout<<"\t\t\t\t\t\too        o         oo           oo       o      oo-o-o-o-o         oo       \n";
    cout<<"\t\t\t\t\t\too        o         oo          oo-o-o-o-o-o     oo    o            oo       \n";
    cout<<"\t\t\t\t\t\too        o         oo         oo           o    oo      o          oo       \n";
    cout<<"\t\t\t\t\t\to-o-o-o-o-o   o-o-o-o-o-o-o   oo             o   oo        o        oo       \n";
    //cout<<"\t\t\t\t\t   -----------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t____________________________________________________________________________\n";
   cout<<"\n\t\t\t\t\t\t----------------------PASSWORD PROTECTED PERSONAL DIARY----------------------\n";

    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t_____________    ____________\n";
    cout<<"\t\t\t\t\t\t\t\t|  SIGN IN    |  |  SIGN UP  |\n";
    cout<<"\t\t\t\t\t\t\t\t--------------   -------------\n";

    cout<<"\n\n\t\t\t\t ENTER 1 FOR SIGN IN OTHERWISE 2 FOR SIGN UP:";
    cout<<"\n\n\t\t\t\t WHAT YOU WANT TO DO....?";
    cout<<"\n\t\t\t\t ENTER THE CHOICE: ";
    int t;
    cin>>t;
    cin.ignore();
    if(t==1)
    {    cout<<"\n";
         char user[30],p[25];
        cout<<"\n\t\t\t  ::USER NAME : ";
        cin.getline(user,30);

        cout<<"\n\t\t\t  ::PASSWORD  : ";



        r.signin(user);
        cout<<"\t\t\t PRESS ANY KEY FOR FURTHER PROCESS...";
         getch();

    }
    else
    {
         cout<<"\n";
         char user[30],p[25],e[100];
        cout<<"\n\t\t\t  ::USER NAME : ";
        cin.getline(user,30);
        cout<<"\n\t\t\t  ::ENTER EMAIL ADDRESS : ";

        cin.getline(e,100);
        cout<<"\n\t\t\t  ::PASSWORD  : ";

        r.signup(user,e);
    }





     int ch;

     while(1)
     {
         system("cls");

         cout<<"\n\n\n\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t o         o      o      o-o-o-o-o   o-o     o    o         o  o-o-o-o  o-o     o  o       o         \n";
            cout<<"\t\t\t\t\t o-o     o-o     o o         o       o  o    o    o-o     o-o  o        o  o    o  o       o           \n";
            cout<<"\t\t\t\t\t o  o   o  o    o-o-o        o       o   o   o    o  o   o  o  o-o-o-o  o   o   o  o       o            \n";
            cout<<"\t\t\t\t\t o   o-o   o   o     o       o       o    o  o    o   o-o   o  o        o    o  o  o       o        \n";
            cout<<"\t\t\t\t\t o    o    o  o       o  o-o-o-o-o   o     o-o    o    o    o  o-o-o-o  o     o-o  o-o-o-o-o              \n";
            cout<<"\t\t\t\t\t ___________________________________________________________________________________________\n\n";

                // cout<<"\n\t---------------------\n";
                cout<<"\n";
                 cout<<"\n\t\t";
                 cout<<"\n\t\t|[1]...ADD RECORD|\t";
                 cout<<"\n\t\t|[2]...VIEW RECORD|\t";
                 cout<<"\n\t\t|[3]...MODIFY RECORD|\t";
                 cout<<"\n\t\t|[4]...DELETE RECORD|\t";
                 cout<<"\n\t\t|[5]...EDIT PASSWORD|\t";
                 cout<<"\n\t\t|[6]...EXIT\t\t";
                 cout<<"\n\n\t\t:: ENTER YOUR CHOICE YOU WANT TO DO:";
                 cin>>ch;
                 cin.ignore();
         switch(ch)
         {
         case 1: r.add_record();break;
         case 2: r.view_record();break;
         case 3: r.modify_record();break;
         case 4: r.delete_record();break;
         case 5: r.edit_password();break;

         case 6:
             cin.ignore();
             system("cls");
             system("color b1");
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout<<"\t\t\t\t\t\t YOU HAD A GREAT EXPERIANCE.........!!!! \n\n\n\n";
             cout<<"\t\t\t\t**************************************************************************************************\n";
             cout<<"\t\t\t\t*\to-o-o-o-o  o       o      o      o-o     o  o     o        o     o  o-o-o-o  o     o\t * \n";
             cout<<"\t\t\t\t*\t    o      o       o     o o     o  o    o  o   o           o   o   o     o  o     o\t * \n";
             cout<<"\t\t\t\t*\t    o      o-o-o-o-o    o-o-o    o   o   o  o-o              o o    o     o  o     o\t * \n";
             cout<<"\t\t\t\t*\t    o      o       o   o     o   o    o  o  o   o             o     o     o  o     o\t * \n";
             cout<<"\t\t\t\t*\t    o      o       o  o       o  o     o-o  o     o           o     o-o-o-o  o-o-o-o\t * \n";
             cout<<"\t\t\t\t**************************************************************************************************\n";
               exit(0);

         default:
             cout<<" \n\t\tYOU TYPED ANYTHING ELSE...............";
             cout<<" \n\t\tPLEASE TRY AGAIN..";
             getch();

         }
     }
     return 0;
}
