//Wrong Answer
#include<iostream>
#include<vector>
#include<set>
using namespace std;
enum {boy, girl};
int main() {
	int t;
	
	cin >> t;
	vector<string> answer;
	for (int i = 0; i < t; i++) { // t times
		int n;
		multiset<int> b, g;
		cin >> n;
		int B, G;
		int now_sex = 0; // 0 is boy 1 is girl
		int bef_sex = -1;
		bool state = true;
		for (int j = 0; j < n; j++) {
			cin >> B;
			b.insert(B);
		}
		for (int j = 0; j < n; j++) {
			cin >> G;
			g.insert(G);
		}
		// boys and girls are sorted.
		auto it_b = b.begin();
		auto it_g = g.begin();
		int b_k = *it_b;
		int g_k = *it_g;
		int count;
		for (int j = 0; j < 2 * n; j++) {
			if (it_b == b.end()) b_k = 101; // put girl
			else b_k = *it_b;

			if (it_g == g.end()) g_k = 101; // put boy
			else g_k = *it_g;

			if (b_k > g_k) { // put girl
				now_sex = girl;
				it_g++;
				if (now_sex == bef_sex) {
					state = false;
					break;
				}
			}
			else if (b_k < g_k) {
				now_sex = boy;
				it_b++;
				if (now_sex == bef_sex) {
					state = false;
					break;
				}
			}
			else { // same
				if (bef_sex == boy) {
					now_sex = girl;
					it_g++;
				}
				else if(bef_sex == girl) {
					now_sex = boy;
					it_b++;
				}
				else { // bef_sex == -1
					now_sex = boy;
					it_b++;
				}
			}
			bef_sex = now_sex;
		
		}
		if (state) answer.push_back("YES");
		else answer.push_back("NO");
	}

	for (int i = 0; i < t; i++) {
		cout << answer[i] << endl;
	}
}