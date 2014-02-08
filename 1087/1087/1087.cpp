#include <stdio.h>
#include <string.h>
#include <cmath>

int num[1005];

int main()
{
	int N;
	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &num[i]);
		}
		
		for (int i = 0; i < N; i++) {
			int res = 2;
			int sq = floor( sqrt(num[i] * 1.0) + 0.5 ) ;	// 0.5 Ϊ�������������
			for (int j = 2; j <= sq; j++) {
				if (num[i] % j == 0) {		// ���������2����Ϊ��ǰ������Լ��
					res += 2;
				}
			}
			if (sq * sq == num[i]) {
				--res;
			}
			printf("%d\n", res);
		}
	}

	return 0;
}