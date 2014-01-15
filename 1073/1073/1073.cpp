#include <stdio.h>

int main()
{
	int n;
	int cur[1000], next[1000];
	while (scanf("%d", &n) != EOF) {
		printf("1 1\n");
		cur[0] = 1; cur[1] = 1;
		for (int i = 3; i <= n; i++) {
			next[0] = 1;
			printf("1 ");
			for (int j = 1; j < i-1; j++) {
				next[j] = cur[j-1] + cur[j];
				printf("%d ", next[j]);
			}
			next[i-1] = 1;
			printf("1\n");
			for (int j = 0; j < i; j++) {
				cur[j] = next[j];
			}
		}
	}

	return 0;
}