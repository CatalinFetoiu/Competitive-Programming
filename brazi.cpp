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
#include<bitset>
#include<map>
#include<unordered_map>

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;

#define Max 3100
#define INF 2000000000

void generateCode(vector<vector<int> > tree, int root, string& code)
{
	if(tree[root][0] != -1)
	{
		code += "0";
		generateCode(tree, tree[root][0], code);
	}
	if(tree[root][1] != -1)
	{
		code += "1";
		generateCode(tree, tree[root][1], code);
	}
	code += "2";
}
	

int main()
{	
	FILE* fin = freopen("brazi.in", "r", stdin);
	FILE* fout = freopen("brazi.out", "w", stdout);

	int N;
	int node, child, position;
	int root;
	unordered_map<string, int> hash;

	int T; scanf("%d", &T);
	vector<string> codes(T);

	for(int k = 0; k < T; k++) {

	scanf("%d", &N);
	vector<vector<int> > tree(N+1, vector<int>(2, -1));

	vector<int> visited(N+1, 1);
	for(int i = 0; i < N - 1; i++)
	{
		scanf("%d%d%d", &node, &child, &position);
		tree[node][position] = child;
		visited[child] = 0;
	}
	for(int i = 1; i <= N; i++)
	{
		if(visited[i] == 1)
		{
			root = i;
			break;
		}
	}

	generateCode(tree, root, codes[k]);
	hash[codes[k]] = 0;
	
	}

	for(int i = 0; i < T; i++)
	{
		printf("%d\n", hash[codes[i]]);
		hash[codes[i]]++;
	}

	fclose(fin);
	fclose(fout);
	
	return 0;
}
























