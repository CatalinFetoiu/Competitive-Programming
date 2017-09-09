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

using namespace std;

typedef pair<int, int> ii;

#define traverse(c, it) \
    for (vector<int>::iterator it = c.begin(); it != c.end(); it++)


int N, sum;
vector<int> prices;

ii findBestPair() {
    vector<ii> pairs;

    for(int i = 0; i < prices.size(); i++) {
        vector<int>::iterator next = lower_bound(prices.begin() + i, prices.end(),
            sum - prices[i]);

        if(next != prices.end() && prices[i] + *next == sum) {
            pairs.push_back(make_pair(i, next - prices.begin()));
        }
    }

    int index = 0;
    int minDiff = INT_MAX;
    for(int i = 0; i < pairs.size(); i++) {
        ii current = pairs[i];
        if(prices[current.second] - prices[current.first] < minDiff) {
            index = i;
            minDiff = prices[current.second] - prices[current.first];
        }
    }

    return pairs[index];
}


int main() {

    bool first = true;

    while(true) {
        cin >> N;
        if(cin.eof()) {
            break;
        }

        prices.clear();
        prices.resize(N);

        for(int i = 0; i < N; i++) {
            cin >> prices[i];
        }

        cin >> sum;

        sort(prices.begin(), prices.end());

        ii res = findBestPair();

        //cout << prices[res.first] << " " << prices[res.second] << endl;
        printf("Peter should buy books whose prices are %d and %d.\n",
            prices[res.first], prices[res.second]);

        cout << endl;
    }

    return 0;
}