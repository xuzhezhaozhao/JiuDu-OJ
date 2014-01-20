#include <string>
#include <map>
#include <iostream>
//#include <stdio.h>

using namespace std;
const int LIM = 10000;	// ��ʾ��״̬���ɴ�
int ip[5000];		// ����IP�ڷ������б��е���ţ�-1��ʾ������
int dp[5000][1000];	// dp[i][j] ��ʾ�����ѷ���0-i��ip�󣬵�ǰ���������Ϊjʱ���õ���С�л���������
			// dp[i][j] = min ( dp[i-1][j], dp[i-1][0-n]����Сֵ + 1 )

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
		// ��ʼ����
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
			mindp = LIM;	// mindp Ϊ dp[i][] �е���Сֵ
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