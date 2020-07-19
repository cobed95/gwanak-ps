#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x, n, tmp;
    vector<int> forbidden_list;
    
    cin >> x >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        forbidden_list.push_back(tmp);
    }
    
    vector<bool> candidates;
    for (int i = 0; i < 100; i++)
        candidates.push_back(true);

    for (int i = 0; i < forbidden_list.size(); i++) 
        candidates[forbidden_list[i] - 1] = false;
    
    int larger_candidate = x - 1;
    int smaller_candidate = x - 1;
    while (smaller_candidate >= 0 && larger_candidate < 100) {
        if (candidates[larger_candidate] && candidates[smaller_candidate]) {
            cout << smaller_candidate + 1 << endl;
            return 0;
        } else if (candidates[smaller_candidate]) {
            cout << smaller_candidate + 1 << endl;
            return 0;
        } else if (candidates[larger_candidate]) {
            cout << larger_candidate + 1 << endl;
            return 0;
        } else {
            larger_candidate++;
            smaller_candidate--;
        }
    }

    cout << smaller_candidate + 1 << endl;
    return 0;
}
