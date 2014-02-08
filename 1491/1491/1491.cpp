#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

//#define LOCAL	// 提交时注释掉

const int MOD = 20123;
const int MAX_B = 101;
int a[MAX_B + 5];	// a[i] 表示所有i或小于i位数中的 1,2个数
int bmod[MAX_B + 5];	// bmod[i] 表示 最小的i+1位数对 MOD 取模的值
int c[10] = {0, 1, 2, 2, 2, 2, 2, 2, 2, 2};	// c[i] 表示F(i) (i <= 9) 的值

// 大数取模，利用公式 （a op b）mod c = (a mod c) op (b mod c), ( op = +、-、* )
int bigMod(string str)
{
	int len = str.size();
	int res = 0;
	for (int i = 0; i < len; i++) {
		res += (str[i] - '0') * bmod[len - i - 1];
		res %= MOD;
	}
	return res;
}
// 递归，计算1,2个数
int F(string str)
{
	int res = 0;
	int len = str.size();
	int first = str[0] - '0';
	if (len == 1 || len == 0) {			// base case
		res = c[ first ];
	} else {
		string newStr = str.substr(1, len-1);
		res = (first * a[len-1]) % MOD;
		res = (res + F(newStr)) % MOD;

		if (first == 1) {
			res = (res + bigMod(newStr) + 1) % MOD;
		} else if (first == 2) {
			res = (res + bmod[len-1] + bigMod(newStr) + 1) % MOD;
		} else if (first > 2) {
			res = (res + 2 * bmod[len-1]) % MOD;
		}	
	}
	return res;
}

int main()
{
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	bmod[0] = 1;
	bmod[1] = 10 % MOD;
	for (int i = 2; i <= MAX_B; i++) {
		bmod[i] = ( 10 * bmod[i-1] ) % MOD;
	}

	a[0] = 0;
	a[1] = 2;
	for (int i = 2; i <= MAX_B; i++) {
		a[i] = ( 10 * a[i-1] + 2 * bmod[i-1] ) % MOD;
	}

	char buf[105];
	while (scanf("%s", buf) != EOF) {
		int res = 0;
		string str = buf;
		res = F(str);
		printf("%d\n", res);
	}

	return 0;
}

/*
#include<stdio.h>
#include<string.h>
 
int main(){
    int now,w,n,k,t,f,i;
    char s[110];
 
    while(scanf("%s",s)!=EOF){
        n = 0 ;
        now = 0 ;
        f = 1 ;
        k = 0 ;
        w = 0 ;
        for(i=strlen(s)-1;i>=0;i--){
            t = s[i] - '0' ;
            now  += k*w*t ;
            switch(t){
            case 0:
                break;
            case 1:
                now += n+1 ;
                break;
            case 2:
                now += n+1 ;
                now += f ;
                break;
            default:
                now += 2*f ;
            }
            k = f*2 ;
            n = n + t*f;
            f *= 10 ;
            w++;
 
            if(k>=20123)
                k %= 20123 ;
            if(f>=20123)
                f %= 20123 ;
            if(now>=20123)
                now %= 20123 ;
            if(n>=20123)
                n%=20123;
 
        }
        printf("%d\n",now);
    }
    return 0;
}
/**************************************************************
    Problem: 1491
    User: 焦点
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:912 kb
****************************************************************/