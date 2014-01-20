#include <stdio.h>
#include <string.h>

typedef long long int LL;
const int MOD = 10000;

void matrixPower(LL *data, LL k)
{
	if (1 == k) {
		return;
	} else {
		if (k % 2 == 0) {
			matrixPower(data, k / 2);
			LL t0, t1, t2, t3;
			t0 = data[0] * data[0] + data[1] * data[2];
			t1 = data[0] * data[1] + data[1] * data[3];
			t2 = data[2] * data[0] + data[3] * data[2];
			t3 = data[2] * data[1] + data[3] * data[3];
			data[0] = t0 % MOD;
			data[1] = t1 % MOD;
			data[2] = t2 % MOD;
			data[3] = t3 % MOD;
		} else {
			LL d0 = data[0];
			LL d1 = data[1];
			LL d2 = data[2];
			LL d3 = data[3];
			matrixPower(data, k / 2);
			LL t0, t1, t2, t3;
			t0 = (data[0] * data[0] + data[1] * data[2]) % MOD;
			t1 = (data[0] * data[1] + data[1] * data[3]) % MOD;
			t2 = (data[2] * data[0] + data[3] * data[2]) % MOD;
			t3 = (data[2] * data[1] + data[3] * data[3]) % MOD;
			data[0] = ( d0 * t0 + d1 * t2 ) % MOD;
			data[1] = ( d0 * t1 + d1 * t3 ) % MOD;
			data[2] = ( d2 * t0 + d3 * t2 ) % MOD;
			data[3] = ( d2 * t1 + d3 * t3 ) % MOD;
		}
		
	}
}

int main()
{
	LL a0, a1, p, q, k;
	while (scanf("%lld %lld %lld %lld %lld", &a0, &a1, &p, &q, &k) != EOF) {
		if (0 == k) {
			printf("%lld\n", a0 % MOD);
		} else if (1 == k) {
			printf("%lld\n", a1 % MOD);
		} else {
			LL data[4] = {p, q, 1, 0};	// 2½×¾ØÕó
			k = k - 1;
			matrixPower(data, k);
			a1 = a1 % MOD;
			a0 %= MOD;
			LL ans = data[0] * a1 + data[1] * a0;
			ans %= MOD;
			printf("%lld\n", ans);
		}
	}

	return 0;
}