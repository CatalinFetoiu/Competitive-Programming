#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;

int dp[110][110];
vector<int> tower1, tower2;

int main()
{
	int m, n;
	int tc = 0;
	while(true)
	{
		tc++;
		tower1.clear();
		tower2.clear();
		cin >> m >> n;
		if(m == 0 && n == 0)
			break;
		tower1.resize(m);
		tower2.resize(n);
		for(int i = 0; i < m; i++)
			cin >> tower1[i];
		for(int i = 0; i < n; i++)
		cin >> tower2[i];
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i <= m; i++)
		{
			for(int j = 0; j <=n; j++)
			{
				if(i == 0 || j == 0)
					dp[i][j] = 0;
				else if(tower1[i-1] == tower2[j-1])
					dp[i][j] = 1 + dp[i-1][j-1];
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}

		cout << "Twin Towers #" << tc << endl;
		cout << "Number of Tiles : " << dp[m][n] << endl;
		cout << endl;
	}

	return 0;
}




