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

#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)
#define BFS_WHITE -1

using namespace std;

int N;
vector<vector<int> > AdjList; /* connected graph */
int colour[220];
int curent_colour;

bool bipartite_check()
{
	queue<int> q, empty;
	q.push(0);
	curent_colour = 0;
	colour[0] = curent_colour;
	bool verify = true;
		
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		
		TRvi(AdjList[u], v)
		{
			if(colour[*v] == BFS_WHITE)
			{
				q.push(*v);
				colour[*v] = 1 - colour[u];
			}
			else
			{
				if(colour[*v] == colour[u])
				{
					verify = false;
					break;
				}
			}
		}
	}

	return verify;
}


int main()
{
	int l;
	int src, dest;	

	while(true)
	{
		cin >> N;
		if(N == 0)
			break;

		cin >> l;
		AdjList.clear();
		memset(colour, BFS_WHITE, sizeof(colour));
		AdjList.resize(N);
	
		for(int i = 0; i < l; i++)
		{
			cin >> src >> dest;
			AdjList[src].push_back(dest);
			AdjList[dest].push_back(src);
		}
	
		int verify = bipartite_check();
		if(verify)
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;
	}
	return 0;
}







	














