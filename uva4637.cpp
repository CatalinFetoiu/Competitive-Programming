#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <list>
#include <queue>
#include <map>

using namespace std;

vector<pair<string ,string> > substitute;
map<string, int> dist; /* first map :D */
string alfa, gamma;

string sed(string s1, string s2, string s3)
{
	vector<int> index;
	int curent_index;
	int pos = 0;
	while(s1.find(s2, pos) != string::npos)
	{
		curent_index = s1.find(s2, pos);
		index.push_back(curent_index);
		pos = curent_index + s2.length();
	}
	int count = 0;
	for(int i = 0; i < index.size(); i++)
	{
		s1.replace(index[i] + count*(s3.length() - s2.length()), s2.length(), s3);
		count++;
	}
	
	return s1;
}

void bfs(string curent)
{
	queue<string> q;
	dist[curent] = 0;
	q.push(curent);
	while(!q.empty() && q.front() != gamma)
	{
		string t = q.front();
		q.pop();
		vector<pair<string ,string> >::iterator v;
		for(v = substitute.begin(); v != substitute.end(); v++)
		{
			string s1 = v->first;
			string s2 = v->second;
			string next = sed(t, s1, s2);
			if(next != t && next.length() <= gamma.length())
			{
				//cout << next << endl;
				if(!dist.count(next))
				{
					dist[next] = dist[t] + 1;
					q.push(next);
					//cout << next << endl;
				}
			}
		}
	}
}








int main()
{
	int N;

	while(true)
	{
		cin >> N;
		if(N == 0)
			break;	
	
		substitute.clear();
		dist.clear();
		
		substitute.resize(N);
		for(int i = 0; i < N; i++)
			cin >> substitute[i].first >> substitute[i].second;
		cin >> alfa;
		cin >> gamma;
		bfs(alfa);
		if(!dist.count(gamma))
			cout << "-1" << endl;
		else
			cout << dist[gamma] << endl; 
		/*string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		cout << sed(s1, s2, s3) << endl; */
	}


	return 0;
}





