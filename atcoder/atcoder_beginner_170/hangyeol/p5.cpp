//wrong answer

#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main(void) {

	vector<int>
		int N, Q;
	scanf_s("%d%d", &N, &Q);

	int* A = new int[N];
	int* B = new int[N];
	int* C = new int[Q];
	int* D = new int[Q];

	for (int i = 0; i < N; i++) {
		scanf("%d%d", &A[i], &B[i]);
	}

	for (int i = 0; i < Q; i++) {
		scanf("%d%d", &C[i], &D[i]);
	}

	int count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				if (B[i] == B[j])
			}
		}
	}

	for (int i = 0; i < Q; i++) {
		B[C[i] - 1] = D[i]; // kindergarten 옮기기 

		// eveness 출력해야 돼.

	}



	return 0;
}