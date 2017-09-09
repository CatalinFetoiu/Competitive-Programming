#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;

int N;
int dfs[220][220];
vector<string> table;

vector<pair<int,int> > neighbours(int row, int col)
{
	vector<pair<int,int> > rez;
	rez.push_back(make_pair(row-1, col-1));
	rez.push_back(make_pair(row-1, col));
	rez.push_back(make_pair(row, col-1));
	rez.push_back(make_pair(row, col+1));
	rez.push_back(make_pair(row+1, col));
	rez.push_back(make_pair(row+1, col+1));
	
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
			/* same color in connected components */
			if(dfs[rez[i].first][rez[i].second] == -1 && table[row][col] == table[rez[i].first][rez[i].second])
				flood_fill(rez[i].first, rez[i].second, color);
		}
	}
}




int main()
{
	int tc = 0;
	while(true)
	{
		cin >> N;
		if(N == 0)
			break;

		tc++;
		table.clear();
		table.resize(N);
		for(int i = 0; i < table.size(); i++)
			cin >> table[i];
	
		memset(dfs, -1, sizeof(dfs));
		//dfs + flood fill
		int componentColor = 0;
		for(int row = 0; row < N; row++)
		{
			for(int col = 0; col < N; col++)
			{
				if(dfs[row][col] == -1)
				{
					componentColor++;
					flood_fill(row, col, componentColor);
				}
			}
		}
	
		bool blackWins = false;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				//if same color and same connected component
				if(table[0][i] == table[N-1][j] && table[0][i] == 'b' &&  dfs[0][i] == dfs[N-1][j])
				{
					blackWins = true;
					break;
				}
			}
		}
	
		
		/*	
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
				cout << dfs[i][j] << " ";
			cout << "gaga" << endl;
		} */
	
		if(blackWins)
			cout << tc << " B" << endl;
		else
			cout << tc << " W" << endl;
	}

	return 0;
}




