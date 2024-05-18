#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

class InvalidInput{
	public:
		const char* what() const throw()
		{
			return "Invalid input\n";
		}
};
class FileNotFound{
	private:
		string filename;;
		
	public:
		FileNotFound(string name):filename(name){
		}
		const char* what() const throw()
		{
			return ("File: "+filename+" not found\n").c_str();
		}
};
class OutOfRange{
	private:
		int index;
	public:
		OutOfRange(int x):index(x){
		}
		
		const char* what() const throw()
		{
			return ("Index "+index+" is out of bound\n").c_str();
		}
};
class DivisionByZero{
	public:
		const char* what() const throw()
		{
			return "\nDivision by zero not possible\n";
		}
};
int main()
{
	 try {
        
        int x;
        std::cout << "Enter a positive integer: ";
        std::cin >> x;
        if (x <= 0) {
            throw InvalidInputException();
        }

        std::ifstream file("non_existent_file.txt");
        if (!file.is_open()) {
            throw FileNotFoundException("non_existent_file.txt");
        }

        int arr[5] = {1, 2, 3, 4, 5};
        int index = 10;
        if (index < 0 || index >= 5) {
            throw OutOfRangeException(index);
        }

        int numerator = 10;
        int denominator = 0;
        if (denominator == 0) {
            throw DivideByZeroException();
        }
        std::cout << "Result of division: " << numerator / denominator << std::endl;

    }
    catch(exception& ex)
    {
    	cout<<"\nError: "<<ex.what()<<endl;
	}
}
