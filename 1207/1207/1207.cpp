#include <stdio.h>
#include <cmath>

int calc(int n)
{
	int i, t;
	int d = sqrt(double(n));
	for (i = 2; i <= d; i++) {	// ÅÐ¶ÏÊÇ·ñÊÇËØÊý
		if (n % i == 0) {
			t = n / i;
			break;
		}
	}
	if (i > d) {
		return 1;	
	} else {
		return calc(t) + calc(i);
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", calc(n));
	}

	return 0;
}