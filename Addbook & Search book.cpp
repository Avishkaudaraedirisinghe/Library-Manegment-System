void addBook(){
	system("cls");
	fstream File;
	string bookID;
	string bookTitle;
	string bookAuthor;
	float bookPrice;
	string bookGenre;
	string bookPublisher;
	bool available;
	string key;
	
	File.open("bookdetails.txt",ios::app);
	
	if(!File){
		cout<<"File open failed!!!";
	}
	else{
		cout<<"\t\t\t*******    Add a book	 *****\n"<<endl;
		cout<<"\t\t\t   1.Enter book ID			: ";
		cin>>bookID;
		cout<<"\t\t\t   2.Enter book title		:";
		cin.ignore();
		getline(cin,bookTitle);
		cout<<"\t\t\t   3.Enter book author		:";
		cin.ignore();
		getline(cin,bookAuthor);
		cout<<"\t\t\t   4.Enter book price		: Rs.";
		cin>>bookPrice;
		cout<<"\t\t\t   5.Enter book publisher	:";
		cin.ignore();
		getline(cin,bookPublisher);
		cout<<"\t\t\t   6.Enter book genre		:";
		cin.ignore();
		getline(cin,bookGenre);		
		cout<<"\t\t\t   7.Availability Status	:";
		cin>>available;
		
		File<<"\n\n1.Book ID		: "<<bookID<<endl;
		File<<"2.Book title		: "<<bookTitle<<endl;
		File<<"3.Book author		: "<<bookAuthor<<endl;
		File<<"4.Book price			: "<<bookPrice<<endl;
		File<<"5.Book publisher		: "<<bookPublisher<<endl;
		File<<"6.Book genre			: "<<bookGenre<<endl;
		File<<"7.Book availability	: "<<available<<endl;
	}
	File.close();
	cout<<"\t\t\tBook Details added successfully!!!";
	cout<<"\n";
	cout<<"\t\t\tEnter 'b' key to go back:";
	cin>>key;
	adddeleteBook();
}
