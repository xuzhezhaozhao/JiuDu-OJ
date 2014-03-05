#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <bitset>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>

using namespace std;
typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
#define mkp make_pair

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)

const int MOD = 1e9 + 7;

int si[100005];
int cnt[100005];

int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) != EOF) {
		memset(cnt, 0, sizeof(cnt));
		memset(si, 0, sizeof(si));
		for (int i = 0; i < n; i++) {
			scanf("%d", &si[i]);
		}	
		if (n == 1) {
			printf("1\n");
			continue;
		}

		cnt[0] = 1;
		for (int i = 1; i < n; i++) {
			if (si[i] > si[i-1]) {
				cnt[i] = 1;
			} else if (si[i] == si[i-1]) {
				cnt[i] = 0;
			} else if (si[i] < si[i-1]) {
				cnt[i] = -1;
			}
		}
		long long sum = 0;
		int pre = 0;
		for (int i = 0; i < n; ) {
			int p = i + 1;
			int t = 0;
			while (p < n && -1 == cnt[p]) {
				++p;
				++t;
			}

			if (cnt[i] == 0) {
				for (int k = 0; k <= t; k++) {
					sum += (k + 1);
				}
				pre = 1;
			} else if (cnt[i] == 1) {
				if (t == 0) {
					sum += (pre + 1);
					++pre;
				} else {
					int u = max(pre + 1, t + 1);
					for (int k = 1; k <= t; k++) {
						sum += k;
					}
					sum += u;
					pre = 1;
				}
			}
			i = i + t + 1;
		}
		printf("%lld\n", sum);
		//cout << sum << endl;
	}

	return 0;
}