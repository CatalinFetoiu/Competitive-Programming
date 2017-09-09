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
#define BFS_WHITE -1
#define INF 2000000000

int V, E, Q;
vector<pair<int, ii> > EdgeList;
vector<vector<ii> > MST;

vector<int> pset;
int numDisjointSets;


void initSets(int num)
{
	pset.assign(num, 0);
	numDisjointSets = num;
	for(int i = 0; i < num; i++)
		pset[i] = i;
}
int findSet(int i)
{
	if(pset[i] == i)
		return i;
	else
		return pset[i] = findSet(pset[i]);
}
bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j)
{
	if(!isSameSet(i, j))
		numDisjointSets -= 1;
	pset[findSet(i)] = findSet(j);
}


void Kruskal()
{
	sort(EdgeList.begin(), EdgeList.end());
	MST.clear();
	MST.resize(V);

	initSets(V);
	for(int i = 0; i < EdgeList.size(); i++)
	{
		pair<int, ii> front = EdgeList[i];
		int u = front.second.first, v = front.second.second;
		int cost = front.first;
		if(!isSameSet(u, v))
		{
			MST[u].push_back(ii(v, cost));
			MST[v].push_back(ii(u, cost));
			unionSet(u, v);
		}
	}
}


int bfs(int start, int destination)
{
	vector<int> dist(V, -1);
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		if(front == destination)
			break;
		TRvi(MST[front], v)
		{
			if(dist[v->first] == -1)
			{
				dist[v->first] = max(dist[front], v->second);
				q.push(v->first);
			}
		}
	}

	return dist[destination]; /* if it is -1 there is no path in MST */
}



int main()
{
	int start, destination, cost;

	int CaseNo = 0;
	while(cin >> V >> E >> Q && V && E && Q)
	{
	CaseNo++;
	EdgeList.clear();
	for(int i = 0; i < E; i++)
	{
		cin >> start >> destination >> cost;
		start--; destination--;
		EdgeList.push_back(make_pair(cost, ii(start, destination)));
	}

	Kruskal();
	if(CaseNo != 1)
		cout << endl;
	printf("Case #%d\n", CaseNo);
	for(int q = 0; q < Q; q++)
	{
		cin >> start >> destination;
		start--; destination--;
		int minimax = bfs(start, destination);
		if(minimax != -1)
			cout << minimax << endl;
		else
			cout << "no path" << endl;
	}
	}
		

	return 0;
}
























