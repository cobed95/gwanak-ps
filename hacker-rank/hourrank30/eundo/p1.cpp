#include <iostream>
#include <vector>
#include <map>

using namespace std;

int differentAt(string a, string b) {

    int i = 0;
    while (i < a.size() && i < b.size() && a.at(i) == b.at(i))
        i++;

    return i;

}

string getPrefix(map<string, string> prefToName, string name, int endIdx) {
    if (endIdx >= name.size()) 
        return name;
    
    string candidate = name.substr(0, endIdx);
    auto mapValueIt = prefToName.find(candidate);

    if (mapValueIt != prefToName.end()) {
            
        int nextEndIdx = differentAt(name, mapValueIt->second) + 1;
        return getPrefix(prefToName, name, nextEndIdx);

    } else {
        
        return candidate;

    }

}

vector<string> solve(vector<string> names) {

    map<string, string> prefToName;
    map<string, int> nameToOccurences;

    vector<string> answer;

    for (int i = 0; i < names.size(); i++) {

        string name = names[i];

        if (nameToOccurences.find(name) != nameToOccurences.end()) {

            int suffix = nameToOccurences[name] + 1;
            string result = name + " " + to_string(suffix);

            nameToOccurences[name] = suffix;
            prefToName.insert(make_pair(result, name));

            answer.push_back(result);

        } else {
            
            string prefix = getPrefix(prefToName, name, 1);

            nameToOccurences.insert(make_pair(name, 1));
            prefToName.insert(make_pair(prefix, name));

            answer.push_back(prefix);

        }
    }
    
    return answer;

}

int main() {
    int n;
    cin >> n;

    string tmp;
    vector<string> names;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        names.push_back(tmp);
    }

    vector<string> answer = solve(names);

    for (string prefix : answer) {
        cout << prefix << endl;
    }

    return 0;
}
