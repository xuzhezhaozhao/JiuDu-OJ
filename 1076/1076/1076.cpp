#include <stdio.h>
#include <stdlib.h>
#include <cstring>

/* 1000! ´ó¸Å2600 Î» */

int a[1001][3000];

int main()
{
	a[0][0] = 1;
	a[1][0] = 1;
	int b[4];
	for (int i = 2; i <= 1000; i++) {
		b[0] = i % 10;
		b[1] = (i / 10) % 10;
		b[2] = (i / 100) % 10;
		b[3] = 0;
		if (1000 == i) {
			b[3] = 1;
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2700; k++) {
				a[i][j+k] += b[j] * a[i-1][k];
				a[i][j+k+1] += a[i][j+k] / 10;
				a[i][j+k] = a[i][j+k] % 10;
			}
		}

	}
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			printf("1\n");
		} else {
			int i;
			for (i = 2700; a[n][i] == 0; i--) {
				
			}
			for (; i >= 0; i--) {
				printf("%d", a[n][i]);
			}
			printf("\n");
		}
	}

	return 0;
}