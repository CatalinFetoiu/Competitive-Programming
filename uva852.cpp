#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <list>
#define N 9

using namespace std;

int dfs[55][55];
vector<string> go;

vector<pair<int,int> > neighbours(int row, int col)
{
	vector<pair<int,int> > rez;
	rez.push_back(make_pair(row-1, col));
	rez.push_back(make_pair(row, col-1));
	rez.push_back(make_pair(row, col+1));
	rez.push_back(make_pair(row+1, col));
	
	return rez;
}

void flood_fill(int row, int col, int color)
{
	dfs[row][col] = color;
	vector<pair<int,int> > rez = neighbours(row, col);

	for(int i = 0; i < rez.size(); i++)
	{
		if(rez[i].first >= 0 && rez[i].second >= 0 && rez[i].first < N && rez[i].second < N)
		{
			if(dfs[rez[i].first][rez[i].second] == -1 && go[rez[i].first][rez[i].second] == go[row][col])
				flood_fill(rez[i].first, rez[i].second, color);
		}
	}
}


int main()
{
	vector<int> components;
	vector<int> surface;
	vector<pair<int,int> > rez;
	
	int T; cin >> T;
	while(T--) {
	
	components.clear();
	surface.clear();
	go.resize(9);
	for(int i = 0; i < go.size(); i++)
		cin >> go[i];

	memset(dfs, -1, sizeof(dfs));

	/* finding connected components */
	int componentNumber = 0;
	int black = 0, white = 0;
	for(int row = 0; row < go.size(); row++)
	{
		for(int col = 0; col < go.size(); col++)
		{
			if(go[row][col] == '.' && dfs[row][col] == -1)
			{
				componentNumber++;	
				flood_fill(row, col, componentNumber);
			}
			if(go[row][col] == 'X')
				black++;
			if(go[row][col] == 'O')
				white++;
		}
	}

	components.resize(componentNumber+1, 0);
	surface.resize(componentNumber+1, 0);

	for(int row = 0; row < go.size(); row++)
	{
		for(int col = 0; col < go.size(); col++)
		{
			if(go[row][col] == '.')
			{
				components[dfs[row][col]]++;
				rez = neighbours(row, col);
				for(int i = 0; i < rez.size(); i++)
				{
					if(rez[i].first >= 0 && rez[i].second >= 0 && rez[i].first < N && rez[i].second < N)
					{
						if(go[rez[i].first][rez[i].second] == 'X')
						{
							if(surface[dfs[row][col]] == 0)
								surface[dfs[row][col]] = 1; /* surface circled by both black and white */
							if(surface[dfs[row][col]] == 2)
								surface[dfs[row][col]] = -1;
						}
						if(go[rez[i].first][rez[i].second] == 'O')
						{
							if(surface[dfs[row][col]] == 0)
								surface[dfs[row][col]] = 2; /* surface circled by both black and white */
							if(surface[dfs[row][col]] == 1)
								surface[dfs[row][col]] = -1;
						}
					}
				}
			}
		}
	}
	for(int i = 1; i <= componentNumber; i++)
	{
		if(surface[i] != -1)
		{
			if(surface[i] == 1)
				black += components[i];
			if(surface[i] == 2)
				white += components[i];
		}
	}
	cout << "Black " << black << " " << "White " << white << endl;
	
	}

		
	return 0;
}
			
	







