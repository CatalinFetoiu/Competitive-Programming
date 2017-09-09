#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std


int grade(vector<int> weight, vector<int> load)
{

	vector<int> LIS;
	LIS.resize(v.size());
	vector<int> capacity;
	capacity.resize(v.size());
	
	int len = 1;
	LIS[0] = 1;
	capacity[0] = load[0];
	
	for(int i = 1; i < weight.size(); i++)
	{
		LIS[i] = 1;
		capacity[i] = 0;
		for(int j = 0; j < i; j++)
		{
			//daca se poate extinde secventa de lungime maxima
			if(capacity[j] > weight[i] && max(capacity[j] - weight[i], capacity[j]) > capacity[i])
			{
				LIS[i] = max(LIS[i], 1 + LIS[j]);
				capacity[i] = max(capacity
		
		}
		if(LIS[i] > len)
			len = LIS[i];
	}
	
	return len;
}


int main()
{
	int n;
	int w, l;
	vector<int> weight;
	vector<int> load;
	
	while(scanf("%d", &n))
	{
		if(n == 0)
			break;
		scanf("%d", &w);
		weight.push_back(w);
		scanf("%d", &l);
		load.push_back(l);
		
		
	}
	
	return 0;
}
		
		












