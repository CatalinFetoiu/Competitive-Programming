#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <list>
#include <stack>
#include <limits.h>

typedef long long int64;

typedef std::pair<int, int> ii;

using namespace std;

int S, N;
vector<int> prices;
vector<int> favours;

int dp[110][10100];

int Knapsack(int index, int currentSum)
{
	if(dp[index][currentSum] != -1)
		return dp[index][currentSum];

	if(currentSum > S && S < 1800)
		return -1;

	if(currentSum > S + 200)
		return -1;

	if(index == N)
	{
		if(currentSum > S && currentSum <= 2000)
			return -1;
		return 0;
	}
	
	return dp[index][currentSum] = max(Knapsack(index+1, currentSum), favours[index] +
		Knapsack(index+1, currentSum + prices[index]));

}


int main()
{
	while(true)
	{
		cin >> S;
		if(cin.eof())
			break;

		cin >> N;
		prices.clear();
		prices.resize(N);
		favours.clear();
		favours.resize(N);

		for(int i = 0; i < N; i++)
			cin >> prices[i] >> favours[i];

		memset(dp, -1, sizeof(dp));

		cout << Knapsack(0, 0) << endl;
	}

	return 0;
}

		

		
		












