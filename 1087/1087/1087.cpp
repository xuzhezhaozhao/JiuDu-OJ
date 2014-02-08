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
			int sq = floor( sqrt(num[i] * 1.0) + 0.5 ) ;	// 0.5 为修正浮点数误差
			for (int j = 2; j <= sq; j++) {
				if (num[i] % j == 0) {		// 能整除则加2，因为有前后两个约数
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