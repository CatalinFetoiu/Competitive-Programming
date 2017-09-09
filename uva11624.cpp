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

using namespace std;

// #define log

struct Node
{
	int row;
	int col;
	char state;
	Node(int x, int y, char s)
	{
		row = x;
		col = y;
		state = s;
	}
};

int R, C;
vector<string> maze;
int dist[1010][1010];
bool visitedByFire[1010][1010];
queue<Node > q;
int xAxis[] = {0, -1, 1, 0};
int yAxis[] = {-1, 0, 0, 1};

bool inBound(int row, int col)
{
	if(0 <= row && row < R)
	{
		if(0 <= col && col < C)
			return true;
	}
	return false;
}

bool onEdge(int row, int col)
{
	if(row == 0 || row == R-1 || col == 0 || col == C-1)
		return true;
	return false;
}


int escape(Node joe)
{
	q.push(joe);
	dist[joe.row][joe.col] = 0;
	
	while(!q.empty())
	{	
		Node cell = q.front();
		q.pop();
		int row = cell.row;
		int col = cell.col;
		int cost = dist[row][col];
		char state = cell.state;
		
		if(state == 'F')
		{
			for(int i = 0; i < 4; i++)
			{
				if(inBound(row+xAxis[i], col+yAxis[i]) && !visitedByFire[row+xAxis[i]][col+yAxis[i]])
				{
					if(maze[row+xAxis[i]][col+yAxis[i]] != '#')
					{
						visitedByFire[row+xAxis[i]][col+yAxis[i]] = true;
						q.push(Node(row+xAxis[i], col+yAxis[i], 'F'));
						maze[row+xAxis[i]][col+yAxis[i]] = 'F';
					}
				}
			}
		}
		if(state == 'J') /* joe can reach position after fire has spread */
		{
			#ifdef log
			for(int i = 0; i < R; i++)
			{
				for(int j = 0; j < C; j++)
					cout << maze[i][j] << " ";
				cout << endl;
			}
			#endif
			for(int i = 0; i < 4; i++)
			{
				int next_row = row + xAxis[i];
				int next_col = col + yAxis[i];
				
				if(inBound(next_row, next_col) && maze[next_row][next_col] == '.'
				 	&& dist[next_row][next_col] == -1)
				{
					if(onEdge(next_row, next_col))
						return cost + 1;
					//cout << next_row << " " << next_col << endl;
					dist[next_row][next_col] = cost + 1;
					q.push(Node(next_row, next_col, 'J'));
				}
			}
		}
	}

	return -1;
}



int main()
{
	queue<Node> empty;
	
	int tc; cin >> tc;
	while(tc--)
	{	
		q = empty;
		cin >> R >> C;
		maze.clear();
		maze.resize(R);
		for(int row = 0; row < R; row++)
			cin >> maze[row];
		memset(dist, -1, sizeof(dist));
		memset(visitedByFire, false, sizeof(visitedByFire));
	
		int xStart;
		int yStart;
		for(int row = 0; row < R; row++)
		{
			for(int col = 0; col < C; col++)
			{
				if(maze[row][col] == 'J')
				{
					xStart = row;
					yStart = col;
				}
				if(maze[row][col] == 'F')
				{
					visitedByFire[row][col] = true;
					q.push(Node(row, col, 'F'));
				}
			}
		}
	
		if(onEdge(xStart, yStart))
			cout << "1" << endl;
		else
		{
			int rez = escape(Node(xStart, yStart, 'J'));
			if(rez == -1)
				cout << "IMPOSSIBLE" << endl;
			else
				cout << rez + 1 << endl;
		}
	}
		
	return 0;
}
		
	
	











