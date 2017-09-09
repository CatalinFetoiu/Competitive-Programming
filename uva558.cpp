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
#define INF 200000000

int V, E;
vector<vector<ii> > AdjList;
vector<int> dist;


bool Bellman_Ford(int start)
{
	dist.assign(V, INF);
	dist[start] = 0;

	for(int i = 0; i < V-1; i++)
	{
		for(int u = 0; u < V; u++)
		{
			TRvi(AdjList[u], v)
			{
				if(dist[u] + v->second < dist[v->first])
					dist[v->first] = dist[u] + v->second;
			}
		}
	}

	bool hasNegativeCycle = false; /* one more pass to check for negative cycle */
	for(int u = 0; u < V; u++)
	{
		TRvi(AdjList[u], v)
		{
			if(dist[u] + v->second < dist[v->first])
				hasNegativeCycle = true;
		}
	}

	return hasNegativeCycle;
}


int main()
{
	int start, end, time;

	int CaseNo; cin >> CaseNo;
	while(CaseNo--)
	{
		cin >> V >> E;
		AdjList.clear();
		AdjList.resize(V);
		for(int i = 0; i < E; i++)
		{
			cin >> start >> end >> time;
			AdjList[start].push_back(ii(end, time));
		}

		printf("%s\n", Bellman_Ford(0) ? "possible" : "not possible");
	}

	return 0;
}
		
	

























