#include "record.h"
#include<string.h>
#include <iostream>
#include<conio.h>
#include<fstream>
using namespace std;
 fstream f,fi;
record::record()
{
   username=new char[50];
   email=new char[100];
}
void record::signin(char *user)
{
    username=user;
    cin.getline(passwords,25);
    //cout<<"\n"<<passwords ;
}
void record::signup(char *user,char *e)
{
    username=user;
     cin.getline(passwords,25);
    email=e;

}
int record::password()
{
        f.open("PASS",ios::in);
        f.read((char*)&passwords,sizeof(passwords));
        f.close();

    int j=0,i=0;
    char p[20]={0};
    cout<<" \n\t\t  WARNING :: ONLY THREE PASSWORD TRIAL ARE ALLOWED ::"<<endl;
    for(;j<3;j++)
    {
    cout<<"\n\n::ENTER THE PASSWORD::   ";
    p[0]=getch();
    i=0;
    for(;p[i]!='\r';)
    {
                            if(p[i]=='\b')
                            {
                                i--;
                                cout<<"\b";
                                cout<<" ";
                                cout<<"\b";
                                 p[i]=getch();
                             }
                             else
                                {  cout<<"*";
                                    i++;
                                p[i]=getch();}

                                }
        p[i]='\0';
        i=0;
        if(strcmp(passwords,p)==0)
        {
         cout<<"\n\n \t .......ACCESS APPROVED....\n\n"<<endl;
         return 1;
        }
        else
        {
        cout<<"\n\n \t YOU ENTERED WRONG PASSWORD......";
        cout<<"YOU HAVE STILL "<<2-j<<" CHANCE\n";
        cout<<"\n\n\t....PLEASE TRY AGAIN.\n\n";

        }

        }
        cout<<" \n\n\t...sorry, your all chances are failed to login...";
        cout<<" \n\n PRESS ANY KEY TO CONTINUE...\n";
        return 0;
        getch();
}
void record::edit_password()
{
    system("cls");
    system("color 60");
    cout<<"\n\n\n";
    char p[20]={0},c[20]={0};

    int choice,i,check;
    check=password();
     cout<<"\t\t  __________________________________\t\t\t";
     cout<<"\n";
     cout<<"\t\t | THIS PORTAL FOR CHANGE PASSWORD |\t\t\t\n";

     cout<<"\t\t  ----------------------------------\t\t\t";


     cout<<"\n";
    if(check==0)
        return;
    do
        { if(check==1)
        {
            choice=0;
            cout<<"\n\n\t\t ::ENTER THE NEW PASSWORD:";
            //cin.ignore();
            p[0]=getch();
            for(i=0;p[i]!='\r';)
            {
                if(p[i]=='\b')
                {
                    i--;
                    cout<<"\b";
                    cout<<" ";
                    cout<<"\b";
                    p[i]=getch();
                }
                else
                {
                    cout<<"*";
                    i++;
                    p[i]=getch();
                }
            }
            p[i]='\0';
            i=0;
           cout<<"\n\n\t\t ::CONFIRM PASSWORD:";
           c[0]=getch();
           for(i=0;c[i]!='\r';)
            {
                if(c[i]=='\b')
                {
                    i--;
                    cout<<"\b";
                    cout<<" ";
                    cout<<"\b";
                    c[i]=getch();
                }
                else
                {
                    cout<<"*";
                    i++;
                    c[i]=getch();
                }
            }
            c[i]='\0';
            if(strcmp(p,c)==0)
            {
                strcpy(passwords,p);
                f.open("PASS",ios::in|ios::out);
                f.seekg(0,ios::beg);
                f.write((char*)&passwords,sizeof(passwords));
                f.close();
                cout<<"\n\n\t\t ...YOUR PASSWORD CHANGED SUCCESSFULLY...";
                cout<<"\n\n\t\t ::YOUR NEW PASSWORD IS::  "<<p<<endl;
                 cout<<" \n\n\n\t PRESS ANY KEY TO CONTINUE...\n";
                 getch();
                 return;

            }
            else
            {
                cout<<"\n\n SORRY,YOUR NEW ENTERED PASSWORD DOES NOT MATCH.";
                cout<<"\n\n\t....PLEASE TRY AGAIN.\n\n";
                choice=1;
            }

        }

    }while(choice==1);
    cout<<"\n\n\tPRESS ANY KEY TO EXIT PASSWORD EDITING MENU......";
    getch();
}

