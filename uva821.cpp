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
#define INF 1000000000

using namespace std;

int AdjMat[110][110];
int numV; //number of vertices


void Floyd_Warshall(vector<int> vertices)
{
	TRvi(vertices, k)
	{
		TRvi(vertices, i)
		{
			TRvi(vertices, j)
				AdjMat[*i][*j] = min(AdjMat[*i][*j], AdjMat[*i][*k] + AdjMat[*k][*j]);
		}
	}
}

int main()
{
	vector<int> vertices;
	int V, src, dest;
	
	int CaseNo = 0;
	while(true)
	{
		for(int i = 0; i < 100; i++)
			for(int j = 0; j < 100; j++)
				AdjMat[i][j] = INF;
		vertices.clear();
		
		bool last_test = true;
		while(cin >> src >> dest && src != 0 && dest != 0)
		{
			last_test = false;
			if(find(vertices.begin(), vertices.end(), src - 1) == vertices.end())
				vertices.push_back(src-1);
			if(find(vertices.begin(), vertices.end(), dest - 1) == vertices.end())
				vertices.push_back(dest-1);
			AdjMat[src-1][dest-1] = 1;
		}
		if(last_test)
			break;
		
		CaseNo++;
		Floyd_Warshall(vertices);
		int rez = 0;
		TRvi(vertices, i)
		{
			TRvi(vertices, j)
			{
				if(*i != *j)
					rez += AdjMat[*i][*j];
			}
		}
		//cout << rez << endl;
		V = vertices.size();
		
		printf("Case %d: average length between pages = %.3lf clicks\n", CaseNo, double(rez) / (V * V - V));
	}
		
	return 0;
}














