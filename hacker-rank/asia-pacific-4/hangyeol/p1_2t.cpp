// Wrong Answer
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string S;
	cin >> S;
	vector<string> t;
	vector<int> count;
	int d;
	cin >> d;
	string buff;
	for (int i = 0; i < d; i++) {
		buff.push_back('0');
	} // have d '0's
	count.push_back(0);
	bool fin = false;
	int mem = 0;
	while (!fin) {
		int index = S.find(buff,mem);
		int add = (d % 2 == 0) ? d / 2 - 1 : d / 2;
		if (d % 2 != 0) add = d / 2;
		else {

		}
		if (index != string::npos) { // have
			S[index + add] = '1';
			count++;
			mem = index;
		}
		else {
			fin = true;
		}
	}
	cout << count << endl;
	return 0;
}