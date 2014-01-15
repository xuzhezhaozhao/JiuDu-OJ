#include <stdio.h>
#include <cstring>

void disPostOrder(char *s1, char *s2, int left1, int left2, int right2)
{
	int i;
	for (i = left2; i <= right2; i++) {
		if (s2[i] == s1[left1]) {
			break;
		}
	}
	if (i - 1 >= left2) {
		disPostOrder(s1, s2, left1 + 1, left2, i - 1);
	} 
	if (i + 1 <= right2) {
		disPostOrder(s1, s2, left1 + i - left2 + 1, i + 1, right2);	
	}
	printf("%c", s1[left1]);
}

int main()
{
	char s1[27], s2[27];
	while (scanf("%s", s1) != EOF) {
		scanf("%s", s2);
		int len = strlen(s1);
		disPostOrder(s1, s2, 0, 0, len-1);
		printf("\n");
	}

	return 0;
}