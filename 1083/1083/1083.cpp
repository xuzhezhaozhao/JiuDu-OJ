#include <stdio.h>

typedef long long int LL;

int main()
{
	LL m , n;

	while (scanf("%lld %lld", &m, &n) != EOF) {
		int d1[10] = {0};
		int d2[10] = {0};
		int k = 0;
		while (m > 0) {
			d1[k] = m % 10;
			++k;
			m /= 10;
		}
		k = 0;
		while (n > 0) {
			d2[k] = n % 10;
			++k;
			n /= 10;
		}
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				sum += d1[i] * d2[j];
			}
		}
		printf("%d\n", sum);
	}

	return 0;
}