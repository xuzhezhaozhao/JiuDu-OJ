#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct stu {
	char name[101];
	int age;
	int score;
}stu;

bool cmp(const stu &s1, const stu &s2) {
	string name1 = s1.name;
	string name2 = s2.name;
	if (s1.score != s2.score) {
		return s1.score < s2.score;
	} else if (name1 != name2) {
		return (name1 < name2);
	} else {
		return s1.age < s2.age;
	}
}

int main()
{
	int n;
	vector <stu> s;
	stu st;

	while ( scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%s %d %d", st.name, &st.age, &st.score);
			s.push_back(st);
		}
		sort(s.begin(), s.end(), cmp);

		for (int i = 0; i < n; i++) {
			printf("%s %d %d\n", s[i].name, s[i].age, s[i].score);
		}
		s.clear();
	}
	return 0;
}