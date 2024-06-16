#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int option1,option2,option3;
	string username="Avishka";
	string password="Avishka2002";
	string name,address,nicnumber,telephonenumber;
	
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
		//Admin Login
		system("cls");
		string uname="Avishka";
		string upw="Avishka2002";
		
		cout<<"Enter your username : ";
		cin>>username;
		
		cout<<"Enter your password : ";
		cin>>password;
		
		if(username==uname && password==upw){
		
				system("cls");
				cout<<"========================================\n";
				cout<<"                   ADMIN           \n  ";
				cout<<"                -------          \n  ";
				cout<<"         1. Sign up librarians        \n  ";
				cout<<"         2. Change the fine rate             \n  ";
				cout<<"         3. Modify maximum borrowing limits  \n  ";
				cout<<"         4. Exit   \n "<<endl;
				
				cout<<"Enter your option : ";
				cin>>option2;
				
			
			switch(option2){
			
			case 1:{
				system("cls");
				cout<<"            SIGN UP         \n\n";
				cout<<"Enter your name : ";
				cin>>name;
				
				cout<<"Enter your address : ";
				cin>>address;
				
				cout<<"Enter your nic number : ";
				cin>>nicnumber;
				
				cout<<"Enter your telephone number : ";
				cin>>telephonenumber;
				
				fstream myfile;
				myfile.open("librarian.dat",ios::app);
				if(myfile.is_open()){
					myfile<<name<<" "<<address<<" "<<nicnumber<<" "<<telephonenumber;
					cout<<"\n\nAdded successful !";
				}else{
					cout<<" Not added !";
				}
				break;
			}
			case 2:{
			    cout<<"";
				break;
			}
		    
		    
				break;
			}
		}else{
			cout<<"\n       !!! Enter correct password or username !!!"<<endl;
		}
			
	}
	
	case 2:{
			system("cls");
				cout<<"========================================\n";
				cout<<"                 LIBRARIAN          \n  ";
				cout<<"              -----------          \n  ";
				cout<<"         1. Add and delete books        \n  ";
				cout<<"         2. Search and update books             \n  ";
				cout<<"         3. Issue books  \n  ";
				cout<<"         4. Accept returned books   \n ";
				cout<<"          5. Add and delete borrowers   \n ";
				cout<<"          6. Search and update borrowers   \n ";
				cout<<"          7. Exit  \n ";
				
				cout<<"Enter your option : ";
				cin>>option2;
		break;
	}
}
	
	return 0;
}
