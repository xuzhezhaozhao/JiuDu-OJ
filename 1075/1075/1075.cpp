#include <stdio.h>

void dis(int n)
{
	if (n == 0) {
		printf("0\n");
	} else if (1 == n) {
		printf("0 1 1\n");
	} else {
		printf("0 1");
		int a1 = 0, a2 = 1;
		for (int i = 3; i <= 2 * n + 1; i++) {
			printf(" %d", a1 + a2);
			int temp = a1;
			a1 = a2;
			a2 = a2 + temp;
		}
		printf("\n");
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			dis(i);
		}
	}

	return 0;
}