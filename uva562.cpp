#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;

int n;
vector<int> coins;
int memo[25050][110];

int knapsack(int W, int coin_index)
{
	if(memo[W][coin_index] != -1)
		return memo[W][coin_index];
	if(coin_index == n || W == 0)
		return 0;
	if(coins[coin_index] > W)
		return knapsack(W, coin_index + 1);
	return memo[W][coin_index] = max(coins[coin_index] + knapsack(W -
		coins[coin_index], coin_index + 1), knapsack(W, coin_index + 1));
}










int main()
{
	int T; cin >> T;
	while(T--)
	{
		cin >> n;
		if(n == 0)
			cout << "0" << endl;
		else
		{
			coins.clear();
			coins.resize(n);
			int sum = 0;
			for(int i = 0; i < n; i++)
			{
				cin >> coins[i];
				sum += coins[i];
			}
		
			memset(memo, -1, sizeof(memo));
			int rez = knapsack(sum/2, 0);
			cout << sum - 2 * rez << endl;
		}
	}
		
	return 0;
}	










