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

int N, M, K;
int cost[1020][1020];
int row, col;
int closestCost;
int r, c;

void findClosest(int budget) {
    row = 0; col = 0;
    closestCost = INT_MIN;
    r = 0; c = 0;

    while(row < N && col < M) {
        if(cost[row][col] == budget) {
            r = row;
            c = col;
            break;
        }

        if(cost[row][col] <= budget) {
            if(cost[row][col] > closestCost) {
                closestCost = cost[row][col];
                r = row;
                c = col;
            }
        }

        if(cost[row][col] < budget) {
            col++;
        } else {
            row++;
        }
    }
}



int main() {

    cin >> N >> M;

    memset(cost, -1, sizeof(cost));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> cost[i][j];
        }
    }

    cin >> K;
    int budget;

    for(int i = 0; i < K; i++) {
        cin >> budget;

        findClosest(budget);
        cout << r << " " << c << endl;
    }




    return 0;
}
