//
// Created by 司田行史 on 2016/05/03.
//

#include <iostream>
using namespace std;
const int MAX = 100;
const int INFTY = 2000000;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int n,M[MAX][MAX];

int prim (){
    int u,minv;
    int d[MAX],p[MAX],color[MAX];

    for (int i = 0; i < n ; ++i) {
        d[i] = INFTY;
        p[i] = -1;
        color[i] = WHITE;
    }

    d[0] = 0;

    while(1){
        minv = INFTY;
        u = -1;
        for (int i = 0; i < n ; ++i) {
            if(minv > d[i] && color[i] != BLACK){
                u = i;
                minv = d[i];
            }
        }
        if( u == -1) break;
        color[u] = BLACK;
        for (int v = 0; v < n ; ++v) {
            if(color[v] != BLACK && M[u][v] != INFTY){
                if(d[v] > M[u][v]){
                    d[v] = M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n ; ++i) {
        if( p[i] != -1) sum += M[i][p[i]];
    }

    return sum;
}

int main(){
    cin >> n;

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n ; ++j) {
            int e; cin >> e;
            // M[i][j] = (e == -1) ? INFTY : e; means
            if( e != -1){
                M[i][j] = e;
            }else{
                M[i][j] = INFTY;
            }
        }
    }

    cout << prim () << endl;
    return 0;
}