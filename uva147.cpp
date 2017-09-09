#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<int> ways(int sum, vector<int> change)
{
	int path;
	vector<int> w(sum + 1, 0);
	w[0] = 1;
	
	for(int i = 0; i < change.size(); i++)
	{
		for(int value = 1; value <= sum; value++)
		{
			if(value - change[i] >= 0)
				w[value] += w[value - change[i]];
		}
		
	}
	return w;
}








int main()
{
	vector<int> change;
	int ch[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000} ;// in cents
	for(int i = 0; i < 11; i++)
		change.push_back(ch[i]);
	
	vector<int> v;
	vector<double> d;
	double s;
	int sum;
	int max = 0;
	while(scanf("%lf", &s))
	{
		if(s == 0)
			break;
		sum = (int)(100 * s);
		if(sum > max)
			max = sum;
		v.push_back(sum);
		d.push_back(s);
	}

	vector<int> w = ways(max, change);
	for(int i = 0; i < v.size(); i++)
		cout << right << setw(6) << setprecision(2) << fixed << d[i] << right << setw(17) << w[v[i]] << right << 100 * d[i] <<  endl;

	return 0;
}


	