void record::add_record()
{
    int i=0;
    system("cls");

     system("color  80");
    char a='Y',t[10];
    record r;
    char file[15];
    int choice;
    int count=0;
    cout<<"\n\n\n\n";
     cout<<"\t\t  __________________________________\t\t\t";
     cout<<"\n";
     cout<<"\t\t |    THIS PORTAL FOR ADD RECORD    |\t\t\t\n";

     cout<<"\t\t  ----------------------------------\t\t\t";
       cout<<"\n\n\n\t\t ::DATE FORMAT:[dd-mm-yyyy] \t\t\t\n";
      cout<<"\n\t\t ::ENTER THE DATE OF YOUR RECORD:";

      cin.getline(file,15);

      f.open(file,ios::in|ios::binary|ios::app|ios::out);
				if(!f.is_open())
				{
					 f.open(file,ios::in|ios::binary|ios::app|ios::out);
					 if(!f.is_open())
					{
					 	cout<<"\nSYSTEM ERROR...";
					 	cout<<"\nPRESS ANY KEY TO EXIT";
					 	getch();
                    return ;
					 }

				}
        while( a=='Y'|| a=='y')
        { choice=0;
            if(i++>0)
                cin.ignore();
                cout<<"\n\t\t ::TIME FORMAT:[hh:mm] \t\t\t\n";
            cout<<"\n\t\t ::ENTER TIME: ";
            cin.getline(t,10);
             while(f.is_open())
                {
                    if(strcmp(r.time,t)==0&&count==0)
                    {
                        count++;
                        cout<<"\n\tTHE RECORD ALREADY EXISTS.\n";
                        choice=1;
                    }
                    count=0;
                    f.close();
                }
                if(choice==0)
             {
                 f.open(file,ios::in|ios::binary|ios::app|ios::out);
                 strcpy(r.time,t);
                 cout<<"\n\t\t ::ENTER THE NAME: ";
                 cin.getline(r.name,30);
                 cout<<"\n\t\t\ ::ENTER THE PLACE: ";
                 cin.getline(r.place,25);
               cout<<"\n\t\t ::ENTER DURATION OF EVENT: ";
                        cin.getline(r.duration,10);

                        cout<<"\n\t\t NOTE:";
                        cin.getline(r.note,500);
                           f.write((char *)&r,sizeof(r));
                        cout<<"\n\t\t.....YOUR RECORD IS ADDED.....\n";
                    }
                        cout<<"\n\t\t    ADD ANOTHER RECORD...(Y/N) ";

                        a = getchar( ) ;
                }
                f.close() ;
                cout<<"\n\n\tPRESS ANY KEY TO EXIT ADDRECORD MENU......";
                getch();

             }

