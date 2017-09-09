#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;

typedef struct
{
	char op;
	int pos1;
	int pos2;
} command;

string s1, s2;
int dp[25][25];


int edit(int i, int j)
{
	if(dp[i][j] != -1)
		return dp[i][j];
	if(i == 0)
		return dp[i][j] = 1 + edit(i, j-1);
	if(j == 0)
		return dp[i][j] = 1 + edit(i-1, j);
	if(s1[i-1] == s2[j-1])
		return dp[i][j] = edit(i-1, j-1);
	int option1 = edit(i-1, j-1) + 1;
	int option2 = edit(i-1, j) + 1;
	int option3 = edit(i, j-1) + 1;
	return dp[i][j] = min(min(option1, option2), option3);
}

void change(int i, int j)
{
	//cout << s1 << endl;
	if(i == 0 && j == 0)
		return;
	if(s1[i-1] == s2[j-1])
		change(i-1, j-1);
	else
	{
		if((i > 0 && j > 0) && dp[i][j] == dp[i-1][j-1] + 1) //replace
		{
			//s1[i-1] = s2[j-1];
			printf("C%c%02d", s2[j-1], i);
			change(i-1, j-1);
		}
		else if(i > 0 && dp[i][j] == dp[i-1][j] + 1) //delete
		{
			//s1.erase(i-1, 1);
			printf("D%c%02d", s1[i-1], i);
			change(i-1, j);	
		}
		else if(j > 0 && dp[i][j] == dp[i][j-1] + 1) //insert
		{
			//s1.insert(i, 1, s2[j-1]);
			printf("I%c%02d", s2[j-1], i + 1);
			change(i, j-1);
		}
	
	}
	
}

		








int main()
{
	while(cin >> s1)
	{
		if(s1 == "#")
			break;
		memset(dp, -1, sizeof(dp));
		cin >> s2;
		int rez = edit(s1.length(), s2.length());
		change(s1.length(), s2.length());
		cout << "E" << endl;
	}
	

	return 0;
}













	
