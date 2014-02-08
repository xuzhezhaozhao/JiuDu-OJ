#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

typedef long long LL;
const int M = 205;
const LL INF = 1E10;

LL a[M];
LL cost[M][M];
LL dist[M];
bool v[M];

int main()
{
	//freopen("data.txt", "r", stdin);
	LL L1, L2, L3, C1, C2, C3, A, B, N;
	while (scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &L1, &L2, &L3, &C1, &C2, &C3, &A, &B, &N) != EOF) {
		memset(v, 0, sizeof(v));
		memset(a, 0, sizeof(a));
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				cost[i][j] = INF;
			}
			dist[i] = INF;
		}
		a[1] = 0;
		for (int i = 2; i <= N; i++) {
			scanf("%lld", &a[i]);
		}
		if (A > B) {
			int temp = A;
			A = B;
			B = temp;
		}
		if (A == B) {
			printf("0\n");
			continue;
		}
		for (int i = A; i <= B; i++) {
			cost[i][i] = 0;
			for (int j = i+1; j <= B; j++) {
				LL s = a[j] - a[i];
				if ( s > 0 && s <= L1 ) {
					cost[i][j] = C1;
				} else if (s > L1 && s <= L2) {
					cost[i][j] = C2;
				} else if (s > L2 && s <= L3) {
					cost[i][j] = C3;						
				} else {
					break;
				}
			}
		}
		// Dijk算法
		set < pair<LL, int> > sdist;
		for (int i = A+1; i <= B; i++) {
			if (cost[A][i] != INF) {
				dist[i] = cost[A][i];
				sdist.insert( make_pair(dist[i], i) );
				v[i] = true;
			}
		}
		while (!sdist.empty()) {
			int next = ( sdist.begin() )->second;
			LL mincost = ( sdist.begin() )->first;
			sdist.erase(sdist.begin());
			dist[next] = mincost;	// 确定一点最短路径
			if (next == B) {
				printf("%lld\n", dist[B]);
				break;
			} else {	// 更新与next相邻的点的距离
				for (int i = next+1; i <= B; i++) {	// next != B
					if (dist[i] > dist[next] + cost[next][i]) {
						if (!v[i]) {
							dist[i] = dist[next] + cost[next][i];
							sdist.insert( make_pair(dist[i], i) );
							v[i] = true;
						} else {
							set < pair<LL, int> >::iterator it;
							it = sdist.find( make_pair(dist[i], i) );
							if (it != sdist.end()) {
								sdist.erase(it);
								dist[i] = dist[next] + cost[next][i];
								sdist.insert( make_pair(dist[i], i) );
							}
						}
					}
				}
			}
		}
	}

	return 0;
}