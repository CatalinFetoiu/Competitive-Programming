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
//#include<unordered_map>

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;

#define Max 3100
#define INF 20000000
#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)

int dp[32][32][32][32];

int N, M;
int mat[35][35];

int getSum(int i, int j, int k, int l)
{
	int res = mat[k][l];
	if(i > 0)
		res -= mat[i-1][l];
	if(j > 0)
		res -= mat[k][j-1];
	if(i > 0 && j > 0)
		res += mat[i-1][j-1];

	return res;
}

int minimize(int row1, int col1, int row2, int col2)
{
	//printf("%d %d %d %d\n", row1, col1, row2, col2);
	if(dp[row1][col1][row2][col2] != -1)
		return dp[row1][col1][row2][col2];

	if(row1 == row2 && col1 == col2)
		return 0;

	int aux = getSum(row1, col1, row2, col2);
	if(aux == 0 || aux == (row2-row1+1) * (col2-col1+1))
		return 0;

	int res = INF;
	if(row1 != row2)
	{
		for(int i = row1; i < row2; i++)
			res = min(res, 1 + minimize(row1, col1, i, col2) + minimize(i+1, col1, row2, col2));
	}
	

	if(col1 != col2)
	{
		for(int i = col1; i < col2; i++)
			res= min(res, 1 + minimize(row1, col1, row2, i) + minimize(row1, i+1, row2, col2));

	}

	return dp[row1][col1][row2][col2] = res;
}


int main()
{
	freopen("matrice8.in", "r", stdin);
	freopen("matrice8.out", "w", stdout);

	string line;

	int T; cin >> T;

	while(T--) {
	
	cin >> N >> M;

	
	memset(mat, 0, sizeof(mat));
	
	for(int i = 0; i < N; i++)
	{
		cin >> line;
		for(int j = 0; j < line.length(); j++)
		{
			mat[i][j] = line[j] - '0';
			if(i > 0)
				mat[i][j] += mat[i-1][j];
			if(j > 0)
				mat[i][j] += mat[i][j-1];
			if(i > 0 && j > 0)
				mat[i][j] -= mat[i-1][j-1];
		}
	}

	//cout << getSum(1, 1, 2, 4) << endl;
	
	memset(dp, -1, sizeof(dp));

	cout << minimize(0, 0, N-1, M-1) << endl;

	}

	return 0;
}























