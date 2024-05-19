#include <iostream>
#include <string>

using namespace std;

class Sport {
public:
    string current_champ;
    int start_year;
    string headquarter_location;
    
    Sport(string champ, int year, string location)
        : current_champ(champ), start_year(year), headquarter_location(location) {}
};

// Global template function to print any attribute of the Sport class
template<typename T>
void PrintIt(const Sport& sport, T attribute) {
    cout << attribute << ": ";
    if constexpr (std::is_same_v<T, string>) {
        if (attribute == "current_champ")
            cout << sport.current_champ << endl;
        else if (attribute == "headquarter_location")
            cout << sport.headquarter_location << endl;
    } else if constexpr (std::is_same_v<T, int>) {
        if (attribute == "start_year")
            cout << sport.start_year << endl;
    } else {
        cout << "Attribute not recognized." << endl;
    }
}

int main() {
    Sport soccer("TeamA", 2020, "CityX");

    // Print different attributes of the Sport object using the PrintIt function
    PrintIt(soccer, "current_champ");
    PrintIt(soccer, "start_year");
    PrintIt(soccer, "headquarter_location");

    return 0;
}
