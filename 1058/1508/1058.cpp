#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	char a[5];
	while (gets(a)) {
		printf("%c%c%c%c\n", a[3], a[2], a[1], a[0]);
	}

	return 0;
}