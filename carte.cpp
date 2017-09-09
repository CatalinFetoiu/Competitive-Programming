#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<limits.h>
#include<list>
#include<queue>
#include<bitset>
#include<map>

using namespace std;

typedef pair<int, int> ii;

#define Max 3100
#define INF 2000000000

int N;
int bookLength;
int dp[3010];
char match[3002][1002]; /* if at index in book starts word from dictionary */
vector<int> dictionary;
int b[Max];

void minimizeLength()
{
	int res;
	for(int index = bookLength; index >= 0; index--)
	{
		if(index == bookLength)
			dp[index] = 0;
		else
		{
			res = INF;
			res = min(res, 1 + dp[index+1]);
	
			for(int wordIndex = 0; wordIndex < N; wordIndex++)
			{
				if(match[index][wordIndex] == '1')
					res = min(res, dp[index + dictionary[wordIndex]]);
			}	
	
			dp[index] = res;
		}
	}
}



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

void kmpSearch(string word, int wordIndex, string T)
{
	kmpPreProcess(word); 

	int m = word.length();
	int n = T.length();
	int i = 0, j = 0;
	while(i < n)
	{
		while(j >= 0 && T[i] != word[j])
			j = b[j];
		i++; j++;
		if(j == m)
		{
			match[i-j][wordIndex] = '1'; /* match found */
			j = b[j];
		}
	}
}
	
	
	
int main()
{
	FILE* fin = freopen("carte.in", "r", stdin);
	FILE* fout = freopen("carte.out", "w", stdout);

	string book;

	int T; cin >> T;
	while(T--)
	{
	cin >> book;
	
	memset(dp, -1, sizeof(dp));
	bookLength = book.length();
	cin >> N;
	
	string word;
	memset(match, '0', sizeof(match)); /* create match table */
	dictionary.clear();
	dictionary.resize(N);
	
	for(int i = 0; i < N; i++)
	{
		cin >> word;
		dictionary[i] = word.length();
		kmpSearch(word, i, book);
	}

	minimizeLength();

	cout << dp[0] << endl;

	}


	fclose(fin);
	fclose(fout);

	return 0;
}


























