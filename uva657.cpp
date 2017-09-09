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

int W, H;
vector<string> image;
int dfs[55][55];
int dfs_dice[55][55];

vector<pair<int,int> > neighbours(int row, int col)
{
	vector<pair<int,int> > rez;
	rez.push_back(make_pair(row-1, col));
	rez.push_back(make_pair(row, col-1));
	rez.push_back(make_pair(row, col+1));
	rez.push_back(make_pair(row+1, col));
	
	return rez;
}

void flood_dice(int row, int col)
{
	dfs_dice[row][col] = 1;
	vector<pair<int,int> > rez = neighbours(row, col);

	for(int i = 0; i < rez.size(); i++)
	{
		if(rez[i].first >= 0 && rez[i].second >= 0 && rez[i].first < H && rez[i].second < W)
		{
			if(dfs_dice[rez[i].first][rez[i].second] == -1 && image[rez[i].first][rez[i].second] == 'X')
				flood_dice(rez[i].first, rez[i].second);
		}
	}
}

int flood_fill(int row, int col)
{	
	if(image[row][col] == '.')
		return 0;
	
	vector<pair<int,int> > rez = neighbours(row, col);
	int dices = 0;
	if(image[row][col] == 'X' && dfs_dice[row][col] == -1)
	{	
		dices += 1;
		flood_dice(row, col);
	}
	
	dfs[row][col] = 1;

	for(int i = 0; i < rez.size(); i++)
	{
		if(rez[i].first >= 0 && rez[i].second >= 0 && rez[i].first < H && rez[i].second < W)
		{
			if(dfs[rez[i].first][rez[i].second] == -1)
			{
				if(image[rez[i].first][rez[i].second] != '.')
					dices += flood_fill(rez[i].first, rez[i].second);
			}
		}
	}
	return dices; /* number of dices on connected component */
}






int main()
{
	vector<int> dices;

	int tc = 0;
	while(true)
	{
		cin >> W >> H;
		if(W == 0 && H == 0)
			break;

		tc++;
		dices.clear();
		image.clear();
		image.resize(H);
		for(int i = 0; i < image.size(); i++)
			cin >> image[i];
	
		memset(dfs, -1, sizeof(dfs));
		memset(dfs_dice, -1, sizeof(dfs));
	
		for(int row = 0; row < H; row++)
		{
			for(int col = 0; col < W; col++)
			{
				if(dfs[row][col] == -1)
				{
					int nr = flood_fill(row, col);
					if(nr != 0)
						dices.push_back(nr);
				}
			}
		}
		std::sort(dices.begin(), dices.end());
	
		cout << "Throw " << tc << endl;
		for(int i = 0; i < dices.size(); i++)
		{
			if(i != dices.size() - 1)
				cout << dices[i] << " ";
			else
				cout << dices[i] << endl;
		}
		cout << endl;
	}

	return 0;
}
	







