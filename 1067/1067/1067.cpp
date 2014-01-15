#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	long long mul;
	int n;
	while ( scanf("%d", &n) != EOF ) {
		mul = 1;
		for (int i = 1; i <= n; i++) {
			mul *= i;
		}
		printf("%lld\n", mul);
	}

	return 0;
}