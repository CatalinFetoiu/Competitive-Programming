#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <list>
#include <sstream>
#include <queue>
#include <map>

#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)
#define DFS_WHITE -1
#define INF 20000000

using namespace std;

int N;
int dp[220][220];
int visited[220];
vector<int> numChildren;
vector<int> inDegree;
map<string, int> mi;
vector<vector<int> > tree; //E = V-1
vector<int> cost;
vector<int> topoSort;

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

int dfsTopologicalSort(int node)
{
	visited[node] = 1;
	int sum = 0;
	TRvi(tree[node], v)
	{
		if(visited[*v] == DFS_WHITE)
			sum += dfsTopologicalSort(*v);
	}
	
	topoSort.push_back(node);
	return numChildren[node] = 1 + sum;
}

void FullTopologicalSort()
{
	for(int node = 0; node < tree.size(); node++)
	{
		if(inDegree[node] == 0)
			dfsTopologicalSort(node);
	}
	
	reverse(topoSort.begin(), topoSort.end());
}
		
int min_cost(int sortIndex, int countriesNeeded)
{
	if(dp[sortIndex][countriesNeeded] != -1)
		return dp[sortIndex][countriesNeeded];
	if(sortIndex >= N)
	{
		if(countriesNeeded <= 0)
			return 0;
		else
			return INF;
	}
	if(countriesNeeded <= 0)
		return 0;
	if(N - sortIndex < countriesNeeded)
		return INF;
	
	int best_cost = min_cost(sortIndex + numChildren[topoSort[sortIndex]], 
			countriesNeeded - numChildren[topoSort[sortIndex]]) + cost[topoSort[sortIndex]];
	
	int second_cost = min_cost(sortIndex + 1, countriesNeeded);

	best_cost = min(best_cost, second_cost);

	return dp[sortIndex][countriesNeeded] = best_cost;
}

	
	






int main()
{
	int M, treeRoot;
	string country1, country2;
	string line;
	int c;
	
	while(true)
	{
		getline(cin, line);
		if(line.length() == 1)
			break;
			
		istringstream is(line);
		is >> N >> M;
		
		tree.clear();
		tree.resize(N);
		topoSort.clear();
		numChildren.clear();
		numChildren.resize(N);
		inDegree.clear();
		inDegree.resize(N, 0);
		
		mi.clear();
		memset(dp, -1, sizeof(dp));
		memset(visited, DFS_WHITE, sizeof(visited));
		cost.clear();
		cost.resize(N);
		
		//getline(cin, line);  /* construct tree */
		for(int i = 0; i < N; i++)
		{
			getline(cin, line);
			istringstream is(line);
			is >> country1 >> c;
			cost[get_id(country1)] = c;
			int u = get_id(country1);
			while(is >> country2)
			{
				tree[u].push_back(get_id(country2));
				inDegree[get_id(country2)]++;
			}
		}
	
		FullTopologicalSort();
		cout << min_cost(0, M) << endl;
	}

	return 0;
}
























