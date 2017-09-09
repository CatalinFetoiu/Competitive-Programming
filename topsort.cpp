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
    for (vector<ii>::iterator it = c.begin(); it != c.end(); it++)

int N, M;
vector<int> value;
//orientat
vector<vector<ii> > AdjList;
vector<ii> nodes;
vector<bool> visited;
vector<int> topoOrder;
priority_queue<ii, vector<ii>, greater<ii> > pq;
vector<int> inDegree; 


void dfs(int node) {
    visited[node] = true;
    cout << node + 1 << " ";

    traverse(AdjList[node], it) {
        int next = it->second;

        if(!visited[next]) {
            inDegree[next]--;
            //cout << inDegree[next] << endl;
            if(inDegree[next] == 0) {
                pq.push(make_pair(value[next], next));
            }
        }
    }

    if(!pq.empty()) {
        ii next = pq.top();
        pq.pop();

        dfs(next.second);
    }
}

void setup() {

    //pq.clear();

    for(int i = 0; i < N; i++) {
        if(inDegree[i] == 0) {
            //cout << i+1 << endl;
            pq.push(make_pair(value[i], i));
        }
    }
}

void topoSort() {

    visited.clear();
    visited.resize(N, false);

    setup();
    ii start = pq.top();
    pq.pop();
    visited[start.second] = true;
    dfs(start.second);

    cout << endl;
}


bool cmp1(ii dest1, ii dest2) {
    if(dest1.second <= dest2.second) {
        return true;
    }
    return false;
}

bool cmp2(ii dest1, ii dest2) {
    if(dest1.second >= dest2.second) {
        return true;
    }
    return false;
}





int main() {

    cin >> N >> M;

    value.clear();
    value.resize(N);
    inDegree.clear();
    inDegree.resize(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> value[i];
    }

    AdjList.clear();
    AdjList.resize(N);

    int start, end;
    for(int i = 0; i < M; i++) {
        cin >> start >> end;
        start--; end--;

        inDegree[end]++;
        AdjList[start].push_back(make_pair(value[end], end));
    }

    topoSort();

    return 0;
}




