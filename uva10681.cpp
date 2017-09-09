#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;

//vector<vector<int> > graph;
int graph[110][110];
int C, L, src, dest, days;
int memo[110][210];

int go(int curent_city, int days_left)
{
	if(memo[curent_city][days_left] != -1)
		return memo[curent_city][days_left];
	if(days_left == 1)
	{
		if(graph[curent_city][dest] == 1)
			return 1;
		else
			return 0;
	}
	int canGo = 0;
	for(int next_city = 0; next_city < C; next_city++)
	{
		if(next_city != curent_city && graph[curent_city][next_city] == 1)
		{
			if(go(next_city, days_left - 1) == 1)
				canGo = 1;
		}
	}
	return memo[curent_city][days_left] = canGo;
}









int main()
{
	while(true)
	{
		cin >> C >> L;
		if(C == 0 && L == 0)
			break;
		/*graph.clear();
		cout << graph.size() << endl;
		graph.resize(C);
		for(int city = 0; city < C; city++)
		{
			graph[city].resize(C);
			fill(graph[city].begin(), graph[city].end(), 0);
		} */
		memset(graph, 0, sizeof(graph));
		for(int l = 0; l < L; l++)
		{
			cin >> src >> dest;
			graph[src-1][dest-1] = 1; graph[dest-1][src-1] = 1;
		}
	
		memset(memo, -1, sizeof(memo));
		cin >> src >> dest >> days;
		src--; dest--;
		if(days == 0)
		{
			if(src == dest)
				cout << "Yes, Teobaldo can travel." << endl;
			else
				cout << "No, Teobaldo can not travel." << endl;
		}
		else
		{
			int rez = go(src, days);
			if(rez == 1)
				cout << "Yes, Teobaldo can travel." << endl;
			else
				cout << "No, Teobaldo can not travel." << endl;
		}
	}	

	return 0;
}
	










