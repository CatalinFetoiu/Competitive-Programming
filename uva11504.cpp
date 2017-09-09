#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <list>
#include <stack>

#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)
#define DFS_WHITE -1
#define max 100000

using namespace std;

int dfs_num[max+100];
int dfs_low[max+100];
int SCC_parent[max+100];
int roots[max+100];
vector<vector<int> > AdjList;
int dfsCounter, numComponents, dfsRoot;
stack<int> st;
bool in_stack[max+100];


void tarjanSCC(int u)
{
	dfs_low[u] = dfs_num[u] = dfsCounter++;
	st.push(u);
	in_stack[u] = true;
	TRvi(AdjList[u], v)
	{
		if(dfs_num[*v] == DFS_WHITE)
			tarjanSCC(*v);
		if(in_stack[*v])
			dfs_low[u] = min(dfs_low[u], dfs_low[*v]);
	}
	if(dfs_low[u] == dfs_num[u] && u == dfsRoot) // root of connected tree
	{
		numComponents++;
		while(!st.empty() && st.top() != u)
		{
			in_stack[st.top()] = false;
			SCC_parent[st.top()] = u;
			st.pop();
		}
		SCC_parent[st.top()] = u;
		in_stack[st.top()] = false; // vertex u
		st.pop();
	}
}

/*
void flood_fill(int u)
{
	dfs_num[u] = 1;
	TRvi(AdjList[u], v)
	{
		if(dfs_num[*v] == DFS_WHITE)
			flood_fill(*v);
	}
} */


int main()
{
	ios_base::sync_with_stdio(false);
	int m, n;
	int src, dest;
	stack<int> empty;
	int T; cin >> T;
	
	while(T--) {
	
	cin >> n >> m;
	AdjList.clear();
	AdjList.resize(n);
	for(int i = 0; i < m; i++)
	{
		cin >> src >> dest;
		AdjList[src-1].push_back(dest-1);
		//AdjList[dest-1].push_back(src-1);
	}

	memset(dfs_num, DFS_WHITE, sizeof(dfs_num));
	memset(in_stack, false, sizeof(in_stack));
	memset(roots, 0, sizeof(roots));
	st = empty;
	dfsCounter = 0; numComponents = 0;
	
	for(int u = 0; u < n; u++)
	{
		if(dfs_num[u] == DFS_WHITE)
			tarjanSCC(u);
	}
	for(int u = 0; u < n; u++)
		roots[SCC_parent[u]] = 1;
	for(int u = 0; u < n; u++)
	{
		TRvi(AdjList[u], v)
		{
			if(SCC_parent[*v] != SCC_parent[u])
				roots[SCC_parent[*v]] = 0;
		}
	}
	for(int u = 0; u < n; u++)
		numComponents += roots[u];
	
	cout << numComponents << endl;


	}

	return 0;
}
	














