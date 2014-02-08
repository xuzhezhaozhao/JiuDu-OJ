#include <stdio.h>
#include <string.h>

bool v[10005];

int main()
{
	int L, M;
	int s1, s2;
	//freopen("data.txt", "r+", stdin);
	while (scanf("%d %d", &L, &M) != EOF) {
		memset(v, 0, sizeof(bool) * (L + 1) );
		int res = L + 1;
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &s1, &s2);
			for (int j = s1; j <= s2; j++) {
				if (!v[j]) {
					--res;
					v[j] = true;
				}
			}
		}
		printf("%d\n", res);
	}

	return 0;
}