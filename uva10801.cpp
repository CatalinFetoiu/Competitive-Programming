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
#include <sstream>

using namespace std;

typedef pair<int, int> ii;

#define TRvii(c, it) \
	for(vector<ii>::iterator it = c.begin(); it != c.end(); it++)
#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)
#define INF 1000000

vector<int> dist;
vector<vector<int> > lifts; /* at which level the lift goes + cost */
vector<vector<int> > levels; /* which lifts go at level */
priority_queue<ii, vector<ii>, greater<ii> > pq; /* heap :D */
vector<int> one_level_cost;

void dijkstra(int src)
{
	pq.push(make_pair(0, src));
	dist[src] = 0;
	while(!pq.empty())
	{
		ii front = pq.top();
		pq.pop();
		int d = front.first, u = front.second; /* u is level */
		if(d == dist[u])
		{	
			TRvi(levels[u], w)
			{
				//cout << *w << endl;
				TRvi(lifts[*w], v)
				{
					if(dist[u] + 60 + one_level_cost[*w] * abs(u-(*v)) < dist[*v])
					{
						dist[*v] = dist[u] + 60 + one_level_cost[*w] * abs(u-(*v));
						pq.push(make_pair(dist[*v], *v));
					}
				}
			}
		}
	}
}


int main()
{
	int N, K;
	priority_queue<ii, vector<ii>, greater<ii> > empty;
	levels.resize(100);
	one_level_cost.resize(100);

	while(true)
	{
		lifts.clear();
		for(int i = 0; i < levels.size(); i++)
			levels[i].clear();
		pq = empty;
		dist.clear();
		dist.resize(100, INF);
		
		cin >> N >> K; K;
		if(cin.eof())
			break;
		//cout << N << endl;
		lifts.resize(N);
		for(int i = 0; i < N; i++)
			cin >> one_level_cost[i];
		string line;
		getline(cin, line);
		int floor;
	
		for(int lift = 0; lift < N; lift++)
		{
			getline(cin, line);
			istringstream is(line);
			while(is >> floor)
			{
				//floor--;
				lifts[lift].push_back(floor);
				levels[floor].push_back(lift);
			}
		}
	
		dijkstra(0);
		if(K == 0)
			cout << "0" << endl;
		else if(dist[K] == INF)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << dist[K] - 60 << endl;
	}

	return 0;
}
	
	
	
















