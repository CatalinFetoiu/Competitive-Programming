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
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)
#define BFS_WHITE -1


int V, E;
vector<pair<int, ii> > EdgeList;
vector<int> pset;
vector<int> maxEdges;
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


bool Kruskal()
{
	sort(EdgeList.begin(), EdgeList.end());
	bool isForest = true;
	initSets(V);
	maxEdges.clear();
	for(int i = 0; i < E; i++)
	{
		pair<int, ii> front = EdgeList[i];
		int u = front.second.first, v = front.second.second;
		int cost = front.first;
		if(!isSameSet(u, v))
			unionSet(u, v);
		else /* a cycle is formed */
		{
			maxEdges.push_back(cost);
			isForest = false;
		}
	}

	return isForest;
}


int main()
{
	int u, v, cost;

	while(cin >> V >> E && V && E)
	{
	EdgeList.clear();
	for(int i = 0; i < E; i++)
	{
		cin >> u >> v >> cost;
		EdgeList.push_back(make_pair(cost, ii(u, v)));
	}

	bool isForest = Kruskal();
	if(!isForest)
	{
		for(int i = 0; i < maxEdges.size(); i++)
		{
			cout << maxEdges[i];
			if(i != maxEdges.size() - 1)
				cout << " ";
		}
		cout << endl;
	}
	else
		cout << "forest" << endl;
	}

	return 0;
}




















