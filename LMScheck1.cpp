#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>

using namespace std;

//Function prototype
void AdminLoginMenu();
void AdminLogin();
void adminTask();
void LibrarianSignUp();
void FineRateChanging();
void AdjustingMaxBorrowingLimit();
void AdminExit();
void LibrarianLoginMenu();
void LibrarianLogin();

int main(){
	//variable initialization
	int loginOption = 0, adminOption = 0, librarianOption = 0;
	
	// Displaying the main menu
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "**                                                                                       **" << endl;
	cout << "**                                                                                       **" << endl;
	cout << "**                         WELCOME TO LIBRARY MANAGEMENT SYSTEM                          **" << endl;
	cout << "**                                                                                       **" << endl;
	cout << "**                                                                                       **" << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	
	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "                \t  Please Choose Any Option Number To Login                                 " << endl;
	cout << "           			   1. Admin                                              	" << endl;
	cout << "           			   2. Librarian                                          	" << endl;
	cout << "           		   	   3. Exit                                               	" << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "Enter the option number : ";
	cin >> loginOption;
	
		
		switch(loginOption){
			case 1:{
				AdminLoginMenu();
				break;
			}
			
			case 2:{
				LibrarianLoginMenu();
				break;
			}
			
			case 3:{
				cout << "\n\t\t Thank You! \n";
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

// Function implementation
void AdminLoginMenu(){
	int adminOption = 0;
	
	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "                \t\t\t  ADMIN  \n                               " << endl;
	cout << "           			   1. Login                                             	" << endl;
	cout << "           			   2. Go back to main menu                                        	" << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "Enter the option number : ";
	cin >> adminOption;
	
	do{	
		if(adminOption == 1){			
			AdminLogin();	
		}
		else if(adminOption == 2){
			system("cls");
			main();	
		}
		else{
			system("cls");
			cout << "\n Please select from the given options \n";
			AdminLoginMenu();	
		}
	}while(adminOption != 1,2);
}

// Function implementation
void AdminLogin(){
	
	string AdminId, AdminPassword, aId, aPwd;
	system("cls");
	
	fstream AdminLoginFile;						//create an object to class fstream and name it ‘LoginFile’
	
	AdminLoginFile.open("AdminUserPwd.txt",ios::out);		//open the file to write, file name – AdminUserPwd.txt , mode out 
	
	aId = "Arno";
	aPwd = "arno123";
	
	AdminLoginFile << aId << " " << aPwd ;			//Writing the userId & Password to the file
	
	AdminLoginFile.close();					// close the file	
	
	//Getting userId & Password
	cout << "\t\t ADMIN \n\n";	
	cout << "Enter The Username To Log In : "; 
	cin >> AdminId;
	cout << "Enter The Password To Log In : "; 
	cin >> AdminPassword;
	
	AdminLoginFile.open("AdminUserPwd.txt",ios::in);		//open the file to read, file name – AdminUserPwd.txt , mode in
	
		
	while(AdminLoginFile >> aId >> aPwd){
		if(aId == AdminId && aPwd == AdminPassword){
			cout << "\n Your LOGIN is successful \n";
			adminTask();
		}
		else{
			cout << "\n LOGIN ERROR \n Please check your Username and Password \n\n";
			system("PAUSE");
			AdminLogin();
		}
	}
	
	AdminLoginFile.close();
}

// Function implementation
void adminTask(){
	int adminTaskOption;
	
	cout << "\n-------------------- ADMIN TASKS--------------------\n" << endl;
	cout << "\t 1. Sign Up Librarians" << endl;
	cout << "\t 2. Change The Fine Rate" << endl;
	cout << "\t 3. Modify Maximum Borrowing Limits" << endl;
	cout << "\t 4. Go Back To Main Menu" << endl;
	cout << "----------------------------------------------------\n" << endl;
	cout << "Enter the option number : ";
	cin >> adminTaskOption;
	
	switch(adminTaskOption){
		case 1:{
			LibrarianSignUp();
			AdminExit();
			break;
		}
		case 2:{
			FineRateChanging();
			AdminExit();
			break;
		}
		case 3:{
			AdjustingMaxBorrowingLimit();
			AdminExit();
			break;
		}
		case 4:{
			system("cls");
			main();	
			break;
		}
		default:{
			system("cls");
			cout << "\n Please select from the given options \n";
			adminTask();
			break;
		}	
	}
}

// Function implementation
void LibrarianSignUp(){
	string lId, lPwd;
	system("cls");
	
	fstream LibrarianSignInFile;						//create an object to class fstream and name it ‘LibrarianSignInFile’
	
	cout << "\n ----------  Sign Up Librarians  ---------- \n" << endl;

	cin.ignore();
	
	cout << " Enter the Username : ";
	getline(cin, lId);
	
	cout << " Enter the Password : ";
	getline(cin, lPwd);
	
	LibrarianSignInFile.open("LibrarianUserPwd.txt",ios::app);		//open the file to write, file name – LibrarianUserPwd.txt , mode out 
	
	LibrarianSignInFile << lId << " " << lPwd ;			//Writing the userId & Password to the file
	
	LibrarianSignInFile.close();					// close the file
	
	cout << "\n Librarian Sign Up Is Successful";		
}

// Function implementation
void FineRateChanging(){
	float fineRate;
	
	cout << "\n ----------  Change The Fine Rate  ---------- \n" << endl;
	cout << " Enter the Fine Rate (%) : ";
	cin >> fineRate;
	
	fstream FineRateFile;		//create an object to class fstream and name it ‘FineRateFile’
	
	FineRateFile.open("FineRate.txt",ios::out);		//open the file to write, file name – FineRate.txt , mode out 
	
	FineRateFile << fineRate;					//Writing the fine rate to the file
	
	FineRateFile.close();					// close the file
	
	cout << "\n The Fine Rate Has Been Successfully Changed";		
}

// Function implementation
void AdjustingMaxBorrowingLimit(){
	int borrowingLimit;
	
	cout << "\n ----------  Modify Maximum Borrowing Limits  ---------- \n" << endl;
	cout << " Enter the Maximum Borrowing Limit Of Books : ";
	cin >> borrowingLimit;
	
	fstream MaxBorrowingLimitFile;		//create an object to class fstream and name it ‘MaxBorrowingLimitFile’
	
	MaxBorrowingLimitFile.open("BorrowingLimit.txt",ios::out);		//open the file to write, file name – BorrowingLimit.txt , mode out 
	
	MaxBorrowingLimitFile << borrowingLimit;					//Writing the borrowing limit to the file
	
	MaxBorrowingLimitFile.close();					// close the file	

	cout << "\n The Maximum Borrowing Limit Of Books Has Been Successfully Changed";
}

// Function implementation
void AdminExit(){
	int adminExitOption;
	
	cout << "\n\n-------  1. Go back to Admin Task Menu  -------" << endl;
	cout << "-------  2. Go back to Main Menu  \t-------" << endl;
	cout << "Enter the option number : ";
	cin >> adminExitOption;
	
	if(adminExitOption == 1){
		system("cls");
		adminTask();
	}
	else if(adminExitOption == 2){
		system("cls");
		main();
	}
	else{
		system("cls");
		cout << "\n Please select from the given options \n";
		AdminExit();
	}		
}

// Function implementation
void LibrarianLoginMenu(){
	int librarianOption = 0;
	
	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "                \t\t\t  LIBRARIAN  \n                               " << endl;
	cout << "           			   1. Login                                             	" << endl;
	cout << "           			   2. Go back to main menu                                        	" << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "Enter the option number : ";
	cin >> librarianOption;
	
	do{	
		if(librarianOption == 1){			
			LibrarianLogin();	
		}
		else if(librarianOption == 2){
			system("cls");
			main();	
		}
		else{
			system("cls");
			cout << "\n Please select from the given options \n";
			LibrarianLoginMenu();	
		}
	}while(librarianOption != 1,2);
}

// Function implementation
void LibrarianLogin(){
	string LibrarianId, LibrarianPassword, lId, lPwd;
	system("cls");
		
	//Getting userId & Password 
	cout << "\t\t LIBRARIAN \n\n";
	
//	cin.ignore();	
	cout << "Enter The Username To Log In : "; cin >> LibrarianId;
//	getline(cin, LibrarianId);
	cout << "Enter The Password To Log In : "; cin >> LibrarianPassword;
//	getline(cin, LibrarianPassword);
	
	fstream LibrarianSignInFile;
	
	LibrarianSignInFile.open("LibrarianUserPwd.txt",ios::in);		//open the file to read, file name – LibrarianUserPwd.txt , mode in
	
		
	while(LibrarianSignInFile >> lId >> lPwd){
		if(lId == LibrarianId && lPwd == LibrarianPassword){
			cout << "\n Your LOGIN is successful \n";
		//	librarianTask();
		}
		else{
			cout << "\n LOGIN ERROR \n Please check your Username and Password \n\n";
			system("PAUSE");
			LibrarianLogin();
		}
	}
	
	LibrarianSignInFile.close();
}
 


