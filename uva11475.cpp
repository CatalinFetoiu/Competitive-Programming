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
	int m = P.length();
	int n = T.length();
	int i = 0, j = 0;
	while(i < n)
	{
		while(j >= 0 && T[i] != P[j])
			j = b[j];
		i++; j++;
		if(i == n)
			return i - j;
		if(j == m)
		{
			j = b[j];
		}
	}
	
}


int main()
{
	string s, rev;
	while(true)
	{
		cin >> s;
		if(cin.eof())
			break;
		rev.clear();
		rev.append(s);
		reverse(rev.begin(), rev.end());
		kmpPreProcess(s);
		int index = kmpSearch(rev, s);
		s.append(rev.begin() + rev.length() - index, rev.end());
			
		cout << s << endl;
	}
	
	return 0;
}










