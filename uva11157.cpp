#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>

using namespace std;


typedef pair<int, int> ii;

int N, D;
int dist;
vector<int> distances;
vector<int> rocks;

void findDist()
{
	int pos = 0;
	while(pos != N+1)
	{
		//cout << pos << endl;
		int aux = pos;
		if(pos == N)
		{
			dist = max(dist, distances[pos+1] - distances[pos]);
			pos++;
		}
		else if(pos < N)
		{
			/* big rock */
			if(rocks[pos+1] == 1)
			{
				dist = max(dist, distances[pos+1] - distances[pos]);
				pos++;
			}
			/* small rock */
			else
			{
				dist = max(dist, distances[pos+2] - distances[pos]);
				pos += 2;
			}
		}
		if(rocks[aux] == 0)
			rocks[aux] = -1;
		//cout << dist << endl;
	}
	//cout << dist << endl;

	while(pos != 0)
	{
		/* big rock */
		if(rocks[pos-1] != -1)
		{
			dist = max(dist, distances[pos] - distances[pos-1]);
			pos--;
		}
		/* small rock */
		else
		{
			if(pos-2 >= 0)
			{
				dist = max(dist, distances[pos] - distances[pos-2]);
				pos -= 2;
			}
			else
			{
				dist = max(dist, distances[pos] - distances[0]);
				pos = 0;
			}
		}
	}
}		

		
			
			
			
	



int main()
{
	int TC;
	cin >> TC;

	for(int k = 1; k <= TC; k++)
	{
		cin >> N;
		distances.clear();
		distances.resize(N+1);
		rocks.clear();
		rocks.resize(N+1);
		cin >> D;
		string rock;

		/* left side */
		distances[0] = 0;
		rocks[0] = 1;
		for(int i = 0; i < N; i++)
		{
			cin >> rock;
			if(rock[0] == 'B')
			{
				distances[i+1] = atoi(rock.substr(2).c_str());
				rocks[i+1] = 1;
			}
			else
			{
				distances[i+1] = atoi(rock.substr(2).c_str());
				rocks[i+1] = 0;
			}
		}
		/* right side */
		distances.push_back(D);
		rocks.push_back(1);

		dist = -1;
		findDist();
	
		cout << "Case " << k << ": " << dist << endl;
	}

	

	return 0;
}
		










	



