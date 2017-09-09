#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;

vector<vector<int> > profit;
int C, S, E, T;
vector<int> canEnd;
int memo[110][1025];

int sell(int curent_city, int cities_left)
{
	if(memo[curent_city][cities_left] != -1)
		return memo[curent_city][cities_left];
	if(cities_left == 1)
	{
		int best = INT_MIN;
		for(int i = 0; i < E; i++)
		{
			if(curent_city != canEnd[i])
				best = max(best, profit[curent_city][canEnd[i]]);
		}
		return memo[curent_city][cities_left] = best;
	}
	int best = INT_MIN;
	for(int next_city = 0; next_city < C; next_city++)
	{
		if(next_city != curent_city)
		{
			int aux = sell(next_city, cities_left - 1);
			if(aux > 0)
				best = max(best, aux + profit[curent_city][next_city]);
		}
	}
	return memo[curent_city][cities_left] = best;
}










int main()
{
	while(true)
	{
		cin >> C >> S >> E >> T;
		if(C == 0)
			break;
		S--;
		profit.clear();
		profit.resize(C);
		for(int r = 0; r < C; r++)
		{
			profit[r].resize(C);
			for(int c = 0; c < C; c++)
				cin >> profit[r][c];
		}
		canEnd.clear();
		canEnd.resize(E);
		for(int i = 0; i < E; i++)
		{
			cin >> canEnd[i];
			canEnd[i]--;
		}
		
		memset(memo, -1, sizeof(memo));
		int rez = sell(S, T);
		cout << rez << endl;
	}	

	return 0;
}
	









