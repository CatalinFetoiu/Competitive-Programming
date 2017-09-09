#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>

using namespace std;


int kadane(vector<int> v, int* start, int* finish)
{
	int sum = 0;
	int maxSum = 0;
	
	int local_start = 0;
	*finish = -1;
	for(int i = 0; i < v.size(); i++)
	{
		sum += v[i];
		if(sum < 0)
		{
			sum = 0;
			local_start = i + 1;
		}
		if(sum > maxSum)
		{
			maxSum = sum;
			*start = local_start;
			*finish = i;
		}
	}

	if(*finish != -1)
		return maxSum;

	//daca toate elementele sunt negative
	maxSum = v[0];
	*start = 0;
	*finish = 0;
	
	for(int i = 1 ; i < v.size(); i++)
	{
		if(v[i] > maxSum)
		{
			maxSum = v[i];
			*start = i;
			*finish = i;
		}
	}
	return maxSum;
}

int uva(vector<vector<int> > a)
{
	int maxSum = INT_MIN;
	int sum, start, finish;
	vector<int> rowSum(a.size(), 0);

	for(int left = 0; left < a.size(); left++)
	{
		fill(rowSum.begin(), rowSum.end(), 0);
	
		for(int right = left; right < a.size(); right++)
		{
			for(int i = 0; i < a.size(); i++)
				rowSum[i] += a[i][right];

			sum = kadane(rowSum, &start, &finish);
			if(sum > maxSum)
				maxSum = sum;
		
		}
	}

	return maxSum;
}
	
	




int main()
{
	int n;
	scanf("%d", &n);
	
	vector<vector<int> > a;	
	a.resize(n);
	for(int i = 0; i < a.size(); i++)
	{
		a[i].resize(n);
		for(int j = 0; j < a.size(); j++)
			cin >> a[i][j];
	}
		
	printf("%d\n", uva(a));

	return 0;
}



	

