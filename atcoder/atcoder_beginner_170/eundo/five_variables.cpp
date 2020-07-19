#include <iostream>

using namespace std;

int main() {
    int tmp;
    for (int i = 1; i <= 5; i++) {
        cin >> tmp;
        if (tmp == 0) {
            cout << i << endl;

            return 0;
        }
    }

    return 0;
}
