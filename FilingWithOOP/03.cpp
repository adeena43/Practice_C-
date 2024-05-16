/*
Address Book: Create a program to manage an address book. Each entry in the address book should store information 
such as name, address, phone number, and email
Implement functionalities to add new contacts, delete contacts, update contact information, and display all contacts.
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class AddressBook{
	
	private:
	string name;
	string address;
	string email;
	
	public:
		void getData()
		{
		    cout << endl << "Enter Name: ";
		    cin >> name; // Read name without spaces
		    cin.ignore(); // Ignore the newline character left in the input buffer
		    cout << endl << "Enter Address: ";
		    getline(cin, address); // Read address including spaces
		    cout << endl << "Enter Email: ";
		    cin >> email; // Read email without spaces
		}
		void addRecord()
		{
			fstream book;
			book.open("myPhone.txt", ios::out);
			AddressBook R;
			try{
				if(!book.is_open())
				{
					throw("Can't open the file");
				}
				else
				{
					R.getData();
					book<<R.name<<" "<<R.address<<" "<<R.email<<endl;
					cout<<"Record added to the file successfully"<<endl;
					book.close();
				}
			}
			catch(string str)
			{
				cout<<"Error occurred: "<<str<<endl;
			}
		}
		
		void deleteRecord(string email)
		{
			ifstream book("myPhone.txt");
			ofstream temp("temp.txt");
			
			if(!book.is_open()||!temp.is_open())
			{
				cerr<<"Error opening files";
			}
			
			AddressBook tempRec;
			
			while(book>>tempRec.name>>tempRec.address>>tempRec.email)
			{
				if(tempRec.email!=email)
				{
					temp<<tempRec.name<<" "<<tempRec.address<<" "<<tempRec.email<<endl;
				}
			}
			temp.close();
			book.close();
			
			remove("myPhone.txt");
			rename("temp.txt", "myPhone.txt");
			
			cout<<"Record deleted successfully"<<endl;
		}
		//Updating contact information
		void updateRecord(string email)
		{
			ifstream book("myPhone.txt");
			ofstream temp("temp.txt");
			
			if(!book.is_open()||!temp.is_open())
			{
				cerr<<"Error opening files";
			}
			
			AddressBook tempRec;
			
			string newName, newAdd, newEmail;
			
			while(book>>tempRec.name>>tempRec.address>>tempRec.email)
			{
				if(tempRec.email!=email)
				{
					temp<<tempRec.name<<" "<<tempRec.address<<" "<<tempRec.email<<endl;
				}
				if(tempRec.email==email)
				{
					cout<<endl<<"Enter new name: ";
					cin>>newName;
					cout<<endl<<"Enter new address: ";
					cin>>newAdd;
					cout<<endl<<"Enter new email: ";
					cin>>newEmail;
					temp<<newName<<" "<<newAdd<<" "<<newEmail<<endl;
				}
				else
			{
				cout<<"No record by this email found"<<endl;
			}
			}
			temp.close();
			book.close();
			
			remove("myPhone.txt");
			rename("temp.txt", "myPhone.txt");
			
			cout<<"Record updated successfully"<<endl;
		}
		
		void displayContactsToConsole()
		{
			ifstream file("myPhone.txt");
        if (!file.is_open()) {
            cout << "Error opening the file!!" << endl;
            return;
        }
        cout << "\n\tName\tAddress\tEmail\n";
        while (file >> name >> address >> email) {
            cout << "\n\t" << name << "\t" << address << "\t" << email;
        }
        file.close();
		}
};

int main()
{
	AddressBook people;
    char ch = 'n';
    
    do {
        people.addRecord();
        cout << "Do you want to add more records to the file? [Y/y or N/n]" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    
    people.displayContactsToConsole();

    cout << "Data written successfully..." << endl;
	people.deleteRecord("adinafraz01@gmail.com");
	people.updateRecord("frazmeer_25@gmail.com");
	
    people.displayContactsToConsole();

    return 0;
	
}
