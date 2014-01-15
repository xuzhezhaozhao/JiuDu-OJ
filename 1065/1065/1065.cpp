#include <stdio.h>

int main()
{
	int h;
	while (scanf("%d", &h) != EOF) {
		int n = h + 2 * (h - 1);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n - (h + 2*i); j++ ) {
				printf(" ");
			}
			for (int j = 0; j < h+2*i; j++) {
				printf("*");
			}
			printf("\n");
		}
	}

	return 0;
}