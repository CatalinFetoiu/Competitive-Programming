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
typedef long long int64;

int64 dp[25][10010];

int cube(int t)
{
	return t*t*t;
}

int64 ways(int coin_index, int sum)
{
	if(sum < 0)
		return -1;
	if(dp[coin_index][sum] != -1)
		return dp[coin_index][sum];
	if(sum == 0 || coin_index == 1)
		return 1;

	int64 count = 0;
	if(ways(coin_index, sum - cube(coin_index)) > 0)
		count += ways(coin_index, sum - cube(coin_index));
	if(ways(coin_index - 1, sum) > 0)
		count += ways(coin_index - 1, sum);
	return dp[coin_index][sum] = count;
}











int main()
{
	int sum;
	memset(dp, -1, sizeof(dp));

	while(true)
	{
		cin >> sum;
		if(cin.eof())
			break;
		int64 rez = ways(21, sum);
		cout << rez << endl;
	}

	return 0;
}









