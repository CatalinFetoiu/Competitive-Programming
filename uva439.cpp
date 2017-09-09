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

#define table_size 8
#define BFS_WHITE -1

using namespace std;

int dist[20][20]; /* BFS layer index */
queue<pair<int, int> > q;
int row[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int col[] = {-2, -2, -1, -1, 1, 1, 2, 2};

void bfs(pair<int, int> knight)
{
	queue<pair<int, int> > empty;
	q = empty;
	dist[knight.first][knight.second] = 0;
	q.push(knight);
	while(!q.empty())
	{
		pair<int, int> top = q.front();
		int l = top.first, c = top.second;
		q.pop();
		for(int i = 0; i < 8; i++)
		{
			if(1 <= l + row[i] && l + row[i] <= table_size)
			{
				if(1 <= c + col[i] && c + col[i] <= table_size)
				{
					if(dist[l+row[i]][c+col[i]] == BFS_WHITE)
					{
						dist[l+row[i]][c+col[i]] = dist[l][c] + 1;
						q.push(make_pair(l+row[i], c+col[i]));
					}
				}
			}
		}
	}
}


int main()
{
	string src, dest;
	int r1, r2, c1, c2;
	while(true)
	{
		cin >> src;
		if(cin.eof())
			break;
		cin >> dest;
		r1 = src[0] - 'a' + 1; c1 = src[1] - '0';
		r2 = dest[0] - 'a' + 1; c2 = dest[1] - '0';
	
		memset(dist, BFS_WHITE, sizeof(dist));
		bfs(make_pair(r1, c1));
		int rez = dist[r2][c2] - dist[r1][c1];
		cout << "To get from " << src << " to " << dest << " takes " << rez << " knight moves." << endl;
	}

	return 0;
}
	
				
		









