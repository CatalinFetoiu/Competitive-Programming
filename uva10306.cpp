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

vector<pair<int, int> > coins;
int dp[325][325];

void createDP()
{
	dp[0][0] = 0;
	for(int i = 0; i <= 300; i++)
	{
		for(int j = 0; j <= 300; j++)
		{
			if(i > 0 || j > 0)
			{
				int best = INT_MAX;
				for(int index = 0; index < coins.size(); index++)
				{
					if(i >= coins[index].first && j >= coins[index].second
						 && dp[i-coins[index].first][j-coins[index].second] != -1)
						best = min(best, dp[i-coins[index].first][j-coins[index].second]);
				}
				if(best != INT_MAX)
					dp[i][j] = 1 + best;
			}
		}
	}
}




















int main()
{
	int tc; cin >> tc;
	int m, sum;

	while(tc--)
	{
		cin >> m >> sum;
		coins.resize(m);
		for(int i = 0; i < coins.size(); i++)
		{
			cin >> coins[i].first;
			cin >> coins[i].second;
		}
		memset(dp, -1, sizeof(dp));
		createDP();
	
		int rez = INT_MAX;
		for(int i = 0; i <= sum; i++)
		{
			for(int j = 0; j <= sum; j++)
			{
				if(dp[i][j] != -1 && i * i + j * j == sum * sum)
					rez = min(rez, dp[i][j]);
			}
		}
		if(rez != INT_MAX)
			cout << rez << endl;
		else
			cout << "not possible" << endl;

	}
	

	return 0;
}
