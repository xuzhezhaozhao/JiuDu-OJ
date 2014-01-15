#include <stdio.h>

int main()
{
	int year, month, day;
	int m1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int m2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	while (scanf("%d %d %d", &year, &month, &day) != EOF) {
		bool flag = false;
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				flag = true;
			}
		} else {
			if (year % 4 == 0) {
				flag = true;
			}
		}
		int sum = day;
		if (!flag) {
			for (int i = 1; i < month; i++) {
				sum += m1[i]; 
			}
		} else {
			for (int i = 1; i < month; i++) {
				sum += m2[i]; 
			}
		}
		printf("%d\n", sum);
	}

	return 0;
}