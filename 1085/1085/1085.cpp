#include <stdio.h>
#include <string.h>

long long int quickPowerMod(long long int x, long long int y, long long int m)
{
	long long int ans = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans = (ans * x) % m;
		}
		x = (x * x) % m;
		y = y / 2;
	}
	return ans;
}

int main()
{
	long long int x, y, k;
	long long int n;
	while (scanf("%lld %lld %lld", &x, &y, &k) != EOF) {
		if (1 == x) {
			n = 1;
		} else {
			n = quickPowerMod(x, y, k-1);
		}
		if (0 == n) {
			n = k - 1;
		}
		printf("%lld\n", n);
	}

	return 0;
}