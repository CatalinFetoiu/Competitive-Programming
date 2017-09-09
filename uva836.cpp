#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>

using namespace std;

int getMax(vector<vector<int> > sum)
{
	int maxSum = INT_MIN;
	int curent_sum, size;

	for(int i = 0; i < sum.size(); i++) for(int j = 0; j < sum.size(); j++) {
		for(int k = i; k < sum.size(); k++) for(int l = j; l < sum.size(); l++)	{
			curent_sum = sum[k][l];
			if(i > 0)
				curent_sum -= sum[i-1][l];
			if(j > 0)
				curent_sum -= sum[k][j-1];
			if(i > 0 && j > 0)
				curent_sum += sum[i-1][j-1];
			size = (k - i + 1) * (l - j + 1);
			if(curent_sum == size)
				maxSum = max(maxSum, curent_sum);
		}
	}

	if(maxSum == INT_MIN)
		return 0;
	else
		return maxSum;
}

	
			







int main()
{
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++)
	{
		vector<vector<int> > input;
		vector<vector<int> > sum;
		
		string line;	
		cin >> line;
		int n = line.length();
		input.resize(n);
		input[0].resize(n);
		for(int i = 0; i < n; i++)
			input[0][i] = line[i] - '0';
		for(int r = 1; r < n; r++)
		{
			cin >> line;
			input[r].resize(n);
			for(int c = 0; c < n; c++)
				input[r][c] = line[c] - '0';
		}
	
		
		sum.resize(n);
		for(int r = 0; r < n; r++)
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

		if(tc != 1)
			printf("\n");
		int rez = getMax(sum);
		cout << rez << endl;
	}

	return 0;
}










