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
    for (vector<int>::iterator it = c.begin(); it != c.end(); it++)


int N, M;
int root;
vector<int> power;
vector<int> value;
vector<vector<int> > AdjList;
vector<int> inDegree;

int lowerPower, higherPower, midPower;
int dp[100010];

int getValue(int node, int currentPower) {
    if(dp[node] != INT_MIN) {
        return dp[node];
    }

    if(currentPower < power[node]) {
        return 0;
    }

    int totalValue = value[node];
    traverse(AdjList[node], it) {
        int next = *it;
        totalValue = max(totalValue, value[node] + getValue(next, currentPower));
    }

    return dp[node] = totalValue;
}

void reset() {
    for(int i = 0; i < N; i++) {
        dp[i] = INT_MIN;
    }
}

int getMax(int currentPower) {
    int res = INT_MIN;
    for(int i = 0; i < N; i++) {
        res = max(res, getValue(i, currentPower));
    }

    return res;
}

void getResult() {

    lowerPower = 1; higherPower = 10000000; midPower = 0;

    while(lowerPower <= higherPower) {
        midPower = lowerPower + (higherPower - lowerPower) / 2;

        reset();
        //getValue(root, lowerPower);
        int left = getMax(lowerPower);
        reset();
        //getValue(root, higherPower);
        int right = getMax(higherPower);
        reset();
        //getValue(root, midPower);
        int mid = getMax(midPower);

        if(left == right) {
            cout << left << " " << lowerPower << endl;
            break;
        }

        if(higherPower == lowerPower + 1) {
            cout << right << " " << higherPower << endl;
            break;
        }

        //left < right
        if(mid < right) {
            lowerPower = midPower;
        } else if(mid == right) {
            higherPower = midPower;
        }
    }
}



int main() {

    cin >> N >> M;
    power.clear();
    power.resize(N);
    value.clear();
    value.resize(N);

    inDegree.clear();
    inDegree.resize(N, 0);
    AdjList.clear();
    AdjList.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> value[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> power[i];
    }

    int start, end;
    for(int i = 0; i < M; i++) {
        cin >> start >> end;
        start--; end--;
        bool found = false;
        traverse(AdjList[start], it) {
            int next = *it;
            if(end == next) {
                found = true;
                break;
            }
        }

        if(!found) {
            AdjList[start].push_back(end);
            inDegree[end]++;
        }
    }

    for(int i = 0; i < N; i++) {
        if(inDegree[i] == 0) {
            root = i;
            break;
        }
    }

    getResult();

    return 0;
}