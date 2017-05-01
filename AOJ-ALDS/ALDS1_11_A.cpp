//
// Created by 司田行史 on 2016/04/27.
//

#include <iostream>
using namespace std;
const int N = 100;

int main (){
    int M[N][N] = {0};
    int n,u,k,v;
    cin >> n;

    for (int i = 0; i < n ; ++i) {
     cin >> u >> k;
        u--; //0オリジンにする
        for (int j = 0; j < k ; ++j) {
            cin >> v;
            v -- ; // 0オリジンにする
            M[u][v] = 1; //uとvの間に辺をはる
        }
    }

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j)  cout << " ";
            cout << M[i][j];
        }
        cout << endl;
    }

    return 0;
}
