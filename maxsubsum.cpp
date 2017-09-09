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
#include<unordered_map>

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;

#define Max 3100
#define INF 2000000000
#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)


int N, M;
vector<int64> A, B;
int64 sumA[2010], sumB[2010];
int64 rangeA[2010], rangeB[2010];

int64 getSum(int i, int j, char what)
{
	if(what == 'A')
		return sumA[j] - sumA[i] + A[i];
	else
		return sumB[j] - sumB[i] + B[i];
}

void getRange()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = i; j <= N; j++)
		{
			rangeA[j-i+1] = max(rangeA[j-i+1], getSum(i, j, 'A'));
		}
	}
	for(int i = 1; i <= M; i++)
	{
		for(int j = i; j <= M; j++)
		{
			rangeB[j-i+1] = max(rangeB[j-i+1], getSum(i, j, 'B'));
		}
	}
}

int64 getMax()
{
	int64 res = -INF;
	for(int l1 = 1; l1 <= N; l1++)
	{
		for(int l2 = 1; l2 <= M; l2++)
		{
			res = max(res, rangeA[l1] * l2 + rangeB[l2] * l1);
		}
	}

	return res;
}


int main()
{
	FILE* fin = freopen("maxsubsum.in", "r", stdin);
	FILE* fout = freopen("maxsubsum.out", "w", stdout);

	scanf("%d%d", &N, &M);
	A.clear();
	A.resize(N+1);
	B.clear();
	B.resize(M+1);

	int64 sum = 0;
	for(int i = 1; i <= N; i++)
	{
		rangeA[i] = -INF;
		scanf("%lld", &A[i]);
		sum += A[i];
		sumA[i] = sum;
	}
	sum = 0;
	for(int i = 1; i <= M; i++)
	{
		rangeB[i] = -INF;
		scanf("%lld", &B[i]);
		sum += B[i];
		sumB[i] = sum;
	}

	getRange();
	//for(int i = 1; i <= N; i++)
		//cout << rangeA[i] << endl;

	printf("%lld\n", getMax());

	fclose(fin);
	fclose(fout);

	return 0;
}




















