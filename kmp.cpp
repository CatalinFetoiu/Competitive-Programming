#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<sstream>
#include<limits.h>
#include<list>
#include<queue>
#include<map>

#define Max 1000000

using namespace std;

int b[Max];

void kmpPreProcess(string P)
{
	int m = P.length();
	int i = 0, j = -1; b[0] = -1;
	while(i < m)
	{
		while(j >= 0 && P[i] != P[j])
			j = b[j];
		i++; j++;
		b[i] = j;
	}
}

int kmpSearch(string P, string T)
{
	vector<int> found;
	int m = P.length();
	int n = T.length();
	int i = 0, j = 0;
	while(i < n)
	{
		while(j >= 0 && T[i] != P[j])
			j = b[j];
		i++; j++;
		if(j == m)
		{
			//printf("index %d\n", i-j);
			found.push_back(i-j);
			j = b[j];
		}
	}
	return found[found.size() - 2];
}


int main()
{
	string s;

	while(true)
	{
		cin >> s;
		if(s == ".")
			break;
		kmpPreProcess(s);

		int last = kmpSearch(s, s+s);
		int rez = s.length() / (s.length() - last);
		cout << rez << endl;
	}

	return 0;	
}




		


























