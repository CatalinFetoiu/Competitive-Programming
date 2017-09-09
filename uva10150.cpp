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


vector<string> words;
map<string, int> mi;
vector<int> parent;
vector<bool> visited;

void addWord(string word) {
    int index = mi.size();
    mi.insert(make_pair(word, index)); 
}

int getIndex(string word) {
    map<string, int>::iterator it = mi.find(word);
    if(it == mi.end()) {
        return -1;
    } else {
        return it->second;
    }
}

char getChar(int val) {
    return 'a' + val;
}

int getInt(char val) {
    return val - 'a';
}

void bfs(string source, string dest) {

    visited.clear();
    visited.resize(words.size(), false);

    parent.clear();
    parent.resize(words.size(), -1);

    queue<string> q;

    visited[getIndex(source)] = true;
    q.push(source);

    while(!q.empty()) {
        string front = q.front();
        q.pop();
        if(front == dest) {
            break;
        }

        string next;
        for(int i = 0; i < front.size(); i++) {
            for(int letter = 0; letter < 26; letter++) {
                if(letter != getInt(front[i])) {
                    next = front;
                    next[i] = getChar(letter);

                    int index = getIndex(next);
                    //word exists in dictionary
                    if(index != -1) {
                        if(!visited[index]) {
                            visited[index] = true;
                            q.push(next);
                            parent[index] = getIndex(front);
                        }
                    }
                }
            }
        }
    }
}

void getSolution(string dest) {
    if(!visited[getIndex(dest)]) {
        cout << "No solution." << endl;
        return;
    }

    int index = getIndex(dest);

    vector<string> path;
    while(index != -1) {
        path.push_back(words[index]);
        index = parent[index];
    }

    for(int i = path.size()-1; i >= 0; i--) {
        cout << path[i] << endl;
    }
}


int main() {

    string word;

    words.clear();
    mi.clear();
    while(true) {
        getline(cin, word);
        if(word.size() == 0) {
            break;
        }

        words.push_back(word);
        addWord(word);
    }

    string start, end;
    bool first = true;

    while(true) {
        cin >> start;
        if(cin.eof()) {
            break;
        }

        cin >> end;

        if(!first) {
            cout << endl;
        }

        bfs(start, end);
        getSolution(end);

        first = false;
    }

    return 0;
}
