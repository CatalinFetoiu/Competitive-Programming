#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
//#include <algorithm>
#include <limits.h>
#include <list>
#include <queue>
#include <map>

#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)
#define BFS_WHITE -1

using namespace std;

int dp[220][10];
bool unique[220][10];
map<string, int> mi;
vector<vector<int> > tree; //E = V-1

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


int max_set(int Node, int chosen)
{
	if(dp[Node][chosen] != -1)
		return dp[Node][chosen];
	if(tree[Node].size() == 0) //node is a leaf
		return dp[Node][chosen] = chosen;
	
	if(chosen == 0)
	{
		int sum = 0;
		TRvi(tree[Node], children)
		{
			int res1 = max_set(*children, 0);
			int res2 = max_set(*children, 1);
			if(res1 > res2)
			{
				sum += res1;
				unique[Node][chosen] &= unique[*children][0];
			}
			if(res1 < res2)
			{
				sum += res2;
				unique[Node][chosen] &= unique[*children][1];
			}
			if(res1 == res2)
			{
				sum += res1;
				unique[Node][chosen] = false;
			}
		}
		return dp[Node][chosen] = sum;
	}
	if(chosen == 1)
	{
		int sum = 0;
		TRvi(tree[Node], children)
		{
			sum += max_set(*children, 0);
			unique[Node][chosen] &= unique[*children][0];
		}
		return dp[Node][chosen] = 1 + sum;
	}
}
		

int main()
{
	int N, treeRoot;
	string name, boss;
	
	while(true)
	{
		cin >> N;
		if(N == 0)
			break;
		
		tree.clear();
		tree.resize(N);
		mi.clear();
		memset(dp, -1, sizeof(dp));
		memset(unique, true, sizeof(unique));
		
		cin >> boss;
		treeRoot = get_id(boss);
	
		for(int i = 0; i < N-1; i++)
		{
			cin >> name >> boss;
			tree[get_id(boss)].push_back(get_id(name));
		}
		
		int res1 = max_set(treeRoot, 0);
		int res2 = max_set(treeRoot, 1);
		if(res1 == res2)
			printf("%d No\n", res1);
		if(res1 > res2)
			printf("%d %s\n", res1, (unique[treeRoot][0]) ? "Yes" : "No");
		if(res1 < res2)
			printf("%d %s\n", res2, (unique[treeRoot][1]) ? "Yes" : "No");
	}
	

	return 0;
}















