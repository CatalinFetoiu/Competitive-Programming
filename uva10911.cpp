#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <list>
#include <queue>
#include <cmath>
#include <map>

#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)
#define BFS_WHITE -1

using namespace std;

int N;
double dist[20][20], memo[1 << 16];

double matching(int bitmask)
{
	if(memo[bitmask] > -0.5)
		return memo[bitmask];
	if(bitmask == (1 << (2 * N)) - 1)
		return memo[bitmask] = 0; //all pairs are matched

	double ans = 2000000000.0;
	for(int p1 = 0; p1 < (2 * N); p1++)
	{
		if(!(bitmask & (1 << p1))) //bit at position p1 is off
		{
			for(int p2 = p1 + 1; p2 < (2 * N); p2++)
			{
				if(!(bitmask & (1 << p2)))//p2 is also off
					ans = min(ans, dist[p1][p2] + matching(bitmask | (1 << p1) | (1 << p2)));
			}
			break;
		}
	}
	
	return memo[bitmask] = ans;
}


int main()
{
	int x[20], y[20];
	string name;
	
	int tc = 0;
	while(true)
	{
		cin >> N;
		if(N == 0)
			break;
		
		tc++;
		memset(memo, -1, sizeof(memo));
	
		for(int i = 0; i < (2 * N); i++)
			cin >> name >> x[i] >> y[i];
		
		for(int i = 0; i < (2 * N); i++)
		{
			for(int j = 0; j < (2 * N); j++)
			{
				dist[i][j] = hypot(double(x[i] - x[j]), double(y[i] - y[j]));
			}
		}
	
		printf("Case %d: %.2lf\n", tc, matching(0));
	}

	return 0;
}




	
	
					
	















