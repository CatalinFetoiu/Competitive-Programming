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
#define directions 8

using namespace std;


int R, C, N;
int memo[1 << 16][20];
int xAxis[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int yAxis[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int pos(int x, int y) //turn 2D position into linear position in bitmask
{
	return R * x + y;
}

bool checkEdges(int x, int y)
{
	return 0 <= x && x < R && 0 <= y && y < C;
}

int blobs(int bitmask, int jump)
{
	if(memo[bitmask][jump] != -1)
		return memo[bitmask][jump];
	if(!(bitmask & (bitmask - 1))) //bitmask is power of 2 means only one blob
	{
		if(jump == 0)
			return 1;
		else
			return 0;
	}  //not necessary but good pruning 
	
	if(jump == 0)
	{
		if(!(bitmask & (bitmask - 1)))
			return 1;
		else
			return 0;
	}
	
	int combinations = 0;
	for(int x = 0; x < R; x++)
	{
		for(int y = 0; y < C; y++)
		{
			if(bitmask & (1 << pos(x, y))) //if there is a blob on (x,y)
			{
				for(int i = 0; i < directions; i++)
				{
					int next_x = x + xAxis[i];
					int next_y = y + yAxis[i];
					int jump_x = x + 2 * xAxis[i];
					int jump_y = y + 2 * yAxis[i];
					
					//if blob on adjacent position
					if(checkEdges(next_x, next_y) && (bitmask & (1 << pos(next_x, next_y))))
					{
						//if jump cell is empty
						if(checkEdges(jump_x, jump_y) && !(bitmask & (1 << pos(jump_x, jump_y))))
						{
							int bm = bitmask;
							bm |= (1 << pos(jump_x, jump_y));
							bm &= ~(1 << pos(x, y));
							bm &= ~(1 << pos(next_x, next_y));
							combinations += blobs(bm, jump - 1);
						}
					}
				}
			}
		}
	}

	return memo[bitmask][jump] = combinations;
}


int main()
{
	int bitmask, x, y;
	
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++)
	{
		cin >> R >> C >> N;
		bitmask = 0;
		for(int i = 0; i < N; i++)
		{
			cin >> x >> y;
			x--; y--;
			bitmask |= (1 << pos(x, y));
		}
	
		memset(memo, -1, sizeof(memo));
		cout << "Case " << tc << ": " << blobs(bitmask, N-1) << endl;
	}
	
	return 0;
}










						


















