#include <iostream>

using namespace std;

int main() {
    int num_animals, num_legs;
    
    cin >> num_animals >> num_legs;
    int num_cranes = num_animals;
    while (num_cranes >= 0) {
        if (num_legs == (num_cranes * 2) + ((num_animals - num_cranes) * 4)) {
            cout << "Yes" << endl;
            return 0;
        }
        
        num_cranes--;
    }

    cout << "No" << endl;
    return 0;
}
