#include <stdio.h>

int main()
{
	int a[61];
	for (int i = 0; i < 61; i++) {
		a[i] = 0;
	}
	for (int i = 2; i <= 60; i++) {
		int sum = 1;
		for (int j = 2; j <= i/2; j++) {
			if (i % j == 0) {
				sum += j;
			}
		}
		if (sum == i) {
			a[i] = 1;
		} else if (sum > i) {
			a[i] = 2;
		}
	}

	printf("E:");
	for (int i = 2; i < 61; i++) {
		if (a[i] == 1) {
			printf(" %d", i);
		}
	}
	printf("\nG:");
	for (int i = 2; i < 61; i++) {
		if (a[i] == 2) {
			printf(" %d", i);
		}
	}

	return 0;
}