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

#define neighbours 4
#define BFS_WHITE -1

using namespace std;

int dist[1010][1010];
vector<vector<int> > map;
int R, C;
pair<int, int> dest;
int xAxis[] = {0, -1, 1, 0};
int yAxis[] = {-1, 0, 0, 1};

void search(pair<int, int> src)
{
	queue<pair<int, int> > q;
	q.push(src);
	dist[src.first][src.second] = 0;
	
	while(!q.empty() && q.front() != dest)
	{
		pair<int, int> pos = q.front();
		q.pop();
		int row = pos.first;
		int col = pos.second;
		for(int i = 0; i < neighbours; i++)
		{
			if(0 <= row + xAxis[i] && row + xAxis[i] < R)
			{
				if(0 <= col + yAxis[i] && col + yAxis[i] < C)
				{
					if(map[row+xAxis[i]][col+yAxis[i]] == 1 && 
						dist[row+xAxis[i]][col+yAxis[i]] == BFS_WHITE) /* not a mine */
					{
						dist[row+xAxis[i]][col+yAxis[i]] = dist[row][col] + 1;
						q.push(make_pair(row+xAxis[i], col+yAxis[i]));
					}
				}
			}
		}
	}
}


int main()
{
	int mine_rows, curent_row, num_mines, mine_col;
	int r1, c1, r2, c2;
	pair<int, int> src;

	while(true)
	{
		cin >> R >> C;
		if(R == 0 && C == 0)
			break;

		map.clear();
		map.resize(R);
		for(int row = 0; row < R; row++)
			map[row].resize(C, 1);
		cin >> mine_rows;
		for(int i = 0; i < mine_rows; i++)
		{
			cin >> curent_row;
			cin >> num_mines;
			for(int j = 0; j < num_mines; j++)
			{
				cin >> mine_col;
				map[curent_row][mine_col] = 0;
			}
		}
		cin >> r1 >> c1;
		src = make_pair(r1, c1);
		cin >> r2 >> c2;
		dest = make_pair(r2, c2);
	
		memset(dist, BFS_WHITE, sizeof(dist));
		search(src);
		
		cout << dist[r2][c2] << endl;
	}
		
	return 0;
}
		














	















	



