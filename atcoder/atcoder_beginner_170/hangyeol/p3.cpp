#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	
	int X, N;
	scanf("%d %d", &X, &N);
	int* p = new int[N];


	if (N != 0)// 0�̸� �Է��� �� �޾�
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
		//���� ����
		test[0] = X + count; // X ��ü�� ���� �� �� �־� -> count = 0; -> ���ϱ�
		test[1] = X - count; // ����
		if (N == 0) {
			answer = X;
			okay = true;
		}
		else // test_m�� test_p�� sequence�� �ִ��� Ȯ��
		{
			bool exist[2] = { false, false };
			for (int i = 0; i < N; i++) {
				if (exist[0] == false && test[0] == p[i]) { // ������ �Ѿ����
					exist[0] = true;
				}
				if (exist[1] == false && test[1] == p[i]) {
					exist[1] = true;
				}
			}
			if (!exist[0]) // ����
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