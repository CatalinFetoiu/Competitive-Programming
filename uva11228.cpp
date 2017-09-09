#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <list>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> ii;

#define TRvi(c, it) \
	for(vector<pair<double, ii> >::iterator it = c.begin(); it != c.end(); it++)
#define BFS_WHITE -1

int N, insideCountry;
vector<ii> cities;
vector<pair<double, ii> > EdgeList;
int numDisjointSets;
double roadCost,railroadCost;

vector<int> pset; /* union-find disjoint sets */

double dist(ii a, ii b)
{
	int x1 = a.first, y1 = a.second;
	int x2 = b.first, y2 = b.second;
	
	return hypot(x1-x2, y1-y2);
}

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
	initSets(N);
	EdgeList.clear();
	for(int src = 0; src < N; src++)
	{
		for(int dest = src+1; dest < N; dest++)
		{
			EdgeList.push_back(make_pair(dist(cities[src], cities[dest]), ii(src, dest)));
		}
	}
	sort(EdgeList.begin(), EdgeList.end());
	
	roadCost = 0; railroadCost = 0;
	int E = EdgeList.size();
	for(int i = 0; i < E; i++)
	{
		pair<double, ii> front = EdgeList[i];
		int u = front.second.first, v = front.second.second;
		double cost = front.first;
		if(!isSameSet(u, v))
		{
			if(cost > insideCountry)
				railroadCost += cost;
			else
				roadCost += cost;
			unionSet(u, v);
		}
	}
}


int main()
{
	int numCountries;
	int x, y;

	int Cases; cin >> Cases;
	for(int CaseNo = 1; CaseNo <= Cases; CaseNo++)
	{
	cin >> N >> insideCountry;
	cities.clear();
	cities.resize(N);
	
	for(int i = 0; i < N; i++)
	{
		cin >> x >> y;
		cities[i].first = x;
		cities[i].second = y;
	}

	initSets(N);
	for(int u = 0; u < N; u++)
	{
		for(int v = u+1; v < N; v++)
		{
			if(dist(cities[u], cities[v]) <= insideCountry)
				unionSet(u, v);
		}
	}
	numCountries = numDisjointSets;

	Kruskal();
	printf("Case #%d: %d %d %d\n", CaseNo, numCountries, (int)(roadCost + 0.5), (int)(railroadCost + 0.5));
	}

	return 0;
}
		
		

















