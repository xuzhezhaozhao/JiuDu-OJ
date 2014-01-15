#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		int sum = 0;
		if (n > 0) {
			for (int i = n; i <= 2*n; i++) {
				sum += i;
			}
		} else if (n < 0) {
			for (int i = 2*n; i <= n; i++) {
				sum += i;
			}
		}
		printf("%d\n", sum);
	}

	return 0;
}