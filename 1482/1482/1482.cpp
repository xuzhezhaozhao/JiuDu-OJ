#include <stdio.h>
#include <string.h>
#include <iostream>
#include <set>
#include <string>

using namespace std;

//#define LOCAL	// 提交时注释掉

bool code[3*3*3*3*3*3*3*3*3*3*3*3*3 + 5];

int getCode(string buf)
{
	int res = 0;
	int N = buf.size();
	for (int i = 0; i < N; i++) {
		res = res * 3 + buf[i] - '0';
	}
	return res;
}

int main()
{
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int N;
	string s;
	char buf[20];
	while (cin >> N >> buf) {
		memset(code, 0, sizeof(code));
		s = buf;
		bool f0, f1, f2;
		f0 = f1 = f2 = false;
		int c2 = 0;
		for (int i = 0; i < N; i++) {
			if ('0' == buf[i]) {
				f0 = true;
			} else if ('1' == buf[i]) {
				f1 = true;
			} else {
				c2++;
			}
		}
		if (c2 >= 2) {
			f2 = true;
		}
		if ( !(f0 && f1 && f2) ) {
			printf("-1\n");
			continue;
		}

		set <pair<int, string> > codeSet;
		int res = 0;
		string des = "2012";
		if (s.find(des) != string::npos) {
			res = 0;
		} else {
			codeSet.insert( make_pair(0, s) );
			code[ getCode(s) ] = true;
			while (!codeSet.empty()) {
				bool ok = false;
				string ns = ( *codeSet.begin() ).second;
				int time = ( *codeSet.begin() ).first;
				codeSet.erase( codeSet.begin() );
				// 对 ns 移位一次
				string st;
				for (int i = 0; i < N - 1; i++) {
					st = ns;
					swap(st[i], st[i+1]);
					if (st.find(des) != string::npos) {
						res = time + 1;
						ok = true;
						break;
					} else {
						if (!code[ getCode(st) ]) {
							codeSet.insert( make_pair(time + 1, st) );
							code[ getCode(st) ]  = true;
						}
					}
				}
				if (ok) {
					break;
				}
			}
		}
		printf("%d\n", res);
	}

	return 0;
}