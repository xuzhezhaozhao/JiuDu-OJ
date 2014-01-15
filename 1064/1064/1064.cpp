#include <stdio.h>

int main()
{
	int i;
	int a, b, c, d;
	int t;
	for (i = 1009; i <= 1111; i += 10) {
		a = i % 10;
		t = (i / 10);
		b = t % 10;
		t = t / 10;
		c = t % 10;
		d = 1;
		if (i * 9 == d + c * 10 + b * 100 + a * 1000) {
			printf("%d\n", i);
		}
	}

	return 0;
}