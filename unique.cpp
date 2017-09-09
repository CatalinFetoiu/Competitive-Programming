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
vector<vector<bool> > blocked;
int A, B;
vector<bool> visited;
vector<int> parent;

bool bfs(int start, int dest, int type) {

   // cout << blocked[0][1] << endl;

    bool found = false;
    queue<int> q;
    q.push(start);

    visited.clear();
    visited.resize(N, false);
    visited[start] = true;

    parent.clear();
    parent.resize(N, -1);

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        if(front == dest) {
            found = true;
            break;
        }

        for(int i = 0; i < AdjList[front].size(); i++) {
            int next = AdjList[front][i];

            if(!visited[next]) {
                int aux;
                for(int j = 0; j < AdjList[front].size(); j++) {
                    if(AdjList[front][j] == next) {
                        aux = j;
                        break;
                    }
                }

                if(!blocked[front][aux]) {
                    //cout << next + 1 << endl;
                    q.push(next);
                    visited[next] = true;
                    
                    parent[next] = front;
                }
            }
        }
    }

    int index = dest;
    while(parent[index] != -1) {
        int src = parent[index];
        int dst = index;

        int aux;
        for(int i = 0; i < AdjList[src].size(); i++) {
            if(AdjList[src][i] == dst) {
                aux = i;
                break;
            }
        }

        //cout << src + 1 << " " << AdjList[src][aux] + 1 << endl;
        blocked[src][aux] = true;
        index = parent[index];
    }

    return found;
}

int main() {

    int F;
    cin >> F;
    while(F--) {
        cin >> N >> M;
        AdjList.clear();
        AdjList.resize(N);
        blocked.clear();
        blocked.resize(N);

        int start, end;
        for(int i = 0; i < M; i++) {
            cin >> start >> end;
            start--; end--;

            AdjList[start].push_back(end);
            AdjList[end].push_back(start);
            blocked[start].push_back(false);
            blocked[end].push_back(false);
        }

        cin >> A >> B;
        A--; B--;

        bfs(A, B, 0);

        cout << 1 - bfs(A, B, 1) << endl;
    }

    return 0;
}