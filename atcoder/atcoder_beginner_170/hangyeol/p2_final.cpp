//accepted

#include<stdio.h>
#include<iostream> // �ʿ� ����
#include<vector> // �ʿ� ���� 
using namespace std;
int main(void) {
	
	int x, y;
	bool yes = false;
	scanf("%d %d", &x, &y);
	for (int i = 0; i <= x; i++) {
		if ((2 * i + 4 * (x - i)) == y) {
			yes = true;
			break; // ���� ã���� �׳� ����. 
		}
	}
	if (yes) printf("Yes");
	else printf("No");
	return 0;
}