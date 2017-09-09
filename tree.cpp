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
#include<unordered_map>

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;

#define MAX 100010
#define INF 2000000000
#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)


int V, treeRoot;
vector<vector<int> > tree;
vector<vector<int> > dp;
vector<vector<int> > dp1;
vector<vector<int> > height;
vector<vector<int> > height1;
vector<ii> EdgeList;

int cantor(int a, int b)
{
	return (((a+b)*(a+b+1))/2 + b) % 100000;
}

int diameter(int node, int parent)
{
	//cout << node << " " << parent << endl;
	if(dp[cc(node, parent)] != -1)
		return dp[cc(node, parent)];

	int res = -INF;
	int maxHeight = 0;
	int child;
	TRvi(tree[node], v)
	{
		child = *v;
		if(child != parent)
		{
			res = max(res, diameter(child, node));
		}
	}

	if(res == -INF) // node is leaf
	{
		dp[cc(node, parent)] = 1;
		return 0;
	}
	

	int max1 = -1;
	int max2 = -1;
	int num;
	TRvi(tree[node], v)
	{
		child = *v;
		if(child != parent)
		{	
			maxHeight = max(maxHeight, height[cc(child, node)]);
			num = height[cc(child, node)];
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
	height[cc(node, parent)] = 1 + maxHeight;

	return dp[cc(node, parent)] = res;
}

void dfs(int node, int parent)
{
	int child;
	TRvi(tree[node], v)
	{
		child = *v;
		if(child != parent)
		{
			dfs(child, node);
		}
	}
}

int minimizeDiameter()
{
	int res = INF;
	int d1, d2, removeEdge;
	int u, v;
	for(int i = 0; i < EdgeList.size(); i++)
	{
		ii front = EdgeList[i];
		u = front.first;
		v = front.second;
		
		d1 = diameter(u, v);
		d2 = diameter(v, u);
		
		removeEdge = -1;
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
	
	scanf("%d", &V);
	tree.clear();
	tree.resize(V);
	EdgeList.clear();

	dp.clear();
	height.clear();


	//cout << "ok" << endl;
	for(int i = 0; i < (V-1); i++)
	{
		scanf("%d%d", &start, &end);
		tree[start].push_back(end);
		tree[end].push_back(start);
		EdgeList.push_back(ii(start, end));
		
		dp[cc(start, end)] = -1;
		dp[cc(end, start)] = -1;
		height[cc(start, end)] = -1;
		height[cc(end, start)] = -1;
	}
	treeRoot = 0;
	//dfs(treeRoot, -1);
	dp[cc(treeRoot, V)] = -1;
	height[cc(treeRoot, V)] = -1;

	cout << minimizeDiameter() << endl;
	
	}

	fclose(fin);
	fclose(fout);
	
	
	return 0;	
}























