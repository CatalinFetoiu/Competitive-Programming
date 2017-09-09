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

vector<string> text1, text2;
int m, n;
int dp[110][110];

vector<string> lcs()
{
	int m = text1.size();
	int n = text2.size();
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <=n; j++)
		{
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(text1[i-1] == text2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	/* reconstruct lcs */
	vector<string> rez;
	rez.resize(dp[m][n]);
	int i = m, j = n;
	int index = dp[m][n];
	while(i > 0 && j > 0)
	{
		if(text1[i-1].compare(text2[j-1]) == 0)
		{
			rez[index-1] = text1[i-1];
			index--; i--; j--;
		}
		else if(dp[i-1][j] > dp[i][j-1])
			i--;
		else
			j--;
	}
	return rez;
}







int main()
{
	string s1, s2;
	while(true)
	{
		text1.clear(); text2.clear();
	
		cin >> s1;
		if(cin.eof())
			break;
		text1.push_back(s1);
		while(cin >> s1)
		{
			if(s1 == "#")
				break;
			text1.push_back(s1);
		}
		while(cin >> s2)
		{
			if(s2 == "#")
				break;
			text2.push_back(s2);
		}
		/*for(int i = 0; i < text1.size(); i++)
		{
				cout << text1[i] << endl;
		}*/
		vector<string> rez = lcs();
		//cout << rez.size() << endl;
		for(int i = 0; i < rez.size(); i++)
		{
			if(i != rez.size() - 1)
				cout << rez[i] << " ";
			else
				cout << rez[i] << endl;
		} 
	}

	return 0;
}









