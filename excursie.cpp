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


int N;
int distances[200][200];
int numberCities[200][200];

void floydWarshall() {

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            numberCities[i][j] = 1;
        }
    }
    for(int i = 0; i < N; i++) {
        numberCities[i][i] = 0;
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(distances[i][k] + distances[k][j] < distances[i][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                    numberCities[i][j] = numberCities[i][k] + numberCities[k][j];
                } else if(distances[i][k] + distances[k][j] == distances[i][j] &&
                    k != i && k != j) {
                    numberCities[i][j] = max(numberCities[i][j], numberCities[i][k] + numberCities[k][j]);
                }
            }
        }
    }
}

void printSolution() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << distances[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << numberCities[i][j] << " ";
        }
        cout << endl;
    }
}



int main() {

    cin >> N;
    memset(distances, -1, sizeof(distances));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> distances[i][j];
        }
    }

    floydWarshall();

    printSolution();


    return 0;
}