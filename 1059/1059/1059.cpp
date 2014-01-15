#include <stdio.h>

int main()
{
	int i, j, k;
	for (i = 0; i <= 9; i++) {
		for (j = 0; j <= 9; j++) {
			for (k = 0; k <= 9; k++) {
				if ( i * 100 + j * 10 + k + j * 100 + k * 10 + k == 532) {
					printf("%d %d %d\n", i, j, k);
				}
			}
		}
	}

	return 0;
}