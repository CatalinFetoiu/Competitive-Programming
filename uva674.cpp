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

vector<int> values;
int memo[10][8000];

int ways(int coin_index, int sum)
{
	if(sum < 0)
		return -1;
	if(memo[coin_index][sum] != -1)
		return memo[coin_index][sum];
	if(sum == 0 || coin_index == values.size() - 1)
		return 1;

	int count = 0;
	if(ways(coin_index, sum - values[coin_index]) > 0)
		count += ways(coin_index, sum - values[coin_index]);
	if(ways(coin_index + 1, sum) > 0)
		count += ways(coin_index + 1, sum);
	return memo[coin_index][sum] = count;
}










int main()
{
	int sum;
	
	values.push_back(50); values.push_back(25); values.push_back(10);
	values.push_back(5); values.push_back(1);
	memset(memo, -1, sizeof(memo));

	while(true)
	{
		cin >> sum;
		if(cin.eof())
			break;
		int rez = ways(0, sum);
		cout << rez << endl;
	}

	return 0;
}




