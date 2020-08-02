#include <iostream>
#include <vector>

using namespace std;

string canConstruct(vector<int> a) {
    vector<vector<int>> numAsDigits;

    for (int i = 0; i < a.size(); i++) {
        vector<int> digits;

        int num = a[i];
        int idx = 0;
        int divisor = 1;

        while (idx < 10) {
            int digit = (num / divisor) % 10;
            digits.push_back(digit);
            divisor *= 10;
            idx++;
        }

        numAsDigits.push_back(digits);
    }

    int sumDigits = 0;
    for (int i = 0; i < numAsDigits.size(); i++) {
        for (int j = 0; j < numAsDigits[i].size(); j++) {
            sumDigits += numAsDigits[i][j];
        }
    }

    if (sumDigits % 3 == 0)
        return "Yes";
    else
        return "No";
}

int main() {
    int t, n, tmp;
    cin >> t;

    vector<string> ans;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> a;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            a.push_back(tmp);
        }

        ans.push_back(canConstruct(a));
    }

    for (auto answer : ans)
        cout << answer << endl;
        
    return 0;
}
