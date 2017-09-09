#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>

#define INF 20000000

using namespace std;


int light[12][12];

int xAxis[] = {-1, 0, 1, 0};
int yAxis[] = {0, -1, 0, 1};

int res;

void swich(int x, int y)
{
	light[x][y] = 1 - light[x][y];
	for(int i = 0; i < 4; i++)
	{
		if(0 <= x + xAxis[i] && x + xAxis[i] < 10)
		{
			if(0 <= y + yAxis[i] && y + yAxis[i] < 10)
			{
				light[x+xAxis[i]][y+yAxis[i]] = 1 - light[x+xAxis[i]][y+yAxis[i]];
			}
		}
	}
}
	

void minSteps(int x, int y, int numSteps)
{
	if(y == 10)
	{
		x++;
		y = 0;
		minSteps(x, y, numSteps);
	}
	else
	{
		if(x == 0)
		{
			swich(x, y);
			minSteps(x, y+1, numSteps+1);
			swich(x, y);
			minSteps(x, y+1, numSteps);
		}
		else if(x == 10)
		{
			for(int i = 0; i < 10; i++)
			{
				if(light[x-1][i] == 1)
					return;
			}
			if(numSteps < res)
				res = numSteps;
		}
		else /* x < 10 */
		{
			if(light[x-1][y] == 1)
			{
				swich(x, y);
				minSteps(x, y+1, numSteps+1);
				swich(x, y);
			}
			else
				minSteps(x, y+1, numSteps);
		}
	}
}


int main()
{
	string line;
	string name;
	string aux = "end";

	while(true)
	{
		cin >> name;
		if(name.compare(aux) == 0)
			break;

		memset(light, 0, sizeof(light));
		for(int i = 0; i < 10; i++)
		{
			cin >> line;
			for(int j = 0; j < line.length(); j++)
			{
				if(line[j] == '#')
					light[i][j] = 0;
				if(line[j] == 'O')
					light[i][j] = 1;
			}
		}

		/*
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				cout << light[i][j] << " ";
			}
			cout << endl;
		}  */
		

		res = INF;
		minSteps(0, 0, 0);
	
		cout << name << " " << res << endl;
	}

	return 0;
}
 
		
			







				
			
			









	
