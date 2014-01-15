#include <stdio.h>

int main()
{
	bool m[200];
	int i, j, k;
	for (i = 0; i < 200; i++) {
		m[i] = false;
	}
	int sum;
	for (i = 0; i <= 5; i++) {
		for (j = 0; j <= 4; j++) {
			for (k = 0; k <= 6; k++) {
				sum = i * 8 + j * 10 + k * 18;
				m[sum] = true;
			}
		}
	}
	int ans = 0;
	for (i = 1; i < 200; i++) {
		if (m[i] == true) {
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}