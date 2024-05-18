#include <iostream>
#include <algorithm> 
#include<string>
using namespace std;

template<typename T, size_t N>
class Container {
protected:
    T items[N];
    size_t itemCount;

public:
    Container() : itemCount(0) {}

    void addItem(const T& item) {
        if (itemCount < N) {
            items[itemCount++] = item;
        } else {
            std::cout << "Container is full!" << std::endl;
        }
    }

    void displayItems() const {
        for (size_t i = 0; i < itemCount; ++i) {
            std::cout << items[i] << std::endl;
        }
    }
};

class StringContainer : public Container<std::string, 10> {
public:
    
    void sortItems() {
        for (size_t i = 0; i < itemCount - 1; ++i) {
            for (size_t j = 0; j < itemCount - i - 1; ++j) {
                if (items[j] > items[j + 1]) {
                    string temp;
                    temp = items[j];
                    items[j]=items[j+1];
                    items[j+1]=temp;
                }
            }
        }
    }
};

int main() {
    StringContainer stringContainer;
    stringContainer.addItem("banana");
    stringContainer.addItem("apple");
    stringContainer.addItem("orange");

    std::cout << "Before sorting:" << std::endl;
    stringContainer.displayItems();

    stringContainer.sortItems();

    std::cout << "\nAfter sorting:" << std::endl;
    stringContainer.displayItems();

    return 0;
}
