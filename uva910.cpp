#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;

int N;
vector<vector<int> > graph;
bool winning_pos[30];
int memo[30][35];

int ways(int curent_pos, int moves_left)
{
	if(memo[curent_pos][moves_left] != -1)
		return memo[curent_pos][moves_left];
	if(moves_left == 0)
	{
		if(winning_pos[curent_pos])
			return 1;
		else
			return 0;
	}
	return memo[curent_pos][moves_left] = ways(graph[curent_pos][0], moves_left - 1)
			+ ways(graph[curent_pos][1], moves_left - 1);
}





int main()
{
	while(true)
	{
		cin >> N;
		if(cin.eof())
			break;	

		graph.clear();
		graph.resize(N);
		for(int pos = 0; pos < N; pos++)
		{
			char letter; cin >> letter;
			char next_pos;
			for(int i = 0; i <= 1; i++)
			{
				cin >> next_pos;
				graph[pos].push_back(next_pos - 'A');
			}
			char special; cin >> special;
			if(special == 'x')
				winning_pos[pos] = true;
			else
				winning_pos[pos] = false;
		}
		int moves_left; cin >> moves_left;
		
		memset(memo, -1, sizeof(memo));
		int rez = ways(0, moves_left);
		cout << rez << endl;
		
	}
	return 0;
}











