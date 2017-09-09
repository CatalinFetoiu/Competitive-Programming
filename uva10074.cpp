#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>

using namespace std;

int m, n;

int getSize(vector<vector<int> > sum)
{
	int maxSize = INT_MIN;
	int curent_sum, size;

	for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
		for(int k = i; k < m; k++) for(int l = j; l < n; l++)	{
			curent_sum = sum[k][l];
			if(i > 0)
				curent_sum -= sum[i-1][l];
			if(j > 0)
				curent_sum -= sum[k][j-1];
			if(i > 0 && j > 0)
				curent_sum += sum[i-1][j-1];
			size = (k - i + 1) * (l - j + 1);
			if(curent_sum == 0)
			{
				maxSize = max(maxSize, size);
			}
		}
	}

	if(maxSize == INT_MIN)
		return 0;
	else
		return maxSize;
}

	
			







int main()
{

	while(true)
	{
		vector<vector<int> > input;
		vector<vector<int> > sum;
		
		cin >> m; cin >> n;
		if(m == 0 && n == 0)
			break;
		input.resize(m);
		for(int r = 0; r < m; r++)
		{
			input[r].resize(n);
			for(int c = 0; c < n; c++)
				cin >> input[r][c];
		}
		
		sum.resize(m);
		for(int r = 0; r < m; r++)
		{
			sum[r].resize(n);
			for(int c = 0; c < n; c++)
			{
				sum[r][c] = input[r][c];
				if(r > 0)
					sum[r][c] += sum[r-1][c];
				if(c > 0)
					sum[r][c] += sum[r][c-1];
				if(r > 0 && c > 0)
					sum[r][c] -= sum[r-1][c-1];
			}
		}

		int rez = getSize(sum);
		cout << rez << endl;
	}

	return 0;
}
