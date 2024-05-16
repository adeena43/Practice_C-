#include<iostream>
#include<string>

using namespace std;

class Vehicle{
	protected:
		string make;
		string model;
		int maxSpeed;
		
	public:
		Vehicle(string make, string model, int speed):make(make), model(model), maxSpeed(speed)
		{
		}
		
		string getMake()
		{
			return make;
		}
		string getModel()
		{
			return model;
		}
		int getMaxSpeed()
		{
			return maxSpeed;
		}
};

class Bus: public Vehicle{
	private:
		int numSeats;
		string route;
		
	public:
		Bus(string make, string model, int speed, int numSeats, string route):Vehicle( make, model,speed),numSeats(numSeats),route(route)
		{
		}
		int getNumSeats()
		{
			return numSeats;
		}
		
		string getRoute()
		{
			return route;
		}
};

class Train: public Vehicle{
private:
		int numSeats;
		string route;
		
	public:
		Train(string make, string model, int speed, int numSeats, string route):Vehicle( make, model,speed),numSeats(numSeats),route(route)
		{
		}
		
		int getNumSeats()
		{
			return numSeats;
		}
		
		string getRoute()
		{
			return route;
		}
};

class Airplane: public Vehicle{
	private:
		int numSeats;
		int altitude;
		
	public:
		Airplane(string make, string model, int speed, int numSeats, int altitude):Vehicle( make, model,speed),numSeats(numSeats),altitude(altitude)
		{
		}
		int getNumSeats()
		{
			return numSeats;
		}
		int getAltitude()
		{
			return altitude;
		}
};

template <class T>
class BookingSystem{
	private:
		T vehicle;
		string departTime;
		string arrivalTime;
		double cost;
		
	public:
		BookingSystem(T vehicle, string depart, string arrival, double cost):vehicle(vehicle), departTime(depart), arrivalTime(arrival), cost(cost)
		{
		}
		
		T getVehicle()
		{
			return vehicle;
		}
		
		string getDepartureTime()
		{
			return departTime;
		}
		string getArrivalTime()
		{
			return arrivalTime;
		}
		
		double getCost()
		{
			return cost;
		}
	
};

int main()
{
	Bus b1("Pata nahi","Ye to bilkul nahi pata", 0.00, 0, "Dozakh");
	Train t1("Mene nahi banai", "Baba Adam se pehle ka", 10000, 9999, "Chalti hi nahi hai bhai");
	Airplane a1("Swift", "Qayamat ke baad banega InShaAllah", 0, 5678, 0);
	
	BookingSystem<Bus> busBooking(b1, "kabhi nahi","kabhi nahi",1000);
	BookingSystem<Train> trainBooking(t1, "Apni marzi se aane ka","Apni marzi se jaane ka",1000);
	BookingSystem<Airplane> airplaneBooking(a1, "Nae me kyun bataon?","Aesi batein batayi nahi jateen!!",1000);
	
	 cout << "Bus Booking Details:" << endl;
    cout << "Make: " << busBooking.getVehicle().getMake() << endl;
    cout << "Model: " << busBooking.getVehicle().getModel() << endl;
    cout << "Max Speed: " << busBooking.getVehicle().getMaxSpeed() << " km/h" << endl;
    cout << "Number of Seats: " << busBooking.getVehicle().getNumSeats() << endl;
    cout << "Route: " << busBooking.getVehicle().getRoute() << endl;
    cout << "Departure Time: " << busBooking.getDepartureTime() << endl;
    cout << "Arrival Time: " << busBooking.getArrivalTime() << endl;
    cout << "Cost: $" << busBooking.getCost() << endl << endl;

    cout << "Train Booking Details:" << endl;
    cout << "Make: " << trainBooking.getVehicle().getMake() << endl;
    cout << "Model: " << trainBooking.getVehicle().getModel() << endl;
    cout << "Max Speed: " << trainBooking.getVehicle().getMaxSpeed() << " km/h" << endl;
    cout << "Number of Seats: " << trainBooking.getVehicle().getNumSeats() << endl;
    cout << "Route: " << trainBooking.getVehicle().getRoute() << endl;
    cout << "Departure Time: " << trainBooking.getDepartureTime() << endl;
    cout << "Arrival Time: " << trainBooking.getArrivalTime() << endl;
    cout << "Cost: $" << trainBooking.getCost() << endl << endl;

    cout << "Airplane Booking Details:" << endl;
    cout << "Make: " << airplaneBooking.getVehicle().getMake() << endl;
    cout << "Model: " << airplaneBooking.getVehicle().getModel() << endl;
    cout << "Max Speed: " << airplaneBooking.getVehicle().getMaxSpeed() << " km/h" << endl;
    cout << "Number of Seats: " << airplaneBooking.getVehicle().getNumSeats() << endl;
    cout << "Altitude: " << airplaneBooking.getVehicle().getAltitude() << " feet" << endl;
    cout << "Departure Time: " << airplaneBooking.getDepartureTime() << endl;
    cout << "Arrival Time: " << airplaneBooking.getArrivalTime() << endl;
    cout << "Cost: $" << airplaneBooking.getCost() << endl;

    return 0;
}
