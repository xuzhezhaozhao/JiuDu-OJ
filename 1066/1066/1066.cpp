#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	char st[21];
	while (gets(st)) {
		vector <char> s;
		for (int i = 0; st[i] != '\0'; i++) {
			s.push_back(st[i]);
		}
		sort(s.begin(), s.end());
		for (int i = 0; i < s.size(); i++) {
			printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}