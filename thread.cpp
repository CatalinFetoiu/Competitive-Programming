#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<limits.h>
#include<list>
#include<queue>
#include<bitset>
#include<map>
//#include<unordered_map>

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;

#define Max 3100
#define INF 2000000000
#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)


int N;
vector<int> numbers;
int visited[70000];
//vector<int> sums;

int sums()
{
	/*
	int count = 0;
	queue<ii> q;
	//q.push(ii(0, 0));
	visited[0] = 1;
	count++;
	
	for(int i = 0; i < N; i++)
	{
		q.push(ii(numbers[i], 1));
		visited[numbers[i]] = 1;
		count++;
	}

	while(!q.empty())
	{
		ii front = q.front();
		q.pop();
		int sum = front.first;
		int index = front.second;

		if(index < N)
		{
			for(int i = 0; i < N; i++)
			{
				if(!visited[sum+numbers[i]])
				{
					q.push(ii(sum+numbers[i], index+1));
					visited[sum+numbers[i]] = 1;
					count++;
				}
			}
		}
	}
	*/

	//int count = 0;
	vector<int> sums;
	//sums.push_back(0);
	//visited[0] = 1;
	
	for(int i = 0; i < N; i++)
	{
		int size;
		if(!visited[numbers[i]])
		{
			sums.push_back(numbers[i]);
			visited[numbers[i]] = 1;
			size = sums.size() - 1;
		}
		else
			size = sums.size();
			
		for(int j = 0; j < size; j++)
		{
			if(!visited[sums[j]+numbers[i]])
			{
				sums.push_back(sums[j]+numbers[i]);
				visited[sums[j]+numbers[i]] = 1;
			}
		}
	}

	return sums.size();
		
	
}


int main()
{
	freopen("thread.in", "r", stdin);
	freopen("thread.out", "w", stdout);

	int T; scanf("%d", &T);

	while(T--) {
	
	scanf("%d", &N);
	numbers.clear();
	numbers.resize(N);

	for(int i = 0; i < N; i++)
		scanf("%d", &numbers[i]);
	
	memset(visited, 0, sizeof(visited));

	printf("%d\n", sums());

	}

	return 0;
}
		



	

















