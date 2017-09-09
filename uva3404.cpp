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
#define INF 2000000000.0

using namespace std;


vector<int> distances;
int N, r;
double b, v, e, f;
double times[110][110]; //time to race on path to checkpoint ai from last checkpoint
double dp[110];

double one_unit(int pos, int check)
{
	double rez = 1;
	int dist = pos - check;
	if(dist >= r)
		return rez / (v - e * (dist-r));
	else
		return rez / (v - f * (r-dist));
}

void preComputeTime() /* O(1M) */
{
	for(int u = 0; u < distances.size() - 1; u++) //last checkpoint
	{
		double sum = 0;
		for(int v = u + 1; v < distances.size(); v++) //arrival checkpoint
		{
			for(int i = 0; i < distances[v] - distances[v-1]; i++)
			{
				sum += one_unit(distances[v-1] + i, distances[u]);
				//cout << one_unit(v + i, u) << endl;
			}
			times[u][v] = sum;
		}
	}
}

double race(int checkPoint)
{
	if(dp[checkPoint] > -0.5)
		return dp[checkPoint];
	if(checkPoint == 0)
		return 0; //no time to reach start point
	
	double result = INF;
	for(int lastCheck = 0; lastCheck < checkPoint; lastCheck++)
	{
		if(lastCheck != 0)
			result = min(result, race(lastCheck) + b + times[lastCheck][checkPoint]);
		else
			result = min(result, race(lastCheck) + times[lastCheck][checkPoint]);
	}

	return dp[checkPoint] = result;
}



int main()
{
	while(true)
	{
		distances.clear();
		memset(dp, -1, sizeof(dp));
		cin >> N;
		if(N == 0)
			break;
		distances.resize(N+1);
		distances[0] = 0;
		for(int i = 1; i <= N; i++)
			cin >> distances[i];
	
		cin >> b;
		cin >> r;
		cin >> v >> e >> f;
		
		preComputeTime();
		printf("%.4lf\n", race(N));
	}

	return 0;
}














		

















