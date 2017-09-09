#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<limits.h>
#include<list>
#include<stack>
#include<queue>
#include<map>

using namespace std;

typedef pair<int, int> ii;

typedef long long int64;

#define Max 15100
#define INF 2000000000
#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)


int V, E;
vector<int> cost;
vector<vector<int> > reverseGraph;
int64 dp[Max];
int visited[Max];
vector<int> topoSort;


void topologicalSorting(int node)
{
	int next;
	visited[node] = 1;

	TRvi(reverseGraph[node], v)
	{
		next = *v;
		if(!visited[next])
			topologicalSorting(next);
	}

	topoSort.push_back(node);
}
		
void createDP()
{
	int node, prev;
	int64 res;	
	for(int i = 0; i < V; i++)
	{
		node = topoSort[i];
		if(reverseGraph[node].size() == 0) /* no indegree */
			dp[node] = cost[node];
		else
		{
			res = -INF;
			TRvi(reverseGraph[node], v)
			{
				prev = *v;
				res = max(res, dp[prev]);
			}
	
			if(res + cost[node] < cost[node])
				dp[node] = cost[node];
			else
				dp[node] = res + cost[node];
		}
	}
}
			
	

int main()
{	
	FILE* fin = freopen("easygraph.in", "r", stdin);
	FILE* fout = freopen("easygraph.out", "w", stdout);

	int src, dest;

	int T; cin >> T;

	while(T--)
	{

	scanf("%d%d", &V, &E);
	
	cost.clear();
	cost.resize(V);
	for(int i = 0; i < V; i++)
		scanf("%d", &cost[i]);

	reverseGraph.clear();
	reverseGraph.resize(V);
	
	for(int i = 0; i < E; i++)
	{
		scanf("%d%d", &src, &dest);
		src--; dest--;
		reverseGraph[dest].push_back(src);
	}

	/* sort vertices */
	topoSort.clear();
	memset(visited, 0, sizeof(visited));
	for(int node = 0; node < V; node++)
	{
		if(!visited[node])
			topologicalSorting(node);
	}

	

	int64 res = -INF;
	//memset(dp, -1, sizeof(dp));
	createDP();
	for(int node = 0; node < V; node++)
		if(res < dp[node])
			res = dp[node];

	/*
	while(true)
	{
		int a; cin >> a; a--;
		cout << endingHere(a) << endl;
	} */

	cout << res << endl;

	}

	fclose(fin);
	fclose(fout);


	return 0;
}
























