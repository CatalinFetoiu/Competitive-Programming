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


string str;
int type;

int dp[10010][3];
vector<int> nex[2];

ii getLength() {
    nex[0].clear();
    nex[0].resize(str.size(), -1);
    nex[1].clear();
    nex[1].resize(str.size(), -1);

    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < str.size(); i++) {
        dp[i][0] = 1;
        dp[i][1] = 1;
    }

    for(int i = str.size() - 1; i >= 0; i--) {
        //dp[i][0] >
        for(int j =  i + 1; j < str.size(); j++) {
            if(str[i] < str[j]) {
                if(dp[i][0] < 1 + dp[j][1]) {
                    dp[i][0] = 1 + dp[j][1];
                    nex[0][i] = j;
                }
            }
        }

        //dp[i][1] <
        for(int j = i + 1; j < str.size(); j++) {
            if(str[i] > str[j]) {
                if(dp[i][1] < 1 + dp[j][0]) {
                    dp[i][1] = 1 + dp[j][0];
                    nex[1][i] = j;
                }
            }
        }
    }

    int result = INT_MIN;
    int index, sign;
    for(int i = 0; i < str.size(); i++) {
        if(dp[i][0] > result) {
            result = dp[i][0];
            index = i;
            sign = 0;
        }
        if(dp[i][1] > result) {
            result = dp[i][1];
            index = i;
            sign = 1;
        }
    }

    cout << result << endl;
    return make_pair(index, sign);
}

void reconstruct(ii start) {
    int index = start.first;
    int sign = start.second;

    while(true) {
        cout << str[index];
        if(nex[sign][index] == -1) {
            break;
        }

        index = nex[sign][index];
        sign = 1 - sign;
    }
    cout << endl;
}





int main() {

    cin >> str;
    cin >> type;

    ii start = getLength();
    if(type == 1) {
        reconstruct(start);
    }


    return 0;
}