// AOJに通すと16/18でWA.マキシマムのケースでつまづいている.
// 大塚: 8行目,9行目を修正しました。これで通ります。
// 大塚: Cの要素は100億くらいのオーダーになりうるので、long型でないとダメです。

#include <iostream>
using namespace std;
int main(){
    int n,m,l;
    int A[100][100],B[100][100];
    long C[100][100];
    cin>>n>>m>>l;

    //行列A
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < m ; ++j) {
            cin>>A[i][j];
        }
    }

    //行列B
    for (int i = 0; i < m ; ++i) {
        for (int j = 0; j < l ; ++j) {
            cin >> B[i][j];
        }
    }

    //行列C
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < l ; ++j) {
            for (int k = 0; k < m ; ++k) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    //出力
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < l-1  ; ++j) {
            cout<<C[i][j]<<" ";
        }
        cout << C[i][l-1] << endl;
    }
    return 0;
}