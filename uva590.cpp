#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;

vector<vector<vector<int> > > cost;
int n, k;
int memo[15][1010];

int escape(int curent_city, int day)
{
	if(day == k)
	{
		if(curent_city == n-1)
			return INT_MAX;
		int d = cost[curent_city][n-1][0]; //cycle length
		int index = (day-1) % d + 1;
		if(cost[curent_city][n-1][index] == 0)
			return INT_MAX;
		else
			return memo[curent_city][day] = cost[curent_city][n-1][index];
	}
	if(memo[curent_city][day] != -1)
		return memo[curent_city][day];
	
	int best = INT_MAX;
	for(int next_city = 0; next_city < n; next_city++)
	{
		if(next_city != curent_city)
		{
			int d = cost[curent_city][next_city][0]; //cycle length
			int index = (day-1) % d + 1;	
			int aux = escape(next_city, day + 1);
			if(aux != INT_MAX)
			{
				if(cost[curent_city][next_city][index] != 0)
					best = min(best, cost[curent_city][next_city][index] + aux);
			}
		}
	}
	return memo[curent_city][day] = best;
}












int main()
{	
	int tc = 0;
	while(true)
	{
		cin >> n; cin >> k;
		if(n == 0 && k == 0)
			break;
		
		tc++;
		cost.clear();
		cost.resize(n);
		int d;
		for(int city = 0; city < cost.size(); city++)
		{
			cost[city].resize(n);
			
			for(int next = 0; next < cost.size(); next++)
			{
				if(next != city)
				{
					cin >> d; /* number of days cycle */
					cost[city][next].push_back(d);
					cost[city][next].resize(cost[city][next][0] + 1);
					
					for(int i = 1; i <= cost[city][next][0]; i++)
						cin >> cost[city][next][i];
				}
			}
		}
	
		memset(memo, -1, sizeof(memo));
		int rez = escape(0, 1);
		printf("Scenario #%d\n", tc);
		if(rez != INT_MAX)
			printf("The best flight costs %d.\n", rez);
		else
			printf("No flight possible.\n");
		printf("\n");
	}

	return 0;
}
			
			









