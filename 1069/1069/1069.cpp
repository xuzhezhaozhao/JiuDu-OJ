#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct stu {
	char str[500];
	int id;
	char name[20];
	char sex[10];
	int age;
} stu;

bool cmp(const stu &s1, const stu &s2)
{
	return s1.id < s2.id;
}

int main()
{
	int n;
	vector <stu> st(1000);
	char buf[100];
	while (scanf("%d\n", &n) != EOF) {
		int i;
		for (i = 0; i < n; i++) {
			gets(st[i].str);
			sscanf(st[i].str, "%d %s %s %d", &st[i].id, st[i].name, st[i].sex, &st[i].age);
		}
		sort(st.begin(), st.begin() + n, cmp);
		int m;
		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			int id;
			scanf("%d", &id);
			int low = 0, high = n - 1;
			int mid;
			while (low <= high) {
				mid = (low + high) / 2;
				if (id == st[mid].id) {
					break;
				} else if (id > st[mid].id) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			if (low <= high) {
				//printf("%d %s %s %d\n", st[mid].id, st[mid].name, st[mid].sex, st[mid].age);
				printf("%s\n", st[mid].str);
			} else {
				printf("No Answer!\n");
			}
		}
	}

	return 0;
}