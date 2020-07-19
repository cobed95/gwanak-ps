#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main(void) {

	int buff[5];
	scanf("%d%d%d%d%d", &buff[0], &buff[1], &buff[2], &buff[3], &buff[4]);
	for (int i = 0; i < 5; i++) {
		if (buff[i] == 0)
			printf("%d", i + 1);
	}
	return 0;
}