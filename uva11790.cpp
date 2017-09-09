#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int grade(vector<int> v, vector<int> weights)
{
	
	vector<int> LIS;
	LIS.resize(v.size());
	
	LIS[0] = weights[0];
	int max_weight = LIS[0];
	for(int i = 1; i < v.size(); i++)
	{
		LIS[i] = weights[i];
		for(int j = 0; j < i; j++)
		{
			//daca se poate extinde secventa de lungime maxima (weighted)
			if(v[i] > v[j])
				LIS[i] = max(LIS[i], LIS[j] + weights[i]);
		}
		if(LIS[i] > max_weight)
			max_weight = LIS[i];
	}
	
	return max_weight;
} 

int main()
{
	int T; scanf("%d", &T);
	int n, val;
	
	vector<int> v;
	vector<int> weights;
	int g1, g2;
	for(int k = 1; k <= T; k++)
	{
		scanf("%d", &n);
	
		for(int i = 0; i < n ; i++)
		{
			scanf("%d", &val);
			v.push_back(val);
		}
		for(int i = 0; i < n ; i++)
		{
			scanf("%d", &val);
			weights.push_back(val);
		}
		
		g1 = grade(v, weights);  /* increasing */
		reverse(v.begin(), v.end());
		reverse(weights.begin(), weights.end());
		g2 = grade(v, weights);  /* decreasing */

		if(g1 >= g2)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", k, g1, g2);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", k, g2, g1);
		
		v.clear();
		weights.clear();
	}
	
	return 0;
}

















