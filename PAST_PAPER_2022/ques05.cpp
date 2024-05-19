#include<iostream>
#include<stdexcept>
#include<exception>
using namespace std;

int count=0;

void Enter()
{
	try{
		if(count>=10)
		{
			throw invalid_argument("Count Overflow");
		}
		else
		{
			count++;
		}
	}
		catch(invalid_argument& arg)
	{
		cout<<arg.what()<<endl;
	}

}
void Exit()
{
	try{
		if(count<=0)
		{
			throw runtime_error("Count Underflow");
		}
		else
		{
			count--;
		}
	}
		catch(runtime_error& err)
	{
		cout<<err.what()<<endl;
	}
}
int main()
{
	int choice;
	while(1)
	{
		cout<<"1. Enter an person\n2. Exit a person\n";
		cin>>choice;
		if(choice==1)
		{
			Enter();
		}
		else if(choice==2)
		{
			Exit();
		}
	}

	return 0;
}
