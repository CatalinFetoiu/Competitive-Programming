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


vector<int> weight;
vector<int> iq;
vector<int> parent;

vector<pair<ii, int> > desIq;
vector<int> lis;

bool cmp(pair<ii, int> elephant1, pair<ii, int> elephant2) {
    if(elephant1.first.second >= elephant2.first.second) {
        return true;
    }
    return false;
}

void computeLis() {

    lis.clear();
    lis.resize(weight.size(), 1);
    parent.clear();
    parent.resize(weight.size(), -1);

    for(int i = 0; i < weight.size(); i++) {
        for(int j = i+1; j < weight.size(); j++) {
            pair<ii, int> elephant1 = desIq[i];
            pair<ii, int> elephant2 = desIq[j];

            if(elephant1.first.second > elephant2.first.second) {
                if(elephant1.first.first < elephant2.first.first) {
                    if(1 + lis[i] > lis[j]) {
                        lis[j]  = 1 + lis[i];
                        parent[j] = i;
                    }
                }
            }
        }
    }

    int bestLis = INT_MIN;
    int end = -1;
    for(int i = 0; i < weight.size(); i++) {
        if(lis[i] > bestLis) {
            bestLis = lis[i];
            end = i;
        }
    }

    cout << bestLis << endl;

    vector<int> path;

    int index = end;
    while(index != -1) {
        path.push_back(index);
        index = parent[index];
    }

    reverse(path.begin(), path.end());

    for(int i = 0; i < path.size(); i++) {
        cout << desIq[path[i]].second + 1 << endl;
    }
}


int main() {

    int w, intell;
    weight.clear();
    iq.clear();

    while(true) {
        cin >> w >> intell;
        if(cin.eof()) {
            break;
        }

        weight.push_back(w);
        iq.push_back(intell);
    }

    desIq.clear();
    for(int i = 0; i < weight.size(); i++) {
        desIq.push_back(make_pair(make_pair(weight[i], iq[i]), i));
    }

    sort(desIq.begin(), desIq.end(), cmp);

    computeLis();


    return 0;
}
