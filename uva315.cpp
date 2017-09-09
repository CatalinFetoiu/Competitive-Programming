#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <list>

#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)
#define DFS_WHITE -1

using namespace std;

int dfs_num[110];
int dfs_low[110];
int dfs_parent[110];
vector<vector<int> > AdjList;
bool articulation_vertex[110];
int dfsCounter, dfsRoot, rootChildren;

void articulationPoints(int u)
{
	dfs_low[u] = dfs_num[u] = dfsCounter++;
	TRvi(AdjList[u], v)
	{
		if(dfs_num[*v] == DFS_WHITE)
		{
			dfs_parent[*v] = u;
			if(u == dfsRoot)
				rootChildren++;
			articulationPoints(*v);
			if(dfs_low[*v] >= dfs_num[u])
				articulation_vertex[u] = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[*v]);
		}
		else
		{
			if(*v != dfs_parent[u])
				dfs_low[u] = min(dfs_low[u], dfs_num[*v]);
		}
	}
}








int main()
{
	int N, src, dest;

	while(true)
	{
		/* read input */
		cin >> N;
		if(N == 0)
			break;
		string line;
		getline(cin, line); //to consume the end line after N
	
		AdjList.clear();
		AdjList.resize(N);
		while(true)
		{
			getline(cin, line);
			istringstream is(line);
			is >> src;
			if(src == 0)
				break;
			while(is >> dest)
			{
				AdjList[src-1].push_back(dest-1);
				AdjList[dest-1].push_back(src-1);
			}
		}
	
		dfsCounter = 0;
		memset(dfs_num, DFS_WHITE, sizeof(dfs_num));
		memset(articulation_vertex, false, sizeof(articulation_vertex));
		for(int u = 0; u < N; u++)
		{
			if(dfs_num[u] == DFS_WHITE)
			{
				dfsRoot = u;
				rootChildren = 0;
				articulationPoints(u);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		int rez = 0;
		for(int u = 0; u < N; u++)
		{
			if(articulation_vertex[u])
				rez++;
		}
		cout << rez << endl;
	}
	
	return 0;		
}






	

