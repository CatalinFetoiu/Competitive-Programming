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

int dp[1010][1010];
string s;

int cost(int l, int r)
{
	if(dp[l][r] != -1)
		return dp[l][r];
	if(l == r)
		return dp[l][r] = 0;
	if(l+1 == r)
	{
		if(s[l] == s[r])
			return dp[l][r] = 0;
		else
			return dp[l][r] = 1;
	}
	if(s[l] == s[r])
		return dp[l][r] = cost(l+1, r-1);
	return dp[l][r] = 1 + min(min(cost(l+1, r-1), cost(l, r-1)), cost(l+1, r));
}	 













int main()
{
	int T; cin >> T;
	for(int i = 1; i <= T; i++)
	{
		cin >> s;
		memset(dp, -1, sizeof(dp));
		int rez = cost(0, s.size() - 1);
		cout << "Case " << i << ": " << rez << endl;
	}
	
	return 0;
}









