#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

/*
vector<int> grade(vector<int> v)
{
	
	vector<int> LIS;
	LIS.resize(v.size());
	
	LIS[0] = 1;
	for(int i = 1; i < v.size(); i++)
	{
		LIS[i] = 1;
		for(int j = 0; j < i; j++)
		{
			//daca se poate extinde secventa de lungime maxima
			if(v[i] > v[j])
				LIS[i] = max(LIS[i], 1 + LIS[j]);
		}
	}
	
	return LIS;
} */

vector<int> grade(vector<int> v)
{
	

	int index;
	//int len;
	vector<int>::iterator low;
	vector<int> tailTable;
	tailTable.push_back(v[0]);
	vector<int> LIS;
	LIS.resize(v.size());
	LIS[0] = 1;
	
	for(int i = 1; i < v.size(); i++)
	{
		if(v[i] < tailTable[0])
		{
			tailTable[0] = v[i];
			LIS[i] = 1;
		}
		else if(v[i] > tailTable[tailTable.size() - 1])
		{
			tailTable.push_back(v[i]);
			LIS[i] = tailTable.size();
		}
		else
		{
			low = lower_bound(tailTable.begin(), tailTable.end(), v[i]);
			index = low - tailTable.begin(); //e ceil direct aici
			
			tailTable[index] = v[i];
			LIS[i] = index + 1;
		}
	}

	return LIS;
}

int main()
{
	vector<int> v;
	int n;
	int nr, wavio;
	while(scanf("%d", &nr) != EOF)
	{
		for(int i = 0; i < nr; i++)
		{
			scanf("%d", &n);
			v.push_back(n);
		}
		vector<int> LIS = grade(v);
		reverse(v.begin(), v.end());
	
		vector<int> LDS = grade(v);
		reverse(LDS.begin(), LDS.end());
	
		wavio = 0;
		for(int i = 0; i < LIS.size(); i++)
		{
			if(min(LIS[i], LDS[i]) > wavio)
				wavio = min(LIS[i], LDS[i]);
		}
		printf("%d\n", 2 * wavio - 1);
		v.clear();
	}
	
	return 0;
}












