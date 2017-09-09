#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>

using namespace std;


typedef pair<int, int> ii;

int N, M;
vector<ii> pieces;
ii start, end;
vector<int> used;


bool canFill(int index, int lastFace)
{
	/* last space */
	if(index == N)
	{
		return lastFace == end.first;
	}

	bool ok = false;
	for(int i = 0; i < pieces.size(); i++)
	{
		if(!used[i])
		{
			used[i] = 1;
			bool aux1 = false, aux2 = false;
			if(pieces[i].first == lastFace)
				aux1 = canFill(index + 1, pieces[i].second);
			if(pieces[i].second == lastFace)
				aux2 = canFill(index + 1, pieces[i].first);
			if(aux1 || aux2)
			{
				ok = true;
			}
			used[i] = 0;
		}
		if(ok == true)
			break;
	}

	return ok;
}


int main()
{
	while(true) {
	
	cin >> N;
	if(N == 0)
		break;
	cin >> M;

	pieces.clear();
	pieces.resize(M);
	used.clear();
	used.resize(M, 0);

	cin >> start.first >> start.second;
	cin >> end.first >> end.second;

	for(int i = 0; i < M; i++)
		cin >> pieces[i].first >> pieces[i].second;

	if(canFill(0, start.second))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	}

	return 0;
}
	
	
		
	










