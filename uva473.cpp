#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;

int N, t, M;
int disks[2500];
int memo[21000][2500];

int place(int space_left, int disk_id)
{
	if(space_left < 0)
		return INT_MIN;
	if(memo[space_left][disk_id] != -1)
		return memo[space_left][disk_id];
	
	if(disk_id == N - 1)
	{
		if(space_left - disks[N-1] >= 0)
			return memo[space_left][disk_id] = 1;
		else
			return memo[space_left][disk_id] = 0;
	}
	
	int space_curent_disk = space_left % t;

	int with_disk;
	if(space_curent_disk >= disks[disk_id])
		with_disk = 1 + place(space_left - disks[disk_id], disk_id + 1);
	else
		with_disk = 1 + place(space_left - space_curent_disk - disks[disk_id], disk_id + 1);

	int without_disk = place(space_left, disk_id + 1);
	int aux = max(with_disk, without_disk);

	return memo[space_left][disk_id] = aux;
}





int main()
{
	int T;	scanf("%d", &T);
	for(int k = 1; k <= T; k++)
	{
		scanf("%d%d%d", &N, &t, &M);
		char separator;
		for(int i = 0; i < N; i++)
		{
			cin >> disks[i];
			if(i != N - 1)
			{
				char comma;
				cin >> comma;
			}
		}
		

		memset(memo, -1, sizeof(memo));
		int rez = place(M * t, 0);
		cout << rez << endl;
		if(k != T)
			printf("\n");
	}

	return 0;
}




	
