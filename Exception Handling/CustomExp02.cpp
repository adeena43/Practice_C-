#include<iostream>
#include<exception>
#include<string>
using namespace std;

class FileOfException: public exception{
	private:
	string message, filename;
	
	public:
		FileOfException(string msg, string fname):message(msg), filename(fname)
		{
		}
		
		const char* what() noexcept override{
			return("File: "+filename+", Error: "+ message).c_str();
		}
};

int main()
{
	try
	{
		string filename = "example.txt";
		throw FileOfException(filename, "File not Found");
		
	}
	catch(const FileOfException& e)
	{
		cout<<"Caught FileOfException: "<<e.what()<<endl;
	}
	catch(exception& e)
	{
		cout<<"Caught standard exception: "<<e.what()<<endl;
	}
	return 0;
}
