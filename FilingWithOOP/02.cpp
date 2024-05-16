#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int roll;
    string discipline;

public:
    void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter discipline: ";
        cin >> discipline;
    }

    void addRecord() {
        try {
            ofstream file("myFile.txt", ios::app);
            if (!file.is_open()) {
                throw("Error opening the file!!");
            } else {
                Student stu;
                stu.getData();
                file << stu.name << " " << stu.roll << " " << stu.discipline << endl;
                cout << "Record added to the file." << endl;
                file.close();
            }
        } catch (string s) {
            cout << "Exception: " << s << endl;
        }
    }

    void DisplayDataOnConsole() {
        ifstream file("myFile.txt");
        if (!file.is_open()) {
            cout << "Error opening the file!!" << endl;
            return;
        }
        cout << "\n\tName\tRoll ID\tDiscipline\n";
        while (file >> name >> roll >> discipline) {
            cout << "\n\t" << name << "\t" << roll << "\t" << discipline;
        }
        file.close();
    }
};

int main() {
    Student s1;
    char ch = 'n';
    
    do {
        s1.addRecord();
        cout << "Do you want to add more records to the file? [Y/y or N/n]" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << "Data written successfully..." << endl;

    s1.DisplayDataOnConsole();

    return 0;
}
