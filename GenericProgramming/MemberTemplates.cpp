#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Complex {
public:
    T real;
    T imaginary;


    Complex(T r, T imag) : real(r), imaginary(imag) {}

    // Overloaded copy constructor which is a member template
    template<typename U>
    Complex(const Complex<U>& c) : real(c.real), imaginary(c.imaginary) {}

    // Friend declaration for the non-member operator<< function
    template<typename U>
    friend ostream& operator<<(ostream& output, const Complex<U>& c);
};

// Definition of the non-member operator<< function
template<typename U>
ostream& operator<<(ostream& output, const Complex<U>& c) {
    output << "(" << c.real << ", " << c.imaginary << ")";
    return output;
}

int main() {
    Complex<int> ic(1, 56);
    Complex<float> fc(23.5, 556.88);
    Complex<double> dc = fc;

    cout << dc << endl;
    cout << fc << endl;
    cout << ic << endl;

    return 0;
}
