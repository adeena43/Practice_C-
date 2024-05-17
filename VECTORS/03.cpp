//Vectors in OOP
#include<iostream>
#include<vector>
using namespace std;

class Student{
	private:
		string name;
		int roll;
		string discipline;
		string section;
		vector<string> courses;
		
	public:
		Student(string n, int roll, string discipline, string sec, vector<string> courses)
		{
			this->name = n;
			this->roll = roll;
			this->discipline = discipline;
			this->section = sec;
			this->courses = courses;
		}
		
		void displayInfo()
		{
			cout<<"Name: "<<name<<endl;
			cout<<"Roll Id: "<<roll<<endl;
			cout<<"Department: "<<discipline<<endl;
			cout<<"Section: "<<section<<endl;
			cout<<"Courses enrolled: ";
			for(int i =0; i<courses.size();i++)
			{
				cout<<endl<<"\t"<<courses[i];
			}
		}
};

class StudentPortal{
	private:
		vector<Student*> students;
	public:
		void addToPortal(Student* stu)
		{
			students.push_back(stu);
		}
		
		void displayStudents()
		{
			for(int i =0; i< students.size();i++)
			{
				cout<<endl<<endl<<"----------------Student "<<i+1<<"------------------"<<endl;
				students[i]->displayInfo();
			}
		}
		
		~StudentPortal()
		{
			for(int i =0; i< students.size();i++)
			{
				delete students[i];
			}
			students.clear();
		}
};

int main()
{
	vector<string> courses1;
    courses1.push_back("OOP");
    courses1.push_back("MVC");
    courses1.push_back("DLD");

    vector<string> courses2;
    courses2.push_back("FE");
    courses2.push_back("PF");
    courses2.push_back("Calculus");

	
	Student stu1("Saeed", 6788, "AI", "BAI-2A", courses1);
	Student stu2("Farhana", 38, "CS", "BCS-1B", courses2);
	
	StudentPortal portal;
	
	portal.addToPortal(&stu1);
	portal.addToPortal(&stu2);
	
	
	portal.displayStudents();
}
