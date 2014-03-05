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

vector <int> getPrimeFactor(int n)
{
	vector <int> prime_factor;
	int lim = floor( sqrt(n * 1.0 + 0.5) );
	for (int i = 2; i <= lim; i++) {
		while (n % i == 0) {
			prime_factor.push_back(i);
			n /= i;
		}
	}
	if (n != 1) {
		prime_factor.push_back(n);
	}
	return prime_factor;
}
int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		if (a == 1 || b == 1) {
			printf("1\n");
			continue;
		}

		vector <int> pa = getPrimeFactor(a);
		vector <int> pb = getPrimeFactor(b);
		sort(pa.begin(), pa.end());
		sort(pb.begin(), pb.end());
		vector <int> g;
		int pre = pa[0];
		int cnt1 = count(pa.begin(), pa.end(), pre);
		int cnt2 = count(pb.begin(), pb.end(), pre);
		int cnt = 0;
		cnt = min(cnt1, cnt2);
		if (cnt > 0) {
			g.push_back(cnt);
		}
		for (int i = cnt1; i < pa.size();) {
			pre = pa[i];
			cnt1 = count(pa.begin(), pa.end(), pre);
			cnt2 = count(pb.begin(), pb.end(), pre);
			cnt = min(cnt1, cnt2);
			i = i + cnt1;
			if (cnt > 0) {
				g.push_back(cnt);
			}
		}
		int res = 1;
		for (int i = 0;i < g.size(); i++) {
			res *= (g[i] + 1);
		}

		printf("%d\n", res);
	}

	return 0;
}