#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

class MyClass {
private:
    string comments;
    int value;

public:
    MyClass(string x, int y) : comments(x), value(y) {}

    string getComments() {
        return comments;
    }

    int getValue() {
        return value;
    }

   void addObjToFile() {
    try {
        fstream file;
        file.open("myFile.txt", ios::app);
        if (!file.is_open()) {
            throw runtime_error("Error opening the file");
        } else {
            file << "Comments: " << getComments() << endl;
            file << "Value: " << getValue() << endl;
            cout << "Object added to the file " <<endl;
            file.close();
        }
    } catch (const runtime_error& ex) {
        cerr << "Exception caught: " << ex.what() << endl;
    }
}

};

int main() {
    MyClass obj1("Hello who is this?", 200);
    obj1.addObjToFile();

    return 0;
}
