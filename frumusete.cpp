#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<limits.h>
#include<list>
#include<queue>
#include<bitset>
#include<map>

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;

#define Max 3100
#define INF 2000000000
#define prime 666013

//dp[n][k][0/1]
int dp[1010][1010][2]; /* how many numbers starting with 0/1 with n bits and grad k */

void createDpTable()
{
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	dp[1][1][0] = 0;
	dp[1][1][1] = 0;
	for(int n = 2; n <= 1000; n++)
	{
		for(int k = 0; k <= 1000; k++)
		{
			if(k == 0)
			{
				dp[n][k][0] = (dp[n-1][0][0] + dp[n-1][0][1]) % prime;
				dp[n][k][1] = dp[n-1][0][0];
			}
			else
			{
				dp[n][k][0] = (dp[n-1][k][0] + dp[n-1][k][1]) % prime; /* adding 0 does not increase count */
				dp[n][k][1] = (dp[n-1][k][0] + dp[n-1][k-1][1]) % prime; /* adding 1 changes with one count */
			}
		}
	}
}

int count(char* number, int k)
{
	int res = 0;
	int frum = 0;
	
	int i;
	for(i = 0; i < strlen(number); i++)
	{
		if(i >= 2)
		{
			if(number[i-1] == '1' && number[i-2] == '1')
				frum++;
		}
		if(frum > k)
			break;
		if(number[i] == '1')
		{
			res += dp[strlen(number)-i][k-frum][0];
			//res = res - (res / prime) * prime;
		}
	}
	if(i == strlen(number) && number[i-1] == '1' && number[i-2] == '1')
		frum++;
	if(frum == k)
		res++;

	return res % prime;
}


int main()
{
	FILE* fin = freopen("frumusete.in", "r", stdin);
	FILE* fout = freopen("frumusete.out", "w", stdout);

	char line[1500];
	char number[1500];

	memset(dp, 0, sizeof(dp));
	createDpTable();

	int k;

	int T; scanf("%d", &T);

	while(T--) 
	{
		scanf("%d%s", &k, number);
		
		printf("%d\n", count(number, k));
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
































