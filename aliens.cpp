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
    for (vector<pair<ii, int> >::iterator it = c.begin(); it != c.end(); it++)


int T[100010];
    
void makeSet(int N) {
    memset(T, 0, sizeof(T));
    for(int i = 0; i < N; i++) {
        T[i] = i;
    }
}
    
int findSet(int id) {
    if(id != T[id]) {
        T[id] = findSet(T[id]);
    }
    return T[id];
}
    
void unionSet(int n1, int n2) {
    T[findSet(n1)] = findSet(n2);
}

int N, M, K;
vector<pair<ii, int> > edgeList;

bool cmp(pair<ii, int> p1, pair<ii, int> p2) {
    if(p1.second < p2.second)
        return true;
    return false;
}

int kruskal() {

    makeSet(N);
    int mstCost = 0;
    int numSets = N;

    traverse(edgeList, it) {
        pair<ii, int> current = *it;
        int start = current.first.first;
        int end = current.first.second;

        if(numSets == K) {
            break;
        }

        if(findSet(start) != findSet(end)) {
            mstCost += current.second;
            unionSet(start, end);
            numSets--;
        }
    }

    return mstCost;
}


int main() {

    cin >> N >> M >> K;
    //cout << N << " " << M << " " << K << endl;

    edgeList.clear();

    int start, end, cost;
    for(int i = 0; i < M; i++) {
        cin >> start >> end >> cost;
        //start--; end--;
        //cout << start << endl;
        //cost--;

        if(start != end) {
            edgeList.push_back(make_pair(make_pair(start, end), cost));
            edgeList.push_back(make_pair(make_pair(end, start), cost));
        }
    }

    //cout << "ok" << endl;
    //traverse(edgeList, it) {
      //  cout << (*it).first.first << endl;
    //}
    sort(edgeList.begin(), edgeList.end(), cmp);
    //traverse(edgeList, it) {
      //  cout << (*it).first.first << endl;
    //}
    //cout << "ok" << endl;

    cout << kruskal() << endl;

    return 0;
}