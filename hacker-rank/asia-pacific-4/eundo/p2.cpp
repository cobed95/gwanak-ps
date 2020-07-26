#include <iostream>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

string arrangeStudents(vector<int> a, vector<int> b) {
    priority_queue<int, vector<int>, greater<int>> boys;
    priority_queue<int, vector<int>, greater<int>> girls;
    
    for (int i = 0; i < a.size(); i++) 
        boys.push(a[i]);
    for (int i = 0; i < b.size(); i++)
        girls.push(b[i]);
    
    if (boys.top() < girls.top()) {
        int last = -1;
        while (!girls.empty()) {
            int boy = boys.top();
            int girl = girls.top();
            if (boy < last || boy > girl)
                return "NO";

            last = girl;

            boys.pop();
            girls.pop();
        }
    } else if (girls.top() < boys.top()) {
        int last = -1;
        while (!boys.empty()) {
            int girl = girls.top();
            int boy = boys.top();
            if (girl < last || girl > boy)
                return "NO";

            last = boy;

            girls.pop();
            boys.pop();
        }
    } else {
        priority_queue<int, vector<int>, greater<int>> boys2;
        priority_queue<int, vector<int>, greater<int>> girls2;
        for (int i = 0; i < a.size(); i++) 
            boys2.push(a[i]);
        for (int i = 0; i < b.size(); i++)
            girls2.push(b[i]);
        
        int last = -1;
        while (!girls.empty()) {
            int boy = boys.top();
            int girl = girls.top();
            if (boy < last || boy > girl)
                return "NO";

            last = girl;

            boys.pop();
            girls.pop();
        }
        
        last = -1;
        while (!boys2.empty()) {
            int girl = girls2.top();
            int boy = boys2.top();
            if (girl < last || girl > boy)
                return "NO";

            last = boy;

            girls2.pop();
            boys2.pop();
        }
    }

    return "YES";
}

int main() {
    vector<int> a;
    vector<int> b;
    
    int n;
    cin >> n;
    
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        b.push_back(tmp);
    }

    cout << arrangeStudents(a, b) << endl;
}