void record::view_record()
{
    system("cls");

    system("color e1");
    record c;
    char t[10],choice,file[20];
    int ch;
    cout<<"\n\n\n\n\n";
    cout<<"\t\t  __________________________________\t\t\t";
     cout<<"\n";
     cout<<"\t\t |    THIS PORTAL FOR VIEW RECORD    |\t\t\t\n";

     cout<<"\t\t  ----------------------------------\t\t\t";
     cout<<"\n\n";
     choice=password();
     if(choice==0)
     {
         return;

     }
     do
     {
      cin.ignore();
      cout<<"\n\n\n\t\t ::DATE FORMAT:[dd-mm-yyyy] \t\t\t\n";
      cout<<"\n\t\t ::ENTER THE DATE OF RECORD YOU WANT TO VIEW:";

      cin.getline(file,20);

      f.open(file,ios::in|ios::binary|ios::app|ios::out);


					 if(!f)
					{
					 	cout<<"\nSYSTEM ERROR...";
					 	cout<<"\nPRESS ANY KEY TO EXIT";
					 	getch();
                    return ;
					 }


				system("cls");
				cout<<"\n\t\t\t .........ENTER THE CHOICE AS PER YOUR PREFRENCE.......\t\t\n\n";
				cout<<"\n\t\t1.WHOLE RECORD OF THE DAY.";

            	cout<<"\n\t\t2.RECORD OF FIX TIME.";
            	cout<<"\n\n\t\t::ENTER YOUR CHOICE:";
            	cin>>ch;
            	switch(ch)
            	{
                case 1:
                    cout<<"\n\t| THE WHOLE RECORD FOT THIS DATE :  "<< file;
                    cout<<"\n\t|_________________________________________________\t\t\t";
                    while (f.read((char *)&c,sizeof(record)))
                        {
            				cout<<"\n\n";
            				cout<<"\n\t\t TIME:        "<<c.time;
            				cout<<"\n\t\t MEETING WITH:"<<c.name;
            				cout<<"\n\t\t MEETING AT:  "<<c.place;
            				cout<<"\n\t\t DURATION:    "<<c.duration;
            				cout<<"\n\t\t NOTE:        "<<c.note;
            				cout<<"\n\n";
            			}
            			break;
                case 2:
                    cin.ignore();
                    cout<<"\n\n\t\t ENTER THE TIME[hh:mm]:";
                    cin.getline(t,10);
                    while( f.read((char *)&c,sizeof(c)))
            				{

            					if(strcmp(c.time,t)==0)
            					{
            						cout<<"\n\t\t YOUR RECORD IS: ";
            						cout<<"\n\t\t TIME:           "<<c.time;
                                    cout<<"\n\t\t MEETING WITH:   "<<c.name;
                                    cout<<"\n\t\t MEETING AT:     "<<c.place;
                                    cout<<"\n\t\t DURATION:       "<<c.duration;
                                    cout<<"\n\t\t NOTE:           "<<c.note;
            					}
            				}
            				break;
                default:
                    cout<<"\n\n......SORRY,INVALID ENTERY FOR CHOICE......."<<endl;

            	}
				cout<<"\n\n\t\t ::WOULD YOU LIKE TO CONTINUE VIEWING RECORD....";
				cout<<"\n\n\t\t PRESS 'Y' FOR YES OTHERWISE 'N' FOR NO..:";
				cout<<" \n\n\t\t ::ENTER THE CHOICE:";
				cin>>choice;
				f.close();


     }while(choice=='Y'||choice=='y');
      cout<<"\n\n\tPRESS ANY KEY TO EXIT VIEWRECORD MENU......";
                getch();
                return ;
}
void record::modify_record()
{
    system("cls");
    system("color d0");
    record c;
    char t[10],choice,file[14];
    int num,count=0,cnt=0;

     cout<<"\t\t  __________________________________\t\t\t";
     cout<<"\n";
     cout<<"\t\t |    THIS PORTAL FOR MODIFY RECORD    |\t\t\t\n";

     cout<<"\t\t  ----------------------------------\t\t\t";
     cout<<"\n\n";
     choice=password();
     if(choice==0)
        return ;
     do{
        cin.ignore();
        cout<<"\n\n\n\t\t ::DATE FORMAT:[dd-mm-yyyy] \t\t\t\n";
        cout<<"\n\t\t ::ENTER THE DATE OF YOUR RECORD TO BE EDITED:";

        cin.getline(file,14);

        cin.ignore();
       cout<<"\n\t\t ::TIME FORMAT:[hh:mm] \t\t\t\n";
            cout<<"\n\t\t ::ENTER TIME: ";
            cin.getline(t,10);
       f.open(file,ios::binary|ios::in);
	   	 if (!f)

        {
                            	cout<<"\nRECORD DOES NOT EXISTS:";
                            	cout<<"\nPRESS ANY KEY TO EXIT MAINMENU..";
                            	getch();
                                return;
	   }
	   while ( f.read((char *)&c,sizeof(c)))
       {
           cnt++;
           if(strcmp(c.time,t)==0)
           {
               cout<<"\n\t\t ::  YOUR OLD RECORD  ::";
               cout<<"\n\t\t    __________________  ";
               cout<<"\nTIME:"<<c.time;
            				cout<<"\n\t\t MEETING WITH:"<<c.name;
            				cout<<"\n\t\t MEETING AT:"<<c.place;
            				cout<<"\n\t\t DURATION:"<<c.duration;
            				cout<<"\n\t\t NOTE:"<<c.note;
            				system("cls");
            				cout<<"\n\n\t\t  #### WHICH DETAIL WOULD YOU LIKE TO EDIT #### ";

            				cout<<"\n\t\t 1.TIME.";
            				cout<<"\n\t\t 2.MEETING PERSON.";
            				cout<<"\n\t\t 3.MEETING PLACE.";
            				cout<<"\n\t\t 4.DURATION.";
            				cout<<"\n\t\t 5.NOTE.";
            				cout<<"\n\t\t 6.WHOLE RECORD.";
            				cout<<"\n\t\t 7.GO BACK TO MAIN MENU.";
            				cout<<"\n\n";

            				do{
                                cout<<"\n\t\t ENTER THE CHOICE: ";
                                cin>>num;

                                  switch(num)
            					{
            						case 1:
            						    cin.ignore();
            							cout<<"\n\t\t ENTER THE NEW DATA:";
            							cout<<"\n\t\t NEW TIME:[hh:mm]:";
            							cin.getline(c.time,10);
                                                    break;

                                     case 2:
                                         cin.ignore();
                                     	cout<<"\n\t\t ENTER THE NEW DATA:";
            							cout<<"\n\t\t NEW MEETING PERSON:";
            							cin.getline(c.name,30);
                                                    break;
                                    case 3:
                                        cin.ignore();
                                    		cout<<"\n\t\t ENTER THE NEW DATA:";
            							cout<<"\n\t\t NEW MEETING PLACE:";
            							cin.getline(c.place,25);
                                                    break;
                                    case 4:
                                        cin.ignore();
                                    		cout<<"\n\t\t ENTER THE NEW DATA:";
            							cout<<"\n\t\t DURATION:";
            							cin.getline(c.duration,10);
                                                    break;
                                    case 5:
                                        cin.ignore();
                                    		cout<<"\n\t\t ENTER THE NEW DATA:";
            							cout<<"\n\t\t NOTE:";
            							cin.getline(c.note,500);
                                                    break;
                                    case 6:
                                        cin.ignore();
                                    	cout<<"\n\t\t ::ENTER THE NEW DATA:";
                                    	cout<<"\n\t\t ::NEW TIME:[hh:mm]:";
                                    	cin.getline(c.time,10);
                                    	cout<<"\n\t\t ::NEW MEETING PERSON:";
                                    	cin.getline(c.name,30);
                                    	cout<<"\n\t\t ::NEW MEETING PLACE:";
                                    	cin.getline(c.place,25);
                                    	cout<<"\n\t\t ::DURATION:";
                                    	cin.getline(c.duration,10);
                                    	cout<<"\n\t\t ::NOTE:";
                                    	cin.getline(c.note,500);
                                    	 break;
                                    case 7:
                                        cin.ignore();
                                    	cout<<"\nPRESS ANY KEY TO GO BACK...\n";
                                    	 getch();
                                                    return ;
                                                    break;
                                    default:
                                        cin.ignore();
                                    	cout<<"\n\t\t YOU TYPED SOMETHING WRONG...\n";
                                    	cout<<"\n\t\t PLEASE TRY AGAIN.....\n";
                                    	break;
            					}
            					} while(num<1||num>8);
            					 f.close();
            				f.open(file,ios::in|ios::binary|ios::out|ios::ate);
            				int location=(cnt-1)*sizeof(c);
            				 f.seekp(location);
                            f.write((char *)&c,sizeof(record));
                            f.close();
                            f.open(file,ios::binary|ios::in);
                             f.seekp(location);
                            f.read((char *)&c,sizeof(record));
                            choice=5;
                            break;
	   	}
}


                    if(choice==5)
                    {
                        system("cls");
                        cout<<"\n\t\t YOUR EDITING COMPLETED....\n\n";
                        cout<<"\n\t\t\t ::  YOUR NEW RECORD  ::";
                        cout<<"\n\t\t\t    __________________  ";
                        cout<<"\n\t\t ::TIME:"<<c.time;
            				cout<<"\n\t\t ::MEETING WITH:"<<c.name;
            				cout<<"\n\t\t ::MEETING AT:"<<c.place;
            				cout<<"\n\t\t ::DURATION:"<<c.duration;
            				cout<<"\n\t\t ::NOTE:"<<c.note;
            				f.close();
            				cout<<"\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)";
            				cin>>choice;
            				count++;}
            				else
            				{
            					cout<<"\n\t\t THE RECORD DOES NOT EXIST::\n";
            					cout<<"\n\n\t\t ::WOULD YOU LIKE TO CONTINUE VIEWING RECORD....";
                                cout<<"\n\n\t\t PRESS 'Y' FOR YES OTHERWISE 'N' FOR NO..:";
                                cout<<" \n\n\t\t ::ENTER THE CHOICE:";
                                cin>>choice;
            					 f.close();
            					cnt=0;
            				}
       } while(choice=='y' || choice=='Y');
       if(count==1)cout<<"\n\n\t\t"<<count<<" FILE IS EDITED....\n";
       else if(count>1)cout<<"\n\n\t\t"<<count<<" FILE IS EDITED....\n";
        else
        {
            cout<<"\n\t\t NO FILES EDITED...\n";
            cout<<"\n\t\t PRESS ENTER TO EXIT MODIFY MENU.";
            getch();
        }



}
void record::delete_record()
{
    system("cls");
    system("color a0");
    record c;
    char file[15],a='Y',t[10];
    int choice,check;
    cout<<"\t\t  _____________\t\t\t";
    cout<<"\n";
    cout<<"\t\t |    THIS PORTAL FOR DELETE RECORD    |\t\t\t\n";

    cout<<"\t\t  -------------------------------------\t\t\t";
    cout<<"\n\n";
    check = password();
    if(check==0)
    {
        return;
    }
    while(a=='Y'||a=='y')
    {
        system("cls");
        cout<<"\n\n\t\t WHICH RECORD WOULD YOU LIKE TO DELETE.\n";
        cout<<"\n\n\t\t [1].DELETE WHOLE RECORD\n";
        cout<<"\n\n\t\t [2].DELETE A PARTICULAR RECORD BY TIME\n";
        do
        {
            cout<<"\n\t\t ::ENTER YOUR CHOICE:";
            cin>>choice;
            switch(choice)
                        {
                            case 1:
                            cout<<"\n\n\n\t\t ENTER THE DATE OF RECORD TO BE DELETED:[dd-mm-yyyy]:";
                            cin.ignore();
                            cin.getline(file,15);
                           f.open (file,ios::in|ios::binary) ;
                            if (!f)
                             {
                                cout<<"\n\t\t THE FILE DOES NOT EXISTS";
                                cout<<"\n\t\t PRESS ANY KEY TO EXIT DELETE RECORD MENU\n";
                                getch();
                                return ;
                            }
                            f.close();
                            remove(file);
                            cout<<"\n\n\t\t......YOUR RECORD DELETED SUCCESFULLY...";
                            break;
                            case 2:
                            cout<<"\n\n\n\t\t ::DATE FORMAT:[dd-mm-yyyy] \t\t\t\n";
                            cout<<"\n\t\t ::ENTER THE DATE OF YOUR RECORD TO BE DELETED:";
                            cin.ignore();
                            cin.getline(file,14);

                           f.open (file,ios::in|ios::binary) ;
                            if (!f)
                             {
                                cout<<"\n\t\t THE FILE DOES NOT EXISTS";
                                cout<<"\n\t\t ....PRESS ANY KEY TO EXIT DELETE RECORD MENU....";
                                getch();
                                return ;
                            }
                            fi.open("temp",ios::in|ios::out|ios::binary|ios::app|ios::ate);
                            if(!fi)
                            {
                                cout<<"\n\t\t SYSTEM ERROR";
                                cout<<"\n\t\t ....PRESS ANY KEY TO EXIT DELETE RECORD MENU....";
                                getch();
                                return ;
                            }
                            cout<<"\n\t\t ::TIME FORMAT:[hh:mm] \t\t\t\n";
                            cout<<"\n\t\t ::ENTER THE TIME OF RECORD TO BE DELETED: ";
                            cin.getline(t,10);
                            while(f.read((char*)&c,sizeof(c)))
                            {
                                if(strcmp(c.time,t)!=0)
                                fi.write((char*)&c,sizeof(c));
                            }
                            f.close();
                            fi.close();
                            remove(file);
                            rename("temp",file);
                            cout<<"\n\n\t\t......YOUR RECORD DELETED SUCCESFULLY...";
                            break;

                            default:
                                cout<<"\n\t\t....YOU ENTERED ANYTHING ELSE.....\n";
                                cout<<"\n\t\t.....PLEASE TRY AGAIN....\n";
                        }
        }while(choice<1 || choice>2);

        cout<<"\n\n\t\t ::WOULD YOU LIKE TO CONTINUE DELETE RECORD....";
        cout<<"\n\n\t\t PRESS 'Y' FOR YES OTHERWISE 'N' FOR NO..:";
        cin>>a;
    }
    cout<<"\n\t\t .....PRESS ANY KEY TO EXIT DELETE RECORD MENU....\n";
    getch();
}
record::~record()
{
    //dtor
}
