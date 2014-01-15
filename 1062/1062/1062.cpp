#include <stdio.h> 

int main()
{
	float x;
	float ans;
	while (scanf("%f", &x) != EOF) {
		if (x >= 0 && x < 2) {
			ans = 2.5 - x;
		} else if (x >= 2 && x < 4) {
			ans = 2.0 - 1.5 * (x - 3) * (x - 3);
		} else if (x >= 4 && x < 6) {
			ans = x / 2.0 - 1.5;
		}
		printf("%.3f\n", ans);
	}

	return 0;
}