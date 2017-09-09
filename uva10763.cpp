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

int N;
map<ii, int> edges;
map<ii, int> result;

vector<ii> all;


int main() {

    while(true) {
        cin >> N;
        if(N == 0) {
            break;
        }

        edges.clear();
        result.clear();

        int start, end;
        bool match = true;
        for(int i = 0; i < N; i++) {
            cin >> start >> end;
            
            ii current = make_pair(start, end);


            if(edges.find(current) == edges.end()) {
                edges.insert(make_pair(current, 1));
                all.push_back(current);
            } else {
                map<ii, int>::iterator it = edges.find(current);
                it->second++;
            }
        }

        for(int i = 0; i < all.size(); i++) {
            ii start = all[i];
            ii end = make_pair(start.second, start.first);

            map<ii, int>::iterator it1 = edges.find(start);
            map<ii, int>::iterator it2 = edges.find(end);

            if(it1->second != it2->second) {
                match = false;
                break;
            }
        }



        if(match) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}