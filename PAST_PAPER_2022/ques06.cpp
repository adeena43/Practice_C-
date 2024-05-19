#include<iostream>
#include<fstream>
using namespace std;

class File{
	protected:
		int size;
		string location;
		string created;
		string modified;
	public:
		File(int size, string path, string created, string modified)
		{
			this->size=size;
			this->location=path;
			this->created= created;
			this->modified=modified;
		}
		
		virtual void Open() =0;
		
		virtual void print()
		{
			cout<<"Printing a file"<<endl;
		}
		friend bool const operator * (File , File );
};
bool const operator * (File file_object_1, File file_object_2)
{
	if(file_object_1.size==file_object_1.size&&(!strcmp(file_object_1.location,file_object_2.location)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

class PDF:public File{
	public:
		PDF(int size, string location, string created, string modified): File(size, location, created, modified)
		{
		}
		
		virtual void Open()
		{
			cout<<"Opening the PDF file"<<endl;
		}
		virtual void print()
		{
			cout<<"Printing the PDF file"<<endl;
		}
		
};

class ASCII:public File{
	public:
		ASCII(int size, string location, string created, string modified): File(size, location, created, modified)
		{
		}
		
		virtual void Open()
		{
			cout<<"Opening the PDF file"<<endl;
		}
		virtual void print()
		{
			cout<<"Printing the ASCII file"<<endl;
		}
};

class PS:public File{
	public:
		PS(int size, string location, string created, string modified): File(size, location, created, modified)
		{
		}
		
		virtual void Open()
		{
			cout<<"Opening the PS file"<<endl;
		}
		virtual void print()
		{
			cout<<"Printing the PS file"<<endl;
		}
};

int main()
{
	File* fptr1;
	File* fptr2;
	File* fptr3;
	fptr1 = new PDF(45, "C drive", "23-03-2012","09-10-2022");
	fptr2 = new PS(45, "C drive", "23-03-2012","09-10-2022");
	fptr3 = new ASCII(45, "C drive", "23-03-2012","09-10-2022");
	fptr1->Open();
	fptr1->print();
	
	fptr2->Open();
	fptr2->print();
	
	fptr3->Open();
	fptr3->print();
	
	delete fptr1;
	delete fptr2;
	delete fptr3;
	return 0;
}
