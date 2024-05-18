#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Printer{
	private:
		T value;
	
	public:
		Printer(T value):value(value)
		{
		}
		
		void print()
		{
			cout<<"Generic print: "<<value<<endl;
		}
};

//specialized template for char
template<>
class Printer<char>
{
	char ch;
	public:
		Printer(char x):ch(x)
		{	
		}
		void print()
		{
			cout<<"Character specialized class: "<<ch<<endl;
		}
};
int main()
{
	Printer<int> ip(12);
	Printer<float> fp(9.88);
	Printer<char> cp('M');
	Printer<string> sp("Hello my name is Adina!");
	sp.print();
	ip.print();
	fp.print();
	cp.print();
	
	return 0;
}
