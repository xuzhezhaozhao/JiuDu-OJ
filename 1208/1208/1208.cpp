#include <stdio.h>
#include <cstring>

int a[1005];
int b[4000];
int c[1005];
char s[1500];

void add(int x)
{
	if (1 == x) {
		for (int i = 0; i < 1000; i++) {
			a[i] = a[i] + c[i];
			a[i+1] += (a[i] / 10);
			a[i] = a[i] % 10;
		}
	}
}

void bigPower()
{
	for (int i = 0; i < 1000; i++) {
		c[i] = c[i] + c[i];
	}
	for (int i = 0; i < 1000; i++) {
		c[i+1] += (c[i] / 10);
		c[i] = c[i] % 10;
	}
}

int main()
{
	while (scanf("%s", s) != EOF) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		int len = strlen(s);
		for (int i = len - 1, j = 0; i >= 0; i--, j++) {
			a[j] = s[i] - '0';
		}
		int k = 0;
		while (len > 0) {
			for (int i = len - 1; i >= 1; i--) {
				int t = a[i] / 2;
				a[i-1] += (a[i] % 2) * 10;
				a[i] = t;
			}
			b[k] = a[0] % 2;
			++k;
			a[0] = a[0] / 2;
			if (a[len-1] == 0) {
				--len;
			}
		}
		c[0] = 1;
		for (int i = k-1; i >= 0; i--) {
			add(b[i]);
			bigPower();
		}
		int i;
		for (i = 1000; a[i] == 0; i--) {
		}
		if (i < 0) {
			printf("0");
		} else {
			for (; i >= 0; i--) {
				printf("%d", a[i]);
			}
		}
		printf("\n");
	}

	return 0;
}