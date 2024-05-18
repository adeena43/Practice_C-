#include<iostream>
#include<string>
#include<cstring>
using namespace std;

template <typename T>
T maximum(T a, T b)
{
    if(a > b)
        return a;
    else
        return b;
}

template<>
const char* maximum<const char*>(const char* a, const char* b)
{
    if(strlen(a) > strlen(b))
        return a;
    else
        return b;
}

int main()
{
    int a = 90, b = -90;
    const char* x = "Adina";
    const char* y = "Sara";
    
    int maxVal1 = maximum(a, b);
    const char* maxVal2 = maximum(x, y);
    
    cout << maxVal1 << " is greater" << endl;
    cout << maxVal2 << " is also greater" << endl;
    
    return 0;
}
