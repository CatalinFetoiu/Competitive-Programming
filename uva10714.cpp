#include <limits.h>
#include <cstdio>
#include <cstdlib>
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


int N, maxDist;
vector<int> distances;

int cost1(int i) {
    return min(distances[i], maxDist - distances[i]);
}

int cost2(int i) {
    return maxDist - cost1(i);
}

int main() {

    int T;
    cin >> T;
    while(T--) {
        cin >> maxDist >> N;
        distances.clear();
        distances.resize(N);

        for(int i = 0; i < N; i++) {
            cin >> distances[i];
        }

        int minimum = INT_MIN;
        int maximum = INT_MIN;

        for(int i = 0; i < N; i++) {
            minimum = max(minimum, cost1(i));
            maximum = max(maximum, cost2(i));
        }

        cout << minimum << " " << maximum << endl;
    }

    

    return 0;
}