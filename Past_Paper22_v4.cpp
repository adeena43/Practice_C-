#include<iostream>
#include<string>
using namespace std;

class Employee{
	protected:
		string name;
		string designation;
		string department;
		int salary;
	public:
		Employee(string name, string designation, string department, int sal)
		{
			this->name=name;
			this->designation=designation;
			this->department=department;
			this->salary=sal;
		}
		string getDept()
		{
			return department;
		}
		
		virtual bool Verify(string str)
		{
		}
		
		int operator++(int)
		{
			int increased = static_cast<int>(salary*0.10);
			salary+=increased;
			return salary;
		}
};

class Course{
	private:
		string code;
		string courseName;
		int cdhrs;
		bool isAssigned;
	public:
		Course(string code, string name, int cdhrs)
		{
			this->code=code;
		    this->courseName=name;
			this->cdhrs=cdhrs;
			this->bool=false;
		}
		
		string getcourseCode()
		{
			return code;
		}
		
		string getCourseName()
		{
			return name;
		}
		
		int getHours()
		{
			return cdhrs;
		}

};

class Faculty:public Employee
{
	protected:
		int hours;
		Course list[];
		int assignedCourses;
	public:
		Faculty(string name, string designation, string dept, int salary, int hrs):Employee(name, designation, department, sal), hours(hrs)
		{
		}
		
		void AssignCourse(Course courses[])
		{
			int total_cdhrs=0
			for(int i =0; i<assignedCourses; i++)
			{
				total_cdhrs+=courses[i].getHours();
			}
			
			for(int i = 0; i<total_cdhrs; i++)
			{
				char department_code=getDepartmen().substr(0,1);
				char course_code = courses[i].getCourseCode().substr(0,1);
				if(department_code==course_code)
				{
					total_cdhrs+=courses[i].getHours();
					if(total_cdhrs<=12)
					{
						cout<<"Assigning course: "<<courses[i].getName()<<endl;
						list[assignedCourses++]=courses[i];
						return;
					}
					else
					{
						cout<<"Warning: Total assigned credit hours exceed the limit"<<endl;
						return;
					}
				}
			}
		}
		void Salary()
		{
			if(hours==36)
			{
				cout<<"Salary = "<<salary;
			}
			else
			{
				int extra_hours = hours-36;
				salary+=1000*extraHours;
				cout<<"Salary: "<<salary<<endl;
							}
		}
		
		Faculty operator++(int)
		{
			Faculty temp(*this);
			salary*=0.20;
			if(designation=="Instructor")
			{
				designation="Lecturer";
			}
			else if(designation=="Lecturer")
			{
				designation="Assistant Professor";
			}
			return temp;
		}
		
		void operator=(const Faculty& other)
		{
			name=other.name;
			desination=other.designation;
			department=other.department;
			salary=other.salary;
		}
};


class Staff: ppublic Emplooyee
{
	protected:
		int overTimeHrs;
	
	public:
		Staff(string name, string designation, string department, int sal, int hrs):Employee(name, designation, department, sal), overTimeHrs(hrs)
		{
		}
		virtual bool Verify(string str)
		{
			if(str==department)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		bool Verify(int x, int y)
		{
			if(x>y)
			{
				if(salary>y&&salary<x)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if(salary>x&&salary<y)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
};

int main()
{
	return 0;
}
