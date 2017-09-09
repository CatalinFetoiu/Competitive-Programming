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

#define max 250
#define INF 2000000000
#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)

int N, M;
int res[max][max];
vector<int> p; /* BFS spanning tree */
int f;
vector<vector<int> > AdjList;
vector<int> tribute;

int Union(int i)
{
	return N + i;
}

void augment(int v, int s, int minEdge)
{
	if(v == s)
	{
		f = minEdge;
		return;
	}
	else if(p[v] != -1)
	{
		augment(p[v], s, min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

int EdmondsKarp(int s, int t) /* returns max flow */
{
	int mf = 0;
	while(true)
	{
		f = 0;
		p.assign(max, -1);
		vector<int> dist(max, INF);
		queue<int> q;
		q.push(s);
		dist[s] = 0;
		while(!q.empty())  /* BFS to find shortest positive path */
		{
			int u = q.front();
			q.pop();
			if(u == t)
				break;
			TRvi(AdjList[u], v)
			{
				int next = *v;
				if(dist[next] == INF && res[u][next] > 0)
				{
					q.push(next);
					p[next] = u;
					dist[next] = dist[u] + 1;
				}
			}
		}

		augment(t, s, INF);
		if(f == 0)
			break;
		mf += f;
	}

	return mf;
}


int main()
{
	FILE* fin = freopen("tribut.in", "r", stdin);
	FILE* fout = freopen("tribut.out", "w", stdout);
	
	int T; cin >> T;
	while(T--) {
	cin >> N >> M;
	int countryTribute, unionTribute, unionSize;
	memset(res, -1, sizeof(res));
	AdjList.clear();
	AdjList.resize(N+M+2);
	tribute.clear();
	tribute.resize(N+1);
	
	int s = 0; int t = N + M + 1;
	for(int u = 1; u <= N; u++)
	{
		cin >> countryTribute;
		AdjList[s].push_back(u);
		AdjList[u].push_back(s);
		res[s][u] = countryTribute; /* each country can pay multiple mini-tributes */
		res[u][s] = res[s][u];
		tribute[u] = countryTribute;
	}

	for(int un = 1; un <= M; un++)
	{
		cin >> unionSize >> unionTribute;
		int country;
		for(int i = 0; i < unionSize; i++)
		{
			cin >> country;
			AdjList[country].push_back(Union(un));
			AdjList[Union(un)].push_back(country);
			
			res[country][Union(un)] = INF;
			res[Union(un)][country] = 0;

		}
		AdjList[Union(un)].push_back(t);
		AdjList[t].push_back(Union(un));
		res[Union(un)][t] = unionTribute;
		res[t][Union(un)] = unionTribute;
	}

	
	int mf = EdmondsKarp(s, t);
	cout << mf << endl;

	}

	fclose(fin);
	fclose(fout);

	return 0;
}






	
			
	 
		




 
		












		
			












































			





