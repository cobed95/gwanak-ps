// Accepted

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main() {
    int n, tmp;
    vector<int> seq;
    map<int, bool> map;

    cin >> n;
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp > max)
            max = tmp;
        
        if (map.find(tmp) == map.end())
            map.insert(make_pair(tmp, false));
        else {
            map.erase(tmp);
            map.insert(make_pair(tmp, true));
        }
    }

    for (auto it = map.begin(); it != map.end(); it++) {
        int multiplicand = it->first;
        int multiplier = 2;
        int multiplied = multiplicand * multiplier;
        while (multiplicand * multiplier <= max) {
            auto found = map.find(multiplied);

            if (found == map.end()) {
                multiplier++;
                multiplied = multiplicand * multiplier;
                continue;
            } else {
                map.erase(multiplied);
                map.insert(make_pair(multiplied, true));
                multiplier++;
                multiplied = multiplicand * multiplier;
            }
        }
    }
    
    int count = 0;
    for (auto it = map.begin(); it != map.end(); it++) {
        if (!it->second)
            count++;
    }

    cout << count << endl;
    return 0;
}
