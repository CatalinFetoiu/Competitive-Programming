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

int N, M, D, Q;
vector<int> numbers;

/* dp of index, numbers chosen, residue */
int dp[210][12][21];

int findNum(int index, int numChosen, int sum)
{
	if(dp[index][numChosen][sum] != -1)
		return dp[index][numChosen][sum];

	if(numChosen == M)
	{
		if(sum % D == 0)
			return 1;
		else
			return 0;
	}

	if(index == N)
		return 0;

	return dp[index][numChosen][sum] = findNum(index+1, numChosen, sum%D) +
		findNum(index+1, numChosen+1, ((sum+numbers[index])%D + D)%D);
}
	


int main()
{
	int caseNo = 0;
	while(true)
	{
		cin >> N >> Q;
		if(N == 0 && Q == 0)
			break;
		
		numbers.clear();
		numbers.resize(N);

		for(int i = 0; i < N; i++)
			cin >> numbers[i];

		caseNo++;
		printf("SET %d:\n", caseNo);
		for(int q = 1; q <= Q; q++)
		{
			cin >> D >> M;
		
			memset(dp, -1, sizeof(dp));
		
			int res = findNum(0, 0, 0);

			printf("QUERY %d: %d\n", q, res);
		}
	}

	return 0;
}














