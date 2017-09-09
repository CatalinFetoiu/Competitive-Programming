#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<limits.h>
#include<math.h>
#include<list>
#include<queue>
#include<map>

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;

#define Max 3100
#define INF 2000000000

int debug;

/* first element in sequence */
int64 first(int64 seq)
{
	return seq * (seq-1) + 1;
}

/* last element in sequence */
int64 last(int64 seq)
{
	return seq * seq;
}

/* get block of a */
int64 find(int64 a)
{
	return 1 + (int)(floor(sqrt(a)));
}

int main()	
{
	
	FILE* fin = freopen("progresie.in", "r", stdin);
	FILE* fout = freopen("progresie.out", "w", stdout);

	int T; cin >> T;
	int64 N, R, curentStart, curentEnd, j, a, b, block;
	bool found;
	
	while(T--)
	{

	cin >> N >> R;
	if(N == 1)
		cout << "1" << endl;
	else
	{	
		found = false;
		int64 res = first(1 + (N-1) * R);

		block = 0;
		while(true)
		{
			block++;
			if(block >= R - N)
				break;

			curentStart = first(block);
			curentEnd = last(block);

			//cout << block << endl;

			bool foundChain = true;
			for(int i = 0; i < N; i++)
			{
				a = curentStart + R; /* max reachable interval from sequence i */
 				b = curentEnd + R;

				//cout << curentStart << " " << curentEnd << endl;

				j = find(a);
				if(first(j) > b)
				{
					foundChain = false;
					break;
				}
				else /* first(j) is <= b */
				{
					if(first(j) < a)
						curentStart = a;
					else
						curentStart = first(j);
					if(last(j) <= b)
						curentEnd = last(j);
					else
						curentEnd = b;
				}
			}

			if(foundChain)
			{
				cout << min(res, curentStart - N * R) << endl;
				found = true;
				break;
			}
		}

		if(!found)
			cout << res << endl;
	
	}

	}

	fclose(fin);
	fclose(fout);

	return 0;
}
		
	
	

























