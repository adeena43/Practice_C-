#include <iostream>
#include <string>

using namespace std;

class Property {
private:
    string address;
    double reservePrice;

public:
    Property(string addr, double price) : address(addr), reservePrice(price) {}

    friend void displayPropertyInfo(const Property& prop);

    string getAddress() const { return address; }
    double getReservePrice() const { return reservePrice; }
};

void displayPropertyInfo(const Property& prop) {
    cout << "Property Address: " << prop.address << endl;
    cout << "Reserve Price: " << prop.reservePrice << endl;
}

class Bid {
public:
    virtual void placeBid(double amount) = 0;
    virtual void displayBidInfo() const = 0;
    virtual ~Bid() {}
};

class Bidder : public Bid {
private:
    string name;
    double bidAmount;

public:
    Bidder(string n, double amount) : name(n), bidAmount(amount) {}

    void placeBid(double amount) override {
        bidAmount = amount;
    }

    void displayBidInfo() const override {
        cout << "Bidder Name: " << name << endl;
        cout << "Bid Amount: " << bidAmount << endl;
    }

    string getName() const { return name; }
    double getBidAmount() const { return bidAmount; }
};

class PropertyBiddingSystem {
private:
    Property property;
    Bidder* bidders[3];
    int numBidders;

public:
    PropertyBiddingSystem(const Property& prop) : property(prop), numBidders(0) {}

    void addBidder(Bidder* bidder) {
        if (numBidders < 3) {
            bidders[numBidders++] = bidder;
        } else {
            cout << "Cannot add more bidders. Maximum limit reached." << endl;
        }
    }

    void displayWinningBidder() const {
        double highestBid = 0.0;
        int winningIndex = -1;
        for (int i = 0; i < numBidders; ++i) {
            if (bidders[i]->getBidAmount() >= property.getReservePrice()) {
                if (bidders[i]->getBidAmount() > highestBid) {
                    highestBid = bidders[i]->getBidAmount();
                    winningIndex = i;
                }
            }
        }
        if (winningIndex != -1) {
            cout << "Winning Bidder: " << bidders[winningIndex]->getName() << endl;
            cout << "Winning Bid Amount: " << highestBid << endl;
        } else {
            cout << "No winning bidder." << endl;
        }
    }

    void displayBiddingSystemInfo() const {
        displayPropertyInfo(property);
        for (int i = 0; i < numBidders; ++i) {
            bidders[i]->displayBidInfo();
        }
    }

    ~PropertyBiddingSystem() {
        for (int i = 0; i < numBidders; ++i) {
            delete bidders[i];
        }
    }
};

int main() {
    Property property("Shah Latif Town", 100000.0);
    Bidder bidder1("Mr. Ubaid Khan", 150000.0);
    Bidder bidder2("Mr. Muhammad Khalid", 110000.0);
    Bidder bidder3("Mr. Waseem Rauf", 130000.0);
    Bidder bidder4("Mr. Sameer", 130000.0);

    PropertyBiddingSystem system(property);
    system.addBidder(&bidder1);
    system.addBidder(&bidder2);
    system.addBidder(&bidder3);
    system.addBidder(&bidder4);

    system.displayWinningBidder();
    system.displayBiddingSystemInfo();

    return 0;
}
