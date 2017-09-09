#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;

int N, L, C;
int lectures[1200];
int memo[510][1010];
int dis[510][1010];

int sat(int time)
{
	if(time == 0)
		return 0;
	else if(1 <= time && time <= 10)
		return -C;
	else
		return (time - 10) * (time - 10);
}

int place(int space_lecture, int lecture_id)
{
	if(space_lecture < 0)
		return INT_MAX;
	if(memo[space_lecture][lecture_id] != -1)
		return memo[space_lecture][lecture_id];
	if(lecture_id == N - 1)
	{
		//cout << space_lecture << endl;
		if(space_lecture >= lectures[N-1])
		{
			dis[space_lecture][N-1] = sat(space_lecture - lectures[N-1]);
			//return 1;
		}
		else
		{
			dis[space_lecture][N-1] = sat(space_lecture) + sat(L - lectures[N-1]);
			//return 1;
		}
		if(space_lecture < lectures[N-1])
			return 1;
		else
			return 0;
	}
	
	int without_extra, with_extra;
	without_extra = place(space_lecture - lectures[lecture_id], lecture_id + 1);
	with_extra = 1 + place(L - lectures[lecture_id], lecture_id + 1);

	if(without_extra < with_extra)
	{
		//if(dis == -1)
		dis[space_lecture][lecture_id] = dis[space_lecture - lectures[lecture_id]][lecture_id + 1];
		return memo[space_lecture][lecture_id] = without_extra;
	}
	if(with_extra < without_extra)
	{
		//if(dis == -1)
		dis[space_lecture][lecture_id] = sat(space_lecture) + dis[L - lectures[lecture_id]][lecture_id + 1];
		return memo[space_lecture][lecture_id] = with_extra;
	}
	if(with_extra == without_extra)
	{
		int dis_total1 = dis[space_lecture - lectures[lecture_id]][lecture_id + 1];
		int dis_total2 = sat(space_lecture) + dis[L - lectures[lecture_id]][lecture_id + 1];

		dis[space_lecture][lecture_id] = min(dis_total1, dis_total2);
		return memo[space_lecture][lecture_id] = with_extra;
	}
}



















int main()
{
	int k = 1;
	while(true)
	{
		scanf("%d", &N);
		if(N == 0)
			break;
		scanf("%d%d", &L, &C);
	
		for(int i = 0; i < N; i++)
			cin >> lectures[i];

		memset(dis, -1, sizeof(dis));
		memset(memo, -1, sizeof(memo));
		int rez = place(0, 0);
		
		if(k != 1)
			printf("\n");
		cout << "Case " << k << ":" << endl;
		cout << "Minimum number of lectures: " << rez << endl;
		cout << "Total dissatisfaction index: " << dis[0][0] << endl;
		k++;	
	}

	return 0;
}



