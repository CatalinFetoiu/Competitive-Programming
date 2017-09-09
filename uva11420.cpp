#include <limits.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <bitset>
//#include <unordered_map>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define traverse(c, it) \
    for (map<ii, int>::iterator it = c.begin(); it != c.end(); it++)


int N, S;
// dp de drawer, last state si number of secure
ll dp[70][3][70];

ll getWays(int index, int last, int secureDrawers) {
    if(dp[index][last][secureDrawers] != -1) {
        return dp[index][last][secureDrawers];
    }

    if(index == N) {
        if(secureDrawers == 0)
            return 1;
        else {
            return 0;
        }
    }

    if(secureDrawers == 0) {
        if(last == 1) {
            return dp[index][last][secureDrawers] = getWays(index+1, 0, secureDrawers);
        } else {
            ll res = getWays(index+1, 0, secureDrawers) +
                      getWays(index+1, 1, secureDrawers);
            return dp[index][last][secureDrawers] = res;
        }
    } else {
        if(last == 1) {
            ll res = getWays(index+1, 0, secureDrawers) +
                      getWays(index+1, 1, secureDrawers - 1);
            return dp[index][last][secureDrawers] = res;
        } else {
            ll res = getWays(index+1, 0, secureDrawers) +
                      getWays(index+1, 1, secureDrawers);
            return dp[index][last][secureDrawers] = res;
        }
    }
}



int main() {

    while(true) {
        cin >> N >> S;
        if(N < 0 && S < 0) {
            break;
        }

        if(S == N) {
            cout << 1 << endl;
        } else {
            memset(dp, -1, sizeof(dp));

            cout << getWays(1, 0, S)  + getWays(1, 1, S-1) << endl;
        }
    }

    return 0;
}