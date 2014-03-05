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
int dp[105];

int rec(int cur)
{
	int & res = dp[cur];
	if (res != -1) {
		return res;
	}
	if (cur == 0) {
		res = 0;
		return 0;
	}
	if (cur == 1 || cur == 2 || cur == 5 || cur == 10 || cur == 20 || cur == 50) {
		res = 1;
		return 1;
	}
	res = 100000;
	if (cur - 1 >= 0) {
		res = min(res, 1 + rec(cur - 1));
	}
	if (cur - 2 >= 0) {
		res = min(res, 1 + rec(cur - 2));
	}
	if (cur - 5 >= 0) {
		res = min(res, 1 + rec(cur - 5));
	}
	if (cur - 10 >= 0) {
		res = min(res, 1 + rec(cur - 10));
	}
	if (cur - 20 >= 0) {
		res = min(res, 1 + rec(cur - 20));
	}
	if (cur - 50 >= 0) {
		res = min(res, 1 + rec(cur - 50));
	}
	return res;
}

int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	
	int p;
	while (scanf("%d", &p) != EOF) {
		int cnt_100 = p / 100;
		p = p % 100;
		memset(dp, -1, sizeof(dp));
		int res = rec(p);
		printf("%d\n", cnt_100 + res);
	}

	return 0;
}