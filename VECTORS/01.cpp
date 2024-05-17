
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> vector1(10);
	std::fill(vector1.begin(), vector1.end(), 0);
	
	cout<<"Enter values upto 10-------"<<endl;
	for(int i =0; i<vector1.size(); i++)
	{
		cin>>vector1[i];
	}
	int sum =0;
	for(int i =0; i<vector1.size();i++)
	{
		sum+=vector1[i];
	}
	cout<<endl<<"Sum: "<<sum;
}

