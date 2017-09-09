#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<limits.h>
#include<list>
#include<queue>
#include<map>

using namespace std;

typedef pair<int, int> ii;

#define MAX 100010
#define INF 2000000000
#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)


int V, treeRoot;
vector<vector<int> > tree;
vector<map<ii, int> > dp;
vector<map<ii, int> > height;
vector<ii> EdgeList;

map<ii, int>::iterator access(ii state, string what)
{
	int node = state.first;
	int parent = state.second;
	
	if(what == "dp")
		return dp[node+parent].find(state);
	if(what == "height")
		return height[node+parent].find(state);
}

int diameter(int node, int parent)
{
	//cout << node << " " << parent << endl;
	map<ii, int>::iterator it = access(ii(node, parent), "dp");
	if(it->second != -1)
	{
		return it->second;
	}

	int res = -INF;
	int maxHeight = 0;
	TRvi(tree[node], v)
	{
		int child = *v;
		if(child != parent)
		{
			res = max(res, diameter(child, node));
		}
	}

	map<ii, int>::iterator hit;
	if(res == -INF) /* node is leaf */
	{
		hit = access(ii(node, parent), "height");
		hit->second = 1;
		return 0;
	}
	

	int max1 = -1;
	int max2 = -1;
	TRvi(tree[node], v)
	{
		int child = *v;
		if(child != parent)
		{
			hit = access(ii(child, node), "height");
			
			maxHeight = max(maxHeight, hit->second);
			int num = hit->second;
			if(num > max1)
			{
				max2 = max1;
				max1 = num;
			}
			else if(num > max2)
			{
				max2 = num;
			}
		}
	}

	if(max1 != -1 && max2 != -1)
		res = max(res, (max1 + max2));
	else if(max1 != -1)
		res = max1;
	else
		res = max2;
	hit = access(ii(node, parent), "height");
	hit->second = 1 + maxHeight;

	return it->second = res;
}

void dfs(int node, int parent)
{
	TRvi(tree[node], v)
	{
		int child = *v;
		if(child != parent)
		{
			dfs(child, node);
		}
	}
}

int minimizeDiameter()
{
	int res = INF;
	for(int i = 0; i < EdgeList.size(); i++)
	{
		int d1, d2;
		ii front = EdgeList[i];
		int u = front.first;
		int v = front.second;
		
		d1 = diameter(u, v);
		d2 = diameter(v, u);
		
		int removeEdge = -1;
		removeEdge = max(max(d1, d2), (d1+1)/2 + (d2+1)/2 + 1);
		res = min(res, removeEdge);
	}

	res = min(res, diameter(treeRoot, V));
	
	return res;
}
		
	
			
int main()
{
	FILE* fin = freopen("revolta.in", "r", stdin);
	FILE* fout = freopen("revolta.out", "w", stdout);	

	int start, end;
	int T; cin >> T;
	while(T--) {
	cin >> V;
	tree.clear();
	tree.resize(V);
	EdgeList.clear();

	dp.clear();
	dp.resize(2 * V);
	height.clear();
	height.resize(2 * V);


	//cout << "ok" << endl;
	for(int i = 0; i < (V-1); i++)
	{
		cin >> start >> end;
		tree[start].push_back(end);
		tree[end].push_back(start);
		EdgeList.push_back(ii(start, end));
		
		dp[start+end][ii(start, end)] = -1; /* kind of hashing with maps */
		dp[start+end][ii(end, start)] = -1;
		height[start+end][ii(start, end)] = -1;
		height[start+end][ii(end, start)] = -1;
	}
	treeRoot = 0;
	dfs(treeRoot, -1);
	dp[treeRoot+V][ii(treeRoot, V)] = -1;
	height[treeRoot+V][ii(treeRoot, V)] = -1;

	int c = 0;
	for(int i = 0; i < dp.size(); i++)
	{
		cout << dp[i].size() << endl;
		c += dp[i].size();
	}
	cout << c << flush;	

	cout << minimizeDiameter() << endl;

	/*
	int a, b;
	while(true)
	{
		cin >> a >> b;
		cout << diameter(a, b) << endl;
		cout << height[a+b][ii(a, b)] << endl;
	} */
	
	}

	fclose(fin);
	fclose(fout);
	
	
	return 0;	
}























