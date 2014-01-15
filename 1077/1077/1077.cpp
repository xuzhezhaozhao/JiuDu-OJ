#include <stdio.h>
#include <iostream>
using namespace std;

long long s[1000001];

int main()
{
	long long n;
	
	while (scanf("%lld", &n) != EOF) {
		long long sum;
		long long maxs;
		for (long long i = 0; i < n; i++) {
			scanf("%lld", &s[i]);
		}

		sum = 0;
		maxs = s[0];
		for (long long i = 0; i < n; i++) {
			sum += s[i];
			if (sum < 0) {
				if (sum > maxs) {
					maxs = sum;
				}
				sum = 0;
			} else {
				if (sum > maxs) {
					maxs = sum;
				}
			}
		}
		cout << maxs << endl;
	}

	return 0;
}