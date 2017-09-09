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

#define traverse(c, it) \
    for (map<ii, int>::iterator it = c.begin(); it != c.end(); it++)


int N, L;
vector<int> cuts;
int dp[1002][1002];

int getMinCuts(int left, int right) {
    if(dp[left][right] != -1) {
        return dp[left][right];
    }

    int bestCost = INT_MAX;

    for(int i = 0; i < N; i++) {
        if(left < cuts[i] && cuts[i] < right) {
            int cost = getMinCuts(left, cuts[i]) + getMinCuts(cuts[i], right) +
                       (right - left);
            bestCost = min(bestCost, cost);
        } 
    }

    if(bestCost == INT_MAX) {
        bestCost = 0;
    }
    return dp[left][right] = bestCost;
}


int main() {

    while(true) {
        cin >> L;
        if(L == 0) {
            break;
        }
        cin >> N;

        cuts.clear();
        cuts.resize(N);

        for(int i = 0; i < N; i++) {
            cin >> cuts[i];
        }

        memset(dp, -1, sizeof(dp));

        printf("The minimum cutting is %d.\n", getMinCuts(0, L));
    }

    return 0;
}