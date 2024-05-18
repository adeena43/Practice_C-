#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;
class Divide{
	float a, b;
	
	public:
		Divide(float x, float y):a(x),b(y)
		{
		}
		
		void divide()
		{
			try
			{
				if(b==0)
				{
					throw runtime_error("Error, Can't divide by zero");
				}
				else{
					cout<<a/b<<endl;
				}
			}
			catch(runtime_error& er)
			{
				cout<<"Exception caught: "<<er.what()<<endl;
			}
			
		}
};

int main()
{
	Divide d1(3, 4);
	Divide d2(2,0);
	
	d1.divide();
	d2.divide();
}
