#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

int grade(vector<int> v)
{
	int LDS[v.size()];
	LDS[0] = 1;
	int len = 1;
	for(int i = 1; i < v.size(); i++)
	{
		LDS[i] = 1;
		for(int j = 0; j < i; j++)
		{
			//daca se poate extinde secventa de lungime maxima
			if(v[i] <= v[j])
				LDS[i] = max(LDS[i], 1 + LDS[j]);
		}
		if(LDS[i] > len)
			len = LDS[i];
	}
	
	return len;
}

int main()
{
	vector<int> v;
	int height;
	int i = 1;
	while(scanf("%d", &height))
	{
		if(height == -1)
			break;
		v.clear();
		v.push_back(height);
		while(scanf("%d", &height))
		{
			if(height == -1)
				break;
			v.push_back(height);
		}
		printf("Test #%d:\n", i);
		printf("  maximum possible interceptions: %d\n", grade(v));
		//printf("\n");
		i++;
	}
	
	return 0;
}







