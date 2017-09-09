#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>

#define INF 200000000

typedef pair<int, int> ii;

using namespace std;


int N, numTracks;
vector<int> length;
vector<int> chosen;

ii findSum(int index, int sum)
{	
	if(index + 1 == numTracks)
	{
		if(sum <= N)
			return make_pair(sum, -1);
		else
			return make_pair(-1, -1);
	}

	if(sum > N)
		return make_pair(-1, -1);


	ii aux1 = findSum(index + 1, sum + length[index+1]);
	ii aux2 = findSum(index + 1, sum);

	if(aux1.first > aux2.first)
	{
		chosen[index+1] = aux1.second;
	}
	else
	{
		if(index + 1 < numTracks)
			chosen[index+1] = 0;
	}
}



int main()
{
	while(true)
	{
	cin >> N;
	if(cin.eof())
		break;
	
	cin >> numTracks;

	length.clear();
	length.resize(numTracks);
	chosen.clear();
	chosen.resize(numTracks, 0);
	
	for(int i = 0; i < numTracks; i++)
		cin >> length[i];
	
	int aux1 = findSum(0, length[0]);
	int aux2 = findSum(0, 0);

	if(aux1 > aux2)
		chosen[0] = 1;
	else
		chosen[0] = 0;

	//cout << max(aux1, aux2) << endl;

	for(int i = 0; i < chosen.size(); i++)
	{
		if(chosen[i] == 1)
			cout << length[i] << " ";
	}

	cout << "sum:";
	cout << max(aux1, aux2) << endl;

	}
	

	return 0;
}








	
	
	


