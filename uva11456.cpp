#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <list>
#include <stack>

using namespace std;

int N;
vector<int> v;
vector<int> lis;
vector<int> lds;


vector<int> createLIS()
{
	vector<int> LIS;
	LIS.resize(N);

	LIS[LIS.size()-1] = 1;
	for(int i = v.size()-1; i >= 0; i--)
	{
		LIS[i] = 1;
		for(int j = v.size()-1; j > i; j--)
		{
			if(v[j] >= v[i])
				LIS[i] = max(LIS[i], 1+LIS[j]);
		}
	}

	return LIS;

}

vector<int> createLDS()
{
	vector<int> LIS;
	LIS.resize(N);

	LIS[LIS.size()-1] = 1;
	for(int i = v.size()-1; i >= 0; i--)
	{
		LIS[i] = 1;
		for(int j = v.size()-1; j > i; j--)
		{
			if(v[j] <= v[i])
				LIS[i] = max(LIS[i], 1+LIS[j]);
		}
	}

	return LIS;
}




int main()
{
	int tc;
	cin >> tc;
	
	while(tc--)
	{
		cin >> N;
		if(N == 0)
			cout << "0" << endl;
		else
		{
	
		v.clear();
		v.resize(N);

		for(int i = 0; i < N; i++)
		{
			cin >> v[i];
		}

		lis = createLIS();
		lds = createLDS();
	
		int maxNr = -1;
		for(int i = 0; i < v.size(); i++)
		{
			maxNr = max(maxNr, lis[i] + lds[i] - 1);
		}

		cout << maxNr << endl;
		}
	}


	return 0;
}











