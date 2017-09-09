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


int N, M, numberCity, numberShops;
vector<vector<ii> > AdjList;
bool isCity[50010];
bool isShop[1010];

vector<int> cities;
vector<int> shops;
int distances[50010];
int source[50010];

void dijkstra() {

    priority_queue<ii, vector<ii>, greater<ii> > pq;

    for(int i = 0; i < N; i++) {
        distances[i] = INT_MAX;
    }
    memset(source, -1, sizeof(source));

    for(int i = 0; i < shops.size(); i++) {
        if(true) {
            distances[shops[i]] = 0;
            source[shops[i]] = shops[i];
            pq.push(make_pair(0, shops[i]));
        }
    }

    while(!pq.empty()) {
        ii front = pq.top();
        pq.pop();

        int node = front.second;
        int d = front.first;

        if(d == distances[node]) {
            traverse(AdjList[node], it) {
                int next = it->first;

                if(distances[node] + it->second < distances[next]) {
                    distances[next] = distances[node] + it->second;
                    source[next] = source[node];
                    pq.push(make_pair(distances[next], next));
                } else if(distances[node] + it->second == distances[next]) {
                    source[next] = min(source[next], source[node]);
                }
            } 
        }
    }
}

void getResult() {
    vector<int> sources;
    for(int i = 0; i < cities.size(); i++) {
        if(true) {
            if(source[cities[i]] == -1) {
                sources.push_back(0);
            } else {
                sources.push_back(source[cities[i]] + 1);
            }

        }
    }

    for(int i = 0; i < sources.size(); i++) {
        if(true) {
            cout << sources[i] << " ";
        }
    }
}


int main() {

    cin >> N >> M;

    AdjList.clear();
    AdjList.resize(N);

    int start, dest, cost;
    for(int i = 0; i < M; i++) {
        cin >> start >> dest >> cost;
        start--; dest--;

        AdjList[start].push_back(make_pair(dest, cost));
        AdjList[dest].push_back(make_pair(start, cost));
    }

    cin >> numberCity >> numberShops;

    memset(isCity, false, sizeof(isCity));
    memset(isShop, false, sizeof(isShop));

    cities.clear();
    int city, shop;
    for(int i = 0; i < numberCity; i++) {
        cin >> city;
        city--;
        isCity[city] = true;
        cities.push_back(city);
    }

    shops.clear();
    for(int i = 0; i < numberShops; i++) {
        cin >> shop;
        shop--;
        isShop[shop] = true;
        shops.push_back(shop);
    }

    dijkstra();

    getResult();

    return 0;
}
