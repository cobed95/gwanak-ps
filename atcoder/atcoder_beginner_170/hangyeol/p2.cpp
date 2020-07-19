#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	
	int x, y;
	bool yes = false;
	scanf("%d %d", &x, &y);
	for (int i = 0; i <= x; i++) {
		if ((2 * i + 4 * (x - i)) == y) {
			yes = true;
		}
	}
	if (yes) printf("yes");
	else printf("no");
	

	
	return 0;
}