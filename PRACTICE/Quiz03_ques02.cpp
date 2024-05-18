#include <iostream>
#include <string>
#include<stdexcept>

using namespace std;

template <typename T>
class Product {
private:
    string name;
    double price;
    string manufacturer;
    int stockLevel;

public:
    Product(const string& name = "", double price = 0.0, const string& manufacturer = "", int stockLevel = 0)
        : name(name), price(price), manufacturer(manufacturer), stockLevel(stockLevel) {}

    string getName() const { return name; }
    double getPrice() const { return price; }
    string getManufacturer() const { return manufacturer; }
    int getStockLevel() const { return stockLevel; }

    void setStockLevel(int stock) { stockLevel = stock; }

    bool operator==(const Product<T>& other) const {
        return name == other.name && price == other.price && manufacturer == other.manufacturer;
    }
};

template <typename T>
class ShoppingCart {
private:
    static const int MAX_PRODUCTS = 100; // Maximum number of products in the cart
    Product<T> products[MAX_PRODUCTS];
    int productCount;

public:
    ShoppingCart() : productCount(0) {}

    void addProduct(const Product<T>& product) {
        if (productCount < MAX_PRODUCTS) {
            products[productCount++] = product;
        } else {
            cout << "Shopping cart is full." << endl;
        }
    }

    void removeProduct(const Product<T>& product) {
        int index = -1;
        for (int i = 0; i < productCount; ++i) {
            if (products[i] == product) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            for (int i = index; i < productCount - 1; ++i) {
                products[i] = products[i + 1];
            }
            --productCount;
            cout << "Product removed from the cart." << endl;
        } else {
            cout << "Product is not in the list." << endl;
        }
    }

    double calculateTotalPrice() {
        double total = 0.0;
        for (int i = 0; i < productCount; ++i) {
            int quantity;
            cout << "Enter quantity for product " << products[i].getName() << ": ";
            cin >> quantity;
            if (quantity <= products[i].getStockLevel()) {
                total += products[i].getPrice() * quantity;
            } else {
                cout << "Quantity exceeds stock level for product " << products[i].getName() << "." << endl;
            }
        }
        return total;
    }

    void displayProducts() const {
        for (int i = 0; i < productCount; ++i) {
            cout << "Product " << i + 1 << ": " << products[i].getName() << ", Price: " << products[i].getPrice()
                 << ", Manufacturer: " << products[i].getManufacturer() << ", Stock Level: " << products[i].getStockLevel() << endl;
        }
    }
};

template <typename T>
class Order {
private:
    string orderID;
    ShoppingCart<T> shoppingCart;

public:
    Order(const string& customerName, const string& phoneNumber, const ShoppingCart<T>& cart)
        : shoppingCart(cart) {
        orderID = generateOrderID(customerName, phoneNumber);
    }

    string generateOrderID(const string& customerName, const string& phoneNumber) {
        if (phoneNumber.size() != 11) {
            throw invalid_argument("Phone number must be 11 digits.");
        }
        return customerName.substr(0, 1) + customerName.substr(customerName.length() - 1, 1) +
                  phoneNumber.substr(phoneNumber.length()-2,2);
    }

    ShoppingCart<T> getShoppingCart() const {
        return shoppingCart;
    }

    string getOrderID() const {
        return orderID;
    }
};

int main() {
    Product<int> product1("TV", 1000.0, "Haier", 10);
    Product<int> product2("Phone", 500.0, "Samsung", 15);

    ShoppingCart<int> cart;
    cart.addProduct(product1);
    cart.addProduct(product2);

    cart.displayProducts();

    double totalPrice = cart.calculateTotalPrice();
    cout << "Total price: " << totalPrice << endl;

    Order<int> order("Adeena", "09876543219", cart);
    cout << "Order ID: " << order.getOrderID() << endl;

    return 0;
}
