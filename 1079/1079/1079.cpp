#include <stdio.h>
#include <string.h>

int getNum(char c)
{
	switch (c) {
		case  'a': return 21;
		case  'b': return 22;
		case  'c': return 23;
		case  'd': return 31;
		case  'e': return 32;
		case  'f': return 33;
		case  'g': return 41;
		case  'h': return 42;
		case  'i': return 43;
		case  'j': return 51;
		case  'k': return 52;
		case  'l': return 53;
		case  'm': return 61;
		case  'n': return 62;
		case  'o': return 63;
		case  'p': return 71;
		case  'q': return 72;
		case  'r': return 73;
		case  's': return 74;
		case  't': return 81;
		case  'u': return 82;
		case  'v': return 83;
		case  'w': return 91;
		case  'x': return 92;
		case  'y': return 93;
		case  'z': return 94;

	}
}

int main()
{
	char buf[101];
	while (gets(buf)) {
		int len = strlen(buf);
		if (0 == len) {
			printf("0\n");
			continue;
		}
		int sum = 0;
		int pre = getNum(buf[0]);
		int d1 = pre / 10;
		sum += pre - (d1 * 10);
		for (int i = 1; i < len; i++) {
			int cur = getNum(buf[i]);
			int d2 = cur / 10;
			sum += cur - (d2 * 10);
			if (d1 == d2) {
				sum += 2;
			}
			d1 = d2;
		}
		printf("%d\n", sum);

	}
	return 0;
}