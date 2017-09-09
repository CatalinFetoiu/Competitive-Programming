#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <list>
#include <stack>
#include <limits.h>

#define INF -200000000

using namespace std;

int N;
int mat[160][160];

int runningSums[160];

int Kadane1(int* start, int* finish)
{
	int min_so_far = 0;
	int min_ending_here = 0;

	*start = -1;
	*finish = -1;

	int local_start = 0;
	
	for(int i = 0; i < N; i++)
	{
		min_ending_here += runningSums[i];
		if(min_ending_here > 0)
		{
			local_start = i+1;
			min_ending_here = 0;
		}
		else
		{
			if(min_ending_here < min_so_far)
			{
				min_so_far = min_ending_here;
				*start = local_start;
				*finish = i;
			}
		}
	}

	/* all elements are negative */
	if(*finish == -1)
	{
		return INT_MAX;
	}
	else
		return min_so_far;
}

int Kadane2(int* start, int* finish)
{
	int max_so_far = 0;
	int max_ending_here = 0;

	*start = -1;
	*finish = -1;

	int local_start = 0;
	
	for(int i = 0; i < N; i++)
	{
		max_ending_here += runningSums[i];
		if(max_ending_here < 0)
		{
			local_start = i+1;
			max_ending_here = 0;
		}
		else
		{
			if(max_ending_here > max_so_far)
			{
				max_so_far = max_ending_here;
				*start = local_start;
				*finish = i;
			}
		}
	}

	/* all elements are negative */
	if(*finish == -1)
	{
		max_so_far = runningSums[0];
		for(int i = 1; i < N; i++)
			max_so_far = max(max_so_far, runningSums[i]);
		return max_so_far;
	}
	else
		return max_so_far;
}



int KadaneMatrix()
{
	int maxSum = INF;

	int start, finish;

	for(int col = 0; col < N; col++)
	{
		memset(runningSums, 0, sizeof(runningSums));

		for(int nextCol = col; nextCol < col + N; nextCol++)
		{
			for(int row = 0; row < N; row++)
				runningSums[row] += mat[row][nextCol];

			start = -1;
			finish = -1;

			int sum = 0;
			for(int row = 0; row < N; row++)
				sum += runningSums[row];
			
			int localMin = Kadane1(&start, &finish);
			if(localMin == INT_MAX)
				maxSum = max(maxSum, sum);
			else if(localMin == sum)
			{
				for(int i = 0; i < N; i++)
					maxSum = max(maxSum, runningSums[i]);
			}
			else
				maxSum = max(maxSum, sum - localMin);

			maxSum = max(maxSum, Kadane2(&start, &finish));
		}
	}

	return maxSum;
}
				




	


int main()
{
	int T;
	cin >> T;
	
	while(T--) {
	
	cin >> N;
	memset(mat, -1, sizeof(mat));

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> mat[i][j];
			mat[i][j+N] = mat[i][j];
		}
	}

	cout << KadaneMatrix() << endl;

	}

	return 0;
}
	














