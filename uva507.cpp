#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int N;
vector<int> distances;
int start, end1;
int s, e;

int Kadane()
{
	int max_so_far = -1;
	int max_ending_here = 0;

	//int s, e;

	s = 0;
	start = s;
	e = 0;
	end1 = e;
	
	for(int i = 0; i < distances.size(); i++)
	{
		max_ending_here += distances[i];
		if(max_ending_here < 0)
		{
			max_ending_here = 0;
			s = i+2;
			e = i+2;
		}
		else
		{
			if(max_ending_here > max_so_far)
			{
				e = i+2;
				start = s;
				end1 = e;
			}
			if(max_ending_here == max_so_far)
			{
				//cout << "da " << endl;
				e = i+2;
				if(e-s > end1-start)
				{
					start = s;
					end1 = e;
				}
			}
				
			max_so_far = max(max_so_far, max_ending_here);
		}
	}

	return max_so_far;
}




int main()
{
	int tc;
	cin >> tc;
	
	for(int k = 1; k <= tc; k++)
	{
		cin >> N;
		if(N <= 0)
			printf("Route %d has no nice parts\n", k);
		else
		{
		distances.clear();
		distances.resize(N-1);

		for(int i = 0; i < N-1; i++)
		{
			cin >> distances[i];
		}

		if(Kadane() == -1)
			printf("Route %d has no nice parts\n", k);
		else
		{
			if(start == 0)
				start++;
			printf("The nicest part of route %d is between stops %d and %d\n", k, start, end1);
		}
		}
	}

	return 0;
}




















