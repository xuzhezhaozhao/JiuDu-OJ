#include <stdio.h>
#include <string.h>

//#define LOCAL	// Ìá½»Ê±×¢ÊÍµô

int main()
{
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	
	int N;
	while (scanf("%d", &N) != EOF) {
		int mx = -1000002;
		int mi = 1000002;
		int x;
		for (int i = 0; i < N; i++) {
			scanf("%d", &x);
			if (x > mx) {
				mx = x;
			}
			if (x < mi) {
				mi = x;
			}
		}
		printf("%d %d\n", mx, mi);
	}

	return 0;
}