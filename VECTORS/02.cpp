#include<iostream>
#include<vector>
using namespace std;

class VectorMath {
private:
    vector<int> vector1;

public:
    VectorMath() {
        vector1 = vector<int>(10, 0);
        int size = vector1.size();
        cout << endl << "Enter " << size << " elements: " << endl;

        for (int i = 0; i < vector1.size(); i++) {
            cin >> vector1[i];
        }
    }

    int minElement() {
        int min = vector1[0];
        for (int i = 1; i < vector1.size(); i++) {
            if (vector1[i] < min) {
                min = vector1[i];
            }
        }
        return min;
    }

    int maxElement() {
        int max = vector1[0]; 
        for (int i = 1; i < vector1.size(); i++) {
            if (vector1[i] > max) {
                max = vector1[i];
            }
        }
        return max;
    }
};

int main() {
    VectorMath v1;
    int min, max;
    min = v1.minElement();
    max = v1.maxElement();
    cout << endl << "The maximum element in the vector is: " << max << endl;
    cout << endl << "The minimum element of the vector is: " << min << endl;
}
