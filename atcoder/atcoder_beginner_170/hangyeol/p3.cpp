#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	
	int X, N;
	scanf("%d %d", &X, &N);
	int* p = new int[N];


	if (N != 0)// 0이면 입력을 안 받아
	{
		for (int i = 0; i < N; i++) {
			scanf("%d", &p[i]);
		}
	}

	bool okay = false;
	int test[2];
	int answer;
	int count = 0;
	while (!okay) {
		//빼기 먼저
		test[0] = X + count; // X 자체도 답이 될 수 있어 -> count = 0; -> 더하기
		test[1] = X - count; // 빼기
		if (N == 0) {
			answer = X;
			okay = true;
		}
		else // test_m과 test_p가 sequence에 있는지 확인
		{
			bool exist[2] = { false, false };
			for (int i = 0; i < N; i++) {
				if (exist[0] == false && test[0] == p[i]) { // 있으면 넘어가야지
					exist[0] = true;
				}
				if (exist[1] == false && test[1] == p[i]) {
					exist[1] = true;
				}
			}
			if (!exist[0]) // 없어
			{
				answer = test[0];
				okay = true;
			}
			if (!exist[1])
			{
				answer = test[1];
				okay = true;
			}
		}
		count++;
	}
	printf("%d", answer);
	delete p;

	


	return 0;
}