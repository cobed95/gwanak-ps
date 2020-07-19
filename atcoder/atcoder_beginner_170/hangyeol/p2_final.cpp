//accepted

#include<stdio.h>
#include<iostream> // 필요 없어
#include<vector> // 필요 없어 
using namespace std;
int main(void) {
	
	int x, y;
	bool yes = false;
	scanf("%d %d", &x, &y);
	for (int i = 0; i <= x; i++) {
		if ((2 * i + 4 * (x - i)) == y) {
			yes = true;
			break; // 답을 찾으면 그냥 리턴. 
		}
	}
	if (yes) printf("Yes");
	else printf("No");
	return 0;
}