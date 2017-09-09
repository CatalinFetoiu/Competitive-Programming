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
vector<vector<int> > AdjList;

bool visited[30010];

int dfs(int node) {
    visited[node] = true;
    int count = 0;

    traverse(AdjList[node], it) {
        int next = *it;
        if(!visited[next]) {
            count += dfs(next);
        }
    }

    return 1 + count;
}


int main() {

    while(true) {
        cin >> N >> M;
        if(N == 0 && M == 0) {
            break;
        }

        AdjList.clear();
        AdjList.resize(N);

        int neighourNumber;
        for(int i = 0; i < M; i++) {
            cin >> neighourNumber;
            vector<int> group;

            int next;
            for(int j = 0; j < neighourNumber; j++) {
                cin >> next;
                group.push_back(next);
            }

            if(group.size() >= 2) {
                for(int i = 0; i < group.size() - 1; i++) {
                    AdjList[group[i]].push_back(group[i+1]);
                    AdjList[group[i+1]].push_back(group[i]);
                }
            }

            int last = group.size() - 1;
            AdjList[group[last]].push_back(group[0]);
            AdjList[group[0]].push_back(group[last]);
        }    

        memset(visited, false, sizeof(visited));
        cout << dfs(0) << endl;
    }

    return 0;
}