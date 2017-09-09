#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <list>

using namespace std;

typedef long long int64;

bool reached[5000555];

int main()
{
	int64 N, P;
	vector<int64> digits;
	digits.push_back(2); digits.push_back(3); digits.push_back(5); digits.push_back(7);
	queue<int64> c, gol;

	FILE* in = freopen("cifre4.in", "r", stdin);
	FILE* out = freopen("cifre4.out", "w", stdout);
	
	
	
	int T; cin >> T;
	int64 num, first;
	bool found;
	while(T--)
	{
		cin >> N >> P;
		memset(reached, 0, sizeof(bool) * 5000555);
	
		c = gol;
		c.push(0);
		reached[0] = 1;

		while(true)
		{
			//printf("ok");
			if(c.empty())
			{
				cout << "-1" << endl;
				break;
			}	
	
			first = c.front();
			found = false;
			for(int i = 0; i < digits.size(); i++)
			{
			    num = first * 10 + digits[i];
				if(num % P == N)
				{
					cout << num << endl;
					found = true;
					break;
				}
				if(!reached[num % P])
				{
					c.push(num);
					reached[num % P] = 1;
				}
			}
			if(found)
				break;
			c.pop();
		}
	}
	fclose(in);
	fclose(out);
			
	return 0;
}
