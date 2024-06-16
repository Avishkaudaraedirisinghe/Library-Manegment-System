#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void AdminMenu();
void AdminLogin();
void AdminTask();
void LibrarianSignUp();
void AdminExit();
void LibrarianMenu();
void LibrarianLogin();

int main(){

	int option1 = 0, option2 = 0, option3 = 0;
	
	cout<<"========================================================================="<<endl;
	cout<<"                                                                         "<<endl;
	cout<<"                                                                         "<<endl;
	cout<<"*************************** BRITISH LIBRARY *****************************"<<endl;
	cout<<"                                                                         "<<endl;
	cout<<"                                                                         "<<endl;
	cout<<"========================================================================="<<endl;
	cout<<"                                                                         "<<endl;
	cout<<"                       WELCOME TO BRITISH LIBRARY !                       "<<endl;
	cout<<"                                                                         "<<endl;
	cout<<"                              1. Admin                                   "<<endl;
	cout<<"                              2. Librarian                               "<<endl;
	cout<<"                              3. Exit                                    "<<endl;
	cout<<"                                                                         "<<endl;
	cout<<"        Enter your option : ";
	cin>>option1;
	
	
         	switch(option1){
			case 1:{
				AdminMenu();
				break;
			}
			
			case 2:{
				LibrarianMenu();
				break;
			}
			
			case 3:{
				cout << "            THANK YOU! COME AGAIN!          ";
				break;
			}
			
			default:{
				system("cls");
				cout << "\n Please select from the given options \n";
				main();
				break;
			}	
		}
	

	return 0;
}
	
void AdminMenu(){
	int option1 = 0;
	
	
	cout << "===========================================================================================" << endl;
	cout << "                                     ADMIN                                " << endl;
	cout << "           			   1. Login                                           	" << endl;
	cout << "           			   2. Go back to main menu                                    	" << endl;
	cout << "===========================================================================================" << endl;
	cout << "        Enter your option : ";
	cin >> option1 ;
	
	do{	
		if(option1 == 1){			
			AdminLogin();	
		}
		else if(option1 == 2){
			system("cls");
			main();	
		}
		else{
			system("cls");
			cout << "\n Please select from the given options \n";
			AdminMenu();	
		}
	}while(option1 != 1,2);
}

	
