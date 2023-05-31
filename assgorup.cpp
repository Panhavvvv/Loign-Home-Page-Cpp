#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <cstdio>
#include <iomanip>
using namespace std;

string getpassword(const string& prompt = "Enter password> " );

//Login Class
void intro();
void entry();
class login
{
	private:
		char username[25],pass[25];
	public:
		void addUser();
		void validate();
};
void login::validate()
{
	login ln;
	string password;
	char pwd[15],user[25];
	cout<<"Please Enter Username : ";
	cin>>user;
	password=getpassword("Please Enter Password : ");
	strcpy(pwd, password.c_str());
	
	bool flag=false;
	ifstream inFile;
	inFile.open("login.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    	while(inFile.read(reinterpret_cast<char *> (&ln), sizeof(login)))
	{
		if(strcmp(ln.username,user)==0 && strcmp(ln.pass,pwd)==0)
		{
			cout<<"\nYou Have Successfully Logged In : "<<endl;
			time_t t;
			time(&t);
			cout<<"Logged In Time : "<<ctime(&t);
			cout<<"Press any key to continue .... ";
			getch();	
			flag=true;
			break;
		}
	}
    inFile.close();
	if(flag==false)
		{
		cout<<"\nYou Entered Incorrect Details...Please Login again...\n";
		getch();
		entry();
		}
}

void login::addUser()
{
	
	login ln;
	string password,password1;
	char pass1[15];
	cout<<"Please Enter Username : ";
	cin>>ln.username;
	password=getpassword("Please Enter Password : ");
	password1=getpassword("\nPlease Confirm Password : ");
	strcpy(ln.pass, password.c_str());
	strcpy(pass1, password1.c_str());
	if(1) //Condistion to check if user already exist or not
	{
	if(strcmp(ln.pass,pass1)==0)
	{
		ofstream outFile;
		outFile.open("login.dat",ios::binary|ios::app);
		
		outFile.write(reinterpret_cast<char *> (&ln), sizeof(login));
		outFile.close();
	
		cout<<"\nYou Have Successfully Logged In :"<<endl;
		cout<<"Press any key to continue .... ";
		getch();
		entry();
	}
	else
	{
		cout<<"\nPasswords don't Match...\n";
		getch();
		entry();
	}
	}
	else
	{
		cout<<"\nUser already exist...Please Login..\n";
		getch();
		entry();
	}
	
}

void entry()
{
	int ch;
	login user;
	system("CLS");
	cout<<"\n WELCOME TO REGISTER AND LOGIN\n";
	cout<<"\t[1] Login \n";
	cout<<"\t[2] Register \n";
	cout<<"\t[3] Exit\n\t";
	cin>>ch;
	if(ch==1)
	{
		user.validate();
	}
	else if(ch==2)
	{
		user.addUser();
	}
	else if(ch==3)
	{
		cout<<"\nProgram is Exiting.\n";
		getch();
		exit(1);
	}
	else
	{
		cout<<"\nYou Entered Incorrect Option.\n";
		getch();
		exit(1);

	}
}

string getpassword( const string& prompt  )
  {
  string result;

  // Set the console mode to no-echo, not-line-buffered input
  DWORD mode, count;
  HANDLE ih = GetStdHandle( STD_INPUT_HANDLE  );
  HANDLE oh = GetStdHandle( STD_OUTPUT_HANDLE );
  if (!GetConsoleMode( ih, &mode ))
    throw runtime_error(
      "getpassword: You must be connected to a console to use this program.\n"
      );
  SetConsoleMode( ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );

  // Get the password string
  WriteConsoleA( oh, prompt.c_str(), prompt.length(), &count, NULL );
  char c;
  while (ReadConsoleA( ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n'))
    {
    if (c == '\b')
      {
      if (result.length())
        {
        WriteConsoleA( oh, "\b \b", 3, &count, NULL );
        result.erase( result.end() -1 );
        }
      }
    else
      {
      WriteConsoleA( oh, "*", 1, &count, NULL );
      result.push_back( c );
      }
    }

  // Restore the console mode
  SetConsoleMode( ih, mode );

  return result;
 }

void intro()
{
	cout<<"\n\n\t\t\t\t\t ROYAL UNIVERSITY OF PHNOM PENH";
	cout<<"\n\n\t\t\t\t\t             CLASS E3";
	cout<<"\n\n\t\t\t\t\t             GORUP 6";
    cout<<"\n\t\tIt is a Simple System Project for our 2nd Semester based on C++ programming language.";
	cout<<"\n\n\t\t\t\t\tMADE BY :PANHA ";
	cout<<"\n\n\t\t\t\t\tMADE BY :RADY" ;
    cout<<"\n\n\t\t\t\t\tMADE BY :VIFON" ;
    cout<<"\n\n\t\t\t\t\tMADE BY :REAPHOU" ;
    cout<<"\n\n\t\t\t\t\tMADE BY :SENGHOR" ;
    cout<<"\n\n\t\t\t\t\tMADE BY :DAVID" ;
    cout<<"\n\n\t\t\t\t\tMADE BY :VANNAK" ;
    cout<<"\n\n\t\t\t\t\tMADE BY :THEAN" ;
    cout<<"\n\n\t\t\t\t\tMADE BY :PISETH" ;
    cout<<"\n\t\tPress any key to return back to main menu. ";
	cin.get();
}


int main()
{
	system("cls");
	intro();
	entry();
    char ch;
	int num;
	do
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t[01]. CREATE NEW STUDENT ";
		cout<<"\n\n\t[02]. DEPOSIT AMOUNT";
		cout<<"\n\n\t[03]. WITHDRAW AMOUNT";
		cout<<"\n\n\t[04]. BALANCE ENQUIRY";
		cout<<"\n\n\t[05]. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t[06]. CLOSE AN ACCOUNT";
		cout<<"\n\n\t[07]. MODIFY AN ACCOUNT";
		cout<<"\n\n\t[08]. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8):";
		cin>>ch;
		system("cls");
		switch(ch)
		{
			case '1':
				break;
			
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
	return 0;
}
