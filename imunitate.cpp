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
//#include<unordered_map>

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;

#define Max 3100
#define INF 2000000000
#define TRvi(c, it) \
	for(vector<int>::iterator it = c.begin(); it != c.end(); it++)

int V, E;
int dp[1 << 18];
vector<vector<int> > AdjList;
int elim[1 << 18][18];
//vector<int> curentDegree;

int getBit(int n, int position)
{
	return (n >> position) & 1;
}

void optimize()
{
	for(int i = 0; i < V; i++)
		elim[0][i] = 0;
	for(int i = 1; i < (1 << V); i++)
	{
		

int politics(int bitmask) /* complexity is ~ O(N * 2^N) */
{
	//for(int 
	if(dp[bitmask] != -1)
		return dp[bitmask];
	if(bitmask == 0)
		return dp[bitmask] = 0;
	else if((bitmask & (bitmask-1)) == 0) /* bitmask is power of 2 */
		return dp[bitmask] = 1;
	
	vector<int> curentDegree(V);
	for(int i = 0; i < V; i++)
	{
		curentDegree[i] = AdjList[i].size();
	}
	
	int setNumber = 0;
	int influence;
	for(int position = 0; position < V; position++)
	{
		if(getBit(bitmask, position) == 1)
		{
			setNumber++;
		}
		else /* politician was removed */
		{
			TRvi(AdjList[position], v)
			{
				influence = *v;
				curentDegree[influence]--;
			}
		}
	}
	
	//cout << bitmask << endl;
	//cout << setNumber << endl;
	//for(int i = 0; i < V; i++)
		//cout << curentDegree[i] << " " << getBit(bitmask, i) << endl;
	//cout << endl;

	
	int res = 0;
	bool found = false;
	for(int position = 0; position < V; position++)
	{
		if(getBit(bitmask, position) == 1)
		{	
			if(curentDegree[position] >= (setNumber+1)/2)
			{
				//if(bitmask == 15)
					//cout << position << endl;
				int aux = ~(1 << position);
				int aux1 = bitmask;
				aux1 &= aux;
				/*if(bitmask == 15)
				{
					cout << position << endl;
					aux1 = bitmask;
					aux1 &= aux;
					cout << aux1 << endl;
				}*/
				//int aux1 = bitmask;
				//if(dp[aux1 & aux] == -1)
				if(dp[aux1] == -1)
					res += politics(bitmask & aux);
				found = true;
			}
		}
	}

	if(!found) /* set is solution */
		return dp[bitmask] = 1;
	
	return dp[bitmask] = res;
}

				


int main()
{
	FILE* fin = freopen("imunitate.in", "r", stdin);
	FILE* fout = freopen("imunitate.out", "w", stdout);
	
	int start, end;
	
	//curentDegree.assign(V, -1);
	
	int T; cin >> T;
	
	while(T--) {

	cin >> V >> E;

	AdjList.clear();
	AdjList.resize(V);

	for(int i = 0; i < E; i++)
	{
		cin >> start >> end;
		start--; end--;
		AdjList[start].push_back(end);
		AdjList[end].push_back(start);
	}

	memset(dp, -1, sizeof(dp));
	cout << politics((1 << V) - 1) << endl;

	}

	//for(int i = 0; i < (1 << V); i++)
		//cout << dp[i] << " ";
	//cout << endl;

	fclose(fin);
	fclose(fout);

	return 0;
}


























