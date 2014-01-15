#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[21][101];

int main()
{
	int m, n;
	int s[21];
	while (scanf("%d", &m) != EOF) {
		scanf("%d", &n);
		memset(dp, 0x0f, sizeof(dp));
		memset(s, 0, sizeof(s));
		for (int i = 0; i < n; i++) {
			scanf("%d", &s[i]);
		}
		if (s[0] <= m) {
			dp[0][ s[0] ] = 1;
		}
		
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= m; j++) {
				if (j - s[i] >= 0) {
					dp[i][j] = min(dp[i-1][j], dp[i-1][j-s[i]] + 1);
				} else {
					dp[i][j] = dp[i-1][j];
				}
			}
			dp[i][ s[i] ] = 1;
		}
		if (dp[n-1][m] > 21) {
			dp[n-1][m] = 0;
		}
		printf("%d\n", dp[n-1][m]);
	}

	return 0;
}