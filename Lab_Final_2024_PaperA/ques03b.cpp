#include <iostream>
#include <string>

using namespace std;

class Hotel {
protected:
    string name;
    string location;
    int starRating;

public:
    Hotel(string name, string location, int starRating)
        : name(name), location(location), starRating(starRating) {}

    string getName() { return name; }
    string getLocation() { return location; }
    int getStarRating() { return starRating; }
};

class LuxuryHotel : public Hotel {
private:
    int numberOfRooms;
    bool swimmingPool;
    bool gym;
    string cuisineOptions;

public:
    LuxuryHotel(string name, string location, int starRating, int numberOfRooms, bool swimmingPool, bool gym, string cuisineOptions)
        : Hotel(name, location, starRating), numberOfRooms(numberOfRooms), swimmingPool(swimmingPool), gym(gym), cuisineOptions(cuisineOptions) {}

    int getNumberOfRooms() { return numberOfRooms; }
    bool hasSwimmingPool() { return swimmingPool; }
    bool hasGym() { return gym; }
    string getCuisineOptions() { return cuisineOptions; }
};

class BudgetHotel : public Hotel {
private:
    int numberOfRooms;
    bool basicAmenities;

public:
    BudgetHotel(string name, string location, int starRating, int numberOfRooms, bool basicAmenities)
        : Hotel(name, location, starRating), numberOfRooms(numberOfRooms), basicAmenities(basicAmenities) {}

    int getNumberOfRooms() { return numberOfRooms; }
    bool hasBasicAmenities() { return basicAmenities; }
};

class Resort : public Hotel {
private:
    int numberOfRooms;
    string recreationalActivities;

public:
    Resort(string name, string location, int starRating, int numberOfRooms, string recreationalActivities)
        : Hotel(name, location, starRating), numberOfRooms(numberOfRooms), recreationalActivities(recreationalActivities) {}

    int getNumberOfRooms() { return numberOfRooms; }
    string getRecreationalActivities() { return recreationalActivities; }
};

template <typename T>
class BookingSystem {
private:
    T hotel;
    string checkInDate;
    string checkOutDate;
    double cost;

public:
    BookingSystem(T hotel, string checkInDate, string checkOutDate, double cost)
        : hotel(hotel), checkInDate(checkInDate), checkOutDate(checkOutDate), cost(cost) {}

    T getHotel() { return hotel; }
    string getCheckInDate() { return checkInDate; }
    string getCheckOutDate() { return checkOutDate; }
    double getCost() { return cost; }
};

int main() {

    LuxuryHotel myLuxuryHotel("Grand Hotel", "City Center", 5, 100, true, true, "International Cuisine");
    BudgetHotel myBudgetHotel("Economy Lodge", "Suburb", 3, 50, true);
    Resort myResort("Beachfront Resort", "Seaside", 4, 200, "Water sports, Spa");

    BookingSystem<LuxuryHotel> luxuryHotelBooking(myLuxuryHotel, "2024-06-01", "2024-06-05", 1000.0);
    BookingSystem<BudgetHotel> budgetHotelBooking(myBudgetHotel, "2024-06-01", "2024-06-05", 400.0);
    BookingSystem<Resort> resortBooking(myResort, "2024-06-01", "2024-06-05", 1500.0);

    cout << "Luxury Hotel Booking Details:" << endl;
    cout << "Hotel Name: " << luxuryHotelBooking.getHotel().getName() << endl;
    cout << "Location: " << luxuryHotelBooking.getHotel().getLocation() << endl;
    cout << "Star Rating: " << luxuryHotelBooking.getHotel().getStarRating() << endl;
    cout << "Check-In Date: " << luxuryHotelBooking.getCheckInDate() << endl;
    cout << "Check-Out Date: " << luxuryHotelBooking.getCheckOutDate() << endl;
    cout << "Cost: $" << luxuryHotelBooking.getCost() << endl;
    cout << "Number of Rooms: " << luxuryHotelBooking.getHotel().getNumberOfRooms() << endl;
    cout << "Swimming Pool: " << (luxuryHotelBooking.getHotel().hasSwimmingPool() ? "Yes" : "No") << endl;
    cout << "Gym: " << (luxuryHotelBooking.getHotel().hasGym() ? "Yes" : "No") << endl;
    cout << "Cuisine Options: " << luxuryHotelBooking.getHotel().getCuisineOptions() << endl;
    cout << endl;

    cout << "Budget Hotel Booking Details:" << endl;
    cout << "Hotel Name: " << budgetHotelBooking.getHotel().getName() << endl;
    cout << "Location: " << budgetHotelBooking.getHotel().getLocation() << endl;
    cout << "Star Rating: " << budgetHotelBooking.getHotel().getStarRating() << endl;
    cout << "Check-In Date: " << budgetHotelBooking.getCheckInDate() << endl;
    cout << "Check-Out Date: " << budgetHotelBooking.getCheckOutDate() << endl;
    cout << "Cost: $" << budgetHotelBooking.getCost() << endl;
    cout << "Number of Rooms: " << budgetHotelBooking.getHotel().getNumberOfRooms() << endl;
    cout << "Basic Amenities: " << (budgetHotelBooking.getHotel().hasBasicAmenities() ? "Yes" : "No") << endl;
    cout << endl;

    cout << "Resort Booking Details:" << endl;
    cout << "Hotel Name: " << resortBooking.getHotel().getName() << endl;
    cout << "Location: " << resortBooking.getHotel().getLocation() << endl;
    cout << "Star Rating: " << resortBooking.getHotel().getStarRating() << endl;
    cout << "Check-In Date: " << resortBooking.getCheckInDate() << endl;
    cout << "Check-Out Date: " << resortBooking.getCheckOutDate() << endl;
    cout << "Cost: $" << resortBooking.getCost() << endl;
    cout << "Number of Rooms: " << resortBooking.getHotel().getNumberOfRooms() << endl;
    cout << "Recreational Activities: " << resortBooking.getHotel().getRecreationalActivities() << endl;

    return 0;
}
