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

#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)
#define INF 2000000000

using namespace std;

int V;
vector<vector<int> > AdjList;
vector<int> energy;
vector<int> dist;
vector<int> connected;

bool bfs(int start, int dest)
{
	vector<int> visited(V, 0);
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	bool canReach = false;
	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		if(front == dest)
		{
			canReach = true;
			break;
		}
		TRvi(AdjList[front], v)
		{
			if(!visited[*v])
			{
				visited[*v] = 1;
				q.push(*v);
			}
		}
	}
	
	return canReach;
}		


bool Bellman_Ford(int start) /* O(V*E) */
{
	dist.assign(V, -INF);
	dist[start] = 100;

	for(int i = 0; i < V-1; i++)
	{
		for(int u = 0; u < V; u++)
		{
			TRvi(AdjList[u], v)
			{
				if(dist[u] + energy[*v] > dist[*v] && dist[u] > 0)
				{
					dist[*v] = dist[u] + energy[*v];
				}
				if(connected[u])
					connected[*v] = 1;
			}
		}
	}

	bool reachWithCycle = false; /* one more pass to check for positive cycle */
	for(int u = 0; u < V; u++)
	{
		TRvi(AdjList[u], v)
		{
			if(dist[u] + energy[*v] > dist[*v] && dist[u] > 0) /* means inside a positive cycle */
			{
				if(bfs(u, V-1) || bfs(*v, V-1))
				{
					reachWithCycle = true;
					break;
				}
			}
		}
	}

	return reachWithCycle;
}


int main()
{
	int start, end, numNeighbours;

	int CaseNo = 0;
	while(true)
	{
		cin >> V;
		if(V == -1)
			break;	
		
		CaseNo++;
		AdjList.clear();
		AdjList.resize(V);
		energy.clear();
		energy.resize(V);
		connected.clear();
		connected.resize(V, 0);
		connected[0] = 1;

		for(int u = 0; u < V; u++)
		{
			cin >> energy[u];
			cin >> numNeighbours;
			for(int i = 0; i < numNeighbours; i++)
			{
				cin >> end;
				AdjList[u].push_back(end-1);
			}
		}
	
		bool reachWithCycle = Bellman_Ford(0);
		if(reachWithCycle)
		{
			cout << "winnable" << endl;
		}
		else if(dist[V-1] > 0)
			cout << "winnable" << endl;
		else
			cout << "hopeless" << endl;
	}
	
	return 0;
}
		






















