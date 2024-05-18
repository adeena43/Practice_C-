#include<iostream>
#include<string>
#include<vector>
#include <cstring> // For strlen, strcpy
using namespace std;

template<>
class Vector<char*> {
private:
    int size;
    char** ptr;

public:
    //default constructor setting initial size of the vector to 10
    Vector(int s = 10) : size(s) {
        if (size != 0) {
            ptr = new char*[size];
            for (int i = 0; i < size; i++) {
                ptr[i] = nullptr;
            }
        } else {
            ptr = nullptr;
        }
    }

    //Overloaded copy constructor
    Vector(const Vector<char*>& copy) {
        size = copy.size;
        if (size == 0) {
            ptr = nullptr;
            return;
        }
        ptr = new char*[size];
        for (int i = 0; i < size; i++) {
            if (copy.ptr[i] != nullptr) {
                ptr[i] = new char[strlen(copy.ptr[i]) + 1];
                strcpy(ptr[i], copy.ptr[i]);
            } else {
                ptr[i] = nullptr;
            }
        }
    }

    //Defining the destructor
    ~Vector() {
        for (int i = 0; i < size; i++) {
            delete[] ptr[i];
        }
        delete[] ptr;
    }

    //defining the getSize() function
    int getSize() const {
        return size;
    }

    //defining the "=" operator overloading function
    const Vector<char*>& operator=(const Vector<char*>& right) {
        if (this == &right) {
            return *this;
        }

        for (int i = 0; i < size; i++) {
            delete[] ptr[i];
        }
        delete[] ptr;

        size = right.size;
        if (size == 0) {
            ptr = nullptr;
            return *this;
        }

        ptr = new char*[size];
        for (int i = 0; i < size; i++) {
            if (right.ptr[i] != nullptr) {
                ptr[i] = new char[strlen(right.ptr[i]) + 1];
                strcpy(ptr[i], right.ptr[i]);
            } else {
                ptr[i] = nullptr;
            }
        }
        return *this;
    }

    //Defining the body of index operator"[]" overloading
    const char*& operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Error, index out of bound" << endl;
            exit(1);
        }
        return ptr[index];
    }

    //Defining the body of insert function
    void insert(char* str, int i) {
        delete[] ptr[i];
        if (str != nullptr) {
            ptr[i] = new char[strlen(str) + 1];
            strcpy(ptr[i], str);
        } else {
            ptr[i] = nullptr;
        }
    }
};

int main() {
    Vector<char*> sv1(2);

    sv1.insert("Amna", 0);
    sv1.insert("Zubair", 1);
    sv1.insert("Rehan", 3); // This should be sv1.insert("Rehan", 2); as the index starts from 0

    Vector<char*> sv2(sv1);
    Vector<char*> sv3(2);
    sv3 = sv1;
    return 0;
}
