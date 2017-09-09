#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;

int N;
int a[110], sum[110];
int memo[110][110];

int s(int i, int j)
{
	return sum[j] - sum[i] + a[i];
}

int play(int left, int right)
{
	if(memo[left][right] != -1)
		return memo[left][right];
	if(left > right)
		return 0;
	if(left == right)
		return memo[left][right] = a[left];

	int best = INT_MIN;
	for(int i = left; i <= right; i++)
	{
		if(s(left, i) - play(i + 1, right) > best)
			best = s(left, i) - play(i + 1, right);
		if(s(i, right) - play(left, i - 1) > best)
			best = s(i, right) - play(left, i - 1);
	}
	return memo[left][right] = best;
}













int main()
{
	while(true)
	{
		cin >> N;
		if(N == 0)
			break;
		
		cin >> a[0]; sum[0] = a[0];
		for(int i = 1; i < N; i++)
		{
			cin >> a[i];
			sum[i] = sum[i-1] + a[i];
		}
	
		memset(memo, -1, sizeof(memo));
		int rez = play(0, N-1);
		cout << rez << endl;
	}
	
	return 0;
}








