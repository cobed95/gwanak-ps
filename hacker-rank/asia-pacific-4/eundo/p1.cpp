#include <iostream>

using namespace std;

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER d
 */

int minimumMoves(string s, int d) {
    int start = 0;
    int probe = start;

    int changeCount = 0;
    while (probe < s.size()) {
        int end = start + d;
        probe = start;
        // cout << start << " " << probe << endl;
        bool foundOne = false;
        while (probe < s.size() && probe < end) {
            if (s.at(probe) == '1') {
                foundOne = true;
                break;
            } else
                probe++;
        }

        if (!foundOne)
            changeCount++;

        if (probe == end) {
            start = probe;
        } else if (probe == s.size()) {
            break;
        } else {
            start = probe + 1;
        }
    }
    
    return changeCount;
}

int main() {
    string s;
    int d;

    cin >> s;
    cin >> d;
    cout << minimumMoves(s, d) << endl;
}
