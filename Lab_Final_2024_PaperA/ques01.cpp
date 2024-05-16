#include<iostream>
using namespace std;

class Attraction{
	protected:
		string name;
		int thrillLevel;
		int capacity;
		int duration;
	public:
		Attraction(string n, int level, int cap, int duration):name(n), thrillLevel(level), capacity(cap), duration(duration)
		{
		}
		
		virtual void displayInfo()
		{
			cout<<"Name: "<<name<<endl;
			cout<<"thrillLevel: "<<thrillLevel<<endl;
			cout<<"capacity: "<<capacity<<endl;
			cout<<"duration: "<<duration<<endl;
		}
		
		virtual void simulateRide()
		{
		}
};

class RollerCoaster:public Attraction{
	int drops;
	
	public:
		RollerCoaster(string n, int level, int cap, int duration, int drops):Attraction(n, level,cap,duration),drops(drops)
		{
		}
		virtual void displayInfo()
		{
			Attraction::displayInfo();
			cout<<"drops: "<<drops<<endl;
		}
		
		virtual void simulateRide()
		{
			cout<<"Simulating RollerCoaster..."<<endl;
		}
};

class WaterRide:public Attraction{
	double waterUsage;
		public:
		WaterRide(string n, int level, int cap, int duration, double waterUsage):Attraction(n, level,cap,duration),waterUsage(waterUsage)
		{
		}
		virtual void displayInfo()
		{
			Attraction::displayInfo();
			cout<<"Water usage: "<<waterUsage<<endl;
		}
		
		virtual void simulateRide()
		{
			cout<<"Simulating Water ride..."<<endl;
		}
};

class Show:public Attraction{
	string performer;
	public:
		Show(string n, int level, int cap, int duration, string performer):Attraction(n, level,cap,duration),performer(performer)
		{
		}
		
		virtual void displayInfo()
		{
			Attraction::displayInfo();
			cout<<"Performer: "<<performer<<endl;
		}
		
		virtual void simulateRide()
		{
			cout<<"Simulating Show ride..."<<endl;
		}
};

class ThemePark{
	Attraction* atts[10];
	int count;
	public:
		ThemePark(int x =0):count(x){
		}
		void addAttraction(Attraction* a1)
		{
			if(count<10)
			{
				atts[count]=a1;
				count++;
			}
			else{
				cout<<"No more space in the theme park to add attractions"<<endl;
			}
		}
		
		void displayAttractions()
		{
			for(int i =0; i<10; i++)
			{
				atts[i]->displayInfo();
				atts[i]->simulateRide();
			}
		}
		
		void simulateDay()
		{
			cout<<"Simulating a day in the theme park..."<<endl;
			for(int i =0; i<count; i++)
			{
				atts[i]->simulateRide();
			}
		}
		
		~ThemePark()
		{
			for(int i =0; i<count; i++)
			{
				delete atts[i];
			}
		}
};

int main()
{
	ThemePark park;

    RollerCoaster* rollerCoaster = new RollerCoaster("Big Dipper", 9, 20, 5, 3);
    WaterRide* waterRide = new WaterRide("Splash Mountain", 7, 30, 10, 100.5);
    Show* show = new Show("Fireworks Spectacular", 5, 100, 20, "The Fireworks Team");

    park.addAttraction(rollerCoaster);
    park.addAttraction(waterRide);
    park.addAttraction(show);

    park.displayAttractions();
    cout << endl;

    park.simulateDay();

	return 0;
}
