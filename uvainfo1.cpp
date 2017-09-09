#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <list>
#define max 1000000

using namespace std;

typedef long long int64;

int64 m = 1000000007; /* prime */

int factorials[max+10];

int64 logpower(int64 x, int64 y, int p)
{
	int64 rez = 1;
	x = x % p;
	while(y > 0)
	{
		if(y & 1)
			rez = (rez*x)%p;
		y = y>>1; //y = y/2
		x = (x*x)%p;
	}
	return rez;
}

int64 cabin(int64 n, int k)
{
	int rez = n%k;
	int64 fact = factorials[k];
	int64 part = (n/k + 1)%(m-1);
	fact = logpower(fact, part, m);
	fact = (fact * logpower(factorials[k-rez], m-2, m))%m;

	return fact;
}






int main()
{
	//ios::sync_with_stdio(false); //muie infoarena
	
	int64 n;
	int k;
	
	factorials[0] = 1;
	int64 aux;
	for(int64 i = 1; i <= max; i++)
	{
		aux = factorials[i-1] * i;
		factorials[i] = aux%m;
	}

	FILE* in = freopen("cabana.in", "r", stdin);
	FILE* out = freopen("cabana.out", "w", stdout);
	
	int T; cin >> T;
	while(T--)
	{
		//cin >> n >> k;
		scanf("%lld%d", &n, &k);
	
		int64 rez = cabin(n, k);
		//cout << rez << endl;
		printf("%lld\n", rez);
	}
	fclose(in);
	fclose(out);


	return 0;
}


