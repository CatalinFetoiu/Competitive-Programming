#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;

int M, C, K, price[25][25];
int memo[210][25];

int shop(int money_left, int garment_id)
{
	if(money_left < 0)
		return INT_MIN;
	if(garment_id == C)
		return M - money_left;
	if(memo[money_left][garment_id] != -1)
		return memo[money_left][garment_id];
	
	int best = INT_MIN;
	for(int i = 1; i <= price[garment_id][0]; i++)
		best = max(best, shop(money_left - price[garment_id][i], garment_id + 1));
	return memo[money_left][garment_id] = best;
}













int main()
{
	int N; cin >> N;
	for(int tc = 0; tc < N; tc++)
	{
		cin >> M; cin >> C;
		for(int i = 0; i < C; i++)
		{
			cin >> K;
			price[i][0] = K;
			for(int j = 1; j <= K; j++)
				cin >> price[i][j];
		}
	
		memset(memo, -1, sizeof(memo));
		int rez = shop(M, 0);
		if(rez < 0)
			cout << "no solution" << endl;
		else
			cout << rez << endl;
	}

	return 0;
}	








