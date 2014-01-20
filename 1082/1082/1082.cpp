#include <string>
#include <map>
#include <iostream>
//#include <stdio.h>

using namespace std;
const int LIM = 10000;	// 表示此状态不可达
int ip[5000];		// 访问IP在服务器列表中的序号，-1表示不存在
int dp[5000][1000];	// dp[i][j] 表示“在已访问0-i个ip后，当前代理服务器为j时所用的最小切换次数。”
			// dp[i][j] = min ( dp[i-1][j], dp[i-1][0-n]的最小值 + 1 )

int main()
{
	//freopen("data.txt", "r", stdin);
	int n, m;
	string s;
	map <string, int> server;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> s;
			server[s] = i;
		}
		cin >> m;
		map <string, int>::iterator it;
		for (int i = 0; i < m; i++) {
			cin >> s;
			it = server.find(s);
			if (it != server.end()) {
				ip[i] = it->second;
			} else {
				ip[i] = -1;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = LIM;
			}
		}
		// 初始条件
		for (int i = 0; i < n; i++) {
			if (ip[0] != i) {
				dp[0][i] = 0;
			}
		}
		int mindp = 0;
		for (int i = 1; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (ip[i] != j) {
					dp[i][j] = min (dp[i-1][j], mindp + 1);
				}
			}
			mindp = LIM;	// mindp 为 dp[i][] 中的最小值
			for (int j = 0; j < n; j++) {
				if (dp[i][j] < mindp) {
					mindp = dp[i][j];
				}
			}
		}
		if (mindp >= LIM) {
			mindp = -1;
		}
		printf("%d\n", mindp);
	}
	
	return 0;
}