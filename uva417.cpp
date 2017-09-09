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

using namespace std;


int main()
{
	string s;
	while(true)
	{
		cin >> s;
		if(cin.eof())
			break;
		bool valid = true;
		for(int i = 0; i < s.length() - 1; i++)
		{
			if(s[i] >= s[i+1])
			{
				valid = false;
				break;
			}
		}
		if(!valid)
			cout << "0" << endl;
		else
		{
			queue<string> q;
			int count = 0;
			q.push("");
			while(q.front() != s)
			{
				string t = q.front();
				//cout << t << endl;
				count++;
				q.pop();
				if(t == "")
				{
					for(char c = 'a'; c <= 'z'; c++)
					{
						char aux[2];
						aux[0] = c;
						aux[1] = 0;
						q.push(aux);
					}
				}
				else
				{
					char last = t[t.size() - 1];
					for(char next = last + 1; next <= 'z'; next++)
						q.push(t + next);
				}
			}
			cout << count << endl;
		}
	}
	
	return 0;
} 








