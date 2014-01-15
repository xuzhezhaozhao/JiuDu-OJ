#include <stdio.h>
#include <iostream>

using namespace std;

bool test(int n)
{
	n = n * n;
	char buf[50];
	string s;
	sprintf(buf, "%d", n);
	s = buf;
	int len = s.size();
	bool flag = true;
	int i = 0, j = len - 1;
	while (i < j) {
		if (s[i] != s[j]) {
			flag = false;
			break;
		}
		++i;
		--j;
	}
	return flag;
}

int main()
{
	for (int i = 0; i < 256; i++) {
		if (test(i)) {
			printf("%d\n", i);
		}
	}

	return 0;
}