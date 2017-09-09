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
#define INF 100000


int dist[20];
vector<vector<ii> > AdjList;
int parent[20];
priority_queue<ii, vector<ii>, greater<ii> > pq; /* heap :D */


void dijkstra(int src)
{
	pq.push(make_pair(0, src));
	dist[src] = 0;
	while(!pq.empty())
	{
		ii front = pq.top();
		pq.pop();
		int d = front.first, u = front.second;
		if(d == dist[u])
		{	
			TRvi(AdjList[u], v)
			{
				if(dist[u] + v->second < dist[v->first])
				{
					dist[v->first] = dist[u] + v->second;
					parent[v->first] = u;
					pq.push(make_pair(dist[v->first], v->first));
				}
			}
		}
	}
}


int main()
{
	priority_queue<ii, vector<ii>, greater<ii> > empty;
	vector<int> path;
	
	int N, neighbours;
	int vertex, cost, src, dest;
	int tc = 0;
	
	while(true)
	{
		tc++;

		cin >> N;
		if(N == 0)
			break;
		AdjList.clear();
		path.clear();
		pq = empty;
		memset(dist, 1000000, sizeof(dist));
		memset(parent, -1, sizeof(parent));
		
		AdjList.resize(N);
		for(int u = 0; u < N; u++)
		{
			cin >> neighbours;
			for(int i = 0; i < neighbours; i++)
			{
				cin >> vertex >> cost;
				AdjList[u].push_back(make_pair(vertex - 1, cost));
			}
		}
	
		cin >> src >> dest; src--; dest--;
		dijkstra(src);
	
		path.push_back(dest);
		int final = dest;
		while(parent[dest] != -1)
		{
			dest = parent[dest];
			path.push_back(dest);
		}
		cout << "Case " << tc << ": Path = ";
		for(int i = path.size() - 1; i >= 0; i--)
		{
			if(i != 0)
				cout << path[i] + 1 << " ";
			else
				cout << path[i] + 1 << "; ";
		}
		cout << dist[final] << " second delay" << endl;
	}
	
	return 0;
}
	
	
	






















