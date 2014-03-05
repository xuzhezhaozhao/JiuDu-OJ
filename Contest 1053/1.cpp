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
int m[11][11];
int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	
	int N;
	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &m[i][j]);
			}
		}
		int mx = INT_MIN;
		int row = -1;
		for (int i = 0; i < N - 1; i++) {
			mx = INT_MIN;
			row = i;
			for (int j = i; j < N; j++) {
				if (m[j][i] > mx) {
					mx = m[j][i];
					row = j;
				}
			}
			for (int j = 0; j < N; j++) {
				swap(m[row][j], m[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - 1; j++) {
				printf("%d ", m[i][j]);
			}
			printf("%d", m[i][N-1]);
			printf("\n");
		}
	}

	return 0;
}