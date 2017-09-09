#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;

typedef long long int64;

int main()
{
	while(true)
	{
		int m, n;
		cin >> m;
		if(cin.eof())
			break;
	
		vector<vector<int> > input;
		input.resize(m);
		cin >> n;
	
		for(int i = 0; i < m; i++)
		{
			input[i].resize(n);
			for(int j = 0; j < n; j++)
				cin >> input[i][j];
		}
	
		vector<list<int> > paths;
		paths.resize(m);
		
		vector<int> sums;
		sums.resize(m);
	
		for(int i = 0; i < m; i++)
		{
			sums[i] = input[i][n-1];
			paths[i].push_front(i);
		}
	
		vector<list<int> > aux_paths;
		vector<int> aux_sums;
		vector<int> s;
		s.resize(3);
		vector<int> da;
		da.resize(3);
		int adaug, t;
		list<int>::iterator l;
		for(int i = n - 2; i >= 0; i--)
		{
			aux_paths = paths;
			aux_sums = sums;
			for(int j = 0; j < m; j++)
			{
				t = j - 1;
				if(t < 0)
					t = m - 1;
				da[0] = j;
				da[1] = t;
				da[2] = (j+1) % m;
				sort(da.begin(), da.end());
				
				s[0] = aux_sums[da[0]] + input[j][i];
				s[1] = aux_sums[da[1]] + input[j][i];
				s[2] = aux_sums[da[2]] + input[j][i];
				
				sums[j] = INT_MAX;
				if(s[2] < sums[j])
				{
					sums[j] = s[2];
					adaug = da[2];
				}
				if(s[1] <= sums[j])
				{
					sums[j] = s[1];
					adaug = da[1];
				}
				if(s[0] <= sums[j])
				{
					sums[j] = s[0];
					adaug = da[0];
				}
	
				paths[j] = aux_paths[adaug];
				paths[j].push_front(j);
				  
			}
		}

		//sort(paths.begin(), paths.end());
		int c = INT_MAX;
		int p;
		for(int i = m - 1; i >= 0; i--)
		{
			if(sums[i] <= c)
			{
				c = sums[i];
				p = i;
			}
		}
		/*list<int>::iterator l; */
		int u = 0;
		for(l = paths[p].begin(); l != paths[p].end(); l++)
		{
			if(u == n - 1)
				cout << *l + 1 << endl;
			else
				cout << *l + 1 << " ";
			u++;
		}
		cout << c << endl;
		/*for(int j = 0; j < m; j++)
		{
		for(l = paths[j].begin(); l != paths[j].end(); l++)
			cout << *l + 1 << " ";
		cout << " " << sums[j];
		cout << endl;
		}
		printf("\n");   */
	}
				

			
	












	return 0;
}








	









