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

vector<int> numCoins;
vector<int> values;
int memo[550];
int dp[10][110][550];    /* max 6 coin values */

void clasicalChange()
{
	memo[0] = 0;
	for(int sum = 5; sum <= 500; sum += 5)
	{
		int best = INT_MAX;
		for(int coin = 0; coin < values.size(); coin++)
		{
			if(sum - values[coin] >= 0 && memo[sum - values[coin]] != -1)
				best = min(best, 1 + memo[sum-values[coin]]);
		}
		if(best != INT_MAX)
			memo[sum] = best;
	}
}

int change(int coin_index, int coins_left, int sum)
{
	if(dp[coin_index][coins_left][sum] != -1)
		return dp[coin_index][coins_left][sum];
	if(sum < 0)
		return 10000;
	if(sum == 0)
		return 0;
	if(coins_left == 0)
	{
		//printf("ok");
		if(coin_index == values.size() - 1)
		{
			if(sum == 0)
				return 0;
			else
				return 10000;
		}
		else
			return dp[coin_index][coins_left][sum] = change(coin_index + 1, numCoins[coin_index+1], sum);
	}
	if(coin_index == values.size() - 1)
		return dp[coin_index][coins_left][sum] = 1 + change(coin_index, coins_left - 1, sum - values[coin_index]);
	int option1 = 1 + change(coin_index, coins_left - 1, sum - values[coin_index]);
	int option2 = change(coin_index + 1, numCoins[coin_index+1], sum);

	//cout << option1 << " " << option2 << endl;
	return dp[coin_index][coins_left][sum] = min(option1, option2);
}
	





int main()
{
	float input;
	int sum; 
	numCoins.resize(6);
	values.push_back(200); values.push_back(100); values.push_back(50);
	values.push_back(20); values.push_back(10); values.push_back(5);
	
	memset(memo, -1, sizeof(memo));
	clasicalChange();
	
	while(true)
	{
		memset(dp, -1, sizeof(dp));
	
		bool remain = false;
		for(int i = 0; i < 6; i++)
		{
			cin >> numCoins[i]; 
			if(numCoins[i] != 0)
				remain = true;
		}
		if(!remain)
			break;
		
		cin >> input;
		sum = (int)(100 * input + 0.01);
		reverse(numCoins.begin(), numCoins.end());
	
		int best = INT_MAX;
		for(int pay = sum; pay <= 500; pay += 5)
		{
			best = min(best, change(0, numCoins[0], pay) + memo[pay - sum]);
		}
		
		printf("%3d\n", best);
	}
/*
	while(true)
	{
		for(int i = 0; i < 6; i++)
		{
			cin >> numCoins[i]; 
			//cout << values[i] << endl;
		}
		cin >> sum;
		cout << change(0, numCoins[0], sum) << endl;
	} */
	
	return 0;
}
		
	














