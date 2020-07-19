//wrong answer

#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	
	int N;
	scanf("%d", &N);
	int* A = new int[N];
	int count = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d",&A[i]);
	}
	int same = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i] != 0 && A[j] != 0 && A[i] == A[j]) same++;
			if (i != j&& A[i] != 0 && A[i]!=A[j] && A[j]!=0) {
				if (A[i] % A[j] == 0) // ³ª´²Á®
					A[i] = 0;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (A[i] != 0) count++;
	}
	same = same / N;
	count -= same;
	printf("%d", count);

	delete A;
	
	return 0;
}