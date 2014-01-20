#include <cstdio>
#include <string.h>
#include <ctype.h>

int getNum(char c)
{
	if (isdigit(c)) {
		return c - '0';
	} else {
		return c - 'A' + 10;
	}
}
#define MAX 500
int a[MAX];	// M 进制
int b[MAX];	// 10 进制
int c[MAX];	// N 进制
char buf[10000];

int main()
{
	//freopen("data.txt","r",stdin);
	// freopen ("myfile.txt","w",stdout);
	int m, n, i, j, k;
	while (scanf("%d %d\n", &m, &n) != EOF) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));

		gets(buf);
		int len = strlen(buf);
		if (len == 1 && buf[0] == '0') {	// 处理数据为零的情况
			printf("0\n");
			continue;
		}
		int lim;
		for (i = 0; i < len; i++) {
			a[i] = getNum(buf[i]);
			// b[] * m
			b[0] *= m;  
			for (lim = MAX-1; lim >= 0 && b[lim] == 0; lim--) {
			}
			for (j = 1; j < lim+5; j++) {
				b[j] *= m;
				b[j] += b[j-1] / 10;
				b[j-1] %= 10;
			}
			// b[] + a[i]
			b[0] += a[i];
			for (lim = MAX-1; lim >= 0 && b[lim] == 0; lim--) {
			}
			for (j = 1; j < lim+5; j++) {
				b[j] += b[j-1] / 10;
				b[j-1] %= 10;
			}
		}
		// b[] 转 n 进制
		for (i = MAX - 1; i >= 0 && b[i] == 0; i--) {
		}
		
		k = 0;
		while (i >= 0) {
			for (j = i; j >= 1; j--) {
				if (b[j] < n) {
					b[j-1] += b[j] * 10;
					b[j] = 0;
					if (j == i) {		// 这个地方要注意加判断，调试了很久才发现这个问题
						--i;
					}
				} else {
					b[j-1] += (b[j] % n) * 10;
					b[j] = b[j] / n;
				}
			}
			c[k] = b[0] % n;
			++k;
			b[0] /= n;
			if (0 == i && 0 == b[0]) {
				break;
			}
		}
		for (i = MAX - 1; i >= 0 && c[i] == 0; i--) {
		}
		for (; i >= 0; i--) {
			if (c[i] >= 0 && c[i] <= 9) {
				printf("%c", c[i] + '0');
			} else {
				printf("%c", c[i] - 10 + 'a');
			}
		}
		printf("\n");
	}

	return 0;
}

/* minix 的提交

#include <stdio.h>
#include <string.h>
#define XMAX 36028797018963968
 
int main(void)
{
    int i, j, k,m, n,len;
    char x[1000]; int y[1000];
    unsigned long long z[1000], s, sum;
 
    while (scanf("%d%d%s",&m,&n,x)!=EOF)
    {
    z[0] = len = 0;
    while(x[len]) { y[len] = (x[len]<='9')?(x[len]-'0'):(x[len]-'A'+10); ++len; }
    k = 1;
    for (i=0; i<len; i++)
    {
        s = 0;
        for (j=0; j<k; j++)
        {
        sum = (j==0)?(z[j]*m+y[i]+s):(z[j]*m+s);
        s = sum/XMAX;  z[j] = sum%XMAX;
        }
        if (s) z[k++] = s;
    }
    for (i=0; z[0]>=n || (z[0]<n&&z[k-1]!=0&&k!=1);i++)
    {
        s = 0;
        for (j=k-1;j>=0;j--)
        {
                sum = z[j]+s*XMAX;
        s = sum%n; z[j] = sum/n;
        }
        y[i] = s;    if ( z[k-1]==0 ) k--;
    }
    y[i] = z[0]; len = i;
    for (i=0; i<=len; i++)
    {
        if ( y[len-i]<10 ) x[i] = y[len-i]+'0';
        else x[i]=y[len-i]-10+'a';
    }
    x[i] = '\0';
    puts(x);
    }
    return 0;
}
/**************************************************************
    Problem: 1080
    User: minix
    Language: C
    Result: Accepted
    Time:10 ms
    Memory:908 kb
****************************************************************/