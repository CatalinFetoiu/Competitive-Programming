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
#include <map>

using namespace std;

typedef pair<int, int> ii;

#define TRvi(c, it) \
	for(vector<ii>::iterator it = c.begin(); it != c.end(); it++)
#define INF 2000000000
#define BFS_WHITE -1


int V, E;
vector<vector<ii> > AdjList;
map<string, int> mi;
int dp[110][110]; /* city and edges left */
vector<int> queries;
int startIndex, destIndex;

int get_id(string s)
{
	if(mi.find(s) != mi.end())
	{
		return mi[s];
	}
	else
	{
		int i = mi.size();
		mi[s] = i;
		return i;
	}
}
		

int minCost(int city, int edgesLeft)
{
	if(dp[city][edgesLeft] != -1)
		return dp[city][edgesLeft];
	if(edgesLeft == 0)
	{
		if(city == destIndex)
			return 0;
		else
			return INF;
	}
	if(city == destIndex)
		return 0;

	int best = INF;
	TRvi(AdjList[city], v)
	{
		int nextCity = v->first;
		int cost = v->second;
		best = min(best, minCost(nextCity, edgesLeft-1) + cost);
	}

	return dp[city][edgesLeft] = best;
}


int main()
{
	string city, start, destination;
	int numQueries, cost;
	
	int Cases; cin >> Cases;
	
	for(int CaseNo = 1; CaseNo <= Cases; CaseNo++)
	{
	cin >> V;
	AdjList.clear();
	AdjList.resize(V);
	mi.clear();
	queries.clear();
	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < V; i++)
	{
		cin >> city;
		get_id(city);
		if(i == 0)
			startIndex = get_id(city);
		if(i == V-1)
			destIndex = get_id(city);
	}

	cin >> E;
	for(int i = 0; i < E; i++)
	{
		cin >> start >> destination >> cost;
		AdjList[get_id(start)].push_back(ii(get_id(destination), cost));
	}
	cin >> numQueries;
	queries.resize(numQueries);
	for(int i = 0; i < queries.size(); i++)
	{
		cin >> queries[i];
	}

	if(CaseNo != 1)
		cout << endl;
	printf("Scenario #%d\n", CaseNo);
	for(int i = 0; i < queries.size(); i++)
	{
		if(minCost(startIndex, queries[i] + 1) != INF)
			printf("Total cost of flight(s) is $%d\n", minCost(startIndex, queries[i] + 1));
		else
			printf("No satisfactory flights\n");
	}
	}

	return 0;
}






















