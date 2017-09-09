#include <limits.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <list>
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


int N;
vector<int> marbles;
vector<int> parent;
vector<int> outDeg;

int countMoves() {

    queue<int> q;
    int count = 0;

    for(int i = 0; i < N; i++) {
        if(outDeg[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        if(parent[node] != -1) {
            int mar = marbles[node];
            marbles[parent[node]] += (mar - 1);
            count += abs(mar - 1);

            outDeg[parent[node]]--;
            if(outDeg[parent[node]] == 0) {
                q.push(parent[node]);
            }
        }
    }

    return count;
}



int main() {

    while(true) {
        cin >> N;
        if(N == 0) {
            break;
        }

        marbles.clear();
        marbles.resize(N);
        parent.clear();
        parent.resize(N, -1);
        outDeg.clear();
        outDeg.resize(N, 0);

        int node, count, neighbourCount, next;
        for(int i = 0; i < N; i++) {
            cin >> node >> count >> neighbourCount;
            node--;
            marbles[node] = count;

            for(int j = 0; j < neighbourCount; j++) {
                cin >> next;
                next--;
                parent[next] = node;
            }
            outDeg[node] = neighbourCount;
        }

        cout << countMoves() << endl;
    }






    return 0;
}